// Implement template class “Stack” with all operations.

#include <iostream>
#include <string.h>

using namespace std;

#define ARRSIZE 5

template <class T>
class A3Q6
{
    int top;
    T arr[ARRSIZE];

public:
    A3Q6()
    {
        top = -1;
    };

    bool isFull()
    {
        if (top == (ARRSIZE - 1))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    };

    bool isEmpty()
    {
        if (top == -1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    };

    void push(T data)
    {
        if (isFull())
        {
            cout << "Stack Is Full." << endl;
        }

        cout << "Element : " << data << endl;

        top = top + 1;

        arr[ARRSIZE] = data;
    };

    T pop()
    {
        T popEle = arr[top];
        top--;
        return popEle;
    };

    T topElement()
    {
        T topEle = arr[top];
        return topEle;
    };
};

int main()
{
    A3Q6<int> obj1;
    A3Q6<string> obj2;

    obj1.push(10);
    obj1.push(12);
    obj1.push(25);
    obj1.pop();

    obj2.push("Praful");
    obj2.push("Suresh");
    obj2.push("Yash");
    obj2.pop();

    cout << "Top Element : " << obj1.topElement() << endl;
    cout << "Top Element : " << obj2.topElement() << endl;

    return 0;
}