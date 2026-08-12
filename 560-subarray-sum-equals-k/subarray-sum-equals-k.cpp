class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> prefix(n,0);
        int count=0;
        unordered_map<int,int> mp;
        int sum=0; 
        for(int i=0;i<n;i++){
            sum+=nums[i];
            prefix[i]=sum;
        }
        for(int j=0;j<n;j++){
            if(prefix[j]==k){
                count++;
            }
            
            int val = prefix[j] - k;
            if(mp.find(val)!=mp.end()){
                count+=mp[val];
            }
            mp[prefix[j]]++;
        }
        return count;
    }
    
};