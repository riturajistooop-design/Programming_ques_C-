class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int i = 0;
        while(i<s.size()){
            if(s[i] == ')'){
                if(st.size()!=0 && st.top() == '('){
                    st.pop();
                    i++;
                }
                else return false;
            }
            else if(s[i] == '}'){
                if(st.size()!=0 && st.top() == '{'){
                    st.pop();
                    i++;
                }
                else return false;
            }
            else if(s[i] == ']'){
                if(st.size()!=0 && st.top() == '['){
                    st.pop();
                    i++;
                }
                else return false;
            }
            else{
                st.push(s[i]);
                i++;
            }
        }
        if(st.size()==0) return true;
        else return false;
    }
};