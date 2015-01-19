#include<iostream>

using namespace std;

const int N = 4;
const int t[N][N] = {
    { 2, 1, 1, 1 },
    { 5, 2, 2, 2 },
    { 6, 2, 2, 2 },
    { 5, 2, 2, 2 }
};
void check (int k, int n, int wynik, int z, bool tab[N][N]){
	int y=0;
	//cout<<"y";
	if (n==N-k+1 or z==N){
		if (wynik==N){ cout<<"TAK";}
		else {cout<<"NIE";}
	}
	else {
		for (int j=n; j<n+k; j++){
			if (tab[j][z]==true) {y++;}
		}
		if (y==1){check (k, n, wynik+1, z+1, tab);}
		else {check (k, n+1, wynik, 0, tab);}
	}
		
}





int main (){
	int k;
	cin>>k;
	
	bool tab[N][N];
	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			if (t[i][j]%2==1) {tab[i][j]=true;}
			else {tab[i][j]=false;
			}
		}
	}
	check (k, 0, 0, 0, tab);
	
}
