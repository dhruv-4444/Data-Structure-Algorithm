#include<bits/stdc++.h>
using namespace std;
 
 class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d)
    {
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
 };

node *buildlot(node* root)
{
    queue<node * > q;
    int data;
    cout<<"enter data for node"<<endl;
    cin>>data;
    if(data==-1)
    {
        return NULL;
    }
    root=new node(data);
    q.push(root);
    while(!q.empty())
    {
        node* temp=q.front();
        q.pop();
        cout<<"enter data for left node"<< endl;
        int left;
        cin>>left;
        if(left!=-1)
        {
            temp->left=new node(left);
            q.push(temp->left);
        }
        cout<<"enter data for right node"<<endl;
        int right;
        cin>>right;
        if(right!=-1)
        {
            temp->right=new node(right);
            q.push(temp->right);
        }
    }
    return root;

}

void rightview(node* root,int level, vector<int> &ans)
{
    if(root==NULL)
    {
        return;
    }
    if(level==ans.size())
    {
        ans.push_back(root->data);
    }
    rightview(root->right,level+1,ans);
    rightview(root->left,level+1,ans);
}

int main()
{
    node * root=NULL;
    root=buildlot(root);
    vector<int> ans;
    rightview(root,0,ans);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }

    return 0;
}