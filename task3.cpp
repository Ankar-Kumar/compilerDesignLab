#include<bits/stdc++.h>
using namespace std;
string str;
int main()
{
    freopen("task3.txt","r",stdin);
    cin>>str;
    string dept[]={"Computer Science & Engineering, ","Electrical & Electronic Engineering, ","Material Science, "};
    string s[5];
    s[1]="computer fundamental";
    s[2]="c";
    s[3]="Computer Architecture";
    s[4]="Compiler Design";
    string year[5];
    year[1]="1st year,";
    year[2]="2nd year,";
    year[3]="3rd year,";
    year[4]="4th year,";
    string semis[3];
    semis[1]="1st ";
    semis[2]="2nd ";
    string s1;
    for(int k=0;k<str.size();k++){
        if(str[k]!='-')
            s1+=str[k];
        else break;
    }
    if(s1=="CSE") cout<<dept[0];
    if(s1=="EEE") cout<<dept[1];
    if(s1=="MS") cout<<dept[2];

    for(int i=1;i<=4;i++)
    if(str[4]==i+'0') cout<<year[i];
    for(int i=1;i<=2;i++)
    if(str[5]==i+'0') cout<<semis[i]<<"semister,";
    for(int i=1;i<=4;i++)
    if(str[6]==i+'0') cout<<s[i];

    if(str[7]=='1') cout<<", Theory";
    if(str[7]=='2') cout<<", Lab";

}
