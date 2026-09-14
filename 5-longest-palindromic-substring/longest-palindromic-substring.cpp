class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        string result="";
        for(int i=0;i<n;i++){
            //odd
            int l=i;
            int r=i;
            string a="";
            while(l>=0 && r<n && s[l]==s[r]){
                if(l==r){
                    a=s[l];
                }else{
                    a=s[l]+a+s[r];
                }
                l--;
                r++;
            }
            if(result.length()<a.length()){
                result=a;
            }


            //even
            l=i-1;
            r=i;
            a="";
            while(l>=0 && r<n && s[l]==s[r]){
                a=s[l]+a+s[r];
                l--;
                r++;
            }
            if(result.length()<a.length()){
                result=a;
            }
    }
    return result;
    }
};