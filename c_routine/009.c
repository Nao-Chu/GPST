#include<stdio.h>

int main()
{
	return 0;
}
#include <stdio.h>

typedef struct Study{
	int age;
	char sex;
	float stature;
	float weigh;
}study;

int main()
{
	study xiaoming;
	xiaoming.age = 18;
	xiaoming.sex = 'Y';
	xiaoming.stature = 175.1;
	xiaoming.weigh = 62.6;
	printf("小明的年龄为:%d\n",xiaoming.age);
	printf("小明的性别为:%c\n",xiaoming.sex);
	printf("小明的身高为:%.1f\n",xiaoming.stature);
	printf("小明的体重为:%.1f\n",xiaoming.weigh);
	return 0;
}
