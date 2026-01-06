// Longest Valid Parentheses

int longestValidParentheses(char* s) {
    int stack[100000];
    int top = -1;
    int maxLen = 0;

    stack[++top] = -1;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') {
            stack[++top] = i;
        } else {
            top--;

            if (top < 0) {
                stack[++top] = i;
            } else {
                int len = i - stack[top];
                if (len > maxLen)
                    maxLen = len;
            }
        }
    }

    return maxLen;
}
