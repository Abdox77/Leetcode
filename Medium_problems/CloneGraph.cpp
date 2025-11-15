
/*
// Definition for a Node.
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
*/

/*
// Definition for a Node.
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
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node)
            return nullptr;
        Node *curr = nullptr;
        queue<Node *>list;
        unordered_map<int, Node *> map;
        unordered_map<int, bool> visitedNodes;

        list.push(node);
        while(!list.empty())
        {
            Node *holder = list.front();
            list.pop();
            if (visitedNodes.find(holder->val) != visitedNodes.end())
                continue;
            if(map.find(holder->val) == map.end())
            {
                curr = new Node(holder->val);
                map[curr->val] = curr;
            }
            else
            {
                curr = map[holder->val];
            }
            for(int i = 0; i < holder->neighbors.size(); ++i)
            {
                Node *currNeighbor = holder->neighbors[i];
                if(map.find(holder->neighbors[i]->val) == map.end())
                {
                    currNeighbor = new Node(currNeighbor->val);
                    map[currNeighbor->val] = currNeighbor;
                    curr->neighbors.push_back(currNeighbor);
                    
                }
                else
                {
                    curr->neighbors.push_back(map[currNeighbor->val]);
                }
                list.push(holder->neighbors[i]);
            }
            visitedNodes[holder->val] = true;
        }
        return map[1];
    }
};

