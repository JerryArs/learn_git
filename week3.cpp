// 236. 二叉树的最近公共祖先
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if( root == NULL) {
        	return NULL;
        }
        if( root == p || root == q) {
        	return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if( left && right) {
        	return root;
        }
        return left ? left : right;
    }
};


// 77. 组合
class Solution {
private:
    vector<vector<int>> result; // Final result
    vector<int> track; // track record
    void backtrack(int n, int k, int start) {
        if (track.size() == k) {
            result.push_back(track);
            return;
        }
        for (int i = start; i <= n; i++) {
            track.push_back(i); // track 
            backtrack(n, k, i + 1);
            track.pop_back(); // revoke track
        }
    } // 未剪枝,待优化
public:
    vector<vector<int>> combine(int n, int k) {
        backtrack(n, k, 1);
        return result;
    }
}; 
