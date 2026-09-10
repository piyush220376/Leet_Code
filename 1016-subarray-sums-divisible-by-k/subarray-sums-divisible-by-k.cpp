class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        int prefixsum=0;
        int count=0;
        unordered_map<int,int> remain;
        remain[0]++;
        for(int i=0;i<n;i++){
            prefixsum+=nums[i];
            int rem=prefixsum%k;
            if(rem<0){
                rem+=k;
            }
            if(remain.find(rem)!=remain.end()){
                count+=remain[rem];
            }
            remain[rem]++;
        }
        return count;            
    }
};