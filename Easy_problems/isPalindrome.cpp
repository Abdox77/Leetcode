class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        long long reversed = 0;
        long long tmp = x;
        int digit = tmp % 10;

        while(tmp != 0)
        {
            reversed = reversed * 10 + digit;
            tmp /= 10;
            digit = tmp % 10;
        }
        if (reversed == x)
            return true;
        return (false);
    }
};
