#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
 		vector<int> result;
		unordered_set<int> set1;
		unordered_set<int> set2;
		for(int i = 0; i < nums1.size(); i++){
			set1.insert(nums1[i]);
		}
		for(int i = 0; i < nums2.size(); i++){
			set2.insert(nums2[i]);
		}
		//unordered_set<int>::iterator iter = 
		for(unordered_set<int>::iterator iter = set1.begin(); iter != set1.end(); iter++){
			if(set2.find((const int)*iter) != set1.end()){
				result.push_back(*iter);
			}
		}
		return result;		
    }
};

int main(int argNum, char *args[]){
	
	Solution s;
	int s1[] = {1, 2, 2, 1};
	int s2[] = {2, 2, 1};
	vector<int>	nums1(s1, s1 + sizeof(s1)/sizeof(int));
	vector<int> nums2(s2, s2 + sizeof(s2)/sizeof(int));
	vector<int> result = s.intersection(nums1, nums2);
	for(int i = 0; i < result.size(); i++){
		cout<<(result[i]);
	}
	cout<<endl;
	return 0;
}
