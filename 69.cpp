#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
       long long i=0;
        while(!(i*i<x && (i+1)*(i+1)>x)) i++;
        return i;
    }
};
int main(){
   Solution solution;

    return 0;
}