#include <vector>
#include <string>
#include <algorithm>
#define INT_MAX 2147483640
using namespace std;

int solution(vector<string> arr)
{
    vector<int> num;
    vector<char> op;
    for (int i = 0; i < arr.size(); i++) {
        if (i & 1) op.push_back(arr[i][0]);
        else num.push_back(stoi(arr[i]));
    }
    int n = num.size();

    vector<vector<int>> max_dp(n, vector<int>(n, -INT_MAX));
    vector<vector<int>> min_dp(n, vector<int>(n, INT_MAX));

    for (int i = 0; i < n; i++) {
        max_dp[i][i] = num[i];
        min_dp[i][i] = num[i];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            int k = j + i;

            for (int l = j; l < k; l++) {
                if (op[l] == '+') {
                    max_dp[j][k] = max(max_dp[j][k], max_dp[j][l] + max_dp[l + 1][k]);
                    min_dp[j][k] = min(min_dp[j][k], min_dp[j][l] + min_dp[l + 1][k]);
                } else {
                    max_dp[j][k] = max(max_dp[j][k], max_dp[j][l] - min_dp[l + 1][k]);
                    min_dp[j][k] = min(min_dp[j][k], min_dp[j][l] - max_dp[l + 1][k]);
                }
            }
        }
    }

    return max_dp[0][n - 1];
}