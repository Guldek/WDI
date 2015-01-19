/*Dany jest ³añcuch zbudowany w oparciu o elementy typu:
 pnode = ^ node;
 node = record
 val : integer;
 next : pnode;
 end;
Dane s¹ dwa niepuste ³añcuchy, z których ka¿dy zawiera
niepowtarzaj¹ce siê elementy. Elementy w pierwszym ³añcuchu s¹
uporz¹dkowane rosn¹co, w drugim elementy wystêpuj¹ w przypadkowej
kolejnoœci. Proszê napisaæ procedurê, która z dwóch takich ³añcuchów
stworzy jeden, w którym uporz¹dkowane elementy bêd¹ stanowiæ sumê
mnogoœciow¹ elementów z ³añcuchów wejœciowych.
Do procedury nale¿y przekazaæ wskazania na oba ³añcuchy. Na przyk³ad
dla ³añcuchów:
 2 -> 3 -> 5 ->7-> 11
 8 -> 2 -> 7 -> 4
powinien pozostaæ ³añcuch:
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


