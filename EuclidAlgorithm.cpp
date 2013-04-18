/*
 * Extension of Euclid algorithm__black books.
 */

#include <iostream>
using namespace std;

typedef unsigned int uInt;

// 递归欧几里德算法
uInt gcd1(uInt x, uInt y) {
    if (x < y) return gcd1(y, x);
    if (0 == y) return x;
    return gcd1(y, x % y);
}
// 迭代欧几里德算法
uInt gcd2(uInt x, uInt y) {
    while (y) {
        uInt tmp = y;
        y = x % y;
        x = tmp;
    }
    return x;
}
// 减法求最大公约数
uInt gcdSub(uInt x, uInt y) {
    if (x < y)  return gcdSub(y, x);
    if (y == 0) return x;
    else return gcdSub(y, x - y);
}
// Stein算法求最大公约数
uInt gcdStein(uInt x, uInt y) {
    if (x < y) return gcdStein(y, x);
    if (y == 0) return x;
    else {
        if (x % 2 == 0) {
            if (y % 2 == 0)
                return gcdStein(x >> 1, y >> 1) << 1;
            else return gcdStein(x >> 1, y) ;
        }
        else {
            if (y % 2 == 0)
                return gcdStein(x, y >> 1);
            return gcdStein(y, x - y);
        }
    }
}

int main(void)
{
    int n, m;
    cin >> n >> m;
    cout << gcd1(n, m) << endl << gcd2(n, m) << endl;
    cout << gcdSub(n, m) << endl << gcdStein(n, m) << endl;
    return 0;
}
