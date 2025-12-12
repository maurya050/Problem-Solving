/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[][]}
 */
var fourSum = function(nums, target) {
    let ans = [];
    let n = nums.length;
    if(nums == null || n < 4){
        return ans;
    }
    nums.sort((a,b) => (a-b));

    for(let i =0; i<n-3; i++){
        if(i > 0 && nums[i] === nums[i-1])
            continue;
        
        for(let j=i+1; j<n-2; j++){
            if(j > i+1 && nums[j] === nums[j-1]){
                continue;
            }
            let left = j+1;
            let right = n-1;
            while(left < right){
                let sum = nums[i] + nums[j] + nums[left] + nums[right];

                if(sum  === target){
                    ans.push([nums[i], nums[j], nums[left], nums[right]]);
                    left++, right--;

                    while(left < right && nums[left-1] === nums[left]) left++;

                    while(left < right && nums[right] === nums[right+1]) right--;

                }
                else if(sum > target){
                    right--;
                }
                else{
                    left++;
                }
            }
        }
    }
    return ans;
};