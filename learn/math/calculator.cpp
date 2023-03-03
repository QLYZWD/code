#include<stdio.h>
#include<string.h> //字符串头文件
#include<stdlib.h>

main()
{
    char str[1000];  //声明一个数组存放输入的文本
    float num[1000];     //储存各给数字
    char num_[1000]={"123"};     //数字文本暂存
    char opt[1000];      //储存各个符号
    int len; //len存放字符长度
    /*输入判断*/
    printf("输入一个算式(+,-,*,/)\n");
    scanf("%s",str);
    len=strlen(str);
    //printf("%s长度为%d\n",str,len);
    int i;
    int o=0; //储存符号数量
    int o1=0; //储存上一个符号的位置
    int n=0; //储存数字的数量
    int n_=0;
    int len_num; //数字长度
    int len_num_; //暂存数字长度
    int i1=0; //录入数字的i
    for(i=0;i<len;i++)
    {
        
        switch (str[i])
        {
        case '+':
            {
            opt[o]='+';
            printf("检测到加号(%d);",o+1);
            o++;
            len_num=i-o1;
            if(n_>0) len_num=len_num-1;
            else len_num=len_num;

            len_num_=len_num;
            
            for(i1=0;i1<len_num;i1++)
            {
                num_[i1]=str[i-len_num_]; //录入数字
                num[n_]=(float)num_[i1];
                len_num_=len_num_-1;
            }
            n_++;
            printf("检测到数字(%s)",num_);
            o1=i;
            break;
            }
        
        case '-':
            {
            opt[o]='-';
            printf("检测到减号(%d);",o+1);
            o++;
            len_num=i-o1;
            len_num_=len_num;
            for(i1=0;i1<len_num;i1++)
            {
                num_[i1]=str[i-len_num_]; //录入数字
                num[n]=(float)num_[i1];
                len_num_=len_num_-1;
            }
            printf("检测到数字(%s)",num_);
            o1=i;
            break;
            }
        
        case '*':
            {
            opt[o]='*';
            printf("检测到乘号(%d);",o+1);
            o++;
            len_num=i-o1;
            len_num_=len_num;
            for(i1=0;i1<len_num;i1++)
            {
                num_[i1]=str[i-len_num_]; //录入数字
                num[n]=(float)num_[i1];
                len_num_=len_num_-1;
            }
            printf("检测到数字(%s)",num_);
            o1=i;
            break;
            }
        
        case '/':
            {
            opt[o]='/';
            printf("检测到除号(%d);",o+1);
            o++;
            len_num=i-o1;
            len_num_=len_num;
            for(i1=0;i1<len_num;i1++)
            {
                num_[i1]=str[i-len_num_]; //录入数字
                num[n]=(float)num_[i1];
                len_num_=len_num_-1;
            }
            printf("检测到数字(%s)",num_);
            o1=i;
            break;
            }

        default:
            
            //printf("%c",str[i]);
            break;
        }
        
    }
    if(str[len-1]=='=')
            {
            len_num=i-o1;
            if(n_>0) len_num=len_num-1;
            else len_num=len_num;

            len_num_=len_num;
            
            for(i1=0;i1<len_num-1;i1++)
            {
                num_[i1]=str[i-len_num_]; //录入数字
                //num[n_]=(float)num_;
                len_num_=len_num_-1;
            }
            scanf("%f",printf("%s",num_));
            n_++;
            if(len_num<3)
            {
                num[n_]=(float)num_[0];

            }
            
            printf("检测到数字(%s)",num_);
            o1=i;                

            }
            else
            {
                printf("最后一位应输入=");
            }
            printf("\n%s",num);


}