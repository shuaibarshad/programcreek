#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <sstream>
#include <algorithm>


template<class T>
void print(const std::vector<T>& v)
{
    for (int i = 0; i < v.size(); ++i) {
        if (i > 0) {
            std::cout << ", ";
        }
        std::cout << v[i];
    }
    std::cout << "\n";
}


void print(const std::string& s)
{
    std::cout << s << "\n";
}


int evalRPN(std::vector<std::string>& tokens)
{
    int ret = 0;
    std::string ops = "+-*/";
    std::stack<std::string> st;

    for (int i = 0; i < tokens.size(); ++i) {
        if (ops.find(tokens[i]) == std::string::npos) {
            st.push(tokens[i]);
        }
        else {
            int res = 0;
            int a = atoi(st.top().c_str());  st.pop();
            int b = atoi(st.top().c_str());  st.pop();
            int index = ops.find(tokens[i]);
            switch (index) {
            case 0:
                res = a+b;
                break;
            case 1:
                res = b-a;
                break;
            case 2:
                res = a*b;
                break;
            case 3:
                res = b/a;
                break;
            }
            std::ostringstream oss;
            oss << res;
            st.push(oss.str());
        }
    }

    ret = atoi(st.top().c_str());  st.pop();
    return ret;
}


int main(int argc, char* argv[])
{
    std::vector<std::string> tokens = {"2", "1", "+", "3", "*"};
    print(tokens);
    int res = evalRPN(tokens);
    std::cout << res << "\n";

    return 0;
}

