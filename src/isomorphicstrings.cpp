#include <iostream>
#include <string>
#include <vector>
#include <map>
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


bool isIsomorphic(std::string& s, std::string& t)
{
    if (s.length() != t.length())
        return false;

    std::map<char, char> mapping;
    
    for (int i = 0; i < s.length(); ++i) {
        char c1 = s[i];
        char c2 = t[i];
        
        if (mapping.find(c1) != mapping.end()) {
            if (mapping[c1] != c2) {
                return false;
            }
        }
        else {
            for (std::map<char, char>::iterator it = mapping.begin(); it != mapping.end(); ++it) {
                if (it->second == c2) {
                    return false;
                }
            }
            
            mapping.insert(std::pair<char, char>(c1, c2));
        }

    }

    return true;
}


int main(int argc, char* argv[])
{
    std::string a = "egg";
    std::string b = "add";
    print(a);
    print(b);
    if (isIsomorphic(a, b))
        std::cout << "Isomorphic";
    else
        std::cout << "Not Isomorphic";
    std::cout << "\n";
    std::string c = "foo";
    std::string d = "bar";
    print(c);
    print(d);
    if (isIsomorphic(c, d))
        std::cout << "Isomorphic";
    else
        std::cout << "Not Isomorphic";
    std::cout << "\n";

    return 0;
}

