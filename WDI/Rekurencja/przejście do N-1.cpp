#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>
using namespace std;

const int N=9;
int tab[N];

bool first(int n)
{
	if(n==1) return false;
	else if(n==2) return true;
	else
	{
		for(int i = 2 ; i*i <= n ; i++) if(n%i==0) return false; 
		return true;
	}
}

bool przejscie (int i, int &licznik){
	
	if (i==N-1) {return true;}
		for (int k=2; k<tab[i]; k++){
			if (first(k) && tab[i]%k==0){
				licznik++;
				if (przejscie (i+k, licznik)) return true;
				
			}
		}
	licznik=0;	
	return false;
	}



int main (){
	 srand(time(NULL));
    for(int i=0; i<N; i++){
            tab[i]=rand() % 15 + 1;
        }
    
    for(int i=0; i<N; i++){
            cout<<tab[i]<<" ";
        }
      cout<<endl;  
    
        
        
    int licznik;
    
	licznik=0;    
    if(przejscie (0, licznik)) {
    cout<<endl<<licznik<<endl;}
    else { cout<<"-1";
    }

	
}
