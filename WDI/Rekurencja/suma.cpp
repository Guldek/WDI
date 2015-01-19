#include <iostream>
using namespace std;

void generate(int n, int tab[],int l,int max)//generate(20,tab,0)
{
	if(n<=0)
	{
		cout << tab[0];
		for(int i = 1;i <  l;i++) cout << " + " << tab[i];
		cout << endl;
	}
	else
	{2
		for(int i=1;i<=max and i<=n; i++)
		{
			tab[l]=i;
			generate(n-i,tab,l+1,i);
		}
	}
}

int main()
{
	int n;
	cin >> n;
	int *p=new int[n];
	
	generate(n,p,0,n);
}
