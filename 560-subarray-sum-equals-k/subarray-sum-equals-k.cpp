class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0;
        unordered_map<int,int> freq;
        vector<int> prefix(n);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        for(int i=0;i<n;i++){
            int sum=prefix[i]-k;
            if(prefix[i]==k){
                count++;
            }
            if(freq.find(sum)!=freq.end()){
                count+=freq[sum];
            }
            freq[prefix[i]]++;
        }
        return count;
    }
};