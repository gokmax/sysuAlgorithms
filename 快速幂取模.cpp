// -- 快速幂取模算法 -- //
// -- a ^ b % n -- //
//a * b % n = ( (a%n) * b) % n;

#include <iostream>
using namespace std;

int modexp_simple(int a, int b, int n) {
    int ans = 1;
    while (b --) {
        ans = (a * ans) % n;
    }
    return ans;
}

int modexp_powerful(int a, int b, int n) {
    int ans = 1;
    while (b) {
        if (b & 0x1) { // b是奇数
            ans = (ans * a) % n;
        }
        a = (a * a) % n; // 权值不断开方，同时模n无影响
        b = b >> 1; // 不断右移除2
    }
    return ans;
}

int modexp_recursion(int a, int b, int n) {
    int ans = 1;
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    ans = modexp_recursion(a, b >> 1, n);
    ans = (ans * ans) % n;
    if (b & 0x1)
        ans = (ans * a) % n; // 递归的话要写成倒序操作，因为栈是从下往上的
    return ans;
}


int main(void)
{
    int a, b, n;
    cin >> a >> b >> n;
    //cout << modexp_simple(a, b, n) << endl;
    cout << modexp_powerful(a, b, n) << endl;
    //cout << modexp_recursion(a, b, n) << endl;
    return 0;
}
