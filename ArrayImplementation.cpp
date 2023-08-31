#include <iostream>
using namespace std;

struct MyStack
{
    int *arr, cap, top;

    MyStack(int c)
    {
        cap = c;
        arr = new int[cap];
        top = -1;
    }

    int pop()
    {
        if(top == -1)
        {
            cout<<"Stack Underflow"<<endl;
        }

        int value = arr[top];
        top--;

        return value;
    }

    void push(int x)
    {
        if(top == cap - 1)
        {
            cout<<"Stack Overflow"<<endl;
        }

        top++;
        arr[top] = x;
    }

    int peek()
    {
        if(top == -1)
            cout<<"Empty Stack"<<endl;

        return arr[top];
    }

    int size()
    {
        return top + 1;
    }

    bool isEmpty()
    {
        return top == -1;
    }
};

int main()
{
    MyStack s(5);

    cout<< s.pop()<<endl;
    cout<< s.peek()<<endl;

    s.push(5);
    s.push(10);
    s.push(20);
    cout<<s.pop()<<endl;
    cout<<s.size()<<endl;
    cout<<s.peek()<<endl;
    cout<<s.isEmpty()<<endl;
    return 0;
}