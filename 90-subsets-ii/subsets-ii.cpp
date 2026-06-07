class Solution {
public:

    void helper(int ind, int n, vector<int> &nums, set<vector<int>> &ans, vector<int> &temp){
        if(ind == n){
            ans.insert(temp);
            return;
        }

        helper(ind+1, n, nums, ans, temp);
        temp.push_back(nums[ind]);
        helper(ind+1, n, nums, ans, temp);
        temp.pop_back();

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();      
        set<vector<int>> ans;
        vector<vector<int>> final;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        helper(0, n, nums, ans , temp);
        final.assign(ans.begin(), ans.end());
        return final;
    }
};