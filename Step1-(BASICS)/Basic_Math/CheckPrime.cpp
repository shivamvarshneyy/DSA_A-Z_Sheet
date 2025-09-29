#include<bits/stdc++.h>
#include"../../Header_File/isPrime.h"
using namespace std;
class MySolution{
public:
   bool checkPrimeNumber(int n){
        IsPrime prime;
        return prime.checkPrime(n);
   }
};
int main(){
   MySolution* obj = new MySolution;
   int n;
   cout<<"Enter a Number"<<endl;
   cin>>n;
   int res = obj -> checkPrimeNumber(n);
   if(res)cout<<"true";
   else cout<<"false";
   delete obj;
   return 0;
}