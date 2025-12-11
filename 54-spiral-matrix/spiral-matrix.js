/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var spiralOrder = function(matrix) {
    let n = matrix.length;
    let m = matrix[0].length;
    let ans = [];
    let left = 0, top = 0, right = m-1, bottom = n-1;

    while(left <= right && top <= bottom){

        for(let it = left; it <= right; it++){
            ans.push(matrix[top][it])
        }
        top++;
        for(let j = top; j <= bottom; j++){
            ans.push(matrix[j][right]);
        }
        right--;
        if(top <= bottom){
            for(let it = right; it >= left; it--){
                ans.push(matrix[bottom][it])
            }
            bottom--;
        }
        if(left <= right ){
            for(let j = bottom ; j >= top; j--){
                ans.push(matrix[j][left])
            }
            left++;
        } 

    }
    return ans;
};
