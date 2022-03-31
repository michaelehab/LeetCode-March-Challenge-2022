class Solution {
public:
    bool canSplit(vector<int>& nums, int maxSum, int m) {
        int sum = 0;
        int total = 0;
        
        for (int n : nums) {
            if (sum + n <= maxSum) sum += n;
            else {
                sum = n;
                total++;
            }
        }
        
        return (total + 1 <= m);
    }
    
    int splitArray(vector<int>& nums, int m) {
        int l = INT_MIN, r = 0, ans = 0;
        for (int n : nums) {
            r += n;
            l = max(l, n);
        }
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (canSplit(nums, mid, m)) {
                r = mid - 1;
                ans = mid;
            } 
            else l = mid + 1;
        }
        
        return ans;
    }
};