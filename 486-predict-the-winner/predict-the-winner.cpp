class Solution {
public:

    int totalSum(int i, int j, vector<int> &nums, vector<vector<int>> &dp){
        if(i > j) return 0;
        if(i == j) return nums[i];

        if(dp[i][j] != -1)
            return dp[i][j];

        int left = nums[i] + min(totalSum(i+2, j, nums, dp), totalSum(i+1, j-1, nums, dp));
        int right = nums[j] + min(totalSum(i+1, j-1, nums, dp), totalSum(i, j-2, nums, dp));
        return dp[i][j] = max(left, right);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int player1 = totalSum(0, n-1, nums, dp);
        int player2 = total - player1;

        return player1 >= player2 ? true : false;
    }
};