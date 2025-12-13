// Palindrome Number

bool isPalindrome(int x) {

    if (x < 0)
        return false;

    int rev = 0, rem = 0;
    int temp = x;

    while (temp > 0) {
        rem = temp % 10;

        // Check if rev * 10 + rem will overflow int
        if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && rem > INT_MAX % 10))
            return false;   // reversed number would overflow, so not a palindrome

        rev = rev * 10 + rem;
        temp /= 10;
    }

    return (x == rev);
}
