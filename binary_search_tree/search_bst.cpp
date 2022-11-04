#include<iostream>
using namespace std;
struct node {
   int d;
   node *left;
   node *right;
};
node* CreateNode(int d) {
   node *newnode = new node;
   newnode->d = d;
   newnode->left = NULL;
   newnode->right = NULL;
   return newnode;
}
node* InsertIntoTree(node* root, int d) {
   node *temp = CreateNode(d);
   node *t = new node;
   t = root;
   if(root == NULL)
      root = temp;
   else {
      while(t != NULL) {
         if(t->d < d) {
            if(t->right == NULL) {
               t->right = temp;
               break;
            }
            t = t->right;
         } else if(t->d > d) {
            if(t->left == NULL) {
               t->left = temp;
               break;
            }
            t = t->left;
         }
      }
   }
   return root;
}
void Search(node *root, int d) {
   int depth = 0;
   node *temp = new node;
   temp = root;
   while(temp != NULL) {
      depth++;
      if(temp->d == d) {
         cout<<"item found at depth: "<<depth;
         return;
      } else if(temp->d > d)
         temp = temp->left;
         else
            temp = temp->right;
   }
   cout<<"item not found";
   return;
}
int main() {
   char ch;
   int n, i, a[10] = {93, 53, 45, 2, 7, 67, 32, 26, 71, 76};
   node *root = new node;
   root = NULL;
   for (i = 0; i < 10; i++)
      root = InsertIntoTree(root, a[i]);
   up:
   cout<<"Enter the Element to be searched: ";
   cin>>n;
   Search(root, n);
   cout<<"\tDo you want to search more...enter choice(y/n)?";
   cin>>ch;
   if(ch == 'y' || ch == 'Y')
      goto up;
   return 0;
}

/***If its In-order and Post-order traversal is given then you have to traverse whole in-order list
  linearly for searching root. It will take O(n^2) times.
 * But the trick here is that, Since In-order traversal is sorted hence we can directly apply Binary search,
 instead of performing the linear search, that reduces the time complexity to O(nlogn). So answer is O(nlogn).*/



//another way to search in bst
 #include<iostream>
 using namespace std;

 struct Node{
   int data;
   Node *left, *right;
   Node(int val){
      data = val;
      left = NULL;
      right = NULL;
   }
 };

 Node* searchInBst(Node *root, int key){

   if(root == NULL){
      return NULL;
   }
   if(root->data == key){
      return root;
   }
   if(root->data > key){
      root->left = searchInBst(root->left, key);
   }
   return searchInBst(root->right, key);
 }


int main(){
   Node *root = new Node(4);
   root->left = new Node(2);
   root->right = new Node(5);
   root->left->left = new Node(1);
   root->left->right = new Node(3);
   root->right->right = new Node(6);

if(searchInBst(root, 10) == NULL){
   cout<<"Key doesn't exist"<<endl;
}else
{
   cout<<"Key exists"<<endl;
}   return 0;
}
