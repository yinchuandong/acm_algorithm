#include <iostream>
using namespace std;


void display(int A[], int n){
	for(int i=0; i<n; i++){
		cout << A[i] <<',';	
	}
	cout <<endl;
}

void swap(int &a, int &b){
	int t = a;
	a = b;
	b = t;
}

void selectsort(int A[], int n){
	int min, i, j;
	for(i = 0; i < n - 1; i++){
		min = i;
		for(j = i + 1; j < n; j++){
			if(A[j] < A[min]){
				min = j;	
			}	
		}
		if(min != i){
			swap(A[i], A[min]);
		}
	}
}


void insertsort(int A[], int n){
	int v, i, j;
	for(i = 1; i < n; i++){
		v = A[i];
		j = i - 1;
		while(j >= 0 && v < A[j]){
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = v;
	}

}

int main(int argnum, char* args[]){
	
	int A[] = {7, 9, 3, 5, 4, 1, 6};
	int n = 7;
	insertsort(A, n);
	display(A, n);
	return 0;
}
