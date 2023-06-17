#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

struct meetings
{
    int start;
    int end;
    int index;
};

bool comparator(struct meetings m1, meetings m2)
{
    if (m1.end < m2.end)
        return true;
    else if (m1.end > m2.end)
        return false;
    else if (m1.index < m2.index)
        return true;
    else
        return false;
}

vector<int> maximumMeetings(vector<int> &start, vector<int> &end){
    // Write your code here.
    int n = start.size();

    struct meetings meet[n];
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        meet[i].start = start[i],
        meet[i].end = end[i],
        meet[i].index = i + 1;
    }

    sort(meet, meet + n, comparator);

    int limit = meet[0].end;
    ans.push_back(meet[0].index);

    for (int i = 1; i < n; i++)
    {
        if (meet[i].start > limit)
        {
            limit = meet[i].end;
            ans.push_back(meet[i].index);
        }
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> start(n), end(n);
    for (int i = 0; i < n; i++)
    {
        cin >> start[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> end[i];
    }
    vector<int> ans = maximumMeetings(start, end);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}
