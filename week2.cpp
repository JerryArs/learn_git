// 242. 有效的字母异位词
//
class Solution {
public:
    bool isAnagram(string s, string t) {
    	if(s.length() != t.length()) {
    		return false;
    	}
    	map<int, int> match;
    	for(int i=0; i < s.length(); i++) {
    		match[s.at(i)] ++;
    	}
    	for(int i=0; i < t.length(); i++) {
    		if(match[t.at(i)] == 0) {
    			return false;
    		}
    		match[t.at(i)] --;
    	}
    	return true;
    }
};


// 49. 字母异位词分组
//
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams_hashtable;
        for (string s : strs) {
            string t = s; 
            sort(t.begin(), t.end());
            anagrams_hashtable[t].push_back(s);
        }
        vector<vector<string>> anagrams_array;
        for (auto p : mp) { 
            anagrams_array.push_back(p.second);
        }
        return anagrams_array;
    }
};


//94. 二叉树的中序遍历
//
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorder(root, result);
        return result;
    }
    void inorder(TreeNode* root, vector<int>& result) {
        if (!root) {
            return;
        }
        inorder(root->left, result);
        result.push_back(root->val);
        inorder(root->right, result);
    } 
};

//144. 二叉树的前序遍历
//
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
    	vector<int> result;
    	preorder(root, result);
    	return result;

    }
    void preorder(TreeNode* root, vector<int>& result) {
        if (!root) {
            return;
        }
        result.push_back(root->val);
        preorder(root->left, result);
        preorder(root->right, result);
    } 
};