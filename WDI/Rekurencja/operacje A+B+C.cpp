#include<iostream>
#include<cmath>
using namespace std;

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

int zmiana (int n){
	int x=n%10;
	n/=10;
	int y=n%10;
	n=(n-y+x)*10+y;
	return n;
}

void wypisz(string s ,int krok)
{
	for(int i = 0; i<krok; i++) cout << s[i] << ' ';
	cout << endl;
}

bool operacje (int x, int k, int n, string s){//10, 84
	
	if (first(k) && x<=n) {wypisz (s,x); return true;}
	if (x>n){return false;}
	else return operacje (x+1, k+3, n, s+'A') or operacje (x+1, 2*k, n, s+'B') or operacje (x+1, zmiana(k),n, s+'C');
	

		
		
		
	//return false;	
	}

int main (){
	int n; int x;
	int k; 	
	string s;
	cin>>n; cin>>k;
	x=0;
	if (operacje (x,k,n,s)) {cout<<"TAK";
	}
	else {cout<<"NIE";
	}
}
