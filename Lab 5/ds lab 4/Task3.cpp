/*
Implement a recursive binary search function to find an element in a sorted array of integers.
*/
#include <iostream>
using namespace std;

int recBinarySearch(int* arr, int l, int h, int t) {
      if (l > h) { return -1; }
    int mid = l + (h - l) / 2;
    if (arr[mid] == t) { return mid; }
    if (arr[mid] > t) { return recBinarySearch(arr, l, mid - 1, t); }
    if (arr[mid] < t) { return recBinarySearch(arr, mid + 1, h, t); }
     return -1;

}


int main() {
    int arr[10] = {2,4,6,8,10,12,14,16,18,20};
    cout << "The array: ";
    for (int i = 0; i < 10; i++) {
          cout << arr[i] << " ";
     }
    cout << endl;
    int val;
    cout << "Enter value to find: ";
    cin >> val;
    int ans = recBinarySearch(arr, 0, 9, val);
    (ans == -1) ? cout << "Value not found.\n" : cout << "Value found at index: " << ans << endl;
    return 0;
}