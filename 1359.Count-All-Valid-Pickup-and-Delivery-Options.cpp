class Solution {
public:
    int MOD = 1e9 + 7;
    int countOrders(int n) {
        long ans = 1;
        for(int i = 1; i <=n; i++){
            ans *= i;
            ans *= (2 * i - 1);
            ans %= MOD;
        }
        return ans;
    }
    
};