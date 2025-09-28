#include<bits/stdc++.h>
#include "GCDorHCF.h"
using namespace std;
class MySolution{
public:
    int getGCD(int a, int b){
        GCD obj;
        int res = obj.gcd(a,b);
        return res;
    }
};
int main(){
   MySolution* obj = new MySolution;
   int a,b;
   cout<<"Enter two Number"<<endl;
   cin>>a;
   cin>>b;
   int res = obj->getGCD(a,b);
   cout<<res<<endl;
   delete obj;
   return 0;
}