class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> cnt(3, 0);

        for(int val: stones){
            cnt[val%3]++;
        }
        int a = cnt[0];
        int b = cnt[1];
        int c = cnt[2];

        if(a % 2 == 0)
            return b > 0 && c > 0;
        return abs(b-c ) > 2;
    }
};