#include<iostream>

using namespace std;

const int N = 4;
int tab1[N*N];
const int tab[N][N] = {
    { 1, 2, 3, 15 },
    { 11, 15, 19, 29 },
    { 5, 6, 15, 83},
    { 15, 21, 24, 25 }
};

int main (){
	int tmp=tab[0][0]; int x=0; int wpis=0; int max=0;
	int help[N];
	for (int i=0; i<N; i++){help[i]=0;}
	for (int i=0; i<N; i++){
		if (max<tab[i][N-1]){
			max=tab[i][N-1];
		}
	}
	for (int t=0; t<N*N; t++){
					
					for (int i=0; i<N; i++){
					
						if (help[i]<N){	
							if (tmp>=tab[i][help[i]]){
								tmp=tab[i][help[i]];
								x=i;
							}
						}	
					}
					help[x]++;
					//cout<<tmp<<" ";
					//cout<<help[x]<<endl;
					
					if (tmp>tab1[t-1] && tmp!=max+1){
						tab1[t]=tmp;
						wpis++;
					}
					else if (tmp==tab1[t-1]){
						t=t-1; 
					}
				
					
					tmp=max+1;
	}
				
	while (wpis<N*N){
			tab1[wpis]=0;
			wpis++;
	}	


	for (int i=0; i<N*N; i++){
		cout<<tab1[i]<<" ";
	}
}
