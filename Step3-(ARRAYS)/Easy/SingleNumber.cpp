// Find the number that appears once, and the other numbers twice

// Problem Statement: Given a non-empty array of integers arr, every element appears twice except for one. Find that single one.

// Examples
// Example 1:
// Input Format: arr[] = {2,2,1}
// Result: 1
// Explanation: In this array, only the element 1 appear once and so it is the answer.


// Example 2:
// Input Format: arr[] = {4,1,2,1,2}
// Result: 4
// Explanation: In this array, only element 4 appear once and the other elements appear twice. So, 4 is the answer.

#include <bits/stdc++.h>
using namespace std;

int singleNumber1(vector<int>& arr) {
    int count = 0;
    for (int num : arr) {
        count = 0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==num)count++;
        }
        if(count == 1)return num;
        else count = 0;
    }
    return -1;
}

int singleNumber2(vector<int>& arr) {
    unordered_map<int,int> m;
    for(int i:arr){
        m[i]++;
    }
    for(auto i:m){
        if(i.second==1)return i.first;
    }
    return -1;
}

int singleNumber3(vector<int>& arr) {
    int result = 0;
    for (int num : arr) {
        result ^= num;
    }
    return result;
}

int main() {
    int n;
    cout << "Enter array size:" << endl;
    
    while (true) {
        cin >> n;
        if (n > 0) break;
        cout << "Invalid size. Re-enter array size: ";
    }

    vector<int> arr(n);
    cout << "Enter array elements:" << endl;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result1 = singleNumber1(arr);
    cout << "The single number is: " << result1 << endl;

    int result2 = singleNumber1(arr);
    cout << "The single number is: " << result2 << endl;

    int result3 = singleNumber1(arr);
    cout << "The single number is: " << result3 << endl;

    return 0;
}