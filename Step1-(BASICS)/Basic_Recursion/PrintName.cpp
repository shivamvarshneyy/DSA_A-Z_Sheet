#include<bits/stdc++.h>
using namespace std;
class MySolution{
public:
   void print(int n, string& name){
        if(n==0)return;
        cout<<name<<endl;
        print(n-1, name);
   }
};
int main(){
   MySolution* obj = new MySolution;
   int n;
   cout<<"Enter a Number"<<endl;
   cin>>n;
   cin.ignore();
   string name;
   cout<<"Enter your name"<<endl;
   getline(cin, name);
   obj -> print(n, name);
   delete obj;
   return 0;
}