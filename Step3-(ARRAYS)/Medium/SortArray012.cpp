// Sort an array of 0s, 1s and 2s

// Problem Statement: Given an array consisting of only 0s, 1s, and 2s. Write a program to in-place sort the array without using inbuilt sort functions. ( Expected: Single pass-O(N) and constant space)

// Examples
// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]

// Input: nums = [2,0,1]
// Output: [0,1,2]

// Input: nums = [0]
// Output: [0]


// | Approach       | Technique Used              | Time Complexity | Space Complexity                             | Passes Over Array          |
// | -------------- | --------------------------- | --------------- | -------------------------------------------- | -------------------------- |
// | **sortArray1** | Library Sort (`std::sort`)  | `O(N log N)`    | `O(1)` (in-place, but library may use stack) | Multiple                   |
// | **sortArray2** | Counting Sort (3 counters)  | `O(N)`          | `O(1)`                                       | 2 passes (count + rewrite) |
// | **sortArray3** | Dutch National Flag (3-way) | `O(N)`          | `O(1)`                                       | 1 pass                     |



#include <bits/stdc++.h>
using namespace std;

class MySolution {
public:
    void sortArray1(vector<int>&arr, int n){
        sort(arr.begin(), arr.end());
    }
    void sortArray2(vector<int>&arr, int n){
        int zero = 0;
        int one = 0;
        int two = 0;
        for(const int& i: arr){
            if(i==0)zero++;
            else if(i==1)one++;
            else two++;
        }
        for(int i=0;i<zero;i++)arr[i]=0;
        for(int i=zero;i<zero+one;i++)arr[i]=1;
        for(int i=zero+one;i<n;i++)arr[i]=2;
    }
    void sortArray3(vector<int>&arr, int n){
        //Dutch National Flag Algorithm
        int low = 0;
        int mid = 0;
        int high = n-1;
        while(mid<=high){
            if(arr[mid]==0){
                swap(arr[low],arr[mid]);
                low++;
                mid++;
            }else if(arr[mid]==1){
                mid++;
            }else{
                swap(arr[mid],arr[high]);
                high--;
            }
        }
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

    obj->sortArray3(arr, n);
    for(const int& i:arr)cout<<i<<" ";
    cout<<endl;

    delete obj;
    return 0;
}