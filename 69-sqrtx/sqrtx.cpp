class Solution {
public:
    int mySqrt(int x) {
        if(x<2){
            return x;
        }
        int left=0;
        int right=x;
        while(left<=right){
            long long mid=left+(right-left)/2;
            if(mid*mid==x){
                return mid;
            }else if(mid*mid>x){
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return round(right);

    }
};