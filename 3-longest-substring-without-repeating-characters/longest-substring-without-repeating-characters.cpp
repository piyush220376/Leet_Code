class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int ans=1;
        int n=s.length();
        if(n==0){
            return 0;
        }
        unordered_map<char,int> freq;
        freq[s[left]]++;
        for(int right=1;right<n;right++){
            freq[s[right]]++;
            while(freq[s[right]]>1){   
                freq[s[left]]--;
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};