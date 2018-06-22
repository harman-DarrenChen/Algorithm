// Weekly Contest 84
/*
Given a binary matrix A, we want to flip the image horizontally, then invert it, and return the resulting image.

To flip an image horizontally means that each row of the image is reversed.  For example, flipping [1, 1, 0] horizontally results in [0, 1, 1].

To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0. For example, inverting [0, 1, 1] results in [1, 0, 0].

Example 1:

Input: [[1,1,0],[1,0,1],[0,0,0]]
Output: [[1,0,0],[0,1,0],[1,1,1]]
Explanation: First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
Then, invert the image: [[1,0,0],[0,1,0],[1,1,1]]
Example 2:

Input: [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
Output: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
Explanation: First reverse each row: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]].
Then invert the image: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
Notes:

1 <= A.length = A[0].length <= 20
0 <= A[i][j] <= 1
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** flipAndInvertImage(int** A, int ARowSize, int *AColSizes, int** columnSizes, int* returnSize) {
    if (!ARowSize) {
        *returnSize = 0;
        *columnSizes = NULL;
        return NULL;
    }
    *returnSize = ARowSize;
    int** ret = (int**) malloc (sizeof(int*) * *returnSize);
    *columnSizes = (int *) malloc (sizeof(int) * *returnSize);
    for (int i = 0; i < ARowSize; i++) {
        (*columnSizes)[i] = AColSizes[i];
        ret[i] = (int*) malloc (sizeof(int) * (*columnSizes)[i]);
        for (int j = 0; j <= (AColSizes[i] - 1) / 2; j++) {
            if (!(A[i][j] ^ A[i][AColSizes[i] - 1 - j])) {
                ret[i][j] = !A[i][j];
                if (j != AColSizes[i] - 1 - j) {
                    ret[i][AColSizes[i] - 1 - j] = !A[i][AColSizes[i] - 1 - j];
                } else {
                    ret[i][AColSizes[i] - 1 - j] = A[i][AColSizes[i] - 1 - j];
                }
            } else {
                ret[i][j] = A[i][j];
                ret[i][AColSizes[i] - 1 - j] = A[i][AColSizes[i] - 1 - j];
            }
        }
        if (AColSizes[i] % 2) {
            ret[i][AColSizes[i] / 2] = !A[i][AColSizes[i] / 2];
        }
    }
    return ret;
}
