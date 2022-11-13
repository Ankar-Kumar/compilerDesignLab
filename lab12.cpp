#include<bits/stdc++.h>
using namespace std;
int isArithmatic(char c)
{
    if(c=='+' || c=='-' || c=='/' || c=='*')
        return 1;
    else return 0;
}

int isCheck(string s)
{
    stack<char>st;
    int ln=s.size();
    if(isArithmatic(s[ln-1])) return 0;//last char operator
    for(int i=0; i<ln-1; i++)
    {
        if(isArithmatic(s[i]) && ( s[i+1] == ')' || isArithmatic(s[i+1]))) return 0;// ++ ,+)
        else if(isdigit(s[i]) && (s[i+1]=='(')) return 0;  //5(
        else if(s[i]=='(' && (s[i+1]==')' || isArithmatic(s[i+1]))) return 0;// (* , ()
        else if(s[i]==')' && (s[i+1]=='('|| isalpha(s[i+1]) || isdigit(s[i+1]))) return 0;// )( , )8
        else if(s[i]=='(') st.push('('); // st=(
        else if(s[i]==')'){
            if(st.empty()) return 0; //
            st.pop();//
        }
    }
    if(s[ln-1]=='(') st.push('(');
    else if(s[ln-1]==')'){
            if(st.empty()) return 0;
            st.pop();
        }
    if(st.empty()) return 1;
    else return 0;
}



int main()
{
    string s;
    while(1){
    cin>>s;
    int j,k,c=0;
    if(isCheck(s))
    {
        cout<<"Valid";
    }
    else cout<<"Invalid";
    cout<<endl;
    }

}

//(5*2+70)+2*(4*5)

