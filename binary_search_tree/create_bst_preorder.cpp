#include<iostream>
#include<bits/stdc++.h>
#include<limits.h> 
using namespace std;

struct Node{
    int data;
    Node *left, *right;
    Node(int val){//building constructor
        data=val;
        left=NULL;
        right=NULL;
    }
};

Node* constructBst(int preorder[], int* preorderIdx, int key, int min, int max, int n){
    if(*preorderIdx >= n){
        return NULL;
    }
    Node *root = NULL;
    if(key > min && key < max){//basic conditions of BST
         root = new Node(key);
         *preorderIdx = *preorderIdx + 1;
         if(*preorderIdx < n){
            root->left = constructBst(preorder, preorderIdx, preorder[*preorderIdx], min, key, n );
         }

         if(*preorderIdx < n){
            root->right = constructBst(preorder, preorderIdx, preorder[*preorderIdx], key, max, n );
         }
    }
    return root;

}

void printPreorder(Node *root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main(){
 int preorder[] = {10, 2, 1, 13, 11};
 int n = 5;
 int preorderIdx = 0;
 Node* root = constructBst(preorder, &preorderIdx, preorder[0], INT_MIN, INT_MAX, n);
 printPreorder(root);
 return 0;

}

/***( O(n) time complexity ):

 The trick is to set a range {min .. max} for every node.
 Initialize the range as {INT_MIN .. INT_MAX}. The first node will definitely be in range, so create a root node.
  To construct the left subtree, set the range as {INT_MIN …root->data}. If a value is in the range {INT_MIN .. root->data}, 
  the values are part of the left subtree. To construct the right subtree, set the range as {root->data..max .. INT_MAX}. */