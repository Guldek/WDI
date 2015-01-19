/*Usuwa duplikaty
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


void duplikaty (){
	p=first;
	node *h;
	q=first->next;
	h=first;
	
	while (p->next!=NULL){
		
		while (q!=NULL){
			if (p->dana==q->dana){
					node *r;
					r=q;
					if (r->next!=NULL) {
					h->next=r->next;
					q=q->next;
					}
					else {
						h->next=NULL;
						q=NULL;
						delete r;
						break;
					}
					
					delete r;
			}
		
		h=q;	
		q=q->next;	
		}
		
	p=p->next;
	h=p;
	q=p->next;	
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
	duplikaty ();
	wyswietl();
	cout << endl;
}

