#include <bits/stdc++.h>

void solve(int idx, int k, vector<int> &arr, vector<int> &temp,
           vector<vector<int>> &ans) {

  if (k == 0) {
    ans.push_back(temp);
    return;
  }

  for (int i = idx; i < arr.size(); i++) {
    if (i > idx && arr[i] == arr[i - 1]) {
      continue;
    }

    if (arr[i] > k) {
      break;
    }

    temp.push_back(arr[i]);
    solve(i + 1, k - arr[i], arr, temp, ans);
    temp.pop_back();
  }

  // solve(idx + 1, k, arr, temp, ans);
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target) {
  // Write your code here.

  sort(arr.begin(), arr.end());

  vector<vector<int>> ans;
  vector<int> temp;

  solve(0, target, arr, temp, ans);

  return ans;
}
