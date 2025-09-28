#include<bits/stdc++.h>
using namespace std;
class MySolution{
public:
   int reverseNumber(int n){
        int res = 0;
        while(n!=0){
            res = res*10 + n%10;
            n /= 10;
        }
        return res;
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