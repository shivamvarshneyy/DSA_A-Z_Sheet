#include <vector>

template <typename T>
class PeakElement{
public:
    static int peakElement(const std::vector<T>& arr){
        int n = arr.size();
        int low = 1;
        int high = n-2;
        if(n==1)return 0;
        else if(arr[0]>arr[1])return 0;
        else if(arr[n-2] < arr[n-1])return n-1;
        else{
            while(low <= high){
                int mid = low + (high - low)/2;
                if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1])return mid;
                else if(arr[mid-1] < arr[mid] && arr[mid] < arr[mid+1])low = mid + 1;
                else high = mid - 1;
            }
        }
        return -1;
    }

    static int arrayPeakElement(const int* arr, int n){
        int low = 1;
        int high = n-2;
        if(n==1) return 0;
        else if(arr[0]>arr[1]) return 0;
        else if(arr[n-2] < arr[n-1]) return n-1;
        else{
            while(low <= high){
                int mid = low + (high - low)/2;
                if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1])return mid;
                else if(arr[mid-1] < arr[mid] && arr[mid] < arr[mid+1])low = mid + 1;
                else high = mid - 1;
            }
        }
        return -1;
    }
};