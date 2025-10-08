#include<vector>
class LinearSearch{
    bool linearSearch(const std::vector<int>& arr, int target){
        for(const int& i : arr){
            if(i == target)return true;
        }
        return false;
    }
};