class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> stk;

        for (char c : expression) {
            if (c == ')') {
                // Process the current sub-expression
                vector<char> subExpr;
                while (stk.top() != '(') {
                    subExpr.push_back(stk.top());
                    stk.pop();
                }
                stk.pop();  // Pop the '('
                char op = stk.top();  // Get the operator
                stk.pop();  // Pop the operator

                // Evaluate based on the operator
                bool result;
                if (op == '!') {
                    // NOT operator
                    result = !(subExpr[0] == 't');
                } else if (op == '&') {
                    // AND operator
                    result = true;
                    for (char expr : subExpr) {
                        if (expr == 'f') {
                            result = false;
                            break;
                        }
                    }
                } else if (op == '|') {
                    // OR operator
                    result = false;
                    for (char expr : subExpr) {
                        if (expr == 't') {
                            result = true;
                            break;
                        }
                    }
                }

                // Push the result of the evaluation
                stk.push(result ? 't' : 'f');
            } else if (c != ',') {
                // Push the characters into the stack except for commas
                stk.push(c);
            }
        }

        // Return the final evaluated result
        return stk.top() == 't';
    }
};
