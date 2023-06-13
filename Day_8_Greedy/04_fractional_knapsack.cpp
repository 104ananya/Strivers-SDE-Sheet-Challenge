//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution
{
    public:
    
    bool static comp(Item a, Item b){
        
        // finding the ratio
        double r1 = (double)a.value/(double)a.weight;
        double r2 = (double)b.value/(double)b.weight;
        
        return r1 > r2;
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        
        sort(arr, arr+n, comp);
        
        int curWgt = 0;
        double maxVal = 0;
        
        for(int i = 0; i < n; i++){
            
            if(curWgt + arr[i].weight <= W){
                maxVal += arr[i].value;
                curWgt += arr[i].weight;
            }
            else{
                int remain = W - curWgt;
                
                double partialVal = ((double)arr[i].value/(double)arr[i].weight)*(double)remain;
                maxVal += partialVal;
                break;
            }
        }
        
        return maxVal;
        
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends

#include <bits/stdc++.h>

bool comp(pair<int, int>a, pair<int, int>b){
    double r1 = (double)a.second/(double)a.first;
    double r2 = (double)b.second/(double)b.first;

    return r1>r2;
}

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.

    // Sort according to value/weight
    sort(items.begin(), items.end(), comp);

    int curWgt = 0;
    double maxval = 0;

    for(int i =0; i < n; i++){
        if(curWgt + items[i].first <= w){
            maxval += items[i].second;
            curWgt += items[i].first;
        }
        else{
            int remain = w - curWgt;

            double ratio = ((double)items[i].second/(double)items[i].first)*(double)remain;
            maxval += ratio;

            break;
        }
    }

    return maxval;


}