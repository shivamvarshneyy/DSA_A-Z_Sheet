//Find the Majority Element that occurs more than N/2 times

// Problem Statement: Given an array of N integers, write a program to return an element that occurs more than N/2 times in the given array. You may consider that such an element always exists in the array.

// Examples

// Example 1:
// Input Format: N = 3, nums[] = {3,2,3}
// Result: 3
// Explanation: When we just count the occurrences of each number and compare with half of the size of the array, you will get 3 for the above solution. 

// Example 2:
// Input Format:  N = 7, nums[] = {2,2,1,1,1,2,2}
// Result: 2
// Explanation: After counting the number of times each element appears and comparing it with half of array size, we get 2 as result.

// Example 3:
// Input Format:  N = 10, nums[] = {4,4,2,4,3,4,4,3,2,4}
// Result: 4


// | Approach             | Technique Used             | Time Complexity | Space Complexity | Notes                        |
// | -------------------- | -------------------------- | --------------- | ---------------- | ---------------------------- |
// | **majorityElement1** | Hash Map (frequency count) | `O(N)`          | `O(N)`           | Simple, but uses extra space |
// | **majorityElement2** | Sorting + Counting         | `O(N log N)`    | `O(1)`           | No extra space, but slower   |
// | **majorityElement3** | Moore’s Voting Algorithm   | `O(N)`          | `O(1)`           | Best approach, single pass   |


#include <bits/stdc++.h>
using namespace std;

class MySolution {
public:
    int majorityElement1(vector<int>& arr, int n){
        unordered_map<int, int> mp;
        for(const int& i:arr)mp[i]++;
        for(const auto& i:mp){
            if(i.second>n/2)return i.first;
        }
        return -1;
    }
    int majorityElement2(vector<int>& arr, int n){
        sort(arr.begin(), arr.end());
        int count = 1;
        for(int i=1;i<n;i++){
            if(arr[i-1] == arr[i])count++;
            else{
                if(count>n/2)return arr[i-1];
                count = 1;
            }
        }
        if(count>n/2)return arr[n-1];
        return -1;
    }
    int majorityElement3(vector<int>& arr, int n){
        //Moore's Voting Algorithm
        int element = arr[0];
        int count = 1;
        for(int i=1;i<n;i++){
            if(count == 0){
                element = arr[i];
                count = 1;
            }else if(arr[i]==element)count++;
            else count--;
        }
        return element;
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

    int a = obj->majorityElement3(arr, n);
    cout<<"Majority Element is: "<<a<<endl;

    delete obj;
    return 0;
}