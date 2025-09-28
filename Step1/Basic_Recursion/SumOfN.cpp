#include<bits/stdc++.h>
using namespace std;
class MySolution{
public:
   int sumOfN(int n){
        if(n==0)return 0;
        return n+sumOfN(n-1);
   }
};
int main(){
   MySolution* obj = new MySolution;
   int n;
   cout<<"Enter a Number"<<endl;
   cin>>n;
   cout<<"Sum of n numbers are: "<< obj -> sumOfN(n);
   delete obj;
   return 0;
}