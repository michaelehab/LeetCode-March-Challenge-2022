class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans(n, 'a');
        int ptr = n - 1;
        
        k -= n;
        while (k > 0) {
            ans[ptr--] += min(k, 25);
            k -= min(k, 25);
        }
        
        return ans;
    }
};