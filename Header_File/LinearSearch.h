#include<vector>
template <typename T>
class LinearSearch{
public:
    static bool search(const std::vector<T>& arr, T target){
        for(const T& i : arr){
            if(i == target)return true;
        }
        return false;
    }
};