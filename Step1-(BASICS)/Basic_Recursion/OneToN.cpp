#include<bits/stdc++.h>
using namespace std;
class MySolution{
public:
   void print(int n){
        if(n==0)return;
        print(n-1);
        cout<<n<<endl;
   }
};
int main(){
   MySolution* obj = new MySolution;
   int n;
   cout<<"Enter a Number"<<endl;
   cin>>n;
   cin.ignore();
   cout<<endl;
   string name;
   obj -> print(n);
   delete obj;
   return 0;
}