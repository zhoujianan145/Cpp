#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
int main(){
	int a = 0;
	int b = 0;
	int c = 0;
	scanf("%d%d", &a,&b);
	    a = a^b;
		b = a^b;
		a = a^b;
		printf("%d\n%d\n", a, b);
        system("pause");
	    return 0;
}