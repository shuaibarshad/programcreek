////////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <list>


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

//
// Given two words (start and end), and a dictionary, find the length of 
// shortest transformation sequence from start to end, such that only one letter
// can be changed at a time and each intermediate word must exist in the 
// dictionary. For example, given:
// start = "hit"
// end = "cog"
// dict = ["hot","dot","dog","lot","log"]
//

class WordNode
{
public:
    WordNode(std::string w, int s)
    : word(w)
    , numSteps(s)
    { }
    
    std::string word;
    int numSteps;
};


int ladderLength(const std::string& beginWord, const std::string& endWord,
        std::set<std::string>& wordDict)
{
    std::list<WordNode> queue;
    queue.push_back(WordNode(beginWord, 1));

    wordDict.insert(endWord);

    while(!queue.empty()) {
        WordNode top = queue.front();
        queue.pop_front();
        std::string word = top.word;

        if (word.compare(endWord) == 0) {
            return top.numSteps;
        }
        
        std::string newWord = word;
        for (int i = 0; i < newWord.length(); ++i) {
            for (char c = 'a'; c < 'z'; ++c) {
                char temp = newWord[i];
                if (newWord[i] != c) {
                    newWord[i] = c;
                }
                if (wordDict.find(newWord) != wordDict.end()) {
                    queue.push_back(WordNode(newWord, top.numSteps+1));
                    wordDict.erase(newWord);
                }

                newWord[i] = temp;
            }
        }
    }

    return 0;
}


int main(int argc, char* argv[])
{
    std::string beginWord("hit");
    std::string endWord("cog");
    std::set<std::string> dict;
    dict.insert(std::string("hot"));
    dict.insert(std::string("dot"));
    dict.insert(std::string("dog"));
    dict.insert(std::string("lot"));
    dict.insert(std::string("log"));
    
    int len = ladderLength(beginWord, endWord, dict);

    std::cout << len << "\n";

    return 0;
}

