#include<bits/stdc++.h>
using namespace std;
class MySolution{
public:
   void print(int n){
        if(n==0)return;
        cout<<n<<endl;
        print(n-1);
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