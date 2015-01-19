#include<iostream>
using namespace std;

void merge (int *tab, int size, int middle, int &inversion){
 	int *merged=new int[size];
 	int left=0;
	int right=middle;
	int i=0;
 	
 	while (left<middle and right<size){
 		if (tab[left]>tab[right]){
 			merged[i++]=tab[left++];
			 inversion=inversion+(size/2)-right;
  		}
 		else if (tab[left]<tab[right]) {
 			merged[i++]=tab[right++];	
 		}
 		else {
 			merged[i++]=tab[left++];
 		}
 	 }
 	while (left<middle){
 			merged[i++]=tab[left++];
 			inversion++;
 	}
 	
 	while (right<size){
 		merged[i++]=tab[right++];
 	
 	}
 	for (int x=0; x<size; x++){
 		tab[x]=merged[x];
 	}
 }
void mergesort (int *tab, int size, int &t){
	if (size==1) return;
	int middle=size/2;	
	mergesort(tab, middle,t);
	mergesort(tab+middle, size-middle,t);
	merge(tab,size,middle,t);		
}
 
 
int main (){
	int n,t;
 	cin>>n;
 	int *tab=new int [n];
	for (int i=0; i<n; i++)
 	{
 		cin>>tab[i];
 	}
 	t=0;
 	if (n!=0)mergesort (tab, n,t);
    cout<<t;
 	
}
