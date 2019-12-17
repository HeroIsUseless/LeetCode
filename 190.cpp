#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int res=0;
        for(int i=0; i<32; i++){
            uint32_t t = n & 1;
            res = res << 1;
            res += t;
            n = n >> 1;
        }
        return res;
    }
};
int main(){
   Solution solution;
    solution.reverseBits(0xffff);
    return 0;
}
// 32位，一个字节8位，一共四个字节，一个字节可以用1个十六进制表示
// 没问题啊？