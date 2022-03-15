class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();
        
        int tmp = 0; 
        for(int i = 0; i < n; ++i){
            if(s[i]== '(') ++tmp;
            else if(s[i] == ')'){
                if(tmp == 0) s[i] = 'I';
                else --tmp;
            }
        }
        
        tmp = 0;
        for(int i = n - 1; i >= 0; --i){
            if(s[i]==')') ++tmp;
            else if(s[i]=='('){
                if(tmp == 0) s[i] = 'I';
                else --tmp;
            }
        }
        
        string ans;
        for(int i = 0; i < n; ++i){
            if(s[i] != 'I') ans += s[i];
        }
        
        return ans;
    }
};