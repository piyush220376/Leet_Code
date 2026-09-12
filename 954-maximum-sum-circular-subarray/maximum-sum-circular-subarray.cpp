class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int minSum=nums[0];
        int maxSum=nums[0];
        int sum=0;
        int sum1=0;
        int n=nums.size();
        int totalSum=0;

        for(int i=0;i<n;i++){
            sum+=nums[i];
            totalSum+=nums[i];
            maxSum=max(sum,maxSum);
            if(sum<0){
                sum=0;
            }

            sum1+=nums[i];
            minSum=min(sum1,minSum);
            if(sum1>0){
                sum1=0;
            }
        }
        if(maxSum<0){
            return maxSum;
        }
        return max(maxSum,totalSum-minSum);    
    }
};