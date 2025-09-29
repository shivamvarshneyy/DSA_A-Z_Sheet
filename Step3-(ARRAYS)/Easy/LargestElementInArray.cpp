#include<bits/stdc++.h>
#include"../../Header_File/MaximumNumberInArray.h"
using namespace std;
class MySolution{
public:
    int largestElementMethod1(vector<int>& arr, int n){
        int maximum = *max_element(arr.begin(), arr.end());
        return maximum;
    }
    // Time Complexity -> O(N);
    // Space Complexity -> O(1);

    int largestElementMethod2(vector<int>& arr, int n){
       int maximum = INT_MIN;
       for(const int& i:arr)maximum = max(maximum, i);
       return maximum;
    }
    // Time Complexity -> O(N);
    // Space Complexity -> O(1);

    int largestElementMethod3(vector<int>& arr, int n){
       sort(arr.begin(), arr.end());
       return arr[n-1];
    }
    // Time Complexity -> O(NlogN);
    // Space Complexity -> O(1);

    int largestElementMethod4(vector<int>& arr){
       MaximumNumberInArray maximumNum;
       return maximumNum.maximumElementInArray(arr);
    }
    // Time Complexity -> O(N);
    // Space Complexity -> O(1);
};


int main(){
   MySolution* obj = new MySolution;
   int n;
   cout<<"Enter a array size"<<endl;
   cin>>n;
   vector<int> arr(n);
   cout<<"Enter array elements"<<endl;
   for(int i=0;i<n;i++)cin>>arr[i];
   cout<<"Largest Element : "<<obj -> largestElementMethod1(arr,n)<<endl;
   cout<<"Largest Element : "<<obj -> largestElementMethod2(arr,n)<<endl;
   cout<<"Largest Element : "<<obj -> largestElementMethod3(arr,n)<<endl;
   cout<<"Largest Element : "<<obj -> largestElementMethod4(arr)<<endl;
   delete obj;
   return 0;
}