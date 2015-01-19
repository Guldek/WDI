#include<iostream>
#include <cstdio>

using namespace std;

void binsqrt(int x){
	double first=0.0;
	double second=1000.0;
	double middle=0.0;
	double range=0.00000001;
	double end=0.0;
	
	bool t=true;
		 
	while (t)
	{

		
		
		middle=(first+second)/2.0;
		end=middle*middle - x;
		if (end>0){second=middle;}else {first=middle;} 
		if (end<0){end=-end;}
		if (end<range) {t=false; printf("%.8f\n", middle);}
			
	}

}



int main(){


int repeat=0;

int n,x;
cin>>n;

  while (repeat!=n){

	cin>>x;
	binsqrt(x);
	repeat++;
  }
}
			
