#include<stdio.h>
main()
{   
    int a,b,c,i;
    scanf("%d%d%d",&a,&b,&c);
    for(i=1;i<2000000;i++)
    {
        if(i%a==0)
        {
            if(i%b==0)
            {
                if(i%c==0)
                {
                printf("%d",i);
                break;
                }
            }

        }

    }

}