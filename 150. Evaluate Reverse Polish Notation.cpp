 int evalRPN(vector<string>& tokens) {
        stack<int>s;

        for (const string& t : tokens){
            if (t.size() > 1 || isdigit(t[0])){
                s.push(stoi(t));
            }
            else{
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();

                switch(t[0]){
                    case '+': 
                        s.push(a + b);
                        break;
                    case '-':
                        s.push(b - a);
                        break;
                    case '*':
                        s.push(a * b);
                        break;
                    case '/':
                        s.push(b / a);
                        break;
                }

            }
        }
        return s.top();
        
    }

'''
  Python implementation
  class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for c in tokens:
            if c == '+':
                stack.append(stack.pop() + stack.pop())
            elif c == '-':
                a, b = stack.pop(), stack.pop()
                stack.append(b - a)
            elif c == '*':
                stack.append(stack.pop() * stack.pop())
            elif c == '/':
                a, b = stack.pop(), stack.pop()
                stack.append(int(b / a))
            else:
                stack.append(int(c))
        return stack[0]
        
'''
