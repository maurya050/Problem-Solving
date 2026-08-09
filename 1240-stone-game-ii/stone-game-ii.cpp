class Solution {
public:
    int helper(int i, int n, vector<int> &nums, int m, vector<vector<int>> &dp, int left_sum){
        
        if(i >= n)
            return 0;
        
        if(dp[i][m] != -1)
            return dp[i][m];
        
        int end = min(n, i+(2*m)); 
        int ans =0;
        int pick =0;
        for(int k = i ; k<end; k++){
            pick += nums[k];
            int new_m = max(m, (k-i+1));
            int new_leftsum = left_sum - pick;
            ans = max(ans, (left_sum - helper(k+1, n, nums, new_m, dp, new_leftsum)));
        }
        return dp[i][m] = ans;
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n+1, vector<int>(100, -1));
        int total_sum = accumulate(piles.begin(), piles.end(), 0);
        return helper(0, n, piles, 1, dp, total_sum);
    }
};