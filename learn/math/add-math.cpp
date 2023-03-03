#include<stdio.h>
//#include "tools.h"

float sfp(char a,int b,float c,int d)
{   
    float e,f,l;
    int i;

    switch (a)
    {
    case 'y':
        f=b*c;
        e=b+f;
        for(i=0;i<=d-3;i++)
        {
            f=f*c;
            e=e+f;
            //printf("%f",f);
        }
        printf("等比数列和为:%.1f",e);
        break;

    case 'n':
        f=b+c;
        e=b+f;
        for(i=0;i<d-2;i++)
        {
            f=f+c;
            e=e+f;
            //printf("%f",f);
        }
        printf("等比数列和为:%.1f",e);
        break;

        
    
    default:
        break;
    }
    return 0;
}

int main()
{
    int a,c,d;
    char b='y';
    float f;
    printf("首项为整数，输入(y/n)确定为等比或等差数列：\n");
    scanf("%c",&b);
    printf("请输入正数\n");
    scanf("%d",&a);
    if(a<0)
        {
            printf("请输入首项(正整数)\n");
            scanf("%d",&a);
        }
    else 
        {

            switch(b)
            {
            case 'y':
                printf("确定为等比数列\n输入q:\n");
                scanf("%f",&f);;
                printf("输入项数:\n");
                scanf("%d",&c);
                sfp('y',a,f,c);
                break;
            case 'n':
                printf("确定为等差数列\n输入d:\n");
                scanf("%f",&f);
                printf("输入项数:\n");
                scanf("%d",&c);
                sfp('n',a,f,c);
                break;
            default:
                printf("输入错误 %c",b);
                break;
            }

        }
    return 0;
}