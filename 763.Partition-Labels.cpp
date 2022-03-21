class Solution {
public:
    vector<int> partitionLabels(string s) {
        int N = s.length();
        unordered_map <char,int> mp;
        for(int i = 0; i < N; ++i) mp[s[i]] = i;
        
        vector <int> ans;
        int l = 0, r = 0;
        
        for(int i = 0; i < N; ++i){
            r = max(r, mp[s[i]]);
            if(i == r){
                ans.push_back(r - l + 1);
                l = r + 1;
            }
        }
        return ans;
    }
};