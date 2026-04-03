class Solution {
public:
    bool isValid(string s) {
        
        //create the stack and the mapping of close to open brackets
        stack<char> stack;
        unordered_map<char, char> closeToOpen = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for(char c:s)
        {
            // if the character given is in my map
            if(closeToOpen.count(c)) // if it's a closing parentheses aka the key
            {
                // if the stack is not empty and the most recent element is the matching open brace
                if(!stack.empty() && stack.top() == closeToOpen[c])
                {
                    stack.pop(); //pop the open brace off the stack
                }
                else
                {
                    return false;
                }
            }
            else
            {
                stack.push(c);
            }
        }

        return stack.empty();
    }
};
