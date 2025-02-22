#include <cassert>
#include <string>
#include <unordered_map>
using namespace std;

class PrefixTree {
public:
    PrefixTree() {}
    
    void insert(string word) {
        PrefixTree* node = this;
        for (char c : word) {
            if (!node->has(c)) {
                node->insert(c);
            }
            node = node->at(c);
        }
        node->markAsWord();
    }
    
    bool search(string word) {
        PrefixTree* node = find(word);
        return node != nullptr && node->isWord();
    }
    
    bool startsWith(string prefix) {
        PrefixTree* node = find(prefix);
        return node != nullptr;
    }

    bool has(char letter) {
        return children.find(letter) != children.cend();
    }

    PrefixTree* at(char letter) {
        return children.at(letter);
    }

    void insert(char letter) {
        children[letter] = new PrefixTree();
    }

    void markAsWord() {
        word = true;
    }

    bool isWord() {
        return word;
    }

private:
    unordered_map<char, PrefixTree*> children;
    bool word;

    PrefixTree* find(string sequence) {
        PrefixTree* node = this;
        for (char c : sequence) {
            if (node->has(c)) {
                node = node->at(c);
            } else {
                return nullptr;
            }
        }
        return node;
    }
};
    

int main() {
    PrefixTree trie;

    trie.insert("dog");
    assert(trie.search("dog"));
    assert(!trie.search("do"));
    assert(trie.startsWith("do"));
    trie.insert("do");
    assert(trie.search("do"));

    return 0;
}