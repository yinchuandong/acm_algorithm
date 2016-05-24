#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int max(int a, int b){
    return a > b ? a : b;
}

int* dfs(TreeNode *root){
    int *arr = new int[2];
    arr[0] = 0; arr[1] = 0;
    if (root != NULL){
        int *L = dfs(root->left);
        int *R = dfs(root->right);
        int not_rob_root = L[0] + R[0];
        int rob_rot = max(not_rob_root, L[1] + R[1] + root->val);
        arr[0] = rob_rot;
        arr[1] = not_rob_root;
    }
    return arr;
}

class Solution {
public:
    int rob(TreeNode* root) {
        // int *arr = dfs(root);
        // rob_L, not_rob_L; rob_R, not_rob_R;
        // not_rob_root = rob_L + rob_R
        // rob_root = max(not_rob_root , not_rob_L + not_rob_R + root.val)
        // arr[0] = rob_root;
        // arr[1] = not_rob_root;

        return dfs(root)[0];
    }
};


int main(int argNum, char *args[]){
    TreeNode *t0 = new TreeNode(3);
    TreeNode *t1 = new TreeNode(2);
    TreeNode *t2 = new TreeNode(3);
    TreeNode *t3 = new TreeNode(3);
    TreeNode *t4 = new TreeNode(1);
    t0->left = t1; t0->right = t2;
    t1->right = t3; t2->right = t4;
    
    // TreeNode *t0 = new TreeNode(4);
    // TreeNode *t1 = new TreeNode(1);
    // TreeNode *t2 = new TreeNode(2);
    // TreeNode *t3 = new TreeNode(3);
    // t0->left = t1; t1->left= t2;
    // t2->left= t3;

    Solution s;
    cout << s.rob(t0)<<endl;
    return 0;
}