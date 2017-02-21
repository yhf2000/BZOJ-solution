#include<iostream>
#include<cstdio>
#include<cstring> 
using namespace std;
inline int read()
{
    char ch=getchar();
    int f=1,x=0;
    while(!(ch>='0'&&ch<='9')){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+(ch-'0');ch=getchar();}
    return x*f;
}
int n,m,mod;
int p[25];
char ch[25];
int a[25][25],b[25][25];
void mul(int a[25][25],int b[25][25],int ans[25][25])
{
	int tmp[25][25];
	for(int i=0;i<m;i++)
	    for(int j=0;j<m;j++)
	    {
	    	tmp[i][j]=0;
	    	for(int k=0;k<m;k++)
	    	    tmp[i][j]=(tmp[i][j]+a[i][k]*b[k][j])%mod;
	    }
	for(int i=0;i<m;i++)
	    for(int j=0;j<m;j++)
	        ans[i][j]=tmp[i][j];
}
int main() 
{
	n=read();m=read();mod=read();
    scanf("%s",ch+1);
    int j=0;
	for(int i=2;i<=m;i++)
    {
    	while(j>0&&ch[j+1]!=ch[i])j=p[j];
    	if(ch[j+1]==ch[i])j++;
    	p[i]=j;
    }
    for(int i=0;i<m;i++)
       for(int j=0;j<=9;j++)
       {
       	    int t=i;
			while(t>0&&ch[t+1]-'0'!=j)
			    t=p[t];
			if(ch[t+1]-'0'==j)t++;
			if(t!=m)b[t][i]=(b[t][i]+1)%mod;
       }
    for(int i=0;i<m;i++)
        a[i][i]=1;
    while(n)
    {
    	if(n&1)mul(a,b,a);
    	mul(b,b,b);
    	n>>=1;
    }
    int sum=0; 
	for(int i=0;i<m;i++)
	    sum=(sum+a[i][0])%mod;
	printf("%d",sum);
	return 0;
}
