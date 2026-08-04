class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefixSum;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            prefixSum.push_back(sum);
        }
        for(int i=0;i<n;i++){
            int rightSum=prefixSum[n-1]-prefixSum[i];
            int leftSum=(i==0)?0:prefixSum[i-1];
            if(leftSum==rightSum){
                return i;
            }

        }
        return -1;
    }
};