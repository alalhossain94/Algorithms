#include<bits/stdc++.h>
using namespace std;
// Binary Search to find the first occurrence of K
int findFirstOccurrence(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    int firstOccurrence = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            firstOccurrence = mid;
            right = mid - 1; // Continue searching in the left half
        } else if (arr[mid] < target) {
            left = mid + 1; // Target is in the right half
        } else {
            right = mid - 1; // Target is in the left half
        }
    }

    return firstOccurrence;
}

// Binary Search to find the last occurrence of K
int findLastOccurrence(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    int lastOccurrence = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            lastOccurrence = mid;
            left = mid + 1; // Continue searching in the right half
        } else if (arr[mid] < target) {
            left = mid + 1; // Target is in the right half
        } else {
            right = mid - 1; // Target is in the left half
        }
    }

    return lastOccurrence;
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

    int firstOccurrence = findFirstOccurrence(arr, k);
    int lastOccurrence = findLastOccurrence(arr, k);

    if (firstOccurrence != lastOccurrence) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
