class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i = 0 ; i < tokens.size() ; i++){
            string t = tokens[i];
            if (t == "+" || t == "-" || t == "*" || t == "/") {
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();
                if (t == "+") a += b;
                else if (t == "-") a -= b;
                else if (t == "*") a *= b;
                else a /= b; 
                        s.push(a); // Push result back
            } else {
                // If it's a number, convert and push to stack
                s.push(stoi(t));
            }
        }
        return s.top(); // Final result
    
        }
    
};