#include <vector>
#include <climits>
class MaximumNumberInArray{
public:
    int maximumElementInArray(const std::vector<int>& arr){
       int maximum = INT_MIN;
       for(const int& i:arr)if(i>maximum)maximum = i;
       return maximum;
    }
    int maximumElementInArray(const int arr[], int n){
       int maximum = INT_MIN;
       for(int i = 0; i < n; i++)if(arr[i]>maximum)maximum = arr[i];
       return maximum;
    }
};