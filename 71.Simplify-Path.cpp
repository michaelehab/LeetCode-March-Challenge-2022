// Using Stack
class Solution {
public:
    string simplifyPath(string path) {
        stack <string> st;
        string ans;
        
        for(int i = 0; i < path.size(); ++i){
            if(path[i] != '/'){
                string tmp;
                while(i < path.size() && path[i] != '/') tmp += path[i++];
                if(tmp != "."){
                    if(tmp == ".."){
                        if(st.size()) st.pop();
                    }
                    else st.push(tmp);
                }
            }
        }
        
        while(st.size()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }
        
        if(!ans.size()) return "/";
        
        return ans;
    }
};

// Using Deque
class Solution {
public:
    string simplifyPath(string path) {
        deque <string> d;
        string ans;
        
        for(int i = 0; i < path.size(); ++i){
            if(path[i] != '/'){
                string tmp;
                while(i < path.size() && path[i] != '/') tmp += path[i++];
                if(tmp != "."){
                    if(tmp == ".."){
                        if(d.size()) d.pop_front();
                    }
                    else d.push_front(tmp);
                }
            }
        }
        
        while(d.size()) {
            ans += "/" + d.back();
            d.pop_back();
        }
        
        if(!ans.size()) return "/";
        
        return ans;
    }
};