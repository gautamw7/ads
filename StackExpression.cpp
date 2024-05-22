#include<iostream>
#include<stack>
using namespace std;

int valueOfChar(char c){
    if(c == '^') return 3;
    else if(c == '*' || c == '/') return 2;
    else if(c == '+' || c == '-') return 1;
    else return 0;
}

string infixToPostfix(string exp){
    stack<char> stack;
    string result = "";
    for(char item : exp){
        if(isalnum(item)){
            result += item;
        }else if(item == '('){
            stack.push(item);
        }else if(item == ')'){
            while(!stack.empty() && stack.top() != '('){
                result += stack.top();
                stack.pop();
            }
            stack.pop();
        }else{
            while(!stack.empty() && valueOfChar(item)  <= valueOfChar(stack.top())){
                result += stack.top();
                stack.pop();
            }
            stack.push(item);
        }
    }

    while (!stack.empty()) {
        result += stack.top();
        stack.pop();
    }

    return result;
}

string reverse(string reverse){
    string result = "";
    for(int i = reverse.length() - 1; i>= 0; i--){
        if(reverse[i] == '(' ) reverse[i] = ')';
        else if(reverse[i] == ')' ) reverse[i] = '(';
        result += reverse[i];
    }
    return result;
}

std::string infixToPrefix(std::string exp){
    string newexp = reverse(exp);
    string result = "";
    stack<char> stack;
    for(char item : newexp){
        if(isalnum(item)){
            result += item;
        }else if(item == '('){
            stack.push(item);
        }else if(item == ')'){
            while(!stack.empty() && stack.top() != '('){
                result += stack.top();
                stack.pop();
            }
            stack.pop();
        }
        else{
            while(!stack.empty() && valueOfChar(item ) <= valueOfChar(stack.top()) ){
                result += stack.top();
                stack.pop();
            }
            stack.push(item);
        }
    }
    while(!stack.empty()){
        result += stack.top();
        stack.pop();
    }
    return reverse(result);
}

int main(){
    string expression = "((A+B)/(d*e-c))^B*D-E";

    string result1 = infixToPrefix(expression);
    string result2 = infixToPostfix(expression);
    cout << "Infix to Prefix " << result1 << " INfix to Postfix " << result2;
}