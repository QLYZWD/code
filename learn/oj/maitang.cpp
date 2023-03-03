#include<stdio.h>
int math(int a,int b,int i)
{
    int p,o,c=2;
    for(p=0;p<100;p++)
        {
        for (o=0;o<100;o++)
        {
        if(i-a*o-b*p==0)
        {
            c=0;
            break;
        }

        }

        }
        if(c==0)
        {
            
        }
        else return 2;
}

main()
{
    int a,b,i=100;
    scanf("%d%d",&a,&b);
    while (1<2)
    {
        if(i%a!=0 && i%b!=0 && math(a,b,i)==2)
        {
            printf("%d",i);
            break;
        }
        i--;
    }
    
}