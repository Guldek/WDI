#include<iostream>
using namespace std;



void mergesort (int *tab, int size){
	if (size==1) return ;
	int middle=size/2;
	mergesort(tab, middle);
	mergesort(tab+middle, size-middle);
	merge(tab,size,middle);		
}
 void merge (int *tab, int size, int middle){
 	int *merged=new int[size];
 	int *left=0;
	int *right=middle;
	int i=0;
 	
 	while (left<middle and right<size){
 		if (tab[left]>=tab[right]){
 			merged[i]=tab[left];
 			left++;
 			i++;
 		}
 		else {
 			merged[i]=tab[right];//merged[i++]=merged[right++]
 			right++;
 			i++;	
 		}
 	 }
 	while (left<middle){
 		merged[i]=tab[left];
 		left++;
 		i++;
 	}
 	
 	while (right<size){
 		merged[i]=tab[right];
 		right++;
 		i++;
 	}
 	for (int x=0; x<size; x++){
 		tab[x]=merged[x];
 	}
 	
 }
