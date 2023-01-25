class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n=tokens.size();

        stack<int>st;
        for(int i=0;i<n;i++){

            if(tokens[i]!="+" && tokens[i]!="-" && tokens[i]!="*" && tokens[i]!="/"){

             stringstream temp(tokens[i]);
                int k;
                temp>>k;
                st.push(k);
            }
            if(tokens[i]=="+"){
                int m = st.top();
                st.pop();
                int n = m+st.top();
                st.pop();
                st.push(n);
            }
            else if(tokens[i]=="-"){
                int m = st.top();
                st.pop();
                int n = st.top();
                st.pop();
                st.push(n-m);
            }
            else if(tokens[i]=="*"){
                int m = st.top();
                st.pop();
                int n = m*st.top();
                st.pop();
                st.push(n);
            }
            else if(tokens[i]=="/"){
                int m = st.top();
                st.pop();
                int n = st.top()/m;
                st.pop();
                st.push(n);
            }
            // else{
            //     stringstream temp(tokens[i]);
            //     int k;
            //     temp>>k;
            //     st.push(k);
            // }
        }

        return st.top();
    }
};