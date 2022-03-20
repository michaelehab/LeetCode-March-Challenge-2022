class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        unordered_map <int, int> top_occ, bottom_occ, same_occ;
        
        for(int i = 0; i < n; ++i){
            ++top_occ[tops[i]];
            ++bottom_occ[bottoms[i]];
            
            if(tops[i] == bottoms[i]) ++same_occ[tops[i]];
        }
        
        int minRotation = INT_MAX;
        
        for(int i = 1; i <= 6; ++i){
            if(top_occ[i] + bottom_occ[i] - same_occ[i] == n)
                minRotation = min(minRotation , min(top_occ[i],bottom_occ[i]) - same_occ[i]);
        }
        
        return minRotation == INT_MAX ? -1 : minRotation;
    }
};