/*广度优先 象棋马 走到目标*/



#include <iostream>
#include<cstdio>
#include<queue>
using namespace std;
#define MAX 10

int data[MAX][MAX];
typedef struct {
  int x;
  int y;
}Loc;
int dir[8][8]={{1,2},{1,-2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,1},{-2,-1}};

int isBound(Loc in)
{
    if(in.x>=0&&in.x<MAX&&in.y>=0&&in.y<MAX)
        return 1;
    else return 0;
}

int BFS(Loc f,Loc t)
{
    queue<Loc> que;
    que.push(f);
    data[f.x][f.y]=1;
    int width=1;
    Loc out;
    Loc in;
    int count=0;
    while(!que.empty()){
        for(int i=width;i>0;--i){
            out=que.front();
            que.pop();
            for(int j=0;j<8;j++){
                in.x=out.x+dir[j][0];
                in.y=out.y+dir[j][1];

                if(isBound(in)&&data[in.x][in.y]==0){
                    if(in.x==t.x&&in.y==t.y){
                         return ++count;
                    }
                    que.push(in);
                    data[in.x][in.y]=1;
                }
            }
        }
        width=que.size();//important
        ++count;
    }
    return 0;
}

int main()
{

    Loc from,to;
    scanf("%d %d",&from.x,&from.y);
    scanf("%d %d",&to.x,&to.y);

    for(int i=0;i<MAX;++i)
        for(int j=0;j<MAX;++j)
            data[i][j]=0;
    int ret=BFS(from,to);
    printf("%d",ret);
    return 0;
}
