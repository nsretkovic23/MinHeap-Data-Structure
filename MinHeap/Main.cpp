#include<iostream>
#include "MinHeap.h"
#include <math.h>
#include<time.h>
using namespace std;
void main(){
	srand(time(NULL));

	int n = 7;
	MinHeap* heap=new MinHeap(n);

	//ubacivanje elemenata
	for (int i = 0; i < n; i++)
	{	
		heap->insert(rand() % 100);
	}
	
	heap->stampaj();
	
	/*cout <<"Koren je:"<< heap->obrisiKoren() << endl;
	heap->stampaj();*/
	cout<<"\nNajmanji element u zadatom nivou je: "<< heap->najmanji(2); //implementirana metoda

}