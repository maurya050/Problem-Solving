/**
 * @param {number[]} nums1
 * @param {number} m
 * @param {number[]} nums2
 * @param {number} n
 * @return {void} Do not return anything, modify nums1 in-place instead.
 */
var merge = function(nums1, m, nums2, n) {
    let l1 = m-1;
    let l2 = n-1;
    let r = m+n-1;

    while(l2 >= 0 && l1 >=0){
        if(nums2[l2] >= nums1[l1]){
            nums1[r] = nums2[l2];
            r--;
            l2--;
        }
        else{
            nums1[r] = nums1[l1];
            r--;
            l1--;
        }
    }
    while(l2 >= 0){
        nums1[r] = nums2[l2];
        r--;
        l2--;
    }
};