/*[Kolokwium zaliczeniowe 2014] 
Zaimplementuj funkcj� Node* moveFront8odd5(Node* head), kt�ra modyfikuje zadan� list� jednokierunkow� w taki spos�b, 
�e przenosi na pocz�tek wszystkie elementy, w kt�rych zapisie �semkowym wyst�puje nieparzysta liczba pi�tek.
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

bool dwa (int n){
	int max=0;
	while (n!=0){
		if (n%8==5) {max++;}
		n=n/8;
	}
	if (max%2==1) return true;
	else return false;
}


void piatka(){
	p=first;
	node *h;
	h=NULL;
	q=NULL;
	
	while (p!=NULL){
		
		if (dwa(p->dana)){
			h=p;
			p=p->next;
			q->next=p;
			h->next=first;
			first=h;
		}
		else {
		q=p;
		p=p->next;
		}
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
	piatka ();
	wyswietl();
	cout << endl;
}

