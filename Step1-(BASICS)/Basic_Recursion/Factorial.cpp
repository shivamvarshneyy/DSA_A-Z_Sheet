#include<bits/stdc++.h>
using namespace std;
class MySolution{
public:
   long long factorial(long long n){
        if(n<2)return 1LL;
        return n*factorial(n-1);
   }
};
int main(){
   MySolution* obj = new MySolution;
   long long n;
   cout<<"Enter a Number"<<endl;
   cin>>n;
   cout<<"Factorial of "<<n<<" is : "<< obj -> factorial(n);
   delete obj;
   return 0;
}