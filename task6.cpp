
#include<bits/stdc++.h>
using namespace std;
bool isother(string str)
{
    for(int i=0;i<str.size();i++)
    {
        if( str[2] =='_' || (str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z') || (str[i]>='0' && str[i]<='9')){
            continue;
        }
        else return 1;
    }
    return 0;
}
bool isval(char str)
{

        if((str>='a' && str<='z') || (str>='A' && str<='Z') || (str>='0' && str<='9'))
            return 1;
        else return 0;
}

bool binary(string str)
{
    int i;
    if(str[0]=='0' && (str[1]=='1' || str[1]=='0'))
    {
        for(i=2; i<str.size(); i++)
        {
            if(str[i]=='1' || str[i]=='0')
            {
                continue;
            }
            else
                return 0;
        }
        return 1;
    }
    else
        return 0;

}

int main()
{
    string str;

    cin>>str;
    int ln=str.size();
    if(isother(str))
    {
        cout<<"Undefined 1";
    }
    else if(str[0]=='c' && str[1]=='h' && str[2]=='_' && (isval(str[3])))
        cout<<"Character variable";
    else if(str[0]=='b' && str[1]=='n' && str[2]=='_' && (isval(str[3])))
    {
        cout<<"Binary Variable";
    }
    else if(binary(str))
    {
        cout<<"Binary Number";
    }
    else
    {
        cout<<"Undefined";
    }

}
