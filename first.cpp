#include<bits/stdc++.h>
using namespace std;
vector<string> v[111];
vector<char> first[111], follow;
int i,j;
isUpper(char c){
    if(c>='A' && c<='Z') return 1;
    else return 0;
}
vector<char> first2(char c){
    string str;
    vector<char>st,tmp;
    if(!isUpper(c)) st.push_back(c);
    else{
    for(i=0;i<v[c].size();i++){
           str=v[c][i];
           //cout<<str<<endl;
           if(isUpper(str[0])){
            tmp=first2(str[0]);
            for(j=0;j<tmp.size();j++){
                if(tmp[j]!='e')
                st.push_back(tmp[j]);
                else tmp=first2(str[1]);
            }
           }
           else{
            st.push_back(str[0]);
           }
    }}
    return st;
}
int main(){

    int n=8,i,j,k;
    freopen("13.txt","r",stdin);
    string s,s2;
    char c1,c2;
    for(i=0;i<n;i++){
        cin>>c1>>s;
        v[c1].push_back(s);
    }
    cout<<endl<<endl;
    for(i='A';i<'Z';i++)
    {
        if(v[i].size())
          {
              vector<char>st=first2(i);
              cout<<(char)i<<" ";
              for(j=0;j<st.size();j++){
                first[i].push_back(st[j]);
                cout<<st[j]<<"";
              }
              cout<<endl<<endl;
          }
    }

}


/*

E TA
A +TA
A e
T FR
R *FR
R e
F (E)
F c

A b
A Ba
B *c
D *c
B e
D B+
*/

