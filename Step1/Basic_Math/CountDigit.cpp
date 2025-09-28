#include<bits/stdc++.h>
using namespace std;
class MySolution{
public:
    int countDigit(int n){
        if(n == 0) return 1;
        int count = 0;
        while(n!=0){
            n/=10;
            count++;
        }
        return count;
    }
};
int main(){
    MySolution* obj = new MySolution;
    int n;
    cout<<"Enter Number:"<<endl;
    cin>>n;
    int res = obj -> countDigit(n);
    cout<<res<<endl;
    delete obj;
    return 0;
}
