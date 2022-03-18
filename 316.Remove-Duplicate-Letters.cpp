class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map <char, int> occ;
        unordered_map <char, bool> seen;
        
        for(auto &c : s) occ[c]++;
        
        string ans;
        for(auto &c : s){
            occ[c]--;
            if(!seen[c]){
                while(ans.length() && ans.back() > c && occ[ans.back()] != 0){
                    seen[ans.back()] = false;
                    ans.pop_back();
                }
                seen[c] = true;
                ans += c;
            }
        }
        
        return ans;
    }
};