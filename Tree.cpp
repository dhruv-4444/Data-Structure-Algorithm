#include <iostream>
#include <queue>
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

// node* buildtree() {
//     int data;
//     cout << "Enter data for node: ";
//     cin >> data;

//     if (data == -1) {
//         return NULL;
//     }

//     node* root = new node(data);
//     cout << "Enter data for left node of " << data << ": " << endl;
//     root->left = buildtree();
//     cout << "Enter data for right node of " << data << ": " << endl;
//     root->right = buildtree();
//     return root;
// }
node *buildtreelot(node *root)
{
    queue<node *> q;
    cout << "enter data for root node" << endl;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        cout << "enter data for left node" << endl;
        int left;
        cin >> left;
        if (left != -1)
        {
            temp->left = new node(left);
            q.push(temp -> left);
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

void printlot(node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        while (size > 0)
        {
            node *temp = q.front();
            q.pop();
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
            size--;
        }
        cout << endl;
    }
}
int main()
{
    node *root = NULL;
    root = buildtreelot(root);
    cout << "Level Order Traversal of the Binary Tree is: " << endl;
    printlot(root);
    return 0;
}
