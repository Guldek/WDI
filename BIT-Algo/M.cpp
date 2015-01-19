#include <iostream>
#include <algorithm>
using namespace std;

int main (){
	int n;
	int k;
	bool t=true;
	
	cin>>n;
	cin>>k;
	
	int *tab=new int [n];
	
	for (int i=0; i<n; i++){
		cin>>tab[i];
	} 
	
	sort(tab, tab + n);
	for (int i=0; i<n; i++){
	if (k-tab[i]>0)
	{if (binary_search(tab+i+1, tab+n, k-tab[i])){
		t=false;
		break;
	}}}
	if (t) {cout<<"NIE";}
	else {cout<<"TAK";}
}

