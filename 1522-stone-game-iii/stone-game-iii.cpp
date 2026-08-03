class Solution {
public:
    int solve(int i, int n, vector<int> &arr, vector<int> &dp){
        if(i >= n) return 0;

        if(dp[i] != INT_MIN)
            return dp[i];
        
        int ans = INT_MIN;

        int sum = 0;

        for(int k = 0; k < 3; k++){
            if(i+k < n){

                sum += arr[i+k];
                ans = max(ans, sum - solve(i+k+1, n, arr, dp));
            }
        }

        return dp[i] = ans;
        
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n, INT_MIN);
        int diff = solve(0, n, stoneValue, dp);

        if(diff > 0) return "Alice";
        if(diff < 0) return "Bob";
        return "Tie";
    }
};