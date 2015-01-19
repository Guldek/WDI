#include<iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const int N = 10;
double *tab = new double[N];

double function (double x)
{
	double function;
	function = tab[0]*sin(tab[1]*x+tab[2]) + tab[3]*exp(tab[4]*x+tab[5]) + tab[6]*abs(tab[7]*x+tab[8]) + tab[9]; 
	return function;
}

int main(){
	
	double p,q;
	cin>>p>>q;
	for (int i=0; i<N; i++)	{cin>>tab[i];}
	double middle=(p+q)/2;
	int eps=24;
	
	if(function(p)>0)
	{
		int tmp = p;
		p=q;
		q=tmp;
	}
	
	
	while (eps--){
			
			if (function(middle)>0){q=middle; middle=(p+q)/2.0;}
			else if (function(middle)<0) {p=middle; middle=(p+q)/2.0;}
			else {break;}
	}
	
printf("%.8f\n", middle);	
	
}
	

