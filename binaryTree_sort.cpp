// #include <array>
#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *left, *right;
};

//fungsi buat masukin nilai
Node* insert(Node* root, int value){
    if (root ==NULL){
        Node* newNode = new Node();
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    if (value < root->data){
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

//buat fungsi sorting ascending, pake inorder
void inorder(Node* root){
    if (root != NULL){
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main(){
    Node* root = NULL;
    int n, val;
    int arr[n];
    cout << "Masukkan jumlah elemen yang akan disorting: ";
    cin >> n;
    cout << "Masukkan elemen:\n";
    for (int i=0; i<n; i++){
        cout << "masukkan elemen ke-"<< i+1 << " => ";
        cin>>val;
        arr[i]=val;
        root = insert(root, val);
    }
    cout << "Elemen yang dimasukkan: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Elemen yang sudah disorting: ";
    inorder (root);
    return 0;
}
