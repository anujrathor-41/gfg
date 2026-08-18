class Solution {
public:
    int mySqrt(int x) {
        long long i=1;
        for( ;i<=x;i++){
            if(i*i>x){
                break;
            }
        }
        return i-1;
    }
};