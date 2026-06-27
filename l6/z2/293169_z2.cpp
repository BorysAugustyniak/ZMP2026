#include <iostream>

using namespace std;

void reverse_tab(int*& tab, int size){
    int* tab2 = new int[size];
    for (int i = 0; i < size; ++i){
        tab2[i] = tab[size - 1 - i];
    }
    delete [] tab;
    tab = tab2;
}

struct Node{
    int key;
    Node* left;
    Node* right;
    Node(){
        key = 0;
        left = nullptr;
        right = nullptr;
    }
    Node(int val){
        key = val;
        left = nullptr;
        right = nullptr;
    }
    ~Node(){
        delete left;
        delete right;
    }
    void nodeDisplay(string output, bool is_left){
        if (right != nullptr){
            right->nodeDisplay(output + (is_left ? "|   " : "    "), false);
        }
        cout << output;
        cout << (is_left ? "\\---" : "/---");
        cout << key << "\n";
        if (left != nullptr){
            left->nodeDisplay(output + (is_left ? "    " : "|   "), true);
        }
    }
    //to jest lepszy nodeDisplay, ale nie działa w niektórych czcionkach
    void nodeDisplayBetter(string output, bool is_left){
        if (right != nullptr){
            right->nodeDisplayBetter(output + (is_left ? "│   " : "    "), false);
        }
        cout << output;
        cout << (is_left ? "└───" : "┌───");
        cout << key << "\n";
        if (left != nullptr){
            left->nodeDisplayBetter(output + (is_left ? "    " : "│   "), true);
        }
    }
    void rootDisplay(){
        if (right != nullptr){
            right->nodeDisplay("", false);
            //right->nodeDisplayBetter("", false);
        }
        cout << key << "\n";
        if (left != nullptr){
            left->nodeDisplay("", true);
            //left->nodeDisplayBetter("", true);
        }
    }
};

Node* copy(Node* node){
    if (node == nullptr){
        return nullptr;
    }
    Node* node_copy = new Node();
    node_copy->key = node->key;
    node_copy->left = copy(node->left);
    node_copy->right = copy(node->right);
    return node_copy;
}

//(ii)
Node* tab_to_node(int*& tab, int size, int index){
    if (index >= size){
        return nullptr;
    }
    Node* node = new Node();
    node->key = tab[index];
    node->left = tab_to_node(tab, size, 2 * index + 1);
    node->right = tab_to_node(tab, size, 2 * index + 2);
    return node;
}

struct Tree{
    Node* root;
    Tree(){
        root = nullptr;
    };
    ~Tree(){
        delete root;
    }
    void tab_to_tree(int*& tab, int size){
        reverse_tab(tab, size);
        root = tab_to_node(tab, size, 0);
    }
    //(i)
    void combine(Tree& T1, Tree& T2, int key_value){
        root = new Node(key_value);
        root->left = copy(T1.root);
        root->right = copy(T2.root);
    }
    void treeDisplay(){
        root->rootDisplay();
    }
};

Tree tab_to_tree(int*& tab, int size){
    Tree T;
    reverse_tab(tab, size);
    T.root = tab_to_node(tab, size, 0);
    return T;
}

//(iii)
bool search(Node* root, int val){
    if (root != nullptr){
        if (root->key == val){
            return true;
        }
        else{
            return (search(root->left, val) || search(root->right, val));
        }
    }
    return false;
}

//(iv)
int height(Node* root){
    if (root != nullptr){
        return (max(height(root->left), height(root->right)) + 1);
    }
    else {return 0;}
}

//(v), 1
int nodes(Node* root){
    if (root != nullptr){
        return (nodes(root->left) + nodes(root->right) + 1);
    }
    else {return 0;}
}
//(v), 2
int leaves(Node* root){
    if (root != nullptr){
        if ((root->left == nullptr) && (root->right == nullptr)){
            return 1;
        }
        else{
            return (leaves(root->left) + leaves(root->right));
        }
    }
    else {return 0;}
}

int main(){
    Tree T;
    //wejście
    int n1, n2, r, s;
    cin >> n1 >> n2 >> r >> s;
    int* tab = new int[n1];
    int* tab2 = new int[n2];
    for (int i = 0; i < n1; ++i){
        cin >> tab[i];
    }
    for (int i = 0; i < n2; ++i){
        cin >> tab2[i];
    }
    //punkt (ii)
    Tree T1 = tab_to_tree(tab, n1);
    Tree T2 = tab_to_tree(tab2, n2);
    delete [] tab;
    delete [] tab2;
    //punkt (i)
    T.combine(T1, T2, r);
    //wyświetla drzewo
    cout << "\n";
    T.treeDisplay();
    cout << "\n";
    //punkty (v), (iv) i (iii)
    cout << "Liczba węzłów drzewa: " << nodes(T.root) << ".\n";
    cout << "Liczba liści drzewa: " << leaves(T.root) << ".\n";
    cout << "Wysokość drzewa: " << height(T.root) << ".\n";
    if (search(T.root, s)){
        cout << "Liczba " << s << " występuje w drzewie.\n";
    }
    else{
        cout << "Liczba " << s << " nie występuje w drzewie.\n";
    }
}
