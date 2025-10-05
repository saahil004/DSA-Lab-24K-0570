/*
4. Given a string, implement a backtracking algorithm to print all permutations of the string characters.
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void perm(string& str, int idx, int n, vector<string>& ans) {
    if (idx == n) {
        ans.push_back(str);
        return;
    }
    for (int i = idx; i < n; i++) {
        swap(str[idx], str[i]);
        perm(str, idx+1, n, ans);
        swap(str[idx], str[i]);
    }
}

int main() {
    vector<string> ans;
    string str = "123";
    perm(str, 0, str.size(), ans);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "Permutation " << i+1 << ": " << ans[i] << endl;
    }
    
    return 0;
}
