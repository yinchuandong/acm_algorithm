#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <vector>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stringstream ret;
        ret << "[";
        queue<TreeNode*> s;
        s.push(root);

        TreeNode* node;
        while(!s.empty()){
            node = s.front();
            s.pop();
            if(node){
                s.push(node->left);
                s.push(node->right);
                // cout<< node->val<< '\t' << endl;
                ret << node->val << ",";
                
            }else{
                // cout << "null"<<endl;
                ret <<"null,";
            }
        }
        ret<<"]";
        // cout << ret.str()<<endl;

        return ret.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        data = data.substr(1, data.length()-3);
        // cout<<data<<endl;
        
        vector<int> nums;
        vector<TreeNode*> nodes;
        
        char *source = strdup(data.c_str());
        char *p;
        while((p = strsep(&source, ",")) != NULL){
            if(nums.size() > 0){
                nums.push_back(nums[nums.size() - 1]);
            }else{
                nums.push_back(0);
            }
            if(strcmp(p, "null") == 0){
                nums[nums.size() - 1] += 1;
                nodes.push_back(NULL);
            }else{
                nodes.push_back(new TreeNode(atoi(p)));
            }
        }
        
        //if the tree is full binary tree, the index of left/right child should be (2*i + 1) / (2*i + 2)
        //howerver, because null node exists and the null child doesn't have any child.
        //the left/right child now shoud be (2*(i - num) + 1) / (2*(i - num) + 2)
        for(int i = 0; i < nodes.size(); i++){
            if(nodes[i] == NULL){
                continue;
            }
            nodes[i]->left = nodes[2*(i - nums[i]) + 1];
            nodes[i]->right = nodes[2*(i - nums[i]) + 2];
        }
        
        return nodes[0];
    }
};

int main(int argsNum, char* args[]){
    TreeNode *root = new TreeNode(1);
    TreeNode *l1 = new TreeNode(2);
    TreeNode *r1 = new TreeNode(3);
    TreeNode *r11= new TreeNode(4);
    TreeNode *r12= new TreeNode(5);
    root->left = l1;
    root->right = r1;
    r1->left = r11;
    r1->right = r12;



    Codec codec;
    string str = codec.serialize(root);
    TreeNode *node = codec.deserialize(str);
//    codec.serialize(root);
//    string encodeStr = "[5,4,7,3,null,2,null,-1,null,9,null,null,null,null,null,]";
//    codec.deserialize(encodeStr);
    cout << "end of main"<<endl;
    // delete root;
    // delete l1;
    // delete r1;
    // delete r11;
    // delete r12;

    return 0;
}

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));