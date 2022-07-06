// Overload the + operator for linked list and insert the node at the appropriate position (in sorted order of any field).

#include <iostream>
#include <conio.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

class LinkedList
{
    Node *head, *tail;

public:
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    int &operator+(int val)
    {
        Node *newnode;
        newnode = new Node;

        newnode->data = val;
        newnode->next = head;

        head = newnode;
        sort();
    }

    void sort()
    {
        Node *current = head;
        Node *index = nullptr;

        if (current == nullptr)
        {
            cout << "List Is Empty.";
        }
        else
        {
            while (current != nullptr)
            {
                index = current->next;
                while (index != nullptr)
                {
                    if (current->data > index->data)
                    {
                        int temp = current->data;
                        current->data = index->data;
                        index->data = temp;
                    }
                    index = index->next;
                }
                current = current->next;
            }
        }
    }

    void display()
    {
        Node *current = head;

        if (current == nullptr)
        {
            cout << "List Is Empty.";
        }
        else
        {
            cout << "List : ";
            while (current != nullptr)
            {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    system("cls");
    LinkedList obj;
    obj + 100;
    obj + 22;
    obj + 42;
    obj + 93;
    obj + 5;
    obj + 12;
    obj + 33;
    obj + 112;
    obj + 91;
    obj + 1;
    obj.display();

    getch();
    return 0;
}
