//多项式加法

#include <iostream>
#include <list>

using namespace std;

typedef list< pair<int,int> > poly;

poly operator +(const poly &p,const poly &q)
{
    poly ret;
    auto p_ptr=p.begin();
    auto q_ptr=q.begin();
    while(p_ptr!=p.end()&&q_ptr!=q.end()){
        if(p_ptr->second==q_ptr->second){
            ret.push_back(make_pair((p_ptr->first)+(q_ptr->first),p_ptr->second));
            ++p_ptr;
            ++q_ptr;
        }
        else if(p_ptr->second>q_ptr->second){
            ret.push_back(*p_ptr);
            ++p_ptr;
        }
        else {
            ret.push_back(*q_ptr);
            ++q_ptr;
        }
    }
    while(p_ptr!=p.end()){
        ret.push_back(*p_ptr);
        ++p_ptr;
    }
    while(q_ptr!=q.end()){
        ret.push_back(*q_ptr);
        ++q_ptr;
    }
    return ret;
}
int main()
{
    poly p1,p2,p;
    int n1,n2;
    cin>>n1>>n2;
    int m,n;
    while(n1--){
        cin>>m>>n;
        p1.push_back(make_pair(m,n));
    }
    while(n2--){
        cin>>m>>n;
        p2.push_back(make_pair(m,n));
    }
    p=p1+p2;
    for(auto it=p.begin();it!=p.end();++it){
        cout<<it->first<<" "<<it->second<<endl;
    }

    return 0;
}
