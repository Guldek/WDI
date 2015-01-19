#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

const int N=8;
int tab[N][N];

bool czy(int w, int k, int pierwsza);
int PierwszaCyfra(int a){
    while(a/10!=0)
        a/=10;
    return a;
}

int main()
{
    srand(time(NULL));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            tab[i][j]=rand() % 100 + 1;
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout<<tab[i][j]<<" ";
        }
      cout<<endl;  
    }

    int pierwsza, w, k;

    ;

    w=rand() % 7 + 1;
    k=rand() % 7 + 1;

    if(czy(w,k,tab[7][7]) || czy(w,k,tab[0][7]) || czy(w,k,tab[7][0]) || czy(w,k,tab[0][0]))
        cout << "\nDa sie przejsc\n";
    else
        cout << "\nNie da sie przejsc\n";\
}

bool czy(int w, int k, int pierwsza){
    if(w==7 && k==7)
        return true;
	if((tab[w][k]%10)>=pierwsza) return false; 
        if(k<N-1){
            if(czy(w, k+1, pierwsza))
                return true;
        }
        if(w<N-1 && k<N-1){
            if(czy(w+1, k+1, pierwsza))
                return true;
        }
        if((w<N-1)){
            if(czy(w+1, k, pierwsza))
                return true;
        }
    
    return false;
}

