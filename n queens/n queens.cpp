//回溯法求n皇后问题
//backtrace for n queens problem



#include <iostream>
using namespace std;
#define max_board 100


class Queens
{
public:
    Queens(int size);
    bool is_solved() const;
    void print() const;
    bool unguarded(int col) const;
    void insert(int col);
    void remove(int col);
    int board_size;
    bool board_check(int i,int j)const;
    void solve_from();
private:
    int count;
    bool queen_square[max_board][max_board];
};

Queens::Queens(int size):board_size(size),count(0)
{
    for(int i=0;i<board_size;++i)
        for(int j=0;j<board_size;++j)
            queen_square[i][j]=0;
}

bool Queens::is_solved() const
{
    if(count==board_size) return true;
    else return false;
}

void Queens::print() const
{
    for(int i=0;i<board_size;++i){
        cout<<endl;
        for(int j=0;j<board_size;++j){
            cout<<queen_square[i][j]<<" ";
        }
    }
    cout<<endl;

}

bool Queens::board_check(int i,int j) const
{
    if(i>=0&&i<=board_size&&j>=0&&j<=board_size) return true;
    else return false;
}

bool Queens::unguarded(int col)const
{

    for(int row=count-1;row>=0;--row){
        if (queen_square[row][col]){
            return false;
        }
    }
    for(int i=count-1,j=col-1;board_check(i,j)==true;--i,--j){
        if (queen_square[i][j]){
            return false;
        }
    }
    for(int i=count-1,j=col+1;board_check(i,j)==true;--i,++j){
        if (queen_square[i][j]){
            return false;
        }
    }
    return true;
}

void Queens::insert(int col)
{
    queen_square[count++][col]=1;
}

void Queens::remove(int col)
{
    queen_square[--count][col]=0;
}

void solve_from(Queens &configuration)
{
    if(configuration.is_solved()) configuration.print();
    else{
        for(int i=0;i<configuration.board_size;++i){
            if(configuration.unguarded(i)){
                configuration.insert(i);
                solve_from(configuration);
                configuration.remove(i);
            }
        }
    }
}

void Queens::solve_from()//important
{
    if(is_solved()) print();
    else{
        for(int i=0;i<board_size;++i){
            if(unguarded(i)){
                insert(i);
                solve_from();
                remove(i);
            }
        }
    }
}


int main()
{
    int i;
    cin>>i;
    Queens queens(i);
    queens.solve_from();

    return 0;
}
