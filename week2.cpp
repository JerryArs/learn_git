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

