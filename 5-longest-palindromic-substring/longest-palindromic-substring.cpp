class Solution {
public:

    int expand(string s, int l, int r) {
        while(l >= 0 && r < s.length() && s[l] == s[r]) {
            l--;
            r++;
        }

        return r - l - 1;
    }

    string longestPalindrome(string s) {
        int n = s.length();
        int len = 0;
        int start = 0;

        for(int i = 0; i < n; i++) {

            // odd
            int a = expand(s, i, i);

            if(a > len) {
                len = a;
                start = i - (a - 1) / 2;
            }

            // even
            a = expand(s, i - 1, i);

            if(a > len) {
                len = a;
                start = i - a / 2;
            }
        }

        return s.substr(start, len);
    }
};