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
		q = new node;
		r->dana = 3 *i;
		q->dana = 2*i;//rand() % 15 + 1;
		r->next = p;
		q->next = s;
		p = r;
		s = q;
	}
	first = r;
	first1 = q;
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
void wyswietl1()
{
	p=NULL;
	r=first1;
	while(r!=NULL)
	{
		cout << r->dana << ' ';
		r=r->next;
	}	
}
void remove (){
	p=first;
	q=NULL;
	node *r, *s;
	r=first1;
	s=NULL;

	while (p!=NULL){
		while (r!=NULL){
			if (p->dana==r->dana){
			
				node *z=p;
				q->next=p->next;
				p=p->next;
				delete z;
				
				node *w=r;
				s->next=r->next;
				r=r->next;
				delete w;	
			}
			else {
				s=r;
				r=r->next;
			}
		}
		
		r=first1;
		s=NULL;
			q=p;
			p=p->next;
		
		}
		
}




int main (){
	srand (time(NULL));
	int n;
	cout << "Jak dluga ma byc lancuch: ";
	cin >> n;
	utworz(n);
	wyswietl();
	cout << endl;
	wyswietl1();
	cout << endl;
	remove ();
	wyswietl();
	cout << endl;
}


