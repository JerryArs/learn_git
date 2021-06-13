// 387. 字符串中的第一个唯一字符
//
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> char_count;
        for (auto &c : s) char_count[c]++;
        for (int i = 0; i < s.size(); i++) {
            if (char_count[s[i]] == 1) return i;
        }
        return -1;
    }
};

// 438. 找到字符串中所有字母异位词
// 滑动窗口
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> pv(26,0), sv(26,0);
        vector<int> res;
        if(s.size() < p.size()) return res;
        for(int i = 0; i < p.size(); ++i) {
            ++pv[p[i]-'a'];
            ++sv[s[i]-'a'];
        }
        if(pv == sv) res.push_back(0);
        for(int i = p.size(); i < s.size(); ++i) {
            ++sv[s[i]-'a'];
            --sv[s[i-p.size()]-'a'];
            if(pv == sv)
               res.push_back(i-p.size()+1);
        }
        return res;
    }
};