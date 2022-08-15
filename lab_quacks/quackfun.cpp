/**
 * @file quackfun.cpp
 * This is where you will implement the required functions for the
 * stacks and queues portion of the lab.
 */

namespace QuackFun {

/**
 * Sums items in a stack.
 *
 * **Hint**: think recursively!
 *
 * @note You may modify the stack as long as you restore it to its original
 * values.
 *
 * @note You may use only two local variables of type T in your function.
 * Note that this function is templatized on the stack's type, so stacks of
 * objects overloading the + operator can be summed.
 *
 * @note We are using the Standard Template Library (STL) stack in this
 * problem. Its pop function works a bit differently from the stack we
 * built. Try searching for "stl stack" to learn how to use it.
 *
 * @param s A stack holding values to sum.
 * @return  The sum of all the elements in the stack, leaving the original
 *          stack in the same state (unchanged).
 */
template <typename T>
T sum(stack<T>& s)
{

    // Your code here
    if (s.empty()){
        return 0;
    }
    
    T top = s.top();
    s.pop();
    if(s.empty()){
        s.push(top);
        return top;
    }
    else{
        T top2 = sum(s);
        s.push(top);
        return top2 + top;
    }
        
    
                // stub return value (0 for primitive types). Change this!
                // Note: T() is the default value for objects, and 0 for
                // primitive types
}

/**
 * Checks whether the given string (stored in a queue) has balanced brackets.
 * A string will consist of square bracket characters, [, ], and other
 * characters. This function will return true if and only if the square bracket
 * characters in the given string are balanced. For this to be true, all
 * brackets must be matched up correctly, with no extra, hanging, or unmatched
 * brackets. For example, the string "[hello][]" is balanced, "[[][[]a]]" is
 * balanced, "[]]" is unbalanced, "][" is unbalanced, and "))))[cs225]" is
 * balanced.
 *
 * For this function, you may only create a single local variable of type
 * `stack<char>`! No other stack or queue local objects may be declared. Note
 * that you may still declare and use other local variables of primitive types.
 *
 * @param input The queue representation of a string to check for balanced brackets in
 * @return      Whether the input string had balanced brackets
 */
bool isBalanced(queue<char> input)
{

    // @TODO: Make less optimistic
    

    std::stack<char> st;
    if(input.empty()){
        return true;
    } 

    while(!input.empty()){
        if (input.front() == '['){
            st.push(input.front());
            input.pop();
        }
        else if (input.front() == ']' && st.empty()){
            return false;
        }
        else if (input.front() == ']' && !st.empty()){
            st.pop();
            input.pop();
        }
        else{
            input.pop();
        }
    }
    if(!st.empty()){
        return false;
    }
    return true;

}

/**
 * Reverses even sized blocks of items in the queue. Blocks start at size
 * one and increase for each subsequent block.
 *
 * **Hint**: You'll want to make a local stack variable.
 *
 * @note Any "leftover" numbers should be handled as if their block was
 * complete.
 *
 * @note We are using the Standard Template Library (STL) queue in this
 * problem. Its pop function works a bit differently from the stack we
 * built. Try searching for "stl stack" to learn how to use it.
 *
 * @param q A queue of items to be scrambled
 */
template <typename T>
void scramble(queue<T>& q)
{
    queue<T> q2;
    queue<T> q3;
    stack<T> s;
    q2 = q;

    while (q.size() != 0) {
        q.pop();
    }

    for (unsigned long i = 1; !q2.empty(); i++){
        for (unsigned long c = 1; c <= i; c++){
            if(!q2.empty()){
                q3.push(q2.front());
                q2.pop();
            }
        }
        if (i % 2 == 0){
            while (q3.size() != 0){
                s.push(q3.front());
                q3.pop();
            }
            while (s.size() != 0){
                q.push(s.top());
                s.pop();
            }
        }
        else{
            while (q3.size() != 0){
                q.push(q3.front());
                q3.pop();
            }
        }
    }
}
}