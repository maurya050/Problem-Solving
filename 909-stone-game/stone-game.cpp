class Solution {
public:
    int findWinner(int i, int j, vector<int> &piles, vector<vector<int>> &dp){
        if(i > j)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];
        int left = piles[i] + min(findWinner(i+2, j, piles, dp), findWinner(i+1, j-1, piles, dp));
        int right = piles[j] + min(findWinner(i+1, j-1, piles, dp), findWinner(i, j-2, piles, dp));

        return dp[i][j] = max(left, right);
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int total = accumulate(piles.begin(), piles.end(), 0);
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int AliceTotal = findWinner(0, n-1, piles, dp);

        int BobTotal = total - AliceTotal;

        return AliceTotal  >= BobTotal ? true : false;
    }
};