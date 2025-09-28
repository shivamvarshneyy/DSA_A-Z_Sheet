#include<bits/stdc++.h>
using namespace std;
class MySolution{
public:
   bool isPalindrome(string& s, int i, int n){
        if(i>=n/2)return true;
        if(s[i] != s[n-i-1])return false;
        isPalindrome(s, i+1, n);
   }
};
int main(){
   MySolution* obj = new MySolution;
   string s;
   cout<<"Enter a string"<<endl;
   cin>>s;
   if(obj -> isPalindrome(s, 0, s.size()))
        cout<<"Palindrome"<<endl;
   else
        cout<<"Not Palindrome"<<endl;
   delete obj;
   return 0;
}