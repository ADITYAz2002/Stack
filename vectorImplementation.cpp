/*
    Vector implementation is more simpler and dynamic in nature 
    and the amortized time complexity is O(1)!
*/
#include <iostream>
using namespace std;
#include<vector>

struct MyStack
{
    vector<int> v;

    void push(int x)
    {
        v.push_back(x);
    }

    int pop()
    {
        int val = v.back();
        v.pop_back();
        return val;
    }

    int size()
    {
        return v.size();
    }

    bool isEmpty()
    {
        return v.empty();
    }

    int peek()
    {
        return v.back();
    }
};
