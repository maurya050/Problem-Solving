class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int lsum = 0, rsum = 0, totalSum = 0;
        int maxSum;

        int  i = 0, n = cardPoints.size();
        for(int i =0; i<k; i++){
            totalSum += cardPoints[i];
        }
        maxSum = totalSum;

        for(int i =0; i<k; i++){
            totalSum -= cardPoints[k-i-1];
            totalSum += cardPoints[n-i-1];
            maxSum = max(totalSum, maxSum);
        }
        return maxSum;
    }
};