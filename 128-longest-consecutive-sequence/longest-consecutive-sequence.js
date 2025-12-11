/**
 * @param {number[]} nums
 * @return {number}
 */
var longestConsecutive = function(nums) {
    let ans = 0; 
    let mp = new Set(nums);

    for(let val of mp){
        if(!mp.has(val-1)){
            let newv = val;
            let count = 0;
            while(mp.has(newv)){
                count++;
                newv++;
            }
            ans = Math.max(ans, count);
        }
    }
    return ans;
};