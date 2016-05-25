#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;

class Solution {
public:
   
    bool isPalindrome(string word){
        int lo = 0, hi = word.size() - 1;
        while(lo < hi){
            if (word[lo++] != word[hi--]){
                return false;
            }
        }
        return true;
    }

    vector< vector<int> > palindromePairs(vector<string>& words) {
        vector< vector<int> > result;
        unordered_map<string, int> wmap;
        for(int i = 0; i < words.size(); i++){
            wmap[words[i]] = i;
        }
        for(int i = 0; i < words.size(); i++){
            string word = words[i];
            int len = word.length();
            reverse(word.begin(), word.end());
            for(int j = 0; j <= len; j++){
                string left = word.substr(0, j);
                string right = word.substr(j, len);
                if(wmap.count(left) > 0 && isPalindrome(right) && wmap[left] != i && len > j){
                    // cout << wmap[left]<< ','<< i<<endl;
                    vector<int> arr(2); arr[0] = wmap[left]; arr[1] = i;
                    result.push_back(arr);
                }
                if(wmap.count(right) > 0 && isPalindrome(left) && wmap[right] != i){
                    // cout << i<< ','<< wmap[right]<<endl;
                    vector<int> arr(2); arr[0] = i; arr[1] = wmap[right];
                    result.push_back(arr);
                }

            }
        }
        return result;
    }
};

int main(int argNum, char *args[]){
    Solution s;
    string arr[] = {"abcd", "dcba", "lls", "s", "sssll","", "hssh"};
    // string arr[] = {"bat", "tab", "cat"};
    vector<string> words(arr, arr + sizeof(arr)/sizeof(string));
    vector< vector<int> > result = s.palindromePairs(words);
    for (int i = 0; i < result.size(); i++){
        cout << result[i][0]<< ',' << result[i][1]<<endl;
    }
    return 0;
}