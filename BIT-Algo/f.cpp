#include <iostream>
using namespace std;

int bin(int arr[], int res[], int beg, int fin, int i, int p)
{
	int mid = (beg + fin)/2;
        bool condition = false;
        bool rightone = false;
        while((beg!=fin and !condition) and !rightone)
        {
                if(arr[mid]>p)
                {
                	fin = mid;
                	mid = (fin + beg)/2; 
                }
                else if(arr[mid]<p)
                {
                	if(beg+1==fin) condition = true;
                	beg = mid;
        	        mid = (fin + beg)/2;
                }
                else
                {
                        if(mid==0)
                        {
                                return mid+1;
                                rightone = true;
                        }
                        else if(arr[mid-1]!=p)
                        {
                                return mid+1;
                                rightone = true;
                        }
                        else
                        {
                                fin = mid;
                                mid = (fin+beg)/2;
                        }
                }
        }
        if(!rightone) return -1;
}

int main()
{
	int n;
	int k;

	cin >> n >> k;
	int loop = k;
	int *arr = new int[n];
	int *res = new int[k];
	cin >> arr[0];
	int max = 0;
	for(int i = 1 ; i < n; i++) 
	{
		cin >> arr[i];
		if(arr[i]<arr[i-1]) max = i-1;
	}
	if(max==0 and arr[0]<arr[n-1]) max = n-1;

	for(int i = 0 ; i < loop; i++)
	{
		int p;
		cin >> p;
		int pos1, pos2;
		pos1 = bin(arr,res,0,max+1,i,p);
		pos2 = bin(arr,res,max,n,i,p);
		if(pos1==-1&&pos2!=-1) res[i]=pos2;
		else if(pos1!=-1&&pos2==-1) res[i]=pos1;
		else
		{
			if(pos2-max>pos1) res[i]=pos2;
			else if(pos2-max<=pos2) res[i]=pos1;
		}
	}
	for(int i = 0 ; i<loop ; i++) cout << res[i] << ' ';
	cout << endl;
}
