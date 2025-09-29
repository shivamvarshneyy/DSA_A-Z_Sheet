#include<bits/stdc++.h>
#include "../../Header_File/Divisors.h"
using namespace std;
class MySolution{
public:
   vector<int> listOfDivisors(int n){
        Divisors obj;
        return obj.divisor(n);
   }
};
int main(){
   MySolution* obj = new MySolution;
   int n;
   cout<<"Enter a Number"<<endl;
   cin>>n;
   vector<int> res = obj->listOfDivisors(n);
   sort(res.begin(), res.end());
   for(int i:res)cout<<i<<" ";
   delete obj;
   return 0;
}