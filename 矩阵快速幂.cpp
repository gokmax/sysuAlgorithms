// 运用类比思想，仔细考虑每个字母深层次的数学含义

#include <iostream>
#include <cstdio>
using namespace std;

struct Matrix {
    int number[2][2];
};

Matrix Multiplex (Matrix a, Matrix b, const int &m) {
    Matrix ans;
    ans.number[0][0] = (a.number[0][0] * b.number[0][0] + a.number[0][1] * b.number[1][0]) % m;
    ans.number[0][1] = (a.number[0][0] * b.number[0][1] + a.number[0][1] * b.number[1][1]) % m;
    ans.number[1][0] = (a.number[1][0] * b.number[0][0] + a.number[1][1] * b.number[1][0]) % m;
    ans.number[1][1] = (a.number[1][0] * b.number[0][1] + a.number[1][1] * b.number[1][1]) % m;
    return ans;
}

int workItOut(int n, const int &m) {
    if (n == 0) {
        return 0;
    }
    if (n == 1 && m != 1) {
        return n;
    }
    if (n == 1 && m == 1) {
        return 0;
    }
    // now n == 2
    //  unit    [1 0]
    //  matrix  [0 1]
    Matrix unitMatrix;
    unitMatrix.number[0][0] = 1;
    unitMatrix.number[0][1] = 0;
    unitMatrix.number[1][0] = 0;
    unitMatrix.number[1][1] = 1;

    //Matrix Initialization
    Matrix nEquals2;
    nEquals2.number[0][0] = 1;
    nEquals2.number[0][1] = 1;
    nEquals2.number[1][0] = 1;
    nEquals2.number[1][1] = 0;

    int Times = n - 1; // !important
    while (Times) {
        //nEquals2 = Multiplex(constant, nEquals2, m);  -- TLE
        if (Times & 1) {
            unitMatrix = Multiplex(unitMatrix, nEquals2, m);
        }
        nEquals2 = Multiplex(nEquals2, nEquals2, m);
        Times = Times >> 1;
    }
    return unitMatrix.number[0][0] % m;
}


int main(void)
{
    int T;
    //cin >> T;
    scanf("%d", &T);
    while (T --) {
        int n, m;
        scanf("%d%d", &n, &m);
        //cin >> n >> m;
        //cout << workItOut(n, m) << endl;
        printf("%d\n", workItOut(n, m));
        //cout << answer.number[0][0] << " " << answer.number[0][1] << endl;
        //cout << answer.number[1][0] << " " << answer.number[1][1] << endl;
        //cout << "----------" << endl;
    }
    return 0;
}
