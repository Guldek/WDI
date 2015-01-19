#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int *tab=new int [n];
	for (int i=0; i<n; i++){cin >>tab[i];}
	
	int start=0;
	int end=n;
	int middle=(start+end)/2;
	
	while (true){
		if (tab[middle-1]<=tab[middle] && tab[middle]<=tab[middle+1]){
			start=middle; 
			middle=(start+end)/2;
		}	
		else if (tab[middle-1]>=tab[middle] && tab[middle]>=tab[middle+1]){
			end=middle; 
			middle=(start+end)/2;
		}	
		else if (tab[middle-1]<=tab[middle] && tab[middle]>=tab[middle+1]){
			cout<<tab[middle];
			break;
		}	
		
		}
		
	}
	
