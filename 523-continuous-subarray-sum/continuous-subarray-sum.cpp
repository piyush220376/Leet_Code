class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
int n=nums.size();
        int prefixsum=0;
        unordered_map<int,int> remain;
        remain[0]=-1;
        for(int i=0;i<n;i++){
            prefixsum+=nums[i];
            int rem=prefixsum%k;
            if(rem<0){
                rem+=k;
            }
            if(remain.find(rem)!=remain.end()){
                if((i-remain[rem])>=2){
                return true;
                }
            }else{
            remain[rem]=i;
            }
        }
        return false;

    }
};