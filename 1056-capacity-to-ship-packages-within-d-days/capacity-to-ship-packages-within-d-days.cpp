class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int maxWeight=-1;
        int n=weights.size();
        int totalWeight=0;
        for(int i=0;i<n;i++){
            maxWeight=max(weights[i],maxWeight);
            totalWeight+=weights[i];
        }
        int left=maxWeight;
        int right=totalWeight;
        while(left<right){
            int mid=left+(right-left)/2;
            int curr=0;
            int day=1;
            for(int i=0;i<n;i++){
                
                if((curr + weights[i])>mid){
                    curr=0;
                    day++;
                }
                curr+=weights[i];

            }
            if(day>days){
                left=mid+1;
            }else{
                right=mid;
            }

        }
        return right;
    }
};