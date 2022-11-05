#include<bits/stdc++.h>
using namespace std;
int mark[400]={0};
void countNum(string s)
{
    int i,j=0,lt=0,c=0,ot=0,d=0,w=1,a=0,o=0;
    int ln=s.size();
    char letter[1000],digit[1000],other[1000];
    for(i=0;i<ln;i++)
    {
        char x=s[i];
        int t=(int)s[i];
        if(s[i]==' ' &&(isalpha(s[i+1]) || (isdigit(s[i+1]))))
        {
            w++;
        }
        if(isdigit(s[i]) && !mark[t]){
            d++;
            digit[j++]=x;
            digit[j++]=' ';
            mark[t]=1;
        }
         if(isalpha(s[i]) &&!mark[t]){
            a++;
            letter[lt++]=x;
            letter[lt++]=' ';
            mark[t]=1;
            mark[t+32]=1;

        }

        if((!isdigit(s[i]))&& !isalpha(s[i]) && ! mark[t]){
            if(s[i]!=' '){
                o++;
                other[ot++]=x;
                other[ot++]=' ';
                mark[t]=1;
            }
        }
    }
    digit[j++]='\0';
    letter[lt++]='\0';
    other[ot++]='\0';
    cout<<w<<" "<<d<<" "<<a<<" "<<o<<endl;
    cout<<digit<<endl;
    cout<<letter<<endl;
    cout<<other<<endl;

}
int main()
{
    freopen("in.txt", "r", stdin);
    string s;
    getline(cin,s);

    countNum(s);
}
//Md. Tareq Zaman, Part-3, 2011
//5 5 16 8
