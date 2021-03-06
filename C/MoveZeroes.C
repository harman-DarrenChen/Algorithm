// Easy Collection
// Bloomberg
// Facebook
// Google
// Array and String

/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.

*/

void moveZeroes(int* nums, int numsSize) {
    int i = 0, j = 0;
    while (i <= numsSize && j < numsSize) {
        if (i == numsSize) {
            nums[j] = 0;
            j++;
            continue;
        }
        if (nums[i] == 0) {
            i++;
        } else {
            nums[j++] = nums[i++];
        }
    }
}
