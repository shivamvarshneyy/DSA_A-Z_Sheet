#include<bits/stdc++.h>
using namespace std;
class MySolution{
public:
   int fib(int n){
        if(n<=1)return n;
        return fib(n-1)+fib(n-2);
   }
};
int main(){
   MySolution* obj = new MySolution;
   int n;
   cout<<"Enter a Number"<<endl;
   cin>>n;
   cout<<obj->fib(n)<<endl;
   delete obj;
   return 0;
}