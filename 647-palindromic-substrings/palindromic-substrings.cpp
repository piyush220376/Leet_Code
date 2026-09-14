class Solution {
public:
    int expand(string s, int l, int r) {
        int count=0;
        while(l >= 0 && r < s.length() && s[l] == s[r]) {
            count++;
            l--;
            r++;
        }

        return count;
    }   
    int countSubstrings(string s) {
        int n=s.length();
        int count=0;
        for(int i=0;i<n;i++){
            //odd
            count+=expand(s,i,i);
            count+=expand(s,i-1,i);
        }
        return count;

    }
};