#include <iostream>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* invertTree(TreeNode* root) {
	if (root == NULL)
		return root;
	TreeNode* tmp = root->left;
	root->left = invertTree(root->right);
	root->right = invertTree(tmp);
	return root;
}