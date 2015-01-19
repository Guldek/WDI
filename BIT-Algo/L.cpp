#include<iostream>
using namespace std;

void merge (int *tab, int size, int middle){
 	int *merged=new int[size];
 	int left=0;
	int right=middle;
	int i=0;
 	
 	while (left<middle and right<size){
 		if (tab[left]>=tab[right]){
 			merged[i++]=tab[left++];
  		}
 		else {
 			merged[i++]=tab[right++];	
 		}
 	 }
 	while (left<middle){
 			merged[i++]=tab[left++];
 	}
 	
 	while (right<size){
 		merged[i++]=tab[right++];
 	}
 	for (int x=0; x<size; x++){
 		tab[x]=merged[x];
 	}
 	
 }
void mergesort (int *tab, int size){
	if (size==1) return;
	int middle=size/2;
	mergesort(tab, middle);
	mergesort(tab+middle, size-middle);
	merge(tab,size,middle);		
}
 

 
void mergetwoarrays (int *tab, int *secondtab, int sizetab, int sizesecond, int *&endtab, int &thesame){
 	int *merged=new int[sizetab+sizesecond];
 	int left=0;
	int right=0;
	int i=0;             
	thesame=0;
 	 
 	
 	while (left<sizetab and right<sizesecond){
 		  if (tab[left]==tab[left+1]) {left++; thesame++;}
		  if (secondtab[right]==secondtab[right+1]) {right++; thesame++;}
		  
		  if (tab[left]==secondtab[right])
		 {
		 	merged[i++]=secondtab[right++];
			left++;	
			thesame++;
		 }
		 if (tab[left]>secondtab[right]){
 			merged[i++]=tab[left++];
  		}
 		if (tab[left]<secondtab[right]){
 			merged[i++]=secondtab[right++];	
 			}
 	 }
 	while (left<sizetab){
 			if (tab[left]==tab[left+1]) {left++; thesame++;}
 			merged[i++]=tab[left++];
 	}
 	
 	while (right<sizesecond){
 		if (secondtab[right]==secondtab[right+1]) {right++; thesame++;}
 		merged[i++]=secondtab[right++];
 	}
 	
 	for (int x=sizesecond+sizetab-thesame-1; x>=0; x--){
 		endtab[x]=merged[x];
 	}
 	
 } 

 
 int main (){
 	int n,k;
 	cin>>n>>k;
 	int *tab=new int [n];
 	int *secondtab=new int [k];
 	int *endtab= new int [n+k];
 	int thesame=0;
 	
 	for (int i=0; i<n; i++)
 	{
 		cin>>tab[i];
 	}
 	for (int i=0; i<k; i++)
 	{
 		cin>>secondtab[i];
 	}
 	
 	if (n!=0)mergesort (tab, n);
 	if (k!=0)mergesort (secondtab, k);
 	mergetwoarrays (tab, secondtab, n, k, endtab, thesame);
 
 	for (int x=n+k-thesame-1; x>=0; x--){
 		cout<<endtab[x]<<" ";
 	}
}        
