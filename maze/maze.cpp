//输出迷宫的所有解  基于递归的回溯法


#include <iostream>
#include <random>
using namespace std;
#define max_row 100
#define max_col 100

class Maze
{
public:
        Maze()=default;
        Maze(int r,int c);
        bool is_solved(int row,int col) const;
        void print()const;
        bool blocked(int row,int col)const;
        bool valid(int row,int col) const;
        void mark(int row,int col);
        void remove(int row,int col);
        void traverse(int i=0,int j=0);
private:
        int row_size;
        int col_size;
        int count;
        int exit_row,exit_col;
        int maze[max_row][max_col];
};

Maze::Maze(int r,int c):count(1),row_size(r),col_size(c),exit_row(r-1),exit_col(c-1)
{
    uniform_int_distribution<unsigned> u(0,1);
    default_random_engine e;
    for(int i=0;i<row_size;++i)
        for(int j=0;j<col_size;++j){
            if(i==0&&j==0) maze[i][j]=1;
            else if(i==exit_row&&j==exit_col) maze[i][j]=0;
            //else maze[i][j]=u(e);
            else maze[i][j]=0;
    }
    for(int i=0;i<row_size;++i){
        cout<<endl;
        for(int j=0;j<col_size;++j)
            cout<<maze[i][j]<<" ";
    }
    cout<<endl;
}

bool Maze::is_solved(int row,int col)const
{
    if(row==exit_row&&col==exit_col){
        for(int i=0;i<row_size;++i){
            cout<<endl;
            for(int j=0;j<col_size;++j)
            cout<<maze[i][j]<<" ";
        }
        cout<<endl;
            return true;
    }
    else return false;
}

void Maze::print()const
{
    int i=0;
    int j=0;
    cout<<"("<<i<<","<<j<<")"<<"->";
    for(int k=0;k<count;++k){
        if(i-1>=0&&maze[i-1][j]==maze[i][j]+1) {
            cout<<"("<<i-1<<","<<j<<")"<<"->";
            i=i-1;
        }
        else if(j-1>=0&&maze[i][j-1]==maze[i][j]+1){
            cout<<"("<<i<<","<<j-1<<")"<<"->";
            j=j-1;
        }
        else if(j+1<col_size&&maze[i][j+1]==maze[i][j]+1){
            cout<<"("<<i<<","<<j+1<<")"<<"->";
            j=j+1;
        }
        else if(i+1<row_size&&maze[i+1][j]==maze[i][j]+1){
            cout<<"("<<i+1<<","<<j<<")"<<"->";
            i=i+1;
        }
    }
    cout<<endl;
}

bool Maze::blocked(int row,int col)const
{
    if(maze[row][col]!=0) return false;
    else return true;
}

bool Maze::valid(int row,int col) const
{
    if(row>=0&&row<row_size&&col>=0&&col<col_size){
        return blocked(row,col);
    }
    else return false;
}

void Maze::mark(int row,int col)
{
    maze[row][col]=++count;
}

void Maze::remove(int row,int col)
{
    maze[row][col]=0;
    --count;
}

void Maze::traverse(int i,int j)//实现的时候不能带默认实参，声明时写就ok
{
    if(is_solved(i,j)) print();
    else{
        if(valid(i-1,j)){
            mark(i-1,j);
            traverse(i-1,j);
            remove(i-1,j);
        }
        if(valid(i+1,j)){
            mark(i+1,j);
            traverse(i+1,j);
            remove(i+1,j);
        }
        if(valid(i,j-1)){
            mark(i,j-1);
            traverse(i,j-1);
            remove(i,j-1);
        }
        if(valid(i,j+1)){
            mark(i,j+1);
            traverse(i,j+1);
            remove(i,j+1);
        }
    }
}

int main()
{
    int r,c;
    cin>>r>>c;
    Maze test(r,c);
    test.traverse();
    return 0;
}
