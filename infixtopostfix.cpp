
#include <bits/stdc++.h>
using namespace std;

int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

int main()
{
    string str;
    // str = "k+l-m*n+(o^p)*w/u/v*t+q"; // 1*2/3+(4-5^6)+7-8";
    str = "A+(B*C-(D/E^F)*G)*H"; //"(A-B)*(D/E)";//"A*(B+C*D)+E";

    stack<char> st;
    string result;
    for (int i = 0; i < str.length(); i++)
    {
        char c = str[i];

        if (isalpha(c) || isdigit(c))
            result += c;
        else if (c == '(')
            st.push(c);

        else if (c == ')')
        {
            while (st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && prec(c) <= prec(st.top()))
            {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }

    cout << result << endl;
    return 0;
}
