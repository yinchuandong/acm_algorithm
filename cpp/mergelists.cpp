#include <iostream>
#include <stdarg.h>

using namespace std;

typedef struct tagNode{
	int value;
	int idInArray;
	int idInList;
}Node;

void swap(Node &a, Node &b){
	Node t = a;
	a = b;
	b = t;
}

void bottomUp(Node heap[], int size){
	int index = size - 1;
	int parent = 0;
	while(index > 0){
		parent = (index - 1) / 2;
		if (heap[index].value >= heap[parent].value){
			break;
		}
		swap(heap[index], heap[parent]);
		index = parent;
	}
}

void inject(Node heap[], int &size, Node elem){
	heap[size++] = elem;
	bottomUp(heap, size);
}

Node eject(Node heap[], int &size){
	swap(heap[0], heap[size-1]);
	Node elem = heap[size-1];
	size --;
	bottomUp(heap, size);
	return elem;
}

void display(int arr[], int size){
	for (int i = 0; i < size; i++){
		cout << arr[i]<<',';
	}
	cout << endl;
}


int merge(int n_args, ...){
	va_list ap;
	va_start(ap, n_args);
	int n = va_arg(ap, int); // total length
	int k = va_arg(ap, int); // k arrays in list
	int hsize = 0; //size of min heap
	Node *heap = new Node[k]; // heap with size being k
	int **src = new int*[k]; // the 2-d array of source list
	int *srcSize = va_arg(ap, int*);; // the array recording the length of src[k]
	for(int i = 4; i <= n_args; i++) {
		int *a = va_arg(ap, int*);
		int idInList = i - 4;
		src[idInList] = a;
		Node elem;
		elem.value = a[0]; elem.idInArray = 0; elem.idInList = idInList;
		inject(heap, hsize, elem);
	}
	int *arr = new int[n];
	int idx = 0;
	while(hsize != 0){
		Node elem = eject(heap, hsize);
		arr[idx++] = elem.value;
		if(elem.idInArray < srcSize[elem.idInList] - 1){
			Node next;
			next.value = src[elem.idInList][elem.idInArray+1];
			next.idInArray = elem.idInArray + 1;
			next.idInList = elem.idInList;
			inject(heap, hsize, next);
		}
	}
	va_end(ap);
	display(arr, n);
	return 0;
}


int main(int argNum, char* args[]){

	int A[] = {1, 4, 7, 11};
	int B[] = {2, 5, 8, 10};
	int C[] = {3, 6, 9, 12};
	int srcSize[] = {4, 4, 4};
	int n = 12;
	int k = 3;
	merge(6, n, k, srcSize, A, B, C);
	return 0;
}


