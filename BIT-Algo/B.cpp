#include<iostream>

using namespace std;

long long NWD(long long a, long long b){
	
	while (b!=0){
		
		long long c;
		c=b;
		b=a%b;
		a=c;
	}
	return a;	
}

long long NWW (long long a, long long b)
{
	long long y;
	y=(a*b)/NWD(a,b);
	return y;
}

int main (){
	
		long long n,a,b;
		cin>>n;
		int t[n];
		int w[n];
		for (long long i=0; i<n; i++){
			cin>>a; 
			cin>>b;
			t[i]=a;
			w[i]=b;
		}
		for (long long i=0; i<n; i++){
		cout<<NWD(t[i],w[i])<<" "<<NWW(t[i],w[i])<<endl;	
		}
}
