class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int largest_sum = INT_MIN;
        int sum = 0;

        for(int val : nums){
            sum += val;
            largest_sum = max(sum, largest_sum);

            if(sum < 0){
                sum = 0;
            }
        }
        return largest_sum;
    }
};