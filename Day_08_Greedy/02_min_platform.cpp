#include<bits/stdc++.h>
#include <algorithm>

int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.

    sort(at, at+n);
    sort(dt, dt+n);

    int platform = 0;
    int max = 0;

    int i = 0, j = 0;

    while(i<n && j<n){
        if(at[i] <= dt[j]){
            platform++;
            i++;
        }
        else{
            platform--;
            j++;
        }

        if(platform > max){
            max = platform;
        }
    }

    return max;

}