#ifndef _TEST_H_
#define _TEST_H_

/* 断言数组是否有序. */
void assert_assend_order(int a[],int size);

void print_array(int a[],int size);

/* 随机产生一个数组.数组元素的取值不超过maxNum */
void random_array(int a[],int size, int maxNum);

#endif
