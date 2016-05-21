#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
		char arr[] = {'A','E','I','O','U','a','e','i','o','u'};
		unordered_set<char> set(arr, arr + 10);
		int lo = 0;
		int hi = s.length() - 1;
		bool flagLo = false, flagHi = false;
		while (lo < hi){
			if(set.find(s[lo]) == set.end()){
				lo ++; 
			}else{
				flagLo = true;
			}
			if(set.find(s[hi]) == set.end()){
				hi --;	
			}else{
				flagHi = true;
			}
			if (flagLo && flagHi){
				char t = s[lo];
				s[lo] = s[hi];
				s[hi] = t;
				hi --; lo ++;
				flagLo = false;
				flagHi = false;
			}
		}
		return s;
    }
};

int main(int argNums, char *args[]){
	Solution s;
	cout << s.reverseVowels("leetcode")<<endl;
	
	return 0;
}
