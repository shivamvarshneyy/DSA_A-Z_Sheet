#include<bits/stdc++.h>
using namespace std;
class MySolution{
public:
   int secondLargest1(vector<int>& arr){
        int maxElement = *max_element(arr.begin(), arr.end());
        int secondMaxElement = INT_MIN;
        for(const int& i: arr){
            if(i!=maxElement)secondMaxElement = max(secondMaxElement, i);
        }
        return secondMaxElement;
   }
   
//    Time Complexity  -> O(2N) ~ O(N)
//    Space Complexity -> O(1)

   int secondLargest2(vector<int>& arr){
        int maxElement = arr[0];
        int secondMaxElement = INT_MIN;
        for(const int& i: arr){
            if(i>maxElement){
                secondMaxElement = maxElement;
                maxElement = i;
            }
            if(i!=maxElement && i>secondMaxElement)
                secondMaxElement = max(secondMaxElement, i);
        }
        return secondMaxElement;
   }

    //    Time Complexity  -> O(N)
    //    Space Complexity -> O(1)

   int secondLargest3(vector<int>& arr){
        sort(arr.begin(), arr.end());
        int n = arr.size();
        for(int i=n-2;i>=0;i--)
            if(arr[n-1]!=arr[i])return arr[i]; 
        return INT_MAX;
   }

   //    Time Complexity -> O(NlogN)+O(N) ~ O(NLogN)
   //    Space Complexity -> O(1)
};
int main(){
   MySolution* obj = new MySolution;
   int n;
   cout<<"Enter a array size"<<endl;
   cin>>n;
   while(n<=0){
    cout<<"Invalid array size.Please re-enter array size"<<endl;
    cin>>n;
   }
   vector<int> arr(n);
   cout<<"Enter array elements"<<endl;
   for(int i=0;i<n;i++)cin>>arr[i];
   cout<<"Largest Element : "<<obj -> secondLargest1(arr)<<endl;
   cout<<"Largest Element : "<<obj -> secondLargest2(arr)<<endl;
   cout<<"Largest Element : "<<obj -> secondLargest3(arr)<<endl;
   delete obj;
   return 0;
}