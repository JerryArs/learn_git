// 1. 两数之和
// 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    	map<int, int> result_candidates;
    	vector<int> result(2);
    	for(int i = 0; i < nums.size(); i++) {
    		if(result_candidates.count(target - nums[i]) > 0
    			&& result_candidates[target - nums[i]] != i) {
    			result[0] = result_candidates[target - nums[i]];
    		    result[1] = i;
    		    break;
    		}
    		else {
    			result_candidates[nums[i]] = i;
    		}
    	}
    	return result;
    }
};


// 283. 移动零
//
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    	int j =0;
    	for(int i=0; i<nums.size(); i++){
    		if(nums[i] != 0){
    			nums[j++] = nums[i];
    		}
    	}
    	for(; j<nums.size(); j++){
    		nums[j] = 0;
    	}
    }
};