#include <iostream>
#include <algorithm>
using namespace std;

// 二分查找的非递归实现
int binsearch_normal(int s[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (key < s[mid]) high = mid - 1;
        else if (key > s[mid]) low = mid + 1;
        else return mid;
    }
    return -1;
}

// 二分查找的递归实现
int binsearch_recursion(int s[], int low, int high, int key) {
    if (low > high) return -1;
    int mid = low + (high - low) / 2;
    if (s[mid] == key) return mid;
    else if (key < s[mid]) 
        return binsearch_recursion(s, low, mid - 1, key);
    else return binsearch_recursion(s, mid + 1, high, key);
}

// 二分查找下界，查找范围[low, high) -- 真实值位置
int my_lower_bound(int* s, int low, int high, int key) {
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (key <= s[mid]) high = mid;
        else low = mid + 1;
    }
    return low;
}

// 二分查找上界，查找范围[low, high) -- 真实值的下一个位置
int my_upper_bound(int* s, int low, int high, int key) {
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (key >= s[mid]) low = mid + 1;
        else high = mid;
    }
    return low;
}
// -->> 设lower_bound和upper_bound的返回值分别为L和R
// -->> 则key出现的子序列为[L, R).

// Mergesort Routine
int reverse_sum = 0;
void merge_sort(int* A, int first, int last, int* T) {
    if (last - first > 1) {
        int mid = first + (last - first) / 2;
        int p = first, q = mid, i = first; // i for iterate
        merge_sort(A, first, mid, T);
        merge_sort(A, mid, last, T);
        while (p < mid || q < last) {
            if (q >= last || (p < mid && A[p] <= A[q]))
                T[i ++] = A[p ++]; // 取前一半元素
            else {
                T[i ++] = A[q ++]; 
                // 取后一半元素 -- 说明前边的数比后边的数小，追溯到单一元素数组，亦即是一个逆序对。
                reverse_sum += mid - p; // 逆序对个数
            }
        }
        for (i = first; i < last; i ++) A[i] = T[i];
    }
}

// 快速排序，原地排序，不像归并排序需}要辅助空间，微调后非常实用。
int Partition(int A[], int p, int r) {
    int pivot = A[p]; // 基准
    // 设两个指针
    int left = p, right = r; // A[left]即A[p]就是第一个坑
    while (right > left) {
        // 从右向左找小于pivot的数来填A[left]
        while (right > left && A[right] >= pivot)
            right --;
        A[left] = A[right]; // 将A[right]填到A[left]中，A[right]就形成了一个新的坑
        left ++;

        // 从左向右找大于或等于pivot的数来填A[right]
        while (right > left && A[left] < pivot)
            left ++;
        A[right] = A[left]; // 将A[left]填到A[right]中，A[left]就形成了一个新的坑
        right --;
    }
    // 退出时，left = right。将pivot填到这个坑中。
    A[left] = pivot;
    return left;
}

void quickSort(int A[], int p, int r) {
    int pivot;
    if (r > p) {
        pivot = Partition(A, p, r);
        quickSort(A, p, pivot - 1);
        quickSort(A, pivot + 1, r);
    }
}

// 求序列中第k小数 - 借用快速排序的框架 - O(n)






















int main(void)
{
    int a[] = {1, 2, 3, 3, 3, 3, 3, 4, 4, 5, 6, 7, 8, 9};
    int n = 14;
    cout << my_upper_bound(a, 0, 13, 3) << endl;
    cout << my_lower_bound(a, 0, 13, 3) << endl;
    cout << upper_bound(a, a + n, 3) - a << endl;
    cout << lower_bound(a, a + n, 3) - a << endl;
    cout << upper_bound(a, a + n, 3) - lower_bound(a, a + n, 3) << endl;
    return 0;
}    
