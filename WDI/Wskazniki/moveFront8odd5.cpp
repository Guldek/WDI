/*[Kolokwium zaliczeniowe 2014] 
Zaimplementuj funkcjê Node* moveFront8odd5(Node* head), która modyfikuje zadan¹ listê jednokierunkow¹ w taki sposób, 
¿e przenosi na pocz¹tek wszystkie elementy, w których zapisie ósemkowym wystêpuje nieparzysta liczba pi¹tek.
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

