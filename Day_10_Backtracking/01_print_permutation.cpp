// METHOD FIRST

#include <bits/stdc++.h> 

void solve(vector<int> &map, string &temp, vector<string> &ans, string &s){
    if(temp.size() == s.size()){
        ans.push_back(temp);
        return;
    }

    for(int i = 0; i < s.size(); i++){
        if(map[i] == 0){
            temp.push_back(s[i]);
            map[i] = 1;
            solve(map, temp, ans, s);
            map[i] = 0;
            temp.pop_back();
        }
    }
}

vector<string> findPermutations(string &s) {
    // Write your code here.
    vector<string> ans;
    string temp = "";

    vector<int> map(s.size(), 0);

    solve(map, temp, ans, s);

    return ans;
}

// METHOD SECOND