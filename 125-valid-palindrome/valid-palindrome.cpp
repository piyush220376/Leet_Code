class Solution {
public:
    bool isPalindrome(string s) {
        
        for(int i=0;i<s.length();){
            if(!isalnum(s[i])){
                s.erase(i,1);
                continue;
            }
            s[i]=tolower(s[i]);
            i++;

        }
        int i=0;
        int j=s.length()-1;
        while(i<j){
            if(s[i++]!=s[j--]){
                return false;
            }
        }
        return true;

    }
};