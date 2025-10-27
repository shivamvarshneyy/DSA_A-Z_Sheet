#include <cmath>
class SquareRoot{
    public:
    static double squareRoot(int n){
        if (n == 0 || n == 1) return n;
        double low = 0;
        double high = n;
        double limit = 1e-6;
        while((high - low) > limit){
            double mid = low + (high-low)/2.0;
            if (fabs(mid * mid - n) < limit)return mid;
            else if(mid*mid > n)high = mid;
            else low = mid;
        }
        return high;
    }
};