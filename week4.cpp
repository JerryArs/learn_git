    
//860. 柠檬水找零
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for (int bill : bills) {
            if (bill == 5) {
                five++;
            }
            else if (bill == 10) {
                if(five > 0) five--, ten++;
                else return false;
            }
            else {
                if (ten > 0 && five > 0) ten--, five--;
                else if (five >= 3) five -= 3;
                else return false;
            }
        }
        return true;
    }
};

//455. 分发饼干
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i = 0, j=0;
        while(i < g.size() && j < s.size()){
            if(g[i] <= s[j])
                i++; 
            j++;
        }
        return i;
    }
};