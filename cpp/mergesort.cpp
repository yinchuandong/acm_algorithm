#include <iostream>
#include <math.h>
using namespace std;

void display(int A[], int n){
	for(int i=0; i<n; i++){
		cout << A[i] <<',';	
	}
	cout <<endl;
}

void merge(int B[], int p, int C[], int q, int A[]){
	int i = 0, j = 0, k = 0;
	while(i < p && j < q){
		if(B[i] <= C[j]){
			A[k] = B[i];
			i++;
		}else{
			A[k] = C[j];
			j++;
		}
		k++;	
	}
	if(i == p){
		// B is over, copy C
		memcpy(A + k, C + j, sizeof(int) * (q - j));
	}else{
		memcpy(A + k, B + i, sizeof(int) * (p - i));
	}
}


/** n, p, q is length, not index */
void mergesort(int A[], int n){
	if(n > 1){
		int p = floor(n/2.0);
		int q = ceil(n/2.0);
		int *B = new int[p];
		int *C = new int[q];
		memcpy(B, A, sizeof(int)*p);
		memcpy(C, A + p, sizeof(int)*q);
		
		//display process
		display(A, n);
		display(B, p);
		display(C, q);
		cout <<endl;
	
		//divide
		mergesort(B, p);
		mergesort(C, q);
		merge(B, p, C, q, A);
		delete[] B;
		delete[] C;
	}
}


int main(int argnum, char *args[]){
	
	int A[] = {7, 9, 3, 5, 4, 1, 6};
	mergesort(A, 7);
	display(A, 7);
	return 0;
}
