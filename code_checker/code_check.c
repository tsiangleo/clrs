#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>

#define IN  1
#define OUT 0
#define MAXPATH 4096

/*
 * 待完善功能：多级目录扫描.
 * */
int c,nc,nl,nw;

/* 统计输入文本流中的字符个数，单词个数，行数。 */
int count(char *s,FILE *fp)
{	
	int state = OUT;
	while((c = fgetc(fp)) != EOF)
	{
		++nc;
		if(c == '\n')
			++nl;
		if(c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if(state == OUT)
		{
			state = IN;
			nw++;
		}
	}

	return 0;
}


int is_codefile( char *file)
{
	int len = strlen(file);
	if(len > 2)
	{
		if(file[len - 1] == 'h' && file[len - 2] == '.') //.h
			return 1;

		if(file[len - 1] == 'c' && file[len - 2] == '.') //.c
			return 1;

		if(len > 3 && file[len - 1] == 'c' && file[len - 2] == 'c' && file[len - 3] == '.') //.cc
			return 1;
		
		if(len > 4 && file[len - 1] == 'p' && file[len - 2] == 'p' && file[len - 3] == 'c' && file[len-4] == '.') //.cpp
			return 1;
	}
	return 0;
}

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		fprintf(stderr,"Usage:%s <prject path>\n",argv[0]);
		return -1;
	}

	DIR *dirp;
	struct dirent *entp;

	dirp = opendir(argv[1]);
	if(dirp == NULL)
	{
		perror("opendir");
		return -1;
	}

	while((entp = readdir(dirp)) != NULL)
	{
		if(is_codefile(entp->d_name))
		{
			FILE *fp;

			char path[MAXPATH] = {0}; //路径名+文件名

			snprintf(path,sizeof(path)-1,"%s",argv[1]);
			if(argv[1][strlen(argv[1])-1] != '/')
				snprintf(path+strlen(argv[1]),sizeof(path)-strlen(argv[1]),"%c%s",'/',entp->d_name);
			else	
				snprintf(path+strlen(argv[1]),sizeof(path)-strlen(argv[1]),"%s",entp->d_name);
	
			printf("scan file:[%s]\n",path);
			if((fp = fopen(path,"r")) == NULL)
			{
				perror("open");
				fprintf(stderr,"open file '%s' error.\n",entp->d_name);
				continue;
			}
		
			count(entp->d_name,fp);
			fclose(fp);
		}
	}
	closedir(dirp);
	
	printf("chars = %d,lines = %d,words = %d\n",nc,nl,nw);
	
	return 0;
}

