#include <iostream>
#include <stdarg.h>

using namespace std;




void swap(int &a, int &b){
	int t = a;
	a = b;
	b = t;
}


void adjustHeap(int arr[], int size, int i){
	int left, right, max;
	max = i;
	while(2*i < size){
		left = 2*i + 1;
		right = 2*i + 2;
		if (left < size && arr[left] > arr[max]){
			max = left;	
		}
		if (right < size && arr[right] > arr[max]){
			max = right;	
		}
		if (max != i){
			swap(arr[max], arr[i]);
			i = max;
		}else{
			break;
		}
	}
}


void buildHeap(int arr[], int size){
	for (int i = size / 2; i >= 0; i--){
		adjustHeap(arr, size, i);
	}
}

void heapsort(int arr[], int size){
	for (int i = size - 1; i > 0; i--){
		swap(arr[i], arr[0]);
		adjustHeap(arr, i, 0);
	}
}


void display(int arr[], int size){
	for (int i = 0; i < size; i++){
		cout << arr[i]<<',';
	}
	cout << endl;
}


int merge(int n_args, ...)
{
	va_list ap;
	va_start(ap, n_args);
	int n = va_arg(ap, int);
	int *arr = new int[n];
	int idx = 0;
	for(int i = 2; i <= n_args; i+=2) {
		int *a = va_arg(ap, int*);
		int len = va_arg(ap, int);
		for (int j = 0; j < len; j++){
			arr[idx++] = a[j];
		}
		display(a, len);
	}
	display(arr, n);
	buildHeap(arr, n);
	heapsort(arr, n);
	display(arr, n);
	va_end(ap);
	return 0;
}


int main(int argNum, char* args[]){
	
	int A[] = {1, 4, 7, 11};
	int B[] = {2, 5, 8, 10};
	int C[] = {3, 6, 9};
	int A_len = 4, B_len = 4, C_len = 3;
	int n = A_len + B_len + C_len;
	merge(7, n, A, A_len, B, B_len, C, C_len);
	return 0;
}


