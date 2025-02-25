#include <cassert>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
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

    void addWord(string word) {
        TrieNode* node = this;
        for (char c : word) {
            if (!node->children.count(c)) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->word = true;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        trie = new TrieNode();

        for (string word : words) {
            trie->addWord(word);
        }

        rows = board.size();
        cols = board[0].size();
        visited.assign(rows, vector<bool>(cols, false));

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                dfs(board, r, c, trie, "");
            }
        }

        delete trie;
        return vector<string>(found_words.begin(), found_words.end());
    }
private:
    unordered_set<string> found_words;
    vector<vector<bool>> visited;

    TrieNode* trie;

    int rows;
    int cols;

    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node, string word) {
        if (r < 0 || r >= rows
            || c < 0 || c >= cols
            || visited[r][c]
            || !node->children.count(board[r][c])
        ) {
            return;
        }

        visited[r][c] = true;
        node = node->children[board[r][c]];
        word += board[r][c];
        if (node->word) {
            found_words.insert(word);
        }

        dfs(board, r + 1, c, node, word);
        dfs(board, r - 1, c, node, word);
        dfs(board, r, c + 1, node, word);
        dfs(board, r, c - 1, node, word);

        visited[r][c] = false;
    }
};
    

int main() {
    Solution sol;

    vector<vector<char>> board{
        {'a', 'b', 'c', 'd'},
        {'s', 'a', 'a', 't'},
        {'a', 'c', 'k', 'e'},
        {'a', 'c', 'd', 'n'}
    };
    vector<string> words{"bat","cat","back","backend","stack"};
    vector<string> expected{"cat","backend","back"};
    assert(sol.findWords(board, words) == expected);

    return 0;
}