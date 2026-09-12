class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum=0,maxCur=0;
        int minSum=0,minCur=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            maxCur+=nums[i];
            maxSum=max(maxSum,maxCur);
            if(maxCur<0){
                maxCur=0;
            }

            minCur+=nums[i];
            minSum=min(minCur,minSum);
            if(minCur>0){
                minCur=0;
            }
        }

        return max(abs(minSum),abs(maxSum));    
    }
};