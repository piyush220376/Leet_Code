class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> freq;
        unordered_map<char,int> G;
        vector<int> result;
        for(int i=0;i<p.length();i++){
            G[p[i]]++;
        }
        int left=0;
        for(int i=0;i<s.length();i++){
            freq[s[i]]++;
            if(i-left+1>p.length()){
                freq[s[left]]--;
                if(freq[s[left]]==0){
                    freq.erase(s[left]);
                }
                left++;
            }
            
            if(freq==G){
                result.push_back(left);
            }
        }
        return result;
    }
};