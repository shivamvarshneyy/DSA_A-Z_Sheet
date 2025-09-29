#include<bits/stdc++.h>
#include"../../Header_File/CountDigit.h"
using namespace std;
class MySolution{
public:
   bool armstrongNumber(int n){
        int temp = n;
        int sum = 0;
        CountDigit cd;
        int noOfDigit = cd.countDigit(n);
        while(temp != 0){
            sum += (int)(pow(temp % 10, noOfDigit) + 0.5);
            temp /= 10;
        }
        return sum == n;
   }
};
int main(){
   MySolution* obj = new MySolution;
   int n;
   cout<<"Enter a Number"<<endl;
   cin>>n;
   if(obj -> armstrongNumber(n))cout<<"true"<<endl;
   else cout<<"false"<<endl;
   delete obj;
   return 0;
}