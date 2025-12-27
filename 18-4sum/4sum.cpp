class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        set<vector<int>> st;
        int n = nums.size();

        for(int i =0; i< n-3; i++){
            for(int j = i+1; j < n-2; j++){
                int k = j+ 1;
                int l = n-1;

                while(k < l){
                    long long total = (long long) nums[i]+ nums[j] + nums[k] + nums[l];
                    if(total == target){
                        st.insert({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;
                    }
                    else if(total < target){
                        k++;
                    }
                    else{
                        l--;
                    }
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};