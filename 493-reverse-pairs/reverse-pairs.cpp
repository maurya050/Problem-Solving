class Solution {
public:
    int merge(vector<int> &nums, int low, int mid, int high){
        int i = low;
        int j = mid+1;
        int count = 0;
        for(i=low; i<= mid; i++){

            while(j<=high && (long long)nums[i] > (long long)2*nums[j])
                j++;
            
            count += j - (mid+1);
        }
        vector<int> ans;
        i = low, j= mid+1;
        while(i <= mid && j<=high){
            if(nums[i] <= nums[j]){
                ans.push_back(nums[i++]);
            }
            else
                ans.push_back(nums[j++]);
        }
        while(i <= mid){
            ans.push_back(nums[i++]);
        }
        while(j <= high){
            ans.push_back(nums[j++]);
        }

        for(int it=low; it<=high; it++)
            nums[it] = ans[it-low];

        return count;
    }
    int  MergeSort(vector<int> &nums, int low, int high){
        if(low >= high)
            return 0;
        int mid = low + (high-low)/2;
        int count = 0;

        count += MergeSort(nums, low, mid);
        count += MergeSort(nums, mid+1, high);
        count += merge(nums, low, mid, high);
        return count;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return MergeSort(nums, 0, n-1);
        
    }
};