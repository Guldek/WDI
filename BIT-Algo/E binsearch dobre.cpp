#include<iostream>
using namespace std;

bool binserach (int size, int tab[], int value, int &position){
	int low=0;
	int high=size-1;
	int middle=0;
	position=-1;
	
	while (low<=high){
		
		middle=low+(high-low)/2;
		if (tab[middle]==value){
			position=middle;
				high=middle-1;
		}
		else {
			if (tab[middle]>value){
				high=middle-1;
			}
			else {
				low=middle+1;
			}
		}
	}
	if (position!=-1) return true;
	return false;
}

int main (){
	int n; int z;
	int k; int position;
	cin>>n; 
	cin>>k;
	
	int *tab= new int [n];
	int *answers= new int [k];	
	
	for (int i=0; i<n; i++){
		cin>>tab[i];		
	}
	
	for (int i=0; i<k; i++){
		cin>>z;
		if (binserach (n, tab, z, position)){ answers[i]=position+1;}
		else {
			 answers[i]=-1;
		}
	}
	
	for(int i=0 ; i<k ; i++) cout << answers[i] << ' ';
	cout << endl;
}
	
	
