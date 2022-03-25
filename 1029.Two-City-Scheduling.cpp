// DP => Time : O(n^2) Space : O(n)
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size()/2;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; i++) dp[i][0] = dp[i - 1][0] + costs[i - 1][0];
        for (int j = 1; j <= n; j++) dp[0][j] = dp[0][j - 1] + costs[j - 1][1];

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dp[i][j] = min(
                    dp[i - 1][j] + costs[i + j - 1][0], 
                    dp[i][j - 1] + costs[i + j - 1][1]
            );

        return dp[n][n];
    }
};

// Greedy => Time : O(nlogn) Space : O(n)
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int N = costs.size();
        vector<int> diff(N);
        int ans = 0;
        
        for(int i = 0; i < N; ++i){
            ans += costs[i][0];
            diff[i] = costs[i][1] - costs[i][0];
        }
        
        sort(diff.begin(),diff.end());
        
        for(int i = 0; i < N / 2; ++i) ans += diff[i];
        
        return  ans;
    }
};