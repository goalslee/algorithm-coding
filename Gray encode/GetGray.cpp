/*��Ŀ������λ������ӡ��������*/







#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

void getGray(int k,vector<string> &ret)
{

    auto itor=ret.end()-1;
    string temp=*itor;
    for(int i=k-1;i>-1;--i){
        //string last=*itor; ��ʧЧ����Ϊvector����ʱ���������ڴ�
        string last=temp;
        if(last.at(i)=='0') last.at(i)='1';
        else last.at(i)='0';
        if(find(ret.begin(),ret.end(),last)==ret.end()) {
                ret.push_back(last);
                getGray(k,ret);
        }
    }
    return;
}

int main()
{
    vector<string> ret;
    int k;
    cin>>k;
    string str(k,'0');
    cout<<str<<endl;
    cout<<endl;
    ret.push_back(str);
    getGray(k,ret);
    for(vector<string>::iterator i=ret.begin();i<ret.end();i++)
    cout << *i << endl;
    return 0;
}
