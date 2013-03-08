/*
 * To find a maximum subsequence sum in a sequence.
 */

#include <iostream>
using namespace std;

//O(n3)
int firstWay(int* a, int len) {
    int sum = 0, max = -10000000;
    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            sum = 0; 
            for (int k = i; k <= j; k++) {
               sum += a[k]; 
            }
            if (sum > max) {
                max = sum;
            }
        }
    }
    return max;
}

//O(n2)
int secondWay(int* a, int len) {
    int max = -10000000;
    int *s = new int[len];
    s[0] = a[0];
    for (int i = 1; i < len; i++) {
        s[i] = s[i - 1] + a[i]; 
    }

    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (s[j] - s[i] > max) {
                max = s[j] - s[i];
            }
        }
    }
    delete [] s;

    return max;
}

//O(nlgn)
int thirdWay(int*a, int x, int y) {
    int i, m, v, Lsum, Rsum, max;
    if (y - x == 1) {
        return a[x];
    }
    m = x + (y - x) / 2;
    max = thirdWay(a, x, m) > thirdWay(a, m, y) ? thirdWay(a, x, m) : thirdWay(a, m, y);
    v = 0; Lsum = a[m - 1];
    for (i = m - 1; i >= x; i--) {
       v += a[i];
       Lsum = Lsum > v ? Lsum : v;
    }
    v = 0; Rsum = a[m];
    for (i = m; i < y; i++) {
       v += a[i];
       Rsum = Rsum > v ? Rsum : v;
    }

    return max > Lsum + Rsum ? max : Lsum + Rsum;
}

//O(n)
int fourthWay(int* a, int len) {
    int max = -10000000;
    int min = +10000000;
    int *s = new int[len];
    s[0] = a[0];
    for (int i = 1; i < len; i++) {
        s[i] = s[i - 1] + a[i];
    }
    for (int i = 0; i < len; i++) {
        if (s[i] < min)
            min = s[i];
    }
    for (int i = 0; i < len; i++) {
        if (s[i] - min > max)
            max = s[i] - min;
    }
    return max;
}

int main(void)
{
    int a[10] = {2, 1, -12, 5, 7, 15, 8, 9, -10, 12};
    cout << firstWay(a, 10) << endl;
    cout << secondWay(a, 10) << endl;
    cout << thirdWay(a, 0, 10) << endl;
    cout << fourthWay(a, 10) << endl;
    return 0;
}
