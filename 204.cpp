#include <iostream>
#include <vector>
#include <math.h>
#include <string>
using namespace std;
class Solution {
public:
    int countPrimes(int n) {
        bool *ar = new bool[n]();
        for(int i=2; i<n; i++){
            for(int j=2; j<sqrt(i); j++){
                if(i%j==0) ar[i] = true;
            }
        }
        int count = 0;
        for(int i=2; i<n; i++){
            if(ar[i] == false)
                cout << i<<" ";
                count ++;
        }
        return count;
    }
};
int main(){
   Solution solution;
    solution.countPrimes(10);
    return 0;
}
