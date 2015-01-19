/*[Kolokwium zaliczeniowe 2010]  Zaimplementuj funkcj� 
Node* removeLongestIncreasingSublist(Node* head), ktora usuwa z �a�cucha wej�ciowego najd�u�szy pod�a�cuch rosn�cy 
(wzgl�dem pola value element�w listy). Warunkiem usuni�cia jest istnienie w �a�cuchu dok�adnie jednego najd�u�szego pod�a�cucha rosn�cego.
*/




#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>

using namespace std;

struct node
{
	node *next;
	int dana;	
};

node *p = NULL;
node *r = NULL;
node *q = NULL;
node *s = NULL;
node *first = NULL;
node *first1 = NULL;

void utworz(int n)
{
	for(int i = n; i > 0; i--)
	{
		r = new node;
		r->dana = rand() % 15 + 1;
		r->next = p;
		p = r;
	}
	first = r;
}
void wyswietl()
{
	p=NULL;
	r=first;
	while(r!=NULL)
	{
		cout << r->dana << ' ';
		r=r->next;
	}
}

void remove (){
	node *h=NULL;
	node *b=NULL;
	q=first;
	p=first->next;
	int w=0;
	int max=0;
	
	do{
		if (q->dana<p->dana){
			w++;
			}
		else {
			w=0;
		}
		if (w==1){
			h=q;
		}
		
		if (w>max){
			max=w;
			b=h;
			//last=p;
		}
		else if (w==max){
			max=0;
		}
		
		q=p;
		p=p->next;
	}while (p!=NULL);
	
	while (max>0){
		node *r;
		r=b->next;
		b->next=r->next;
		delete r;
		max--;
	}
}

int main()
{
	srand (time(NULL));
	int n;
	cout << "Jak dluga ma byc lancuch: ";
	cin >> n;
	utworz(n);
	wyswietl();
	cout << endl;
	remove ();
	wyswietl();
	cout << endl;
}
