/**
 * @param {number} rowIndex
 * @return {number[]}
 */
var getRow = function(rowIndex) {
    let ans = [];
    let last;
    for(let i = 1; i <= rowIndex+1; i++){
        let arr = Array(i).fill(1);
        for(let j=1 ; j<i-1; j++){
            arr[j] = last[j] + last[j-1];
        }
        last = arr;
        ans.push(last);
    }
    console.log(ans);
    return ans[rowIndex];
};