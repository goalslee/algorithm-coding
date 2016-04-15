/*
Michaelϲ����ѩ���Ⲣ����֣� ��Ϊ��ѩ��ȷ�ܴ̼�������Ϊ�˻���ٶȣ������������������б�����ҵ��㻬���µף��㲻�ò��ٴ������»��ߵȴ������������㡣Michael��֪��һ�����������ѩ��������һ����ά��������������ÿ�����ִ����ĸ߶ȡ�
25->15->2->1  ���Ϊ24

5
5
1 4 5 6 10
2 3 7 8 13
15 25 20 23 24
21 9 11 14 12
19 18 17 16 22
*/


#include <iostream>
#include<cstdio>
using namespace std;

int dp[100][100];
int data[100][100];
int dir[4][4]={{-1,0},{1,0},{0,-1},{0,1}};
int m,n;

int isBound(int x,int y)
{
    if(x>=0&&x<m&&y>=0&&y<n)
        return 1;
    else return 0;
}

int DP(int x,int y)
{
    if(dp[x][y]!=0) return dp[x][y];
    int max=0;
    int x1,y1;
    for(int i=0;i<4;i++){
            x1=x+dir[i][0];
            y1=y+dir[i][1];
            if(isBound(x1,y1)){
                if(data[x][y]>data[x1][y1]){
                    int temp=DP(x1,y1)+data[x][y]-data[x1][y1];
                    if(max<temp) max=temp;
               }
            }
    }
    dp[x][y]=max;
    return max;
}


int main()
{
    int ret=0;
    int k,s;
    scanf("%d",&m);
    scanf("%d",&n);
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++){
            scanf("%d",&data[i][j]);
            dp[i][j]=0;
        }
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++){
           int temp=DP(i,j);
           if(ret<temp) ret=temp;
        }
   /*for(int i=0;i<m;i++){
        printf("\n");
        for(int j=0;j<n;j++)
            printf("%5d ",dp[i][j]);
    }
    */




    printf("���ѩ���Ϊ: %d  \n",ret);
    return 0;
}
