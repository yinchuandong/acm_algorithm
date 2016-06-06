#include <iostream>

using namespace std;

/** <=hi */
void display(int A[], int lo, int hi){
	for(int i=lo; i <= hi; i++){
		cout << A[i] <<',';	
	}
	cout <<endl;
}

void swap(int &a, int &b){
	if(a == b){ return; }
	int t = a;
	a = b;
	b = t;
}

int partition(int A[], int lo, int hi){
	int p = A[lo];
	int s = lo;
	for(int i = lo + 1; i <= hi; i++){
		if(A[i] < p){
			s = s + 1;
			swap(A[s], A[i]);
		}	
	}
	swap(A[lo], A[s]);
	display(A, lo, hi);
	cout << "lo:"<<lo<<" hi:"<<hi<<endl;
	return s;
}

int quickselect(int A[], int lo, int hi, int k){
	if(lo > hi){
		return A[lo];
	}
	int s = partition(A, lo, hi);
	if(k - 1 == s){
		return A[s];
	}else{
		if(k - 1 < s){
			return quickselect(A, lo, s - 1, k);
		}else{
			return quickselect(A, s + 1, hi, k);
		}
	}
}

// this implementation has a bug,
// when input is [1, 2, 3, 4, 5, 6, 7, 8] and k 3 or 5
int quickselect_old(int A[], int lo, int hi, int k){
	int s = partition(A, lo, hi);
	if(lo + k - 1 == s){
		return A[s];
	}else{
		if(s > lo + k - 1){
			return quickselect_old(A, lo, s - 1, k);
		}else{
			return quickselect_old(A, s + 1, hi, k - (s + 1));
		}
	}
}


int main(int argnum, char *args[]){
	// correct version
	int A[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int rt = quickselect(A, 0, 7, 3);
	cout<<"result:"<<rt<<endl;

	// wrong version
	// int rt2 = quickselect_old(A, 0, 7, 3);
	// cout<<"result:"<<rt2<<endl;

	// int B[] = {72, 29, 64, 86, 33, 89, 38, 32, 94, 42};
	// int rt2 = quickselect(B, 0, 9, 5);
	// cout<<"result:"<<rt2<<endl;
	return 0;
}
