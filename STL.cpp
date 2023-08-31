#include <iostream>
#include <stack>
using namespace std;

void showStack(stack<int> st)
{
    while(!st.empty())
    {
        cout<<"\t"<<st.top();
        st.pop();
    }
    cout<<endl;
}

int main()
{
    stack<int> st;

    st.push(10); 
    st.push(30); 
    st.push(20); 
    st.push(5); 
    st.push(1);

    cout << "The stack is : "; 
    showStack(st); 
  
    cout << "\ns.size() : " << st.size(); 
    cout << "\ns.top()  : " << st.top(); 
  
  
    cout << "\ns.pop()  : "; 
    st.pop(); 
    showStack(st); 
  
    return 0;
}