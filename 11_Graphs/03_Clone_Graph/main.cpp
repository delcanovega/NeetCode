#include <cassert>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }

        unordered_map<Node*, Node*> clones_by_original;
        return deep_clone(node, clones_by_original);
    }
private:
    Node* deep_clone(Node* node, unordered_map<Node*, Node*>& clones_by_original) {
        if (clones_by_original.find(node) != clones_by_original.end()) {
            return clones_by_original[node];
        }

        Node* clon = new Node(node->val);
        clones_by_original[node] = clon;
        for (Node* neighbor : node->neighbors) {
            clon->neighbors.push_back(deep_clone(neighbor, clones_by_original));
        }
        return clon;
    } 
};

Node* build_graph(const vector<vector<int>>& adj_list) {
    if (adj_list.empty()) {
        return nullptr;
    }
    
    unordered_map<int, Node*> nodes;
    
    // Create all nodes
    for (size_t i = 0; i < adj_list.size(); ++i) {
        nodes[i + 1] = new Node(i + 1);
    }

    // Connect neighbors
    for (size_t i = 0; i < adj_list.size(); ++i) {
        for (int neighbor : adj_list[i]) {
            nodes[i + 1]->neighbors.push_back(nodes[neighbor]);
        }
    }
    
    return nodes[1];
}

vector<vector<int>> serialize_graph(Node* node) {
    if (!node) {
        return {};
    }
    
    unordered_map<int, vector<int>> adj_map;
    unordered_map<int, bool> visited;
    queue<Node*> q;
    
    q.push(node);
    visited[node->val] = true;
    
    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        
        for (Node* neighbor : curr->neighbors) {
            adj_map[curr->val].push_back(neighbor->val);
            if (!visited[neighbor->val]) {
                visited[neighbor->val] = true;
                q.push(neighbor);
            }
        }
    }
    
    int n = adj_map.size();
    vector<vector<int>> adj_list(n);
    
    for (int i = 1; i <= n; ++i) {
        adj_list[i - 1] = adj_map[i];
    }
    
    return adj_list;
}

int main() {
    Solution sol;

    vector<vector<int>> input{{2}, {1,3}, {2}};
    Node* node = build_graph(input);
    Node* clon = sol.cloneGraph(node);
    assert(serialize_graph(clon) == input);

    return 0;
}