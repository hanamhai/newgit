#include <iostream>
#include <vector>
#include <climits>
#include <cstdlib>

struct Node{
    int key, priority;
    Node *left, *right;
    Node(int x){
        key = x;
        priority = rand() % 10000;
        left = right = NULL;
    }
};

class Treap{
private:
    Node *root;

    Node * rotateLeft(Node *p){
        Node *q = p->right;
        
        p->right = q->left;
        q->left = p;

        return q;
    }

    Node * rotateRight(Node *q){
        Node *p = q->left;

        q->left = p->right;
        p->right = q;

        return p;
    }

     Node * insert(Node *sub_tree, int key){
        // If leaf is reached
        if(sub_tree == NULL)
            return new Node(key);
        
        if(sub_tree->key < key){
            // Run insert for right sub-tree
            sub_tree->right = insert(sub_tree->right, key);

            // Check if right subtree satisfies min-heap property
            if(sub_tree->right->priority < sub_tree->priority){
                // Perform left rotate
                sub_tree = rotateLeft(sub_tree);
                
            }
        }
        else{
            // Run insert for left sub-tree
            sub_tree->left = insert(sub_tree->left, key);

            // Check if left subtree satisfies min-heap property
            if(sub_tree->left->priority < sub_tree->priority){
                // Perform right rotate
                sub_tree = rotateRight(sub_tree);
            }
        }
        return sub_tree;
    }

    Node * search(Node *sub_tree, int key){
        if(sub_tree == NULL)
            return NULL;
        
        if(sub_tree->key == key)
            return sub_tree;
        else if(sub_tree->key < key){
            return(search(sub_tree->right, key));
        }
        else return(search(sub_tree->left, key));
    }

    void inorderTraversal(Node *node){
        if(node == NULL)
            return;
        inorderTraversal(node->left);
        std::cout << node->key << ' ';
        inorderTraversal(node->right);
    }
public:
    Treap(){
        root = NULL;
    }

    void insert(int x){
        root = insert(root, x);
    }

    void Search(int x){
        Node *temp = search(root, x);
        if(temp == NULL)
            std::cout << "Key not found\n";
        else
            std::cout << "Key found with priority " << temp->priority
                      << '\n';
    }

    void inorderTraversal(){
        inorderTraversal(root);
    }
    
};

int main() {
    std::vector<int> ar = {5, 4, 3, 2, 1};
    Treap tree;
    for(auto x : ar)
        tree.insert(x);
    tree.inorderTraversal();
    std::cout << '\n';
}
