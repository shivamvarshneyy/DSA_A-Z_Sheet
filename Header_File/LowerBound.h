#include <vector>
template <typename T>
class LowerBound{
public:
    static int lowerBound(const std::vector<T>& arr, T target){
        int n = arr.size();
        int low = 0;
        int high = n-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(arr[mid] < target)low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
    static int arrayLowerBound(const T *arr, int n, T target){
        int low = 0;
        int high = n-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(arr[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};