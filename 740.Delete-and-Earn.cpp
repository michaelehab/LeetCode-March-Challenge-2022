class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int N = nums.size();
        if(N == 1) return nums[0];
        int mx = INT_MIN;
        unordered_map <int, int> score;
        
        for(int n : nums){
            score[n] += n;
            mx = max(mx, n);
        }
        
        vector<int> dp(mx + 1, 0);
        dp[0] = 0;
        dp[1] = score[1];
        for(int i = 2; i <= mx; i++) dp[i] = max(dp[i - 1], score[i] + dp[i-2]);
        
        return dp[mx];
    }
};