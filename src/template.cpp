////////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <vector>
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


int main(int argc, char* argv[])
{


    return 0;
}

