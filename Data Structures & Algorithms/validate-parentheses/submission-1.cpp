
class Solution {
    int top;
    vector<char> st;
public:
    bool isValid(string s) {
        for(int i=0; i < s.size(); i++) {
            switch(s[i]){
                case ')':
                    if(st.size() > 0 && st[st.size()-1] == '(') {
                        pop();
                    } else {
                        return false;
                    }
                break;
                case '}':
                    if(st.size() > 0 && st[st.size()-1] == '{') {
                        pop();
                    } else {
                        return false;
                    }
                break;
                case ']':
                    if(st.size() > 0 && st[st.size()-1] == '[') {
                        pop();
                    } else {
                        return false;
                    }
                break;
                default:
                    st.push_back(s[i]);
            }
        }
        if(st.size() > 0) {
            return false;
        }
        return true;
    }

    void pop() {
        st.pop_back();
    }
};
