#include <bits/stdc++.h>
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    string s = "((A+B)*C-(D-E)^(F+G))";

    unordered_map<char, int> mp;
    mp['+'] = mp['-'] = 1;
    mp['*'] = mp['/'] = 2;
    mp['^'] = 3;

    stack<char> st;
    string postfix = "";

    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') {
            st.push(s[i]);
            continue;
        }

        if(s[i] >= 'A' && s[i] <= 'Z') {
            postfix += s[i];
            continue;
        }

        if(s[i] == ')') {
            while(st.size() != 0 && st.top() != '(') {
                char top = st.top();
                postfix += top;
                st.pop();
            }
            if(st.size() != 0 && st.top() == '(') st.pop();
            continue;
        }

        if(mp[s[i]] > mp[st.top()]) st.push(s[i]);
        else if (mp[s[i]] < mp[st.top()]) {
            while(mp[s[i]] < mp[st.top()]) {
                postfix += st.top();
                st.pop();
                if(st.top() == '(') {
                    st.pop();
                    break;
                }
            }
            st.push(s[i]);
        }
        else {
            postfix += st.top();
            st.pop();
            st.push(s[i]);
        }

    }

    cout << postfix << endl;

    return 0;
}
