#include<bits/stdc++.h>
using namespace std;

template<class K, class V>
class BinaryTree{
    public: 
        class Node;

    private: Node* root;

    public:
        BinaryTree() : root(nullptr){}
        ~BinaryTree(){}
        class Node{
            private: 
                K key; // dùng để
                V value; // dùng để lưu giá trị
                Node *pRight, *pLeft;
                friend class BinaryTree;
            
            public:
                Node(K key_in, V value_in): key(key_in), value(value_in), pLeft(NULL), pRight(NULL){}
                ~Node(){}      
        };
        void BFS();
        void addNode(string posFromRoot, K key_in, V value_in){
            if(posFromRoot == ""){
                this->root = new Node(key_in, value_in);
                return;
            }
            Node *current = this->root;
            int n = posFromRoot.size();
            for(int i = 0; i < n - 1; i++){
                if(!current){
                    return;
                }
                if(posFromRoot[i] == 'L')  current = current->pLeft;
                if(posFromRoot[i] == 'R')   current = current->pRight;
                
            }

            if(posFromRoot[n - 1] == 'L')   current->pLeft = new Node(key_in, value_in);
            if(posFromRoot[n - 1] == 'R')   current->pRight = new Node(key_in, value_in);
        }
};

template<class K, class V>
void BinaryTree<K, V>::BFS() {
    if (root == nullptr) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        cout <<curr->value << " ";
        if (curr->pLeft) q.push(curr->pLeft);
        if (curr->pRight) q.push(curr->pRight);

    }
}
int main(){
    BinaryTree<int, int> binaryTree;
    binaryTree.addNode("",2, 4); // Add to root
    binaryTree.addNode("L",3, 6); // Add to root's left node
    binaryTree.addNode("R",5, 9); // Add to root's right node
    binaryTree.BFS();
}