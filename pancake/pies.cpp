//烙饼排序问题：一次只能抓最上面的几块饼，把它们上下颠倒


#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

void sort_pies(vector<int>& pies,int to)
{
    if(0!=to){
        vector<int>::iterator first=pies.begin();
        vector<int>::iterator last=pies.begin()+to+1;//end() point to the end+1,so add 1;
        vector<int>::iterator m =max_element(first,last);
        if(m==last-1){
            --to;
        }
        else{
            reverse(first,m+1);
            reverse(first,last);
            --to;
        }
        sort_pies(pies,to);
    }
}

void sort_pies_not(vector<int>& pies,int to)
{
    while(0!=to){
        vector<int>::iterator first=pies.begin();
        vector<int>::iterator last=pies.begin()+to+1;//end() point to the end+1,so add 1;
        vector<int>::iterator m =max_element(first,last);
        if(m==last-1){
            --to;
        }
        else{
            reverse(first,m+1);
            reverse(first,last);
            --to;
        }
    }
}


int main()
{
    vector<int> pies={8,4,9,5,6};
    sort_pies_not(pies,4);
    for(auto it=pies.begin();it!=pies.end();++it)
         cout << *it << endl;
    return 0;
}
