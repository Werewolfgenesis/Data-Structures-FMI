#include <iostream>
#include <stack>

//O(N)
void reverse_stack(std::stack<char>& input){
    std::stack<char> result;
    
    
    //filling the result stack with the elements of input in reverse order
    while (!input.empty())
    {
        result.push(input.top());
        input.pop();
    }
    //couting the result stack
    while (!result.empty())
    {
        std::cout << result.top();
        result.pop();
    }
    //if we want to return std::stack
    // input = result;
    // return result;
}
//task2
//T(N) = O(N) + O(N^2) = O(N^2)
bool isValid2(const char* str)
{
    //O(N)
    int counter = 0;
    int index = 0;
    while (str[index])
    {
        if (str[index] == '(' || str[index] == ')' || 
        str[index] == '{' || str[index] == '}' ||
        str[index] == '[' || str[index] == ']' )
        {
            counter++;
        }
        index++;
    }
    if (counter % 2 != 0)
    {
        return false;
    }
    //O(N^2)
    std::stack<char> mystack;
    for (size_t i = 0; str[i]; i++)
    {
        if(str[i] == '(')
        {
            mystack.push('(');
            for (size_t j = i; str[j]; j++)
            {
                if (str[j] == ')')
                {
                    mystack.pop();
                    break;
                } 
            }   
        }
        else if(str[i] == '[')
        {
            mystack.push('[');
            for (size_t j = i; str[j]; j++)
            {
                if (str[j] == ']')
                {
                    mystack.pop();
                    break;
                }
            }
        }
        else if(str[i] == '{')
        {
            mystack.push('{');
            for (size_t j = i; str[j]; j++)
            {
                if (str[j] == '}')
                {
                    mystack.pop();
                    break;
                }
            }
        }
    }
    return mystack.empty();
}
//task3 - postfix calc
int postfix_calc(std::string in){
    std::stack<int> result;

    for (size_t i = 0; in[i]; i++)
    {
        if (in[i] >= '0' && in[i] <= '9')
        {
            result.push(in[i] - '0');
        }
        else if(in[i] == '+'){
            int first = result.top(); result.pop();
            int second = result.top(); result.pop();

            result.push(second + first);
        }
        else if(in[i] == '*'){
            int first = result.top(); result.pop();
            int second = result.top(); result.pop();

            result.push(second * first);
        }
        else if(in[i] == '/'){
            int first = result.top(); result.pop();
            int second = result.top(); result.pop();

            result.push(second / first);
        }
    }
    return result.top();
}
//task 5
//sort stack
std::stack<int> sort(std::stack<int>& in){
    std::stack<int> temp;

    while (!in.empty())
    {
        int current_top = in.top(); in.pop();

        while (!temp.empty() && temp.top() > current_top)
        {
            in.push(temp.top());
            temp.pop();
        }
        
        temp.push(current_top);
    }
    return temp;
}

void test(){
    std::cout << std::boolalpha << isValid2("(())"); // true
    std::stack<int> in;
    in.push(3);
    in.push(1);
    in.push(21);
    in.push(7);
    in.push(8);

    std::stack<int> res = sort(in);

    while (!res.empty())
    {
        std::cout << res.top() << std::endl; res.pop();
    }
    std::cout << postfix_calc("437+*2/");
}
int main()
{
    test();
    return 0;   
}