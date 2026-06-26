class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        //unordered_set<string>num = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0"};
        for(auto s: tokens){
            if(s!="+"&&s!="-"&&s!="*"&&s!="/"){
                int val = stoi(s);
                st.push(val);
            }
            else{
                if(s=="+"){
                    int op1 = st.top();
                    st.pop();
                    int op2 = st.top();
                    st.pop();
                    st.push(op1+op2);
                }
                if(s=="-"){
                    int op1 = st.top();
                    st.pop();
                    int op2 = st.top();
                    st.pop();
                    st.push(op2-op1);
                }
                if(s=="*"){
                    int op1 = st.top();
                    st.pop();
                    int op2 = st.top();
                    st.pop();
                    st.push(op1*op2);
                }
                if(s=="/"){
                    int op1 = st.top();
                    st.pop();
                    int op2 = st.top();
                    st.pop();
                    st.push(op2/op1);
                }
            }
            }
            return st.top();
        }
};
