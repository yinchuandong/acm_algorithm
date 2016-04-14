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
	cout << "lo:"<<lo<<" hi"<<hi<<endl;
	return s;
}

int quickselct(int A[], int lo, int hi, int k){
	int s = partition(A, lo, hi);
	if(lo + k - 1 == s){
		return A[s];
	}else{
		if(s > lo + k - 1){
			return quickselct(A, lo, s - 1, k);
		}else{
			return quickselct(A, s + 1, hi, k - (s + 1));
		}
	}
}


int main(int argnum, char *args[]){
	int A[] = {39, 23, 12, 77, 48, 61, 55};
	int rt = quickselct(A, 0, 6, 4);
	cout<<"result:"<<rt<<endl;
	int B[] = {72, 29, 64, 86, 33, 89, 38, 32, 94, 42};
	int rt2 = quickselct(B, 0, 9, 5);
	cout<<"result:"<<rt2<<endl;
	return 0;
}
