// | Operation | Complexity   |
// | --------- | ------------ |
// | Time      | **O(log n)** |
// | Space     | **O(1)**     |


#include <vector>

template <typename T>
class BinarySearch {
public:
    static bool binarySearch(const std::vector<T>& arr, const T& target) {
        int low = 0;
        int high = arr.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target) return true;
            else if (arr[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
};
