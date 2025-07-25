#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> prices(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> prices[i];
    }

    std::vector<int> dp(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i] = std::max(dp[i], dp[i - j] + prices[j - 1]);
        }
    }

    std::cout << dp[N] << std::endl;
    return 0;
}
