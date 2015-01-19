#include<iostream>
#include<string>
#include<ctype.h>
using namespace std;
int samo (string s)
{ 
	int wynik=0;
	for (int i=0; i<s.size(); i++){
		s[i]=tolower(s[i]);
	if (s[i]=='a' or s[i]=='y' or s[i]=='u' or s[i]=='i' or s[i]=='e' or s[i]=='o') wynik++;
	}
	return wynik;
}
int suma (string s){
	int wynik=0;
	for (int i=0; i<s.size(); i++){
		//s[i]=tolower(s[i]);
		wynik=wynik+s[i];
		
	}
return wynik;	
}
bool check (string s, string m, string mieszany, int i){
	if (i>m.size()) return false;
	if (suma(s)==suma(mieszany) && samo(s)==samo(mieszany)) return true;
	return (check (s,m, mieszany+m[i], i+1) || check (s,m, mieszany, i+1));
	
	
}

int main (){
	int wynik=0; int w=0;
string s,m;
cin>>s; 
cin>>m;
string r;
if (check(s,m, r, 0)) {cout<<"TAK";}
else {cout<<"NIE";}
}
