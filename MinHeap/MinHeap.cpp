#include "MinHeap.h"
#include<math.h>
MinHeap::MinHeap(int capacity)
{
	cap = capacity;
	brojacel = 0;
	heap = new int[cap + 1];
}
void MinHeap::insert(int el)
{
	if (brojacel == cap)
	{
		std::cout << "HEAP JE PUN" << std::endl;
		return;
	}
	brojacel++;
	int i = brojacel;
	while (i > 1 && heap[i / 2] > el)
	{
		heap[i] = heap[i / 2];
		i /= 2;
	}
	heap[i] = el;
}
int MinHeap::obrisiKoren()
{
	if (brojacel == 0)
	{
		std::cout << "HEAP JE PRAZAN" << std::endl;
		return 0;
	}
	int result = heap[1];
	int last = heap[brojacel];
	
	brojacel--;
	long i = 1;
	while (2 * i < brojacel+1)
	{
		long child = 2 * i;
		if (child + 1 < brojacel + 1 && heap[child + 1] < heap[child])
			child += 1;
		if (last <= heap[child]) break;
		heap[i] = heap[child];
		i = child;
	}
	heap[i] = last;
	
	return result;
}

void MinHeap::sort(int* a, long n)
{
	MinHeap h(n + 1);
	for (long i= 0; i < n; i++)
	{
		h.insert(a[i]);
	}
	long i = 0;
	while (!h.jePrazan())
	{
		a[i++] = h.obrisiKoren();
	}
}

void MinHeap::stampaj()
{
	int stepen = 0;
	int vrednost = 1;
	for (int i=1; i <= cap; i++)
	{

		std::cout << heap[i] << " "<<"Pozicija: "<<i<<std::endl;
	}
}

int MinHeap::najmanji(int k) //k je nivo, od 0 do n
{
	int first = pow(2, k); //odakle krenuti
	int last;
	if (pow(2, k + 1) > brojacel)
	{
		last = brojacel+1;
	}
	else {
		last = pow(2, k + 1); //dokle, do (2^(k+1)) - 1, tj i<last
	}
	
	int min=heap[first];
	if (pow(2, k) > brojacel)
	{
		std::cout << "Preveliki nivo!";
		return -1;
	}
	else if (k == 0)
	{
		return heap[1];
	}
	else {
		for (int i = first+1; i < last; i++)
		{
			if (min > heap[i])
			{
				min = heap[i];
			}
		}
		return min;
	}
}