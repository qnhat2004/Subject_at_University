#include <bits/stdc++.h>
using namespace std;

class calculate
{
    string s;
    stack<string> st;
    stringstream ss;
    public:
        void input()
        {
            getline(cin, s);
        }
        int getPriority(char c)
        {
            if (c == '+' || c == '-') return 1;
            if (c == '*' || c == '/') return 2;
            if (c == 'a') return 3;
            return 0;
        }
        void convert() // infix to postfix
        {
            for (int i = 0; i < s.size(); ++i)
            {
                if (s[i] == ' ') continue;
                if (isdigit(s[i]))
                {
                    while (i < s.size() && isdigit(s[i]))
                    {
                        ss << s[i++];
                    }
                    ss << ' ';
                    --i;
                }
                else if (s[i] == '(') st.push(string(1, s[i]));
                else if (s[i] == ')')
                {
                    while (st.size() && st.top() != "(")
                    {
                        ss << st.top() << ' ';
                        st.pop();
                    }
                    st.pop();
                    if (st.size() && st.top() == "a")
                    {
                        ss << st.top() << ' ';
                        st.pop();
                    }
                }
                else
                {
                    while (st.size() && getPriority(st.top()[0]) >= getPriority(s[i]))
                    {
                        ss << st.top() << ' ';
                        st.pop();
                    }
                    st.push(string(1, s[i]));
                }
            }
            while (st.size())
            {
                ss << st.top() << ' ';
                st.pop();
            }
        }
        void cal() // Tính toán
        {
            string s;
            while (ss >> s)
            {
                if (isdigit(s[0]))
                {
                    st.push(s);
                }
                else
                {
                    int b = stoi(st.top());
                    st.pop();
                    int a = (s == "a" ? 0 : stoi(st.top()));
                    if (s != "a") st.pop();
                    if (s == "+") st.push(to_string(a + b));
                    else if (s == "-") st.push(to_string(a - b));
                    else if (s == "*") st.push(to_string(a * b));
                    else if (s == "/") st.push(to_string(a / b));
                    else if (s == "a") st.push(to_string(abs(b)));
                }
            }
            cout << st.top() << '\n';
        }
};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    calculate c;
    c.input();
    c.convert();
    c.cal();

    return 0;
}
