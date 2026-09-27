class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int> original;
        unordered_map<string,int> freq;
        vector<int> result;
        
        int need=words.size();
        int k=words[0].size();
        for(int i=0;i<words.size();i++){
            original[words[i]]++;
        }
        for(int offset=0;offset<k;offset++){
            int left=offset;
            int have=0;
            freq.clear();
            for(int right=offset;right<s.size();right+=k){
                string rightword=s.substr(right,k);
                //check
                if(original.find(rightword)==original.end()){
                    have=0;
                    freq.clear();
                    left=right+k;
                    continue;
                }
                freq[rightword]++;
                have++;
                //extra copy
                while(freq[rightword]>original[rightword]){
                    string leftword=s.substr(left,k);
                    
                    freq[leftword]--;
                        have--;
                    if(freq[leftword]==0){
                        freq.erase(leftword);
                    }
                    left+=k;
                }

                //equal
                if(have==need){
                    result.push_back(left);
                    string leftword=s.substr(left,k);
                    freq[leftword]--;
                    have--;
                    if(freq[leftword]==0){
                        freq.erase(leftword);                
    
                    }
                    left+=k;
            }
        }
        }
        return result;

    }
};