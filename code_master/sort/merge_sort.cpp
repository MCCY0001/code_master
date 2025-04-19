#include <iostream>
#include <vector>

using namespace std;

void Merge(vector<int>& arr, int left, int mid, int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;
  vector<int> L(n1), R(n2);
  for (int i = 0; i < n1; ++i) {
    L[i] = arr[left + i];
  }
  for (int j = 0; j < n2; ++j) {
    R[j] = arr[mid + 1 + j];
  }

  int i = 0, j = 0, k = left;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k++] = L[i++];
    } else {
      arr[k++] = R[j++];
    }
  }

  while (i < n1) {
    arr[k++] = L[i++];
  }

  while (j < n2) {
    arr[k++] = R[j++];
  }
}

void MergeSort(vector<int>& arr, int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;
    MergeSort(arr, left, mid);
    MergeSort(arr, mid + 1, right);
    Merge(arr, left, mid, right);
  }
}

void Print(const vector<int>& arr) {
  for (auto num : arr) {
    cout << num << ' ';
  }
  cout << '\n';
}

int main() {
  vector<int> arr = {12, 11, 13, 5, 6, 7};

  Print(arr);

  MergeSort(arr, 0, arr.size() - 1);

  Print(arr);
}