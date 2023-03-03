#include<stdio.h>
int num[1000000];
int num2[500000];
int num3[250000];
int num4[250000];
int main()
{
    int a,b,i,i2=1,i3=1,i4=1;
    
    scanf("%d%d",&a,&b);
    for(i=1;i<1000001;i++)
    {
        num[i-1]=i;
    }
    i=1;
    for(i=0;i<1000000;i++)
    {
        if(i%2!=0)
        {num2[i2-1]=num[i-1];i2++;}
        
    }
    i=1;
    i2=1;
    for(i2=1;i2<250002;i2++)
    {
        if(i2%3!=0)
        {num3[i3-1]=num2[i2];i3++;}
        
    }
    i2=1;
    i3=1;
        for(i3=1;i3<250002;i3++)
    {
        if(i3%7!=0)
        {num3[i4-1]=num3[i3];i4++;}
        
    }
    i3=1;
    i4=1;
    for(i=0;i<100;i++)
    {
        printf("%d ",num3[i]);
    }

    return 0;
}
int num12(int a)
{

}