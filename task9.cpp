
#include<bits/stdc++.h>
using namespace std;
string pn[10] = {"Sagor","Selim","Salma","Nipu","he","she","I","We","you","they"};
string verb[5] = {"read","eat","take","write","run"};
string n[7] = {"book","eat","dog","home","grass","rice","mango"};
int main(){
	bool yes = 0;
	int i,j=0;
	vector<string>words;
	freopen("in9.txt", "r", stdin);
	string input,temp;
	getline(cin,input);

	for(i=0;i<input.size();i++){
		if(input[i]==' '){
			words.push_back(temp);
			temp = "";
		}
		else
			temp+=input[i];
	}
	words.push_back(temp);

	if(words.size()>1 && words.size()<4)
		yes = 1;
	bool tempyes = 0;
	for(i=0;i<10;i++){
		if(words[0]==pn[i])
			tempyes = 1;
	}
	if(tempyes == 0)
		yes = 0;

	tempyes = 0;
	for(i=0;i<5;i++){
		if(words[1]==verb[i])
			tempyes = 1;
	}
	if(tempyes==0)
		yes = 0;

	if(words.size()==3){
		tempyes = 0;
		for(i=0;i<7;i++){
			if(words[2]==n[i])
				tempyes = 1;
		}
	}
	if(!tempyes)
		yes = 0;
	if(yes == 1)
		cout <<"Syntectically valid"<<endl;
	else
		cout <<"Invalid"<<endl;
}
