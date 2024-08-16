class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
		if (root == NULL) {
			return new TreeNode(val);
		}

		if (val > root->val and !root->right) {
			root->right = new TreeNode(val);
			return root;
		} else if (val < root->val and !root->left) {
			root->left = new TreeNode(val);
			return root;
		} else if (!root->left and !root-> right) {
			if (val > root->val) root->right = new TreeNode(val);
			if (val < root->val) root->left = new TreeNode(val);
			return root;
		}

		if (val > root->val) insertIntoBST(root->right, val);
		if (val < root->val) insertIntoBST(root->left, val);

		return root;
    }
};
