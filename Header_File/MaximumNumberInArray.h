#include <vector>
#include <climits>
template <typename T>
class MaximumNumberInArray{
public:
    static T maxElement(const std::vector<T>& arr){
       if (arr.empty()) throw std::invalid_argument("Array cannot be empty");
       T maximum = std::numeric_limits<T>::lowest();
       for(const T& i:arr)if(i>maximum)maximum = i;
       return maximum;
    }
    static T maxElement(const T arr[], int n){
       if (arr.empty()) throw std::invalid_argument("Array cannot be empty");
       T maximum = std::numeric_limits<T>::lowest();
       for(int i = 0; i < n; i++)if(arr[i]>maximum)maximum = arr[i];
       return maximum;
    }
};