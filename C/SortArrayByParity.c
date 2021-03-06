// Weekly Contest 102
/*
Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.

You may return any answer array that satisfies this condition.



Example 1:

Input: [3,1,2,4]
Output: [2,4,3,1]
The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.


Note:

1 <= A.length <= 5000
0 <= A[i] <= 5000
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* A, int ASize, int* returnSize) {
    *returnSize = ASize;
    int* ret = (int*) malloc (sizeof(int) * ASize);
    int startIndex = 0;
    int endIndex = ASize - 1;
    for (int i = 0.; i < ASize; i++) {
        if (A[i] % 2 == 0) {
            ret[startIndex++] = A[i];
        } else {
            ret[endIndex--] = A[i];
        }
    }
    return ret;
}
