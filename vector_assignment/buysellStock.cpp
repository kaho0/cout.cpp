#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int price : prices) {
            // Update min price so far
            if (price < minPrice) {
                minPrice = price;
            }
            // Calculate profit if selling today
            int profit = price - minPrice;
            if (profit > maxProfit) {
                maxProfit = profit;
            }
        }
        return maxProfit;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    cout << "Max profit (Example 1): " << sol.maxProfit(prices1) << endl;

    // Example 2
    vector<int> prices2 = {7, 6, 4, 3, 1};
    cout << "Max profit (Example 2): " << sol.maxProfit(prices2) << endl;

    return 0;
}
