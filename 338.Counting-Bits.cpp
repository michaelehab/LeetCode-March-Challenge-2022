// O(nlogn)
class Solution {
public:
    int count_bits(int n){
        int bits = 0;
        while(n != 0){
            bits += n % 2;
            n /= 2;
        }
		return bits;
    }
    vector<int> countBits(int n) {
        vector <int> ans;
        for(int i = 0; i <= n; i++){
            ans.push_back(count_bits(i));
        }
        return ans;
    }
};

// O(n)
class Solution {
public:
    vector<int> countBits(int n) {
        vector <int> ans(n + 1);
        ans[0] = 0;
        if(n != 0){
            ans[1] = 1;
            for(int i = 2; i <= n; i++) ans[i] = ans[i / 2] + (i % 2);
        }
        return ans;
    }
};