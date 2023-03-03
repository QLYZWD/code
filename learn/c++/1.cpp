#include<iostream>
using namespace std;
void max(int a,int b)
{
	if (a>b) cout<<"max("<<a<<','<<b<<')'<<'='<<a<<endl;
		else cout<<"max("<<a<<','<<b<<')'<<'='<<b<<endl;
}
void max(double a,double b)
{
	if (a>b) cout<<"max("<<a<<','<<b<<')'<<'='<<a<<endl;
		else cout<<"max("<<a<<','<<b<<')'<<'='<<b<<endl;
}
void max(int a,int b,int c)
{
	if (a>b&&a>c) cout<<"max("<<a<<','<<b<<','<<'c'<<')'<<'='<<a<<endl;
		else if(b>a&&b>c) cout<<"max("<<a<<','<<b<<','<<'c'<<')'<<'='<<b<<endl;
			else if(c>a&&c>b) cout<<"max("<<a<<','<<b<<','<<'c'<<')'<<'='<<c<<endl;
}
void max(double a,double b,double c)
{
	if (a>b&&a>c) cout<<"max("<<a<<','<<b<<','<<'c'<<')'<<'='<<a<<endl;
		else if(b>a&&b>c) cout<<"max("<<a<<','<<b<<','<<'c'<<')'<<'='<<b<<endl;
			else if(c>a&&c>b) cout<<"max("<<a<<','<<b<<','<<'c'<<')'<<'='<<c<<endl;
}		
int main( )
{
int a, b, c;
double x, y, z;
cout<<"请输入 3 个整数:";
cin>>a>>b>>c;
max(a, b);
max(a, c);
max(b, c);
max(a, b, c);
cout<<"请输入 3 个实数:";
cin>>x>>y>>z;
max(x, y);
max(x, z);
max(y, z);
max(x, y, z);
system("pause");
return 0;
}