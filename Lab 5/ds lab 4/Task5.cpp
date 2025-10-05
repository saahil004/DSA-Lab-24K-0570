/*
5. Given an array of distinct integers and a target number, find all unique combinations where numbers
sum to the target using backtracking.
*/
#include <iostream>
#include <vector>
using namespace std;

int sum(vector<int>& arr) {
    int t = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        t += arr[i];
    }
    return t;
}

void sumCombos(vector<int>& nums, int idx, int n, vector<vector<int>>& ans, vector<int>& arr, int t) {
    
    if (sum(arr) == t)
    {
        ans.push_back(arr);
        return;
    }
    
    if (idx >= n) { return; }
    for (int i = idx; i < n; i++)
    {
        arr.push_back(nums[i]);
        sumCombos(nums, i+1, n, ans, arr, t);
        arr.pop_back();
    }
    
}


int main() {
    vector<int> nums = {2, 3, 5, 7}; // distinct integers
    int target = 5;                 // target sum to find

    vector<vector<int>> ans;  // stores all combinations
    vector<int> arr;          // temporary combination

    sumCombos(nums, 0, nums.size(), ans, arr, target);

    cout << "Combinations that sum to " << target << " are:\n";
    if (ans.empty()) {
        cout << "No combinations found.\n";
    } else {
        for (auto& combo : ans) {
            cout << "[ ";
            for (int num : combo) cout << num << " ";
            cout << "]\n";
        }
    }

    return 0;
}
