#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

const int N=3;
int tab[N][N];

void zmiana (int w, int k, int suma, int &suma1, int i){//0,0,
	
	/*for (int i=0; i<6; i++) 
	{cout<<tab1[i]<<" ";}
	cout<<endl;*/
	
	if(suma>suma1) suma1=suma;  
	if(w==N-1 and k==N-1) cout<<suma;
	if (w<=N-1) { tab1[i]=tab[w][k]; zmiana (w+1, k, suma+tab[w+1][k], suma1, i+1); 
	}
	if (k<=N-1) {tab1[i]=tab[w][k]; zmiana (w, k+1 ,suma+tab[w][k+1], suma1, i+1); //tab1[i]=0;
	}
	tab1[i]=0;
 }

	return suma1;
}
