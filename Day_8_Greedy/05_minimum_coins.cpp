#include <bits/stdc++.h>
int findMinimumCoins(int amount) {
  // Write your code here
  int deno[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
  int n = 9;
  int count = 0;

  for (int i = n - 1; i >= 0; i--) {
    while (amount >= deno[i]) {
        amount -= deno[i];
        count++;
    }
  }

  return count;
}


//  MUCH OPTIMAL SOLUTION
#include <bits/stdc++.h>
int findMinimumCoins(int amount) {
  // Write your code here
  int deno[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
  int n = 9;
  int count = 0;

  for (int i = n - 1; i >= 0; i--) {
   
    if(amount >= deno[i]){
        int num = amount/deno[i];
        amount -= num*deno[i];
        count += num;
    }
  }

  return count;
}
