//2个大整数相加 例如12346578974654114548+454561654543213146546
//思路：转化成字符的相加

#include <iostream>
#include<string>
#include<stack>

using namespace std;

int main()
{
    string str1,str2;
    stack<char> stk1,stk2,ret;
    char flag=0;
    cin>>str1>>str2;
    for(auto iter=str1.begin();iter!=str1.end();++iter)
        stk1.push(*iter);
    for(auto iter=str2.begin();iter!=str2.end();++iter)
        stk2.push(*iter);

    while(!stk1.empty()&&!stk2.empty()){
        char temp=stk1.top()-'0'+stk2.top()-'0'+flag;
        stk1.pop();
        stk2.pop();
        if(temp>9){
            flag=1;
            temp/=10;
        }
        else flag=0;
        ret.push(temp+'0');
    }

    while(!stk1.empty()){
        char temp=stk1.top()-'0'+flag;
        stk1.pop();
        if(temp>9){
            flag=1;
            temp/=10;
        }
        else flag=0;
        ret.push(temp+'0');
    }
	
    while(!stk2.empty()){
        char temp=stk2.top()-'0'+flag;
        stk2.pop();
        if(temp>9){
            flag=1;
            temp/=10;
        }
        else flag=0;
        ret.push(temp+'0');
    }
	
    if(1==flag) ret.push('1');
	
    while(!ret.empty()){
        cout << ret.top();
        ret.pop();
    }
    return 0;
}
