//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    
    bool static comparison(Job a, Job b){
        return (a.profit > b.profit );
    }
    
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        
        // sort the array aas per PROFIT
        sort(arr, arr+n, comparison);
        
        // create array of size of maximum deadline.
        
        // to find the maximum deadline in the whole array
        int maxdead = arr[0].dead;
        
        for(int i = 0; i < n; i++){
            maxdead = max(maxdead, arr[i].dead);
        }
        
        int work[maxdead + 1];
        
        // set each slot to -1 which denotes empty slot
        for(int i = 0; i <= maxdead; i++){
            work[i] = -1;
        }
        
        int count = 0; 
        int total = 0;
        
        // interate over the arr[]
        // inside that iterate over slot array to find the empty slot
        
        for(int i = 0; i <n; i++){
            for(int j = arr[i].dead; j > 0; j--){
                
                // is the last day of the deadline is empty then fill that place otherwise fill the below place
                if(work[j] == -1){
                    work[j] = i;
                    count++;
                    total += arr[i].profit;
                    break;
                }
            }
        }
        
        vector<int> ans;
        ans.push_back(count);
        ans.push_back(total);
        
        return ans;
        
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends