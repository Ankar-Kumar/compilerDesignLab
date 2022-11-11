#include<bits/stdc++.h>
using namespace std;

string keywords[32]={"auto","double","int","struct","break","else","long",
       "switch","case","enum","register","typedef","char",
       "extern","return","union","const","float","short",
       "unsigned","continue","for","signed","void","default",
       "goto","sizeof","voltile","do","if","static","while"};


bool isKeyword(string s){
    for(int i=0;i<32;i++){
        if(keywords[i]==s)
            return 1;
    }
    return 0;
}
bool isArithmatic(string s){
    if(s=="+" || s=="-" || s=="*" || s=="/" || s=="^" || s=="=" || s=="%")
        return 1;
    else return 0;

}
bool isLogical(string st)
{
     if(st=="<"||st==">"||st=="!="||st=="=="||st=="<="||st==">=")
        return 1;
     return 0;
}
bool isConstant(string s){

}

int isNumber(string str){
    int cn = 0;
    for(int i =0; i<str.size();i++){
        if(str[i]=='.'){
            cn++;
        }
        else if(!isdigit(str[i])){
            return 0;
        }
    }
    if(cn==1) return 2;
    if(cn==0) return 1;
  
}


void checker(string s)
{
    if(isKeyword(s))
        cout<<"Keyword";
    else if(s[0]=='_' || isalpha(s[0]))
    {
        cout<<"Identifier";
    }
    else if(isArithmatic(s)){
        cout<<"Arithmatic Operator";
    }
    else if(isLogical(s)){
        cout<<"Logical OP";
    }
//    else if(isConstant(s)){
//        cout<<"constant";
//    }
    else{
        if(isNumber(s)==2)
            cout<<"Float";
        else if(isNumber(s)==1)
            cout<<"Integer";
        else
            cout<<"undefined";
    }


}

int main()
{
   string s;
   while(1){
    cin>>s;
    checker(s);
    cout<<endl;
   }
}
