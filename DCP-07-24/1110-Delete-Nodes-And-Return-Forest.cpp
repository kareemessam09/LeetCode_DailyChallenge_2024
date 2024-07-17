class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> rst;
        unordered_set<int> removeSet(to_delete.begin(), to_delete.end());

        root = dfs(root, removeSet, rst);
        if (root) rst.push_back(root);
        return rst;
    }


    TreeNode* dfs(TreeNode* root, unordered_set<int>& removeSet, vector<TreeNode*>& rst){
        if (root==nullptr) return nullptr;
        auto leftNode = dfs(root->left, removeSet, rst);
        auto rightNode = dfs(root->right, removeSet, rst);

        root->left = leftNode;
        root->right = rightNode;

        if (removeSet.count(root->val)){
            if (root->left) rst.push_back(root->left);
            if (root->right) rst.push_back(root->right);
            delete root;
            return nullptr;
        }
        return root;
    }
};