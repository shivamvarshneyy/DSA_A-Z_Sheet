// Count Reverse Pairs

// Problem Statement: Given an array of numbers, you need to return the count of reverse pairs. Reverse Pairs are those pairs where i<j and arr[i]>2*arr[j].

// Examples

// Example 1:
// Input: N = 5, array[] = {1,3,2,3,1)
// Output: 2 
// Explanation: The pairs are (3, 1) and (3, 1) as from both the pairs the condition arr[i] > 2*arr[j] is satisfied.

// Example 2:
// Input: N = 4, array[] = {3,2,1,4}
// Output: 1
// Explaination: There is only 1 pair  ( 3 , 1 ) that satisfy the condition arr[i] > 2*arr[j]


/*********************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************** */
// | Approach                   | Code Function  | Time Complexity | Space Complexity                            | Explanation                                                                                           | Pros                                                                                    | Cons                                                                      | When to Use                                                  |
// | -------------------------- | -------------- | --------------- | ------------------------------------------- | ----------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------- | ------------------------------------------------------------------------- | ------------------------------------------------------------ |
// | **Brute Force**            | `reversePair1` | **O(n²)**       | **O(1)**                                    | Checks every pair `(i, j)` with `i < j` and counts if `arr[i] > 2 * arr[j]`.                          | Very simple, easy to implement.                                                         | Extremely slow for large `n` (will TLE when `n > 10⁴`).                   | Only for very small arrays (`n ≤ 1000`).                     |
// | **Optimized (Merge Sort)** | `reversePair2` | **O(n log n)**  | **O(n)** (for temporary array during merge) | Uses modified merge sort. At each merge step, counts valid `(i, j)` pairs efficiently before merging. | Efficient, works for large arrays (`n ≤ 10⁵`). Passes LeetCode/FAANG-level constraints. | Harder to implement, needs careful handling of overflow (`2LL * arr[j]`). | Best for competitive programming & interview-level problems. |
/*********************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************** */



#include <bits/stdc++.h>
using namespace std;

class MySolution {
private: 
    void merge(vector<int>& arr, int low, int mid, int high){
        vector<int> temp;
        int i = low;
        int j = mid+1;
        while(i<=mid && j<=high){
            if(arr[i]<=arr[j]){
                temp.emplace_back(arr[i++]);
            }else{
                temp.emplace_back(arr[j++]);
            }
        }
        while(i<=mid){
            temp.emplace_back(arr[i++]);
        }
        while(j<=high){
            temp.emplace_back(arr[j++]);
        }
        for(i=low;i<=high;i++){
            arr[i] = temp[i-low];
        }
    }
    int countPairs(vector<int>& arr, int low, int mid, int high){
        int count = 0;
        int right = mid+1;
        for(int left=low;left<=mid;left++){
            while(right<=high && arr[left] > 2*arr[right])right++;
            count += (right-mid-1);
        }
        return count;
    }
    int mergeSort(vector<int>& arr, int low, int high){
        int count = 0;
        if(low >= high)return count;
        int mid = low + (high - low)/2;
        count += mergeSort(arr, low, mid);
        count += mergeSort(arr, mid+1, high);
        count += countPairs(arr, low, mid, high);
        merge(arr, low, mid, high);
        return count;
    }
public:
    int reveresePair1(vector<int>& arr, int n){
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(arr[i]>2*arr[j])count++;
            }
        }
        return count;
    }
    int reveresePair2(vector<int>& arr, int n){
        int count = mergeSort(arr, 0, n-1);
        return count;
    }
};

int main() {
    MySolution* obj = new MySolution;

    int n;
    cout << "Enter array size:" << endl;
    
    while (true) {
        cin >> n;
        if (n > 0) break;
        cout << "Invalid size. Re-enter array size: ";
    }

    vector<int> arr(n);
    cout << "Enter array elements:" << endl;
    for (int i = 0; i < n; i++) cin >> arr[i];

    int a = obj->reveresePair1(arr, n);
    cout<<"Number of reverse pair that are present in the array is: "<<a<<endl;

    int b = obj->reveresePair2(arr, n);
    cout<<"Number of reverse pair that are present in the array is: "<<b<<endl;


    delete obj;
    return 0;
}