#include <cassert>
#include <string>
#include <unordered_map>
using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool word = false;

    ~TrieNode() {
        for (auto& [_, child] : children) {
            delete child;
        }
    }
};

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }

    ~WordDictionary() { 
        delete root; 
    }

    void addWord(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children.count(c)) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->word = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }

private:
    TrieNode* root;

    bool dfs(string word, int pos, TrieNode* node) {
        TrieNode* current = node;

        for (size_t i = pos; i < word.size(); i++) {
            char c = word[i];
            if (c == '.') {
                for (auto it : current->children) {
                    if (dfs(word, i + 1, it.second)) {
                        return true;
                    }
                }
                return false;
            } else if (!current->children.count(c)) {
                return false;
            }
            current = current->children.at(c);
        }
        return current->word;
    }
};
    

int main() {
    WordDictionary wordDictionary;

    wordDictionary.addWord("day");
    wordDictionary.addWord("bay");
    wordDictionary.addWord("may");
    assert(!wordDictionary.search("say"));
    assert(wordDictionary.search("day"));
    assert(wordDictionary.search(".ay"));
    assert(wordDictionary.search("b.."));

    return 0;
}