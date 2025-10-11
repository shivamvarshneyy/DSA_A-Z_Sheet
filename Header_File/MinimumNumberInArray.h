#include <vector>
#include <limits>

template <typename T>
class MinimumNumberInArray
{
public:
    static T minimum(const std::vector<T>& arr){
        T res = std::numeric_limits<T>::max();
        for(const T& i : arr){
            if(i<res)res = i;
        }
        return res;
    }
    static T array_minimum(const T* arr, int size){
        T res = std::numeric_limits<T>::max();
        for(int i = 0; i < size; i++){
            if(arr[i]<res)res = arr[i];
        }
        return res;
    }
};
