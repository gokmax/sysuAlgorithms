/*
 * Implementations of Arithmetic Operations in Mathmetics.
 */

// Al Khwarizmi - Multiplication in France -- O(n2)

#include <iostream>
#include <utility>
using namespace std;

int multiply(int x, int y) {
    if (y == 0) return 0;
    if (y % 2 == 0)
        return multiply(x, y / 2) * 2;
    else    
        return multiply(x, y / 2) * 2 + x;
}

// Division x = y * q + r
pair<int, int>  division(int x, int y) {
    if (x == 0) return make_pair(0, 0);
    int q, r;
    pair<int, int> Qr = make_pair(q, r);
    Qr = division(x / 2, y);
    q = Qr.first; r = Qr.second;
    q *= 2; r *= 2;
    if (x % 2 != 0) {
        r ++;
    }
    if (r >= y) {
        r -= y; 
        q ++;
    }
    return make_pair(q, r); 
}


int main(void)
{
    cout << multiply(2, 5) << endl;
    cout << division(30, 4).first << " " << division(30, 4).second << endl;
    
    return 0;
}
