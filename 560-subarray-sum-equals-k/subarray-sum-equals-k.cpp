class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> prefixSum;
        unordered_map<int,int> freq;

        int n=nums.size();
        int sum=0;
        int count=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            prefixSum.push_back(sum);
        }

        for(int j=0;j<n;j++){
            if(prefixSum[j]==k){
                count++;
            }
            int val=prefixSum[j]-k;
            if(freq.find(val)!=freq.end()){
            count+=freq[val];
            }if(freq.find(prefixSum[j])==freq.end()){
                freq[prefixSum[j]]=0;
            }
            freq[prefixSum[j]]++;
        }
        return count;

    }
};