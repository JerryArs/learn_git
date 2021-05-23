// 70. 爬楼梯
// 递归解法
class Solution {
public:
    unordered_map<int,int> dp;
    int climbStairs(int n) {
        if (n == 0)
            return 0;
        if (n == 1) 
            return 1; 
        if (n == 2)
            return 2; 
        if (dp.find(n) != dp.end()) //剪枝
            return dp[n];
        int steps = climbStairs(n-1) + climbStairs(n-2); 
        dp[n] = steps;
        return steps;
    }
};

// 22. 括号生成
// 
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        addPar(result, "", n, n);
        return result;
    }
    void addPar(vector<string> & res, string str, int left, int right){
        if(left == 0 && right == 0){
            res.push_back(str);
            return;
        }
        if(left > 0) addPar(res, str + "(", left - 1, right);
        if(right > left) addPar(res, str + ")", left, right - 1);
    }
};