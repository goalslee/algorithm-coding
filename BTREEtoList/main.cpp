/*��������
����һ�ö���������������Ҫ���ö���������ת����һ�������˫������������ת���Ĺ����У����ܴ����κ��µĽ�㣬ֻ�ܵ������еĽ��ָ���ָ����ʵ�֡�
*/

#include <iostream>
#include<vector>
using namespace std;

typedef struct Btree{
    int data;
    Btree* left;
    Btree* right;
}BTree;
BTree* insert_node(BTree* root,int data){
    if(nullptr==root){
        root=new BTree;
        root->data=data;
        root->left=nullptr;
        root->right=nullptr;
    }
    else{
        if(data>root->data) root->right=insert_node(root->right,data);
        else root->left=insert_node(root->left,data);
    }
    return root;
}

void convert(BTree* root,BTree** last)//must BTree**,��ΪҪ��������ѽ��������һ���ڵ�ĵ�ַ������Ҫ��ָ�������ַ��ָ�롣����������ʱlastû�иı�
{
    if(nullptr==root) return ;
    convert(root->left,last);
    root->left=*last;
    if(nullptr!=*last) (*last)->right=root;
    *last=root;
    convert(root->right,last);

}

BTree* find_left(BTree *root)
{
    if(nullptr==root) return NULL;
    while(nullptr!=root->left) root=root->left;
    return root;
}

void print(BTree* root)
{
    if(nullptr==root) return;
    print(root->left);
    cout<<root->data<<"-->";
    print(root->right);
}

int main()
{
    BTree *root=nullptr,*last=nullptr;
    vector<int> input{1,2,3,4,5,99,44,35,64,42};
    for(auto itor=input.begin();itor!=input.end();itor++){
        root=insert_node(root,*itor);//import
    }
    BTree *head=find_left(root);

    print(root);
    cout<<endl;
    convert(root,&last);
    while(nullptr!=head){
    cout << head->data << "-->";
    head=head->right;
    }
    return 0;
}
