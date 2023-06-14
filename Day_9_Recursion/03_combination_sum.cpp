
class Solution
{
public:
    void solve(int i, int k, vector<int> &arr, vector<int> &temp, vector<vector<int>> &ans)
    {

        if (i == arr.size())
        {
            if (k == 0)
            {
                ans.push_back(temp);
            }

            return;
        }

        if (arr[i] <= k)
        {
            temp.push_back(arr[i]);
            solve(i, k - arr[i], arr, temp, ans);
            temp.pop_back();
        }

        solve(i + 1, k, arr, temp, ans);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> temp;

        solve(0, target, candidates, temp, ans);

        return ans;
    }
};

// NEGATIVE CONSTRAINTS

void solution(int ind, int k, vector<int> arr, vector<int> &temp,
              vector<vector<int>> &ans, int n)
{

    if (ind == n)
    {
        if (k == 0)
        {
            ans.push_back(temp);
        }

        return;
    }

    // picking up the element

    {
        temp.push_back(arr[ind]);
        solution(ind + 1, k - arr[ind], arr, temp, ans, n);
        temp.pop_back();
    }

    // not picking up
    solution(ind + 1, k, arr, temp, ans, n);
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
    vector<vector<int>> ans;
    vector<int> temp;

    solution(0, k, arr, temp, ans, n);

    return ans;
}

