#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define MAX 10000
class MyInt{
private:
    int _n;
    int *_arr;
public:
    MyInt();
    MyInt(int k);
    MyInt(vector<int> v);
    MyInt(string s);               // 支持从字符串创建
    friend MyInt operator+(MyInt const &mi1, MyInt const  &mi2);
    string toString();
    vector<int> toVector();
    friend void print(MyInt mi);
    ~MyInt();
};
MyInt::MyInt(){
    _n=0; 
    _arr = new int[MAX];
}
MyInt::MyInt(int k){
    _n = 0;
    _arr = new int[MAX];
    if(k == 0){
        _n = 1;
        _arr[0] = 0;
    }
    while(k!=0){
        _arr[_n] = k%10;
        k /= 10;
        _n++;
    }
}
MyInt::MyInt(vector<int> v){
    _n = v.size();
    _arr = new int[MAX];
    for(int i=0; i<_n; i++)
        _arr[i] = v[_n-1-i];
}
// 倒着存
MyInt::MyInt(string s){
    _n = s.length();
    _arr = new int[MAX];
    for(int i=0; i<_n; i++)
        _arr[i] = s[_n-1-i]-'0';
}

MyInt operator+(MyInt const &mi1, MyInt const  &mi2){
    MyInt mi3;
    int i1=0, i2=0, i3=0;
    bool c = false; // 进位标志
    while(i1<mi1._n || i2<mi2._n){
        int k1 = i1<mi1._n?mi1._arr[i1]:0;
        int k2 = i2<mi2._n?mi2._arr[i2]:0;
        int t = k1+k2+c;
        if(t >= 10){
            t %= 10;
            c = true;
        }
        else c = false;
        mi3._arr[i3] = t;
        i1++; i2++; i3++;
    }
    mi3._arr[i3]=c;
    mi3._n = i3+c;
    return mi3;
}

string MyInt::toString(){
    string s;
    for(int i=0; i<_n; i++)
        s += _arr[_n-1-i]+'0';
    return s;
}

vector<int> MyInt::toVector(){
    vector<int> v;
    for(int i=0; i<_n; i++)
        v.push_back(_arr[_n-1-i]);
    return v;
}

void print(MyInt mi){
    for(int i=0; i<mi._n; i++) 
        cout<<mi._arr[mi._n-1-i];
}

MyInt::~MyInt(){
    delete[] _arr;
}

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        MyInt mi1(A);
        MyInt mi2(K);
        MyInt mi3 = mi1+mi2;
        return mi3.toVector();
    }
};
int main(){
   Solution solution;

    return 0;
}
