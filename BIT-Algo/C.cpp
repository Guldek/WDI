#include<iostream>
#include<cmath>
using namespace std;

bool first (int n){
	if (n==1) return false;
	if (n==2) return true;
	 
	  	for(int i = 2; i*i<=n;i++)
		{
			if(n%i==0) return false;	
		}
		return true;
	
}


int main (){

	  int n;
	  cin>>n;
	  int *tab=new int [n];
	  bool *prime=new bool [n];
	  
	  
	  for (int i=0; i<n; i++){
				cin>>tab[i];		
				prime[i]=first(tab[i]);
		}
		
		
	 		
		for(int i = 0;i<n;i++)
	{
		if(prime[i]) cout << "TAK" << endl;
		else cout << "NIE" << endl;
	}
}
 

