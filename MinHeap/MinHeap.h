#pragma once
#include <iostream>
class MinHeap
{
private:
	long brojacel;
	long cap;
	int* heap;
public:
	MinHeap(int);
	~MinHeap() { delete[] heap; heap = 0; };
	bool jePrazan() { return brojacel == 0; };
	void insert(int);
	int obrisiKoren();
	static void sort(int*, long n);
	int najmanji(int);
	void stampaj();

};

