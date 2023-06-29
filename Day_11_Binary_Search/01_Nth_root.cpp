int fun(int mid, int n, int m) {
  long long mul = 1;
  for (int i = 1; i <= n; i++) {
    mul = mul * mid;

    if (mul > m) {
      return 2;
    }
  }
  if (mul == m) {
    return 1;
  }
  return 0;
}

int NthRoot(int n, int m) {
  // Write your code here.
  int low = 1;
  int high = m;
  int ans = -1;

  while (low <= high) {
    int mid = (low + high) / 2;

    // mid^n = m
    if (fun(mid, n, m) == 1) {
      ans = mid;
      return ans;
    }
    // mid^n < m
    else if (fun(mid, n, m) == 0) {
      low = mid + 1;
    }
    // mid^n > m
    else {
      high = mid - 1;
    }
  }
  return ans;
}