#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildlot(node *root)
{
    queue<node *> q;
    int data;
    cout << "enter data for node" << endl;
    cin >> data;
    if (data == -1)
        return NULL;
    root = new node(data);
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        cout << "enter data for left" << endl;
        int left;
        cin >> left;
        if (left != -1)
        {
            temp->left = new node(left);
            q.push(temp->left);
        }
        cout << "enter data for right node" << endl;
        int right;
        cin >> right;
        if (right != -1)
        {
            temp->right = new node(right);
            q.push(temp->right);
        }
    }
    return root;
}

void topview(node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return;
    }
    map<int, int> mpp;
    queue<pair<node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        node *no = it.first;
        int line = it.second;

        if (mpp.find(line) == mpp.end())
            mpp[line] = no->data;

        if (no->left != NULL)
        {
            q.push({no->left, line - 1});
        }
        if (no->right != NULL)
        {
            q.push({no->right, line + 1});
        }
    }
    for (auto it : mpp)
    {
        cout << it.second << " ";
    }
}

int main()
{
    node *root = NULL;
    root = buildlot(root);
    topview(root);

    return 0;
}
