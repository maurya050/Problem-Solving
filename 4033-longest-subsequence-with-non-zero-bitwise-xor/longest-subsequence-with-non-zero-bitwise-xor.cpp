class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int total = 0, len = nums.size();

        bool nonZero = false;

        for(int n : nums){
            nonZero = nonZero or n > 0;
            total = total ^ n;
        }

        if(total > 0)
            return len;
        if(nonZero)
            return len - 1;
        
        return 0;
    }
};