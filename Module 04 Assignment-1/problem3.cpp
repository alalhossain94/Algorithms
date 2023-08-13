#include<bits/stdc++.h>
using namespace std;

// Binary Search to find the first and last occurrence of K
bool hasMultipleOccurrences(const vector<int>& arr, int target) 
{
    int left = 0;
    int right = arr.size() - 1;

    // Find the first occurrence of K
    while (left <= right) 
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            if (mid == 0 || arr[mid - 1] != target) {
                // First occurrence found, now search for last occurrence
                left = mid;
                break;
            } else {
                right = mid - 1; // Continue searching in the left half
            }
        } else if (arr[mid] < target) {
            left = mid + 1; // Target is in the right half
        } else {
            right = mid - 1; // Target is in the left half
        }
    }

    // Find the last occurrence of K
    right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            if (mid == arr.size() - 1 || arr[mid + 1] != target) {
                // Last occurrence found
                return true;
            } else {
                left = mid + 1; // Continue searching in the right half
            }
        } else if (arr[mid] < target) {
            left = mid + 1; // Target is in the right half
        } else {
            right = mid - 1; // Target is in the left half
        }
    }

    // No multiple occurrences found
    return false;
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

    bool multipleOccurrences = hasMultipleOccurrences(arr, k);

    if (multipleOccurrences) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
