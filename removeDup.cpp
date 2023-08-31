#include <iostream>
#include <stack>
using namespace std;

string remDup(string s)
{
    string ans = "";
    stack<char> st;

    for(int i = 0; i < s.length(); i++)
    {
        if(st.empty())
            st.push(s[i]);
        
        else if(st.top() == s[i])
            continue;
        else
            st.push(s[i]);
        
    }
    while(!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string s;
    getline(cin, s);

    cout<<remDup(s);

    return 0;
}