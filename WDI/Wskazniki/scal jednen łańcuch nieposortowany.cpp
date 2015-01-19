/*Dany jest �a�cuch zbudowany w oparciu o elementy typu:
 pnode = ^ node;
 node = record
 val : integer;
 next : pnode;
 end;
Dane s� dwa niepuste �a�cuchy, z kt�rych ka�dy zawiera
niepowtarzaj�ce si� elementy. Elementy w pierwszym �a�cuchu s�
uporz�dkowane rosn�co, w drugim elementy wyst�puj� w przypadkowej
kolejno�ci. Prosz� napisa� procedur�, kt�ra z dw�ch takich �a�cuch�w
stworzy jeden, w kt�rym uporz�dkowane elementy b�d� stanowi� sum�
mnogo�ciow� element�w z �a�cuch�w wej�ciowych.
Do procedury nale�y przekaza� wskazania na oba �a�cuchy. Na przyk�ad
dla �a�cuch�w:
 2 -> 3 -> 5 ->7-> 11
 8 -> 2 -> 7 -> 4
powinien pozosta� �a�cuch:
 2 -> 3 -> 4 -> 5 ->7-> 8 -> 11 
 
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
		q = new node;
		r->dana = 3 *i;
		q->dana = rand() % 15 + 1;
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
//znajduje najmniejsza wartosc w drugiej liscie, zwraca ja i usuwa ja z listy
int najmniejszy (){
	int n=first1->dana;
	node *p=first1;
	node *q=first1;
	node *b=NULL;
	
	while (p!=NULL){
		if (p->dana<n){
			n=p->dana;
			b=p;
		}
	p=p->next;		
	}
	
	if (first1->dana==n){
		b=first1;
		first1=first1->next;
		delete b;
	}else {
		while (q->next!=b){
		q=q->next;
		}
	
	q->next=b->next;
	delete b;		
	}
	return n;	
}

void scal (){
	p=first->next;
	q=first;
	int x=0;
	
	while (first1!=NULL){
		p=first->next;
		q=first;
		x=najmniejszy();
		
		if (x<first->dana){
			r=new node;
			r->dana=x;
			r->next=first;
			first=r;	
		}
		else {
			while (p!=NULL){
					if (x==p->dana) break;
					if (q->dana <x and x< p->dana){
						r= new node;
						r->dana=x;
						q->next=r;
						r->next=p;
						q=r;
						break;
					}else {
						q=p;
						p=p->next;
					}
				
			}
			
		}
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
	
	scal ();
	wyswietl();
	cout << endl;
	wyswietl1();
	cout << endl;
}


