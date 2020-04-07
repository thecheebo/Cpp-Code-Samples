#include <iostream>
using namespace std;

struct node
{
    int value;
    node *prev;
    node *next;
    
};

node *head;
node *tail;

void insert(int data)
{
    node *temporary_head = head;
    if (head != NULL)
    {
        while (temporary_head->next != NULL)
        {
            temporary_head = temporary_head->next;
        }
        node *new_node = new node;
        temporary_head->next = new_node;
        new_node->prev = temporary_head;
        new_node->value = data;
        new_node->next = NULL;
    }
    else
    {
        node *new_node = new node;
        new_node->value = data;
        new_node->prev = NULL;
        new_node->next = NULL;
        head = new_node;
    }
}

void remove(int x)
{
    node *t = head;
    while (t->value != x)
    {
        t = t->next;
    }
    t->prev->next = t->next;
    t->next->prev = t->prev;
    delete t;
}

void search(int x)
{
    node *t = head;
    int found = 0;
    while (t != NULL)
    {
        if (t->value == x)
        {
            cout << "\nFound\n";
            found = 1;
            break;
        }
        t = t->next;
    }
    if (found == 0)
    {
        cout << "\nNot Found\n";
    }
}

void show()
{
    node *t = head;
    while (t != NULL)
    {
        cout << t->value << "\t";
        t = t->next;
    }
    cout << endl;
}

void reverseShow()
{
    node *t = head;
    while (t->next != NULL)
    {
        t = t->next;
    }
    while (t != NULL)
    {
        cout << t->value << "\t";
        t = t->prev;
    }
    cout << endl;
}

int main()
{
insert(1);insert(2);insert(3);insert(4);insert(5);insert(6);
remove(5);
search(5);search(4);
show();
reverseShow();

    return 0;
}
