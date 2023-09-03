#include <iostream>
#include <stack>
using namespace std;

int getLargestHist(int arr[], int n)
{
    stack<int> s;

    int res = 0;
    for(int i = 0; i < n; i++)
    {
        while(s.empty() == false && arr[i] <= arr[s.top()])
        {
            int tp = s.top();
            s.pop();
            int curr = arr[tp] * (s.empty() ? i : (i-s.top()-1));
            res = max(res, curr);
        }
        s.push(i);
    }

    while(!s.empty())
    {
        int tp = s.top();
        s.pop();
        int curr = arr[tp] * (s.empty() ? n : (n-s.top()-1));
        res = max(res, curr);
    }

    return res;
}

int getLargestRectangle(int arr[R][C])
{
    int res = getLargestHist(arr[0], C);

    for(int i = 1; i < R; i++)  //finding largest area row-wise
    {
        for(int j = 0; j < C; j++)  //building base for histogram and wanting to find the largest area 
        {
            if(arr[i][j] == 1)
                arr[i][j] += arr[i-1][j];   //updating the value of the arr as the new histogram row!
        }
        res = max(res, getLargestHist(arr[i], C));
    }
    return res;
}