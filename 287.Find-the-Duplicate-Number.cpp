// Using Binary Search
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l = 1, r = nums.size() - 1, ans = INT_MAX;
        while(l <= r){
            int mid = l + (r - l)/2;
            int cnt = 0;
            for(int i : nums)
                if(i <= mid) 
                    ++cnt;
            if(cnt > mid){
                r = mid - 1;
                ans = min(ans, mid);
            }
            else l = mid + 1;
        }
        return ans;
    }
};

// Using Floyd Cycle Detection
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast) break;
        }
        int slow2 = 0;
        while(true){
            slow = nums[slow];
            slow2 = nums[slow2];
            if(slow == slow2) break;
        }
        return slow;
    }
};