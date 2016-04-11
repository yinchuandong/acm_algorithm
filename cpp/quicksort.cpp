#include <iostream>
using namespace std;

void swap(int &a, int &b){
	int t = a;
	a = b;
	b = t;
}

int partition(int A[], int lo, int hi){
	int p = A[lo];
	int i = lo, j = hi;
	//do{
	while(i < j){
		while(i < hi && A[i] <= p)	{ i++; }
		while(j >= lo && A[j] > p) { j--; }
		swap(A[i], A[j]);
	}
	//}while(i < j);
	swap(A[i], A[j]);
	swap(A[lo], A[j]);
	return j;
}

/** optimized version */
int partition2(int A[], int lo, int hi){
	int p = A[lo];
	//int i = lo, j = hi + 1;
	//do{
	//	do{ i++; } while(A[i] < p);
	//	do{ j--; } while(A[j] > p);
	//	swap(A[i], A[j]);
	//}while(i < j);
	int i = lo, j = hi;
	while(i < j){
		while(A[i] <= p) { i++; }
		while(A[j] > p) { j--; }
		swap(A[i], A[j]);
	}
	swap(A[i], A[j]);
	swap(A[lo], A[j]);
	return j;
}

void quicksort(int A[], int lo, int hi){
	if (lo < hi){
		int s = partition2(A, lo, hi);
		quicksort(A, lo, s - 1);
		quicksort(A, s + 1, hi);
	}
}


int main(int argnum, char *args[]){

	int A[] = {7, 9, 3, 5, 4, 1, 6};
	quicksort(A, 0, 6);
	for(int i = 0; i < 7; i++){
		cout << A[i]<<',';
	}
	cout << endl;
	return 0;
}
