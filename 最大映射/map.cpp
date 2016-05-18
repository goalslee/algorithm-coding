/*
[编程题] 最大映射
有 n 个字符串，每个字符串都是由 A-J 的大写字符构成。现在你将每个字符映射为一个 0-9 的数字，不同字符映射为不同的数字。这样每个字符串就可以看做一个整数，唯一的要求是这些整数必须是正整数且它们的字符串不能有前导零。现在问你怎样映射字符才能使得这些字符串表示的整数之和最大？

输入描述:
每组测试用例仅包含一组数据，每组数据第一行为一个正整数 n ， 接下来有 n 行，每行一个长度不超过 12 且仅包含大写字母 A-J 的字符串。 n 不大于 50，且至少存在一个字符不是任何字符串的首字母。


输出描述:
输出一个数，表示最大和是多少。

输入例子:
2
ABC
BCA

输出例子:
1875
*/


#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
    vector<pair<long long,char>> sum = {{0,'A'},{0,'B'},{0,'C'},{0,'D'},{0,'E'},{0,'F'},{0,'G'},{0,'H'},{0,'I'},{0,'J'}};
    int n;
    long long ret=0;
    cin>>n;
    vector<char> mark;
    while(n--){
        string input;
        cin>>input;
        mark.push_back(input[0]);
        long long weight=1;
        for(auto iter=input.rbegin();iter!=input.rend();++iter){
            sum[*iter-'A'].first+=weight;
            weight*=10;
        }
    }

    sort(sum.begin(),sum.end(),[](const pair<long long,char>&s1,const pair<long long,char>&s2){return s1.first>s2.first;});

    if(find(mark.begin(),mark.end(),sum[9].second)!=mark.end()){//for 0 start string
        auto i=sum.end()-2;
        while( find(mark.begin(),mark.end(),i->second) !=mark.end()) --i;
        auto temp=*i;
        sum.erase(i);
        sum.push_back(temp);
    }

    for(int i=0;i<10;++i) ret+=(sum[i].first)*(9-i);

    cout << ret << endl;
    return 0;
}
