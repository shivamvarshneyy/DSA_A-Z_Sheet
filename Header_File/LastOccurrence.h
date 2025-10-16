#include<vector>

template<typename T>
class LastOccurrence{
public: 
    static int lastOccurrence(const std::vector<T>& arr, const T target){
        int n = arr.size();
        int low = 0;
        int high = n-1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(arr[mid] > target){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        if(high < 0 || arr[high] != target)return -1;
        return high;
    }
    static int lastOccurrence(const T *arr, int n, const T target){
        int low = 0;
        int high = n-1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(arr[mid] > target){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        if(high < 0 || arr[high] != target)return -1;
        return high;
    }
};

