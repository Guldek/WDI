#include <iostream>

using namespace std;

const int N = 1000;
int tab[N];

void bubblesort(int n)
{
  for(long long k=n-1;k>0;k--)
    for(long long i=0;i<k;i++)
      if(tab[i] > tab[i+1])
        swap(tab[i],tab[i+1]);
}



int main()
{ 
long long n;
long long y;
cin>>n;
for (long long i=0; i<n; i++){
	cin>>y;
	tab[i]=y;
} 

  bubblesort(n);  
  for(long long i=0;i<n;i++)
	cout << tab[i] << " ";
 ;
}
