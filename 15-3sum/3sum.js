/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function(nums) {
    let ans = [];
    let n = nums.length;
    nums.sort((a, b) => (a - b));
    
    for(let i =0; i <n-2; i++){
        if(i > 0 && (nums[i-1] === nums[i]))
            continue;
        let left = nums[i];
        j = i+1;
        k = n-1;
        while(j < k){
            let sum = nums[i] + nums[j] + nums[k];
            if(sum == 0){
                ans.push([nums[i], nums[j], nums[k]]);
                j++;
                k--;

                while(j < k && nums[j-1] === nums[j]) j++;

                while(j < k && nums[k] == nums[k+1]) k--;
            }
            else if(sum < 0){
                j++;
            }
            else{
                k--;
            }
        }
    }
    return ans;
};