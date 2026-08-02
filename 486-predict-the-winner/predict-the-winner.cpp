class Solution {
public:
    int helper(int i, int j, vector<int> &nums, vector<vector<int>> &dp){
        
        if(i > j)
            return 0;
        if(i == j)
            return nums[i];
        if(dp[i][j] != -1)
            return dp[i][j];
        int left_pick = nums[i] + min(helper(i+2, j, nums, dp), helper(i+1, j-1, nums, dp));
        int right_pick = nums[j] + min(helper(i+1, j-1, nums, dp), helper(i, j-2, nums, dp));
        
        return dp[i][j] = max(left_pick, right_pick);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int player1_sum = helper(0, n-1, nums, dp);
        int player2 = total - player1_sum;
        return player1_sum >= player2 ? true : false;
    }
};