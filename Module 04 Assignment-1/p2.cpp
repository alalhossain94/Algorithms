#include<bits/stdc++.h>
using namespace std;
// Binary Search function
int binarySearch(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // Found the element at index mid
        } else if (arr[mid] < target) {
            left = mid + 1; // Target is in the right half
        } else {
            right = mid - 1; // Target is in the left half
        }
    }

    return -1; // Element not found in the array
}

int main() {
    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    int index = binarySearch(arr, k);
    if (index != -1) {
        cout <<index << endl;
    } else {
        cout << "Not Found" << endl;
    }

    return 0;
}
