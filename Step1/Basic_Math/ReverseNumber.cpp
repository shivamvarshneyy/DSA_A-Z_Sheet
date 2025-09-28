#include<bits/stdc++.h>
#include "ReverseNumber.h"
using namespace std;
class MySolution{
public:
   int reverseNumber(int n){
      if(n<0 || n>=INT_MAX)return 0;
      ReverseNumber obj;
      return obj.reverse(n);
   }
};
int main(){
   MySolution* obj = new MySolution;
   int n;
   cout<<"Enter a Number"<<endl;
   cin>>n;
   int res = obj -> reverseNumber(n);
   cout<<res<<endl;
   delete obj;
   return 0;
}