#include<vector>

class Divisors{
public:
    std::vector<int> divisor(int n) {
        std::vector<int> list;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                list.emplace_back(i);
                if(n/i!=i)list.emplace_back(n/i);
            }
        }
        return list;
    }

};