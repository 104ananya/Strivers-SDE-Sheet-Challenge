#include <bits/stdc++.h>

void solution(int ind, vector<int> &arr, vector<int> temp, vector<vector<int>> &ans) {

  ans.push_back(temp);

  for (int i = ind; i < arr.size(); i++) {
    if (i != ind && arr[i] == arr[i-1]) {
      continue;
    }
    temp.push_back(arr[i]);
    solution(i + 1, arr, temp, ans);
    temp.pop_back();
  }
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr) {
  // Write your code here.

  sort(arr.begin(), arr.end());

  vector<vector<int>> ans;
  vector<int> temp;

  solution(0, arr, temp, ans);

  return ans;
}