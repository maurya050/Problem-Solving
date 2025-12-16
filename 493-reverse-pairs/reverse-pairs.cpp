class Solution {
public:
    int merge(vector<int> &nums, int low, int mid, int high){
        int j = mid +1;
        int count = 0;

        for(int i= low; i<= mid; i++){

            while(j <= high && (long long)nums[i] > (long long)2*nums[j]){
                j++;
            }
            count += j- (mid+1);
        }
        int start1 = low;
        int start2 = mid+1;
        vector<int> temp;
        while(start1 <= mid && start2 <= high){
            if(nums[start1] <= nums[start2]){
                temp.push_back(nums[start1++]);
            }
            else{
                temp.push_back(nums[start2++]);
            }
        }
        while(start1 <= mid){
            temp.push_back(nums[start1++]);
        }
        while(start2 <= high){
            temp.push_back(nums[start2++]);
        }

        for(int it = low; it <= high; it++){
            nums[it] = temp[it-low];
        }
        return count;
    }
    int mergeSort(vector<int> &nums, int low, int high){

        if(low >= high)
            return 0;
        int mid = low + (high-low)/2;
        int count = 0;

        count +=mergeSort(nums, low, mid);
        count += mergeSort(nums, mid+1, high);
        count += merge(nums, low, mid, high);
        return count;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums, 0, n-1);
    }
};