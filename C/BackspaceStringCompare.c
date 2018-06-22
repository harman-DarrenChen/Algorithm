// Weekly Contest 87
/*
Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.



Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".
Example 2:

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".
Example 3:

Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".
Example 4:

Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".


Note:

1 <= S.length <= 200
1 <= T.length <= 200
S and T only contain lowercase letters and '#' characters.
*/

bool backspaceCompare(char* S, char* T) {
    if (strcmp(S, T) == 0) {
        return true;
    }
    int lengthS = strlen(S);
    int lengthT = strlen(T);
    char* actualS = (char *) malloc (sizeof(char) * lengthS);
    char* actualT = (char *) malloc (sizeof(char) * lengthT);
    int indexActualS = 0;
    int indexActualT = 0;
    for (int i = 0; i < lengthS; i++) {
        if (S[i] != '#') {
            actualS[indexActualS++] = S[i];
        } else {
            if (indexActualS != 0) {
                indexActualS--;
            }
        }
    }
    for (int i = 0; i < lengthT; i++) {
        if (T[i] != '#') {
            actualT[indexActualT++] = T[i];
        } else {
            if (indexActualT != 0) {
                indexActualT--;
            }
        }
    }
    if (indexActualS != indexActualT) {
        return false;
    }
    actualS[indexActualS] = '\0';
    actualT[indexActualT] = '\0';
    if (strcmp(actualS, actualT) == 0) {
        return true;
    } else {
        return false;
    }
}
