#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define MAX 10000
// 一个大数类
class MyInt{
private:
    int     _n; // 盛放的数字的个数，当 _n=0 时代表 NaN
    int  *_arr; // 盛放数字的数组，倒着放 
    bool _sign; // 作为正负号标志，1代表负数，2代表正数
    void init();// 初始化上述变量的函数
public:
    MyInt();                     // 初始化为0
    MyInt(int k);                // 初始化为k
    MyInt(vector<int> const &v); // 初始化为v中的数字，要求v中数字为单个数字，否则返回 _n=0，NaN
    MyInt(string const &s);      // 初始化为s中的数字，若字符串不是数字返回 _n=0，NaN
    int operator[](int i); // 支持取单个数位，是外部接口，内部直接用_arr而不使用它
    MyInt operator<<(const MyInt &mi); // 数学运算的左移右移
    MyInt operator>>(MyInt &mi);       // 数学运算的左移右移 TODO:
    friend ostream & operator<<( ostream & os, const MyInt & mi); // cin的输入
    friend istream & operator>>( istream & is, MyInt & mi);       // cout的输出 TODO:
    friend MyInt operator+(MyInt const &mi1, MyInt const  &mi2); // 加法
    friend MyInt operator*(MyInt const &mi1, MyInt const  &mi2); // 乘法
    friend bool operator==(MyInt const &mi1, MyInt const  &mi2); // 等于判断TODO:
    string to_string();     // 转换为STL中的string
    vector<int> to_vector();// 转换为STL中的vector
    friend void print(MyInt mi); // 打印函数，被设计成了友元函数，通过重载能够打印不同的My类
    ~MyInt(); // 析构函数
};

void MyInt::init(){
    _sign = false;         // 默认为正号
    _n = 1;
    _arr = new int[MAX](); // 默认为0
}

MyInt::MyInt(){
    init();
}

MyInt::MyInt(int k){
    init(); // TODO:这里有问题
    while(k!=0){
        _arr[_n] = k%10;
        k /= 10;
        _n++;
    }
}
MyInt::MyInt(vector<int> const &v){
    init();
    _n = v.size();
    for(int i=0; i<_n; i++)
        _arr[i] = v[_n-1-i];
}
// 倒着存
MyInt::MyInt(string const &s){
    init();
    _n = s.length();
    for(int i=0; i<_n; i++)
        _arr[i] = s[_n-1-i]-'0';
}

int MyInt::operator[](int i){
    return _arr[_n-1-i];
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

MyInt operator*(MyInt const &mi1, MyInt const  &mi2){
    MyInt mi3;
    if(mi1==0 || mi2==0) return mi3;
    for(int i=0; i<mi1._n; i++){
        for(int j=0; j<mi2._n; j++){
            int t = mi1._arr[i]*mi2._arr[j];
            int c = t/10;
            t = t%10;
            mi3._arr[i+j]+=t; // 这样加会有溢出，所以
            if(mi3._arr[i+j]>=10){
                mi3._arr[i+j]/=10;
                mi3._arr[i+j+1]++;
            }
            mi3._arr[i+j+1]+=c;// 这里仍然会有溢出
            if(mi3._arr[i+j+1]>=10){
                mi3._arr[i+j+1]/=10;
                mi3._arr[i+j+2]++;
            }

        }
    }
    int n = mi1._n + mi2._n;
    if(mi3._arr[n]==0) n--;
    mi3._n = n;
    return mi3;


     public String multiply(String num1, String num2) {
        if (num1.equals("0") || num2.equals("0")) {
            return "0";
        }
        int[] res = new int[num1.length() + num2.length()];
        for (int i = num1.length() - 1; i >= 0; i--) {
            int n1 = num1.charAt(i) - '0';
            for (int j = num2.length() - 1; j >= 0; j--) {
                int n2 = num2.charAt(j) - '0';
                int sum = (res[i + j + 1] + n1 * n2);
                res[i + j + 1] = sum % 10;
                res[i + j] += sum / 10;
            }
        }

        StringBuilder result = new StringBuilder();
        for (int i = 0; i < res.length; i++) {
            if (i == 0 && res[i] == 0) continue;
            result.append(res[i]);
        }
        return result.toString();
    }

}

bool operator==(MyInt const &mi1, MyInt const  &mi2){
    if(mi1._n*mi2._n==0 || mi1._n!=mi2._n) return false;
    for(int i=0; i<mi1._n; i++){
        if(mi1._arr[i] != mi2._arr[i]) return false;
    }
    return true;
}

string MyInt::to_string(){
    string s;
    for(int i=0; i<_n; i++)
        s += _arr[_n-1-i]+'0';
    return s;
}

vector<int> MyInt::to_vector(){
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
    string multiply(string num1, string num2) {
        MyInt mi1(num1);
        MyInt mi2(num2);
        MyInt mi3 = mi1*mi2;
        return mi3.toString();
        
    }
};
int main(){
   Solution solution;
    string s1 = "11";
    string s2 = "22";
    cout<< solution.multiply(s1, s2);
    return 0;
}
