/**
 * @param {number[][]} intervals
 * @return {number[][]}
 */
var merge = function(intervals) {
    intervals.sort((a,b) =>(a[0] - b[0]));
    let ans = [];
    let n = intervals.length;
    let last = intervals[0];
    for(let i = 1; i<n; i++){
        if(last[1]>= intervals[i][0]){
            if(last[1] < intervals[i][1])
                last[1] = intervals[i][1];
        }
        else{
            ans.push(last);
            last = intervals[i];
        }
    }
    ans.push(last);
    return ans;
};