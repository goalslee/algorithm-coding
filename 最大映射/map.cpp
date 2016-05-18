/*
[�����] ���ӳ��
�� n ���ַ�����ÿ���ַ��������� A-J �Ĵ�д�ַ����ɡ������㽫ÿ���ַ�ӳ��Ϊһ�� 0-9 �����֣���ͬ�ַ�ӳ��Ϊ��ͬ�����֡�����ÿ���ַ����Ϳ��Կ���һ��������Ψһ��Ҫ������Щ���������������������ǵ��ַ���������ǰ���㡣������������ӳ���ַ�����ʹ����Щ�ַ�����ʾ������֮�����

��������:
ÿ���������������һ�����ݣ�ÿ�����ݵ�һ��Ϊһ�������� n �� �������� n �У�ÿ��һ�����Ȳ����� 12 �ҽ�������д��ĸ A-J ���ַ����� n ������ 50�������ٴ���һ���ַ������κ��ַ���������ĸ��


�������:
���һ��������ʾ�����Ƕ��١�

��������:
2
ABC
BCA

�������:
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
