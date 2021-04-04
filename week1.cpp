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









// 641. 设计循环双端队列
//
class MyCircularDeque {
private:
	vector<int> buffer;
	int front;
	int rear;
	int size;
	int len;
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k): buffer(k), size(k), front(k-1), rear(0), len(0) {
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(isFull()) {
        	return false;
        }
        else {
        	buffer[front] = value;
        	front = (front - 1 + size) % size;
        	len++;
        	return true;
        }
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(isFull()) {
        	return false;
        }
        else {
        	buffer[rear] = value;
        	rear = (rear + 1) % size;
        	len++;
        	return true;
        }
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(isEmpty()) {
        	return false;
        }
        else {
        	front = (front + 1) % size;
        	len--;
        	return true;
        }
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(isEmpty()) {
        	return false;
        }
        else {
        	rear = (rear - 1 + size) % size;
        	len--;
        	return true;
        }
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        return isEmpty() ? -1 : buffer[(front + 1) % size];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        return isEmpty() ? -1 : buffer[(rear - 1 + size) % size];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return len == 0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return len == size;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */