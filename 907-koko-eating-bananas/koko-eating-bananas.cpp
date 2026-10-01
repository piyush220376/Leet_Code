class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile=-1;
        int n=piles.size();
        for(int i=0;i<n;i++){
            maxPile=max(maxPile,piles[i]);
        }
        int end=maxPile;
        int start=1;
        while(start<end){
            int hr=0;
            int mid=start+(end-start)/2;
            for(int i=0;i<n;i++){
                hr+=(piles[i]/mid);
                if(piles[i]%mid!=0){
                    hr++;
                }
            }
            if(hr>h){
                start=mid+1;
            }else{
                end=mid;
            }
        }
        return end;
    }
};