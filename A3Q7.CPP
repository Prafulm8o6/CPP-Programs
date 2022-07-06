// Implement template class “Binary Tree” with all operations.

#include <iostream>
using namespace std;

template <class T>
class A3Q7
{

public:
    struct Node
    {
        T data;
        Node *left, *right;
    };

    A3Q7()
    {
        root = nullptr;
    }

    Node *root;

    void insert(Node *&ptr, Node *&newnode)
    {
        if (ptr == nullptr)
        {
            ptr = newnode;
        }
        else if (newnode->data < ptr->data)
        {
            insert(ptr->left, newnode);
        }
    }

    void insertNode(T val)
    {
        Node *newnode = nullptr;
        newnode = new Node;
        newnode->data = val;
        newnode->left = newnode->right = nullptr;
        insert(root, newnode);
    }

    void destroySubTree(Node *ptr)
    {
        if (ptr->left)
        {
            destroySubTree(ptr->left);
        }
        if (ptr->right)
        {
            destroySubTree(ptr->right);
        }
        delete ptr;
    }

    bool searchNode(T val)
    {
        bool status = false;
        Node *ptr = root;
        while (ptr)
        {
            if (ptr->data == val)
            {
                status = true;
            }
            else if (val < ptr->data)
            {
                ptr = ptr->left;
            }
            else
            {
                ptr = ptr->right;
            }
        }
        return status;
    }

    void deleteNode(T val, Node *&ptr)
    {
        if (val < ptr->data)
        {
            deleteNode(val, ptr->left);
        }
        else if (val > ptr->data)
        {
            deleteNode(val, ptr->right);
        }
        else
        {
            makeDeletion(ptr);
        }
    }

    void remove(T val)
    {
        deleteNode(val, root);
    }

    void makeDeletion(Node *&ptr)
    {
        Node *temp = nullptr;

        if (ptr == nullptr)
        {
            cout << "Cannot delete empty  node.\n";
        }
        else if (ptr->right == nullptr)
        {
            temp = ptr;
            ptr = ptr->left;
            delete temp;
        }
        else if (ptr->left == nullptr)
        {
            temp = ptr;
            ptr = ptr->right;
            delete ptr;
        }
        else
        {
            temp = ptr->right;
            while (temp->left)
            {
                temp = temp->left;
            }
            temp->left = ptr->left;
            temp = ptr;
            ptr = ptr->right;
            delete temp;
        }

        cout << endl;
        cout << endl
             << "Now deleting " << ptr->data << " from the tree." << endl;
    }

    void displayInOrder()
    {
        displayInOrder(root);
    }

    void displayPreOrder()
    {
        displayPreOrder(root);
    }

    void displayPostOrder()
    {
        displayPostOrder(root);
    }

    void displayInOrder(Node *ptr)
    {
        if (ptr != nullptr)
        {
            displayInOrder(ptr->left);
            cout << ptr->data << " ";
            displayInOrder(ptr->right);
        }
    }

    void displayPreOrder(Node *ptr)
    {
        if (ptr != nullptr)
        {
            cout << ptr->data << " ";
            displayPreOrder(ptr->left);
            displayPreOrder(ptr->right);
        }
    }

    void displayPostOrder(Node *ptr)
    {
        if (ptr != nullptr)
        {
            displayPostOrder(ptr->left);
            displayPostOrder(ptr->right);
            cout << ptr->data << " ";
        }
    }

    int numNodes()
    {
        return countNodes(root);
    }

    int countNodes(Node *&ptr)
    {
        int count;
        if (ptr == nullptr)
        {
            count = 0;
        }
        else
        {
            count = 1 + countNodes(ptr->left) + countNodes(ptr->right);
        }
        return count;
    }

    ~A3Q7()
    {
        destroySubTree(root);
    }
};

int main()
{
    A3Q7<int> obj1;
    obj1.insertNode(1);
    obj1.insertNode(2);
    obj1.insertNode(30);
    obj1.insertNode(20);
    obj1.insertNode(100);
    obj1.insertNode(3);
    obj1.insertNode(4);
    obj1.insertNode(10);

    cout << "No. Of Nodes : " << obj1.numNodes() << endl;
    obj1.remove(1);
    obj1.remove(4);
    obj1.displayInOrder();
    obj1.displayPreOrder();
    obj1.displayPostOrder();
    obj1.searchNode(10);
    return 0;
}