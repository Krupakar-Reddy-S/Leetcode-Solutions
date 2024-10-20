class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> stack;

        for (char ch : expression) {
            if (ch == ',') {
                continue;
            }
            else if (ch == 't' || ch == 'f' || ch == '!' || ch == '&' || ch == '|' || ch == '(') {
                stack.push(ch);
            }
            else {
                int fc = 0;
                int tc = 0;

                while (stack.top() != '(') {
                    char top = stack.top();

                    if (top == 'f') {
                        fc++;
                    }
                    else {
                        tc++;
                    }

                    stack.pop();
                }

                stack.pop();

                if (stack.empty()) {
                    stack.push(tc == 1 ? 't' : 'f');
                }
                else {
                    char op = stack.top();
                    stack.pop();

                    if (op == '!') {
                        stack.push(fc == 1 ? 't' : 'f');
                    }
                    else if (op == '|') {
                        stack.push(tc != 0 ? 't' : 'f');
                    }
                    else {
                        stack.push(fc == 0 ? 't' : 'f');
                    }
                }

            }
        }

        return stack.top() == 't';
    }
};