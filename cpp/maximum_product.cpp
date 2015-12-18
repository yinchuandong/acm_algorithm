#include<iostream>
#include<vector>
#include<string>

using namespace std;


class Solution {
public:
	int maxProduct(vector<string>& words) {
		return 0;
	}
	
	void init(){
		vector<string> words;
		words.push_back("a");
		words.push_back("b");
		print(words);
	}

	void print(vector<string> words){
		vector<string>::iterator iter = words.begin();
		for(; iter != words.end(); iter++){
			cout<<*iter<< ' ';
		}
		cout <<endl;
	}

};

int main(int argnum, char* args[]){
	Solution model;
	model.init();
	return 0;
}


