class Solution {
public:
    bool isValid(string s) {
        stack <char> tmp;
        
        for(int i = 0; i < s.length(); i++) {
            char top = tmp.empty() ? '#' : tmp.top();
            if(top == '(' && s[i] == ')') tmp.pop();
            else if(top == '{' && s[i] == '}') tmp.pop();
            else if(top == '[' && s[i] == ']') tmp.pop();
            else tmp.push(s[i]);  
        }
        
        return tmp.empty();
    }
};