#include <iostream>
#include <queue>
#include <map>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *buildlot(Node *root)
{
    queue<Node *> q;
    int data;
    cout << "enter data for node" << endl;
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    root = new Node(data);
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        cout << "enter data for left node" << endl;
        int left;
        cin >> left;
        if (left != -1)
        {
            temp->left = new Node(left);
            q.push(temp->left);
        }
        cout << "enter data for right node" << endl;
        int right;
        cin >> right;
        if (right != -1)
        {
            temp->right = new Node(right);
            q.push(temp->right);
        }
    }
    return root;
}

void bottomview(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return;
    }
    map<int, int> mpp;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        Node *no = it.first;
        int line = it.second;
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
    Node *root = NULL;
    root = buildlot(root);
    bottomview(root);

    return 0;
}
