#include <bits/stdc++.h>
using namespace std;
vector<string> inp[100];
vector<char> first[111];
int i, j, k;
string str, s;
char ch1;
int capital(char c)
{
    if (c >= 'A' && c <= 'Z')
        return 1;
    else
        return 0;
}
vector<char> find_first(char s1)
{
    vector<char> tmp, st;
    for (i = 0; i < inp[s1].size(); i++)
    {
        string last = inp[s1][i];
        if (capital(last[0]))
        {
            tmp = find_first(last[0]);
            for (j = 0; j < tmp.size(); j++)
            {
                st.push_back(tmp[j]);
            }
        }
        else
        {
            st.push_back(last[0]);
        }
    }
    return st;
}
int main()
{
    freopen("13.txt", "r", stdin);
    for (i = 0; i < 8; i++)
    {
        cin >> ch1 >> str;
        inp[ch1].push_back(str);
    }
    for (i = 'A'; i <= 'Z'; i++)
    {
        if (inp[i].size())
        {
            vector<char> temp = find_first(i);
            for (j = 0; j < temp.size(); j++)
            {
                cout << temp[j] << " ";
            }
        }
    }
}