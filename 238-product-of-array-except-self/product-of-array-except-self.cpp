class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> result(n);
        
        vector<int> prefixP(n);
        vector<int> suffixP(n);
        int product=1;
        for(int i=0;i<n;i++){
            product *=nums[i];
            prefixP[i]=product;
        }
        product=1;
        for(int i=n-1;i>=0;i--){
            product*=nums[i];
            suffixP[i]=product;
        }
        for(int i=0;i<n;i++){
            if(i==0){
                result[i]=suffixP[i+1];
            }else if (i==n-1){
                result[i]=prefixP[i-1];
            }
            else{
                result[i]=prefixP[i-1]*suffixP[i+1];
            }
        }
        return result;
    }
};