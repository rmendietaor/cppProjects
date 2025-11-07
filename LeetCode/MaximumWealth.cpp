#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int currMax = 0;
        int maxWealth = 0;
        int currAcc = 0;
        //int custSize = accounts.size();
        //int accSize = accounts[1].size();
        //cout << "Accounts size: " << accSize << endl;
        //cout << "Customers size: " << custSize << endl;
        for(int i=1; i<=accounts.size(); i++){
            //cout << "i: " << i << endl;
            for(int j=1; j<=accounts[i-1].size(); j++){
                currAcc = accounts[i-1][j-1];
                currMax = currMax + accounts[i-1][j-1];
                //cout << "j: " << j << endl;
                cout << "Current account: " << currAcc << endl;
            }
            if(currMax>maxWealth)
                maxWealth = currMax;
                currMax = 0;
        }
        return maxWealth;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> accounts = {{1, 1}, {2, 3}, {5, 6}};
    int result = solution.maximumWealth(accounts);
    cout << result << endl;
}