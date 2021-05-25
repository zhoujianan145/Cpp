#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
void Printbit(int num)
{
	//for (int i = 31; i >= 1; i -= 2)
	//{
	//	printf("%d ", num &(1 << i));
	//}
	//printf("\n");
	//for (int i = 30; i >= 0; i -= 2)
	//{
	//	printf("%d ", num &(1 << i));
	//}
	//printf("\n");
	for (int i = 31; i >= 1; i -= 2)
	{
		printf("%d ", (num>>i)&1);
	}
	printf("\n");
	for (int i = 30; i >= 0; i -= 2)
	{
		printf("%d ", (num >> i) & 1);
	}
	printf("\n");

}
int main()
{
	int num = 0;
	printf("请输入一个数： ");
	scanf("%d", &num);
	Printbit(num);
	system("pause");
	return 0;
}
