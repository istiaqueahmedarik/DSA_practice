#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
class BST
{
public:
    Node *root;
    BST()
    {
        root = NULL;
    }
    Node *insert(Node *curr, int val)
    {
        if (curr == NULL)
            return curr = new Node(val);
        if (curr->data > val)
            curr->left = insert(curr->left, val);
        else
            curr->right = insert(curr->right, val);
        return curr;
    }
    Node *search(Node *curr, int val)
    {
        if (curr == NULL || curr->data == val)
            return curr;
        if (curr->data > val)
            return search(curr->left, val);
        else
            return search(curr->right, val);
    }
    void Pairs(Node *curr, int x)
    {
        if (curr == NULL)
            return;
        Pairs(curr->left, x);
        if (curr->data < x - curr->data && search(root, x - curr->data) != NULL)
        {
            cout << curr->data << " " << x - curr->data << endl;
        }
        Pairs(curr->right, x);
    }
    void Pairs(int x) { Pairs(root, x); }
    void insert(int val) { root = insert(root, val); }
    void print(Node *curr)
    {
        if (curr)
        {
            print(curr->left);

            print(curr->right);
        }
    }
    void print() { print(root); }
};
int main()
{
    BST b;
    while (1)
    {
        cout << "1. Insert     2. Print pairs" << endl
             << "Insert your choice: ";
        int choice, x;
        cin >> choice;
        if (choice == 1)
        {
            cout << "Insert value: ";
            cin >> x;
            b.insert(x);
            cout << x << " is inserted in the BST" << endl;
        }
        else if (choice == 2)
        {
            cout << "Insert value: ";
            cin >> x;
            /// Call your required function/s from here
            b.Pairs(x);
        }
        cout << endl
             << endl;
    }
}