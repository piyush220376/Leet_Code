class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n=dist.size();
        int ans=-1;
        int left=1;
        int right=10000000;
        while(left<=right){
            int mid=left+(right-left)/2;
            double curr=0;
            for(int i=0;i<n;i++){
                int remainder=(dist[i]%mid)? 1 : 0;
                if(i==n-1){ 
                curr+=(double)dist[i]/mid;

                }else{
                curr+=(dist[i]/mid)+remainder;

                }
            }
            if(curr<=hour){
                ans=mid;
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return ans;

    }
};