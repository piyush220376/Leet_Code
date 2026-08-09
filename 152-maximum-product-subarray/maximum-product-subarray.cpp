class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int Amin=nums[0];
        int Amax=nums[0];
        int m=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0){
                swap(Amin,Amax);
            }
            Amin=min(nums[i],nums[i]*Amin);
            Amax=max(nums[i],nums[i]*Amax);
            m=max(m,Amax);
            
        }
        return m;
    }
};