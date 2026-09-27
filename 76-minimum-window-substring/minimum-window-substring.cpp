class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> freqs;
        unordered_map<char,int> freqt;
        int left=0;
        int len=INT_MAX;
        int start=0;
        
        for(int i=0;i<t.size();i++){
            freqt[t[i]]++;
        }
        int need=freqt.size();
        int have=0;

        for(int right=0;right<s.size();right++){
            if(freqt.find(s[right])!=freqt.end()){
                freqs[s[right]]++;
                if(freqs[s[right]]==freqt[s[right]]){
                    have++;
                }
            }
            while(have==need){
                int len1=right-left+1;
                if(len>len1){
                    len=len1;
                    start=left;
                }
                if(freqt.find(s[left])!=freqt.end()){
                    freqs[s[left]]--;
                    if(freqs[s[left]]<freqt[s[left]]){
                        have--;
                    }
                }
                left++;
            }
        }
        if(len==INT_MAX){
            return "";
        }

        return s.substr(start,len);
    }
};