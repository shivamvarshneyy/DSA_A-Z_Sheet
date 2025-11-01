// Search Single Element in a sorted array

// Problem Statement: Given an array of N integers. Every number in the array except one appears twice. Find the single number in the array.

// Pre-requisite: Binary Search Algorithm

// Examples

// Example 1:
// Input Format: arr[] = {1,1,2,2,3,3,4,5,5,6,6}
// Result: 4
// Explanation: Only the number 4 appears once in the array.

// Example 2:
// Input Format: arr[] = {1,1,3,5,5}
// Result: 3
// Explanation: Only the number 3 appears once in the array.

//------------------------------------------------------------------------------------------------------------------------------------------------------
// | Method           | Time Complexity | Space Complexity | Notes                                                                                     |
// | ---------------- | --------------- | ---------------- | ----------------------------------------------------------------------------------------- |
// | `singleElement0` | O(N)            | O(N)             | Uses a hash map/unordered_map to count frequencies. Extra space needed for map.           |
// | `singleElement1` | O(N)            | O(1)             | Uses XOR trick. Very efficient and constant space. Works for unsorted arrays too.         |
// | `singleElement2` | O(N)            | O(1)             | Linear scan with boundary checks. Works only for sorted arrays with pairs.                |
// | `singleElement3` | O(log N)        | O(1)             | Binary search method with index parity checks. More complex, but works for sorted arrays. |
// | `singleElement4` | O(log N)        | O(1)             | Optimized binary search. Cleanest, safest, recommended for interviews.                    |
//------------------------------------------------------------------------------------------------------------------------------------------------------


#include <bits/stdc++.h>
using namespace std;

class MySolution {
public:
    int singleElement0(vector<int>& arr, int n){
        unordered_map<int,int> mp;
        for(const int& i: arr)mp[i]++;
        for(const auto& i: mp)if(i.second==1)return i.first;
        return 0;
    }
    
    int singleElement1(vector<int>& arr, int n){
        int ans = 0;
        for(const int& i: arr)ans ^= i;
        return ans;
    }

    int singleElement2(vector<int>& arr, int n){
        if(n==1)return arr[0];
        else if(arr[0]!=arr[1])return arr[0];
        else if(arr[n-1]!=arr[n-2])return arr[n-1];
        else{
            for(int i=1;i<n-1;i++){
                if(arr[i-1] != arr[i] && arr[i] != arr[i+1])return arr[i];
            }
        }
        return 0;
    }

    int singleElement3(vector<int>& arr, int n){
        int ans = 0;
        int s = 1;
        int e = n-2;
        int mid = s + (e-s)/2;
        if(n==1)return arr[0];
        else if(arr[0]!=arr[1])return arr[0];
        else if(arr[n-1]!=arr[n-2])return arr[n-1];
        else{
            while(s<=e){
                if(arr[mid-1] != arr[mid] && arr[mid] != arr[mid+1])return arr[mid];
                else  if((arr[mid-1] == arr[mid] && (mid-1)%2==0) || (arr[mid+1] == arr[mid] && (mid)%2==0))s = mid+1;
                else e = mid-1;
                mid = s+(e-s)/2;
            }
        }
        return ans;
    }
    int singleElement4(vector<int>& arr, int n){
        int s = 0;
        int e = n-1;
        int mid = s + (e-s)/2;
        while(s<e){
            if(mid%2==1)mid--;
            if(arr[mid] != arr[mid+1]){
                e = mid;
            }else{
                s+=2;
            }
            mid = s+(e-s)/2;
        }
        return arr[s];
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

    int z = obj->singleElement0(arr, n);
    cout<<"Single Element present in array is : "<<z<<endl;

    int a = obj->singleElement1(arr, n);
    cout<<"Single Element present in array is : "<<a<<endl;

    int b = obj->singleElement2(arr, n);
    cout<<"Single Element present in array is : "<<b<<endl;

    int c = obj->singleElement3(arr, n);
    cout<<"Single Element present in array is : "<<c<<endl;

    int d = obj->singleElement4(arr, n);
    cout<<"Single Element present in array is : "<<d<<endl;

    delete obj;
    return 0;
}