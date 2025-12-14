/**
 * @param {number[]} nums
 * @return {number}
 */
var findDuplicate = function(nums) {
    nums.sort((a,b) => (a-b));
    let n = nums.length;
    for(let it = 0; it < n; it++){

        if(nums[it] == nums[it-1])
            return nums[it];
    }
    
};