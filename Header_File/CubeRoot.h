#include <cmath>
class CubeRoot {
public:
    static double cubeRoot(int n) {
        if (n == 0 || n == 1) return n;

        bool isNegative = (n < 0);
        double num = fabs(n);

        double low = 0, high = num;
        double limit = 1e-6;

        while ((high - low) > limit) {
            double mid = low + (high - low) / 2.0;
            long double cube = mid * mid * mid;

            if (fabs(cube - num) < limit)
                return isNegative ? -mid : mid;
            else if (cube > num)
                high = mid;
            else
                low = mid;
        }

        double result = low + (high - low) / 2.0;
        return isNegative ? -result : result;
    }
};
