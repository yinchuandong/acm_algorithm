#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Wrap{
public:
	int number;
	int count;
	Wrap(){
	}
	Wrap(int number, int count){
		this->number = number;
		this->count = count;
	}
};

void swap(Wrap &a, Wrap &b){
	Wrap t = a;
	a = b; b = t;
}

int partition(vector<Wrap> &A, int lo, int hi){
	int s = lo;
	int p = A[lo].count;
	for(int i = lo + 1; i <= hi; i++){
		if(A[i].count > p)	{
			s++;
			swap(A[i], A[s]);
		}
	}
	swap(A[lo], A[s]);
	return s;
}


void quickselect(vector<Wrap> &A,int lo,int hi,int k){
	if(lo > hi){
		return;
	}
	int s = partition(A, lo, hi);
	if(k - 1 == s){
		return;
	}else{
		if(k - 1 < s){
			return quickselect(A, lo, s - 1, k);
		}else{
			return quickselect(A, s + 1, hi, k);
		}
	}
}

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    	map<int, int> m;
    	for (int i = 0; i < nums.size(); i++){
    		if (m.find(nums[i]) == m.end()){
    			m.insert(pair<int, int>(nums[i], 1));
    		}else{
    			m[nums[i]] += 1;
    		}
    	}
    	vector<Wrap> A;
    	map<int, int>::iterator iter;
    	for (iter = m.begin(); iter != m.end(); iter++){
    		Wrap w(iter->first, iter->second);
    		A.push_back(w);
    	}
    	vector<int> r;
    	quickselect(A, 0, A.size() - 1, k);
    	for (int i = 0; i < k; i++){
    		r.push_back(A[i].number);
    	}
    	return r;
    }
};

void test2(){
	int a[] = {4,1,-1,2,-1,2,3};
	vector<int> arr(a, a + sizeof(a)/sizeof(int));
	Solution s;
	vector<int> r = s.topKFrequent(arr, 2);
	for(int i = 0; i < r.size(); i++){
		cout << r[i]<<',';
	}
	cout <<endl;
}

int main(int argNum, char *args[]){
	test2();	
	return 0;
}
