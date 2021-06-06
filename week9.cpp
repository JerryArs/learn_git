// 1122. 数组的相对排序
// Map
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> element_count;
        int pos = 0;
        for (auto i : arr1) element_count[i]++;
        for (auto j : arr2) {
            while(element_count[j]-- > 0) arr1[pos++] = j;
        }
        for (auto m : element_count) {
            while(m.second-- > 0) arr1[pos++] = m.first;
        }
        return arr1;
    }
};

// 205. 同构字符串
// without Map
// 相同字符找到的下标相同
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        for(int i = 0; i < s.size(); ++i)
            if(s.find(s[i]) != t.find(t[i]))
                return false;
        return true;
    }
};