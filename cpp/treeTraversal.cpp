#include <iostream>
#include <stack>
using namespace std;



struct Tree{
	Tree *left;
	Tree *right;
	int val;
};


void preorder(Tree *root){
	stack<Tree*> st;
	Tree *p = root;
	st.push(root);
	while(!st.empty()){
		p = st.top();
		st.pop();
		cout<<p->val<<',';
		if (p->right != NULL){
			st.push(p->right);
		}
		if (p->left != NULL){
			st.push(p->left);
		}
	}
	cout<<endl;	
}

void preorder_rer(Tree *node){
	if (node != NULL){
		cout<<node->val<<',';
		preorder_rer(node->left);
		preorder_rer(node->right);
	}
}

void inorder_rer(Tree *node){
	if (node != NULL){
		inorder_rer(node->left);
		cout<<node->val<<',';
		inorder_rer(node->right);
	}
}

void postorder_rer(Tree *node){
	if (node != NULL){
		postorder_rer(node->left);
		postorder_rer(node->right);
		cout<<node->val<<',';
	}
}

void postorder(Tree *node){
	stack<Tree*> st;
    Tree *pre = NULL;
    Tree *cur = NULL;
    st.push(node);
    while(!st.empty()){
        cur = st.top();
        if ((cur->left == NULL && cur->right == NULL) 
            || (pre != NULL && (cur->left == pre || cur->right == pre))){
            cout << cur->val<<',';
            st.pop();
            pre = cur;
        }else{
            if (cur->right != NULL){
                st.push(cur->right);
            }
            if (cur->left != NULL){
                st.push(cur->left);
            }
        }
    }
}

int main(int argsNum, char* args[]){
	Tree *t17 = new Tree(); t17->val = 17;
	Tree *t33 = new Tree(); t33->val = 33;
	Tree *t48 = new Tree(); t48->val = 48;
	Tree *t19 = new Tree(); t19->val = 19;
	Tree *t16 = new Tree(); t16->val = 16;
	Tree *t11 = new Tree(); t11->val = 11;
	Tree *t14 = new Tree(); t14->val = 14;
	Tree *t38 = new Tree(); t38->val = 38;
	Tree *t31 = new Tree(); t31->val = 31;

	t17->left = t33; t17->right = t48;
	t33->left = t19; t33->right = t16;
	t48->left = t11; t48->right = t14;
	t16->left = t38; t16->right = t31;	

	// preorder(t17);
	// preorder_rer(t17); cout<<endl;
	// inorder_rer(t17); cout<<endl;
	// postorder_rer(t17); cout<<endl;
	// postorder(t17); cout<<endl;


		
	return 0;

}
