#ifndef _TOOLS_H_
#define _TOOLS_H_
    #include<stdio.h>

int scanfs(char a)
{
    int b;
    switch (a)
    {
    case 'd':
        {
        (int)b;
        printf("输入整数：");
        b=scanf("%d",&b);
        break;
        }

    case 'o':
        {
        (int)b;
        printf("输入整数：");
        b=scanf("%o",&b);
        break;
        }

    case 'x':
        {
        (int)b;
        printf("输入整数：");
        b=scanf("%x",&b);
        break;
        }

    case 'c':
        {
        (char)b;
        printf("输入字符：");
        b=scanf("%c",&b);
        break;
        }

    /*
    case 's':
        {
            {}
        }

    */
    default:
        break;
    }
    return b;
    
}



#endif