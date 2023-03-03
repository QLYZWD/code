#include<stdio.h>
#include<windows.h>

int cube(int a)
{
	return a*a*a;
}
int isTureNum(int a)
{
	int b,c,d,e;
	b=a/100;
	c=(a-b*100)/10;
	d=a%10;
	e=cube(b)+cube(c)+cube(d);
	return e;
}
int main() 
{
	int i;
	for(i=100;i<1000;i++)
	{
		//printf("%d ",i);
		if(i==isTureNum(i))
		{
			printf("%d \n",i);
		} 
		/*else
		{
			printf("\n");
		}
		*/
	}
	return 0;
}


