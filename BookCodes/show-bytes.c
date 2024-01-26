#include <stdio.h>

// 非负整数字符指针
typedef unsigned char *byte_pointer;

/******************************************************************
 * start是一个指向`unsigned char`对象的指针
 * start: unsigned char类型数组
 * length: 数组长度
 ******************************************************************/
void show_bytes(byte_pointer start, size_t length) {
  for (byte_pointer p = start; p < start + length; p++) {
    // 打印至少2个十六进制数字，如果不足2位，则前面补0
    printf(" %.2x", *p);
  }
  printf("\n");
}

/********************************************************************************
 * int类型变量，存储变量需要`sizeof(int)`个字节。以64位机器为例，是以4个字节存储int类型变量
 * &x指向的是4个字节中的第0个字节位置
 * 强制转换&x为`unsigned char *`
 * 告诉编译器这个指针看成指向一个宇节序列，而不是指向一个原始数据类型的对象
 *******************************************************************************/
void show_int(int x) {
  //
  show_bytes((byte_pointer)&x, sizeof(x));
}

void show_float(float x) {
  //
  show_bytes((byte_pointer)&x, sizeof(x));
}

void show_pointer(void *x) {
  //
  show_bytes((byte_pointer)&x, sizeof(void *));
}

void test_show_bytes(int);

int main(void) {
  test_show_bytes(12345);
  return 0;
}

void test_show_bytes(int val) {
  int ival = val;
  int fval = (float)val;
  int *pval = &val;

  show_int(ival);
  show_float(fval);
  show_pointer(pval);
}