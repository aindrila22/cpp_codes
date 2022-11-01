#include<iostream>
using namespace std;

struct Node {
    int data;//data to be passed
    Node *left, *right;// pointers
    Node(int val){//initialize the root node
        data = val;
        left = NULL;
        right = NULL; 
    }
};
/*  insert a node in bst */
Node* insertBST(Node *root, int val){//(returntype functionName(datatype variable)=> passing parameterss in the function)
    if(root == NULL){// if we reach empty node, there we will create new node
        return new Node(val);
    }
    if(val < root->data){//compare the values
        root->left = insertBST(root->left, val);
    }else{
       root->right =  insertBST(root->right, val);
    }
    return root;
}



void inorder(Node *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << "";
    inorder(root->right);
}

int main(){
    Node *root = NULL;
    root = insertBST(root, 5);
    insertBST(root, 1);
    insertBST(root, 3);
    insertBST(root, 4);
    insertBST(root, 2);
    insertBST(root, 7);
//print inorder
inorder(root);
cout<<endl;
return 0;

}


//the output is 123457
//BST inorder traversal always gives a sorted array