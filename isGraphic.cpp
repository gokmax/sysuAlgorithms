#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 100000
int sequence[MAXN];

bool cmp(const int& a, const int& b) {
    return a > b;
}

bool isGraphic(int *a, int start, int n) {
    if (start == n) {
        if (a[n - 1] != 0) {
            return false;
        }
        return true; // judge from the last element, also the ending of recursive function.
    }
    if (a[start] + start >= n) {
        return false; // each time minus 1 so you should add them back, for the degree of one vertice should smaller than the amount of the vertices.
    }
    sort(a + start, a + n, cmp); // sort the sequence from big to small in start to n.
    int sum = 0;
    for (int i = start; i < n; i++) {
        if (a[i] < 0) return false;
        sum += a[i];
    }
    if (sum % 2 != 0) {
        return false; // caculate the sum of them. And the sum should be even.
    }
    int tmp = start;
    for (int j = 0; j < a[start]; j++) {
        a[++tmp] --; // the lemma is here.
    }
    start ++;
    isGraphic(a, start, n);
}

int main()
{

recur:
    cout << "Please enter the number of the vertices:" << endl;
    int n;
    cin >> n;
    cout << "Please enter the sequence you want to isGraphic, each seperate by a blank." << endl;
    for (int i = 0; i < n; i++) 
        cin >> sequence[i];

    if (isGraphic(sequence, 0, n)) 
        cout << "The sequence you entered is graphic!" << endl;
    else 
        cout << "The sequence you entered is not graphic!" << endl;
    cout << "Try again? Enter y to try again and other character to end this program." << endl;
    char y;
    cin >> y;
    if (y == 'y') {
        goto recur;
    }
    else return 0;
}
