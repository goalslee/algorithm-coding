/*
最长公共子序列

*/


#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
using namespace std;

char dp[100][100];
int b[100][100];


int LCS(char* x,char* y)
{
	int m=strlen(x);
	int n=strlen(y);
	int i,j;
	for(i=0;i<m;++i) dp[i][0]=0;
	for(i=0;i<n;++i) dp[0][i]=0;
	
	for(i=1;i<=m;++i)
		for(j=1;j<=n;++j){
			if(x[i-1]==y[j-1]) {
				dp[i][j]=dp[i-1][j-1]+1;
				b[i][j]=0;
			}
			else if(dp[i-1][j]>dp[i][j-1]) {
						dp[i][j]=dp[i-1][j];
						b[i][j]=1;
					}
			else {
				dp[i][j]=dp[i][j-1];
				b[i][j]=2;
			}					
		}
	
}

void printpath(int i,int j,char* x)
{
	if(0==i||0==j) return;
	if(0==b[i][j]) {
	        printpath(i-1,j-1,x);//important
			cout<<x[i-1]<<" ";
			}
	else if(1==b[i][j]) printpath(i-1,j,x);
	else printpath(i,j-1,x);
}


int main()
{

	char x[100],y[100];
	//cin>>x;
	//cin>>y;
	scanf("%s",x);
	scanf("%s",y);
	int m=strlen(x);
	int n=strlen(y);
	LCS(x,y);
	printpath(m,n,x);
	return 0;
}
