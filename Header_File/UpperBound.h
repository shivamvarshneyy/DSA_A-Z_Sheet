#include <vector>

template<typename T>
class UpperBound{
public:
    static int upperBound(const std::vector<T>& arr, T target){
        int n = arr.size();
        int low = 0;
        int high = n-1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(arr[mid] > target)high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
    static int arrayUpperBound(const T *arr, int n, T target){
        int low = 0;
        int high = n-1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(arr[mid] > target)high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};