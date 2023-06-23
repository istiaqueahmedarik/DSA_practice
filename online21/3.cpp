#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    char val;
    Node *prev;
    Node *next;
    Node(char d)
    {
        val = d;
        prev = NULL;
        next = NULL;
    }
};
class Dequeue
{
    Node *head, *tail;

public:
    Dequeue()
    {
        head = tail = NULL;
    }
    void push_back(char val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    void push_front(char val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
    void pop_back()
    {
        Node *temp = tail;
        if (temp)
        {
            tail = tail->prev;
            tail->next = NULL;
            delete temp;
        }
    }
    void pop_front()
    {
        Node *temp = head;
        if (temp)
        {
            head = head->next;
            head->prev = NULL;
            delete temp;
        }
    }
    void print()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void complementarySequence()
    {
        Node *temp = tail;
        while (temp)
        {
            cout << temp->val << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main()
{
    Dequeue dq;
    while (1)
    {
        cout << "---" << endl;
        cout << "1. push_back" << endl
             << "2. push_front" << endl
             << "3. pop_back" << endl
             << "4. pop_front" << endl
             << "5. print" << endl
             << "6. complementarySequence" << endl
             << "7. exit" << endl;
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            char val;
            cin >> val;
            dq.push_back(val);
        }
        else if (choice == 2)
        {
            char val;
            cin >> val;
            dq.push_front(val);
        }
        else if (choice == 3)
        {
            dq.pop_back();
        }
        else if (choice == 4)
        {
            dq.pop_front();
        }
        else if (choice == 5)
        {
            dq.print();
        }
        else if (choice == 6)
        {
            dq.complementarySequence();
        }
        else if (choice == 7)
        {
            break;
        }
    }
}