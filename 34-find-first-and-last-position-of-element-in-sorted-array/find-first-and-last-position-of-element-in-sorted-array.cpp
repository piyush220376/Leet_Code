class Solution {
public:
    int lowerBound(vector<int> & arr,int target){
        int start=0;
        int end=arr.size()-1;
        int ans=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(arr[mid]>=target){
                end=mid-1;
                ans=mid;
            }else{
                start=mid+1;
            }
            
        }
        return ans;
    }
    int upperBound(vector<int> & arr,int target){
        int start=0;
        int end=arr.size()-1;
        int ans=arr.size()-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(arr[mid]>target){
                end=mid-1;
                ans=mid-1;
            }else{
                start=mid+1;
            }
            
        }
        return ans;

    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int lower_bound=lowerBound(nums,target);
        int upper_bound=upperBound(nums,target);
        if(lower_bound==-1 || nums[lower_bound]!=target){
            return {-1,-1};
        }
        ans.push_back(lower_bound);
        ans.push_back(upper_bound);
        return ans;
    }
};