#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


//
// Given an input string, reverse the string word by word. A word is 
// defined as a sequence of non-space characters.
//
// The input string does not contain leading or trailing spaces and 
// the words are always separated by a single space.
//
// For example,
// Given s = "the sky is blue",
// return "blue is sky the".
//


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


// reverse all individual words first and then reverse the complete string
void reverseWords(std::string& s)
{
	int i = 0;
    for (int j = 0; j < s.length(); ++j) {
        if (s[j] == ' ') {
            std::reverse(s.begin()+i, s.begin()+j);
            i = j + 1;
        }
    }
    std::reverse(s.begin()+i, s.end());
    std::reverse(s.begin(), s.end());
}


int main(int argc, char* argv[])
{
    std::string s = "the sky is blue";
    print(s);
    reverseWords(s);
    print(s);


    return 0;
}

