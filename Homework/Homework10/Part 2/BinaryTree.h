#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
using namespace std;

// Stack template
template <class T>
class BinaryTree
{
private:
   struct TreeNode
   {
      T value;           // The value in the node
      TreeNode *left;    // Pointer to left child node
      TreeNode *right;   // Pointer to right child node
   };

   TreeNode *root;       // Pointer to the root node
   
   // Private member functions
   void insert(TreeNode *&, TreeNode *&);
   void destroySubTree(TreeNode *);
   void deleteNode(T, TreeNode *&);
   void makeDeletion(TreeNode *&);
   void displayInOrder(TreeNode *) const;
   void displayPreOrder(TreeNode *) const;
   void displayPostOrder(TreeNode *) const;
   void loadInOrderRec(TreeNode *nodePtr, T A[], int &pos);
   void IndentBlock(int);
   void PrintTree(TreeNode*, int, int);
   int countNodes(TreeNode*, int&);
   void countLeaves(TreeNode*, int&);
   int countHeight(TreeNode*);
   void clearTree(TreeNode*);
   void copyTree(TreeNode*);
   
public:
   // Constructor
   BinaryTree()
      { root = nullptr; }

   //Copy Constructor
   BinaryTree(const BinaryTree &tree){
      copyTree(tree.root);
   }
      
   // Destructor
   ~BinaryTree()
      { destroySubTree(root); }
      
   // Binary tree operations
   void insertNode(T);
   bool searchNode(T);
   void remove(T);
   void treeSort(T [], int);
   
   void displayInOrder() const
      {  displayInOrder(root); }
      
   void displayPreOrder() const
      {  displayPreOrder(root); }
      
   void displayPostOrder() const
      {  displayPostOrder(root); }

   void loadInOrder(T A[])
      {
         int test = 0;
         loadInOrderRec(root, A, test);

      }

   int numberOfNodes()
   {
      int size = 0;
      return countNodes(root, size);

   }

   int numberOfLeafNodes(){
      int n = 0;
      countLeaves(root, n);
      return n;
   }

   int height(){ return countHeight(root); }

   void clear(){
      clearTree(root);
      root = nullptr;
   }

   BinaryTree & operator=(const BinaryTree &rhs){
      clearTree(root);
      root = nullptr;
      copyTree(rhs.root);
      return *this;
   }



   void PrintTree(int Indent = 4, int Level = 0);
};

//*************************************************************
// insert accepts a TreeNode pointer and a pointer to a node. *
// The function inserts the node into the tree pointed to by  *
// the TreeNode pointer. This function is called recursively. *
//*************************************************************
template <class T>
void BinaryTree<T>::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
   if (nodePtr == nullptr)
      nodePtr = newNode;                  // Insert the node.
   else if (newNode->value < nodePtr->value)
      insert(nodePtr->left, newNode);     // Search the left branch
   else 
      insert(nodePtr->right, newNode);    // Search the right branch
}

//**********************************************************
// insertNode creates a new node to hold num as its value, *
// and passes it to the insert function.                   *
//**********************************************************
template <class T>
void BinaryTree<T>::insertNode(T item)
{
   TreeNode *newNode = nullptr;	// Pointer to a new node.

   // Create a new node and store num in it.
   newNode = new TreeNode;
   newNode->value = item;
   newNode->left = newNode->right = nullptr;
   
   // Insert the node.
   insert(root, newNode);
}

//***************************************************
// destroySubTree is called by the destructor. It   *
// deletes all nodes in the tree.                   *
//***************************************************
template <class T>
void BinaryTree<T>::destroySubTree(TreeNode *nodePtr)
{
   if (nodePtr)
   {
      if (nodePtr->left)
         destroySubTree(nodePtr->left);
      if (nodePtr->right)
         destroySubTree(nodePtr->right);
      delete nodePtr;
   }
}
   
//***************************************************
// searchNode determines if a value is present in   *
// the tree. If so, the function returns true.      *
// Otherwise, it returns false.                     *
//***************************************************
template <class T>
bool BinaryTree<T>::searchNode(T item)
{
   TreeNode *nodePtr = root;

   while (nodePtr)
   {
      if (nodePtr->value == item)
         return true;
      else if (item < nodePtr->value)
         nodePtr = nodePtr->left;
      else
         nodePtr = nodePtr->right;
   }
   return false;
}

//**********************************************
// remove calls deleteNode to delete the       *
// node whose value member is the same as num. *
//**********************************************
template <class T>
void BinaryTree<T>::remove(T item)
{
   deleteNode(item, root);
}

//********************************************
// deleteNode deletes the node whose value   *
// member is the same as num.                *
//********************************************
template <class T>
void BinaryTree<T>::deleteNode(T item, TreeNode *&nodePtr)
{
   if(nodePtr){
      if (item < nodePtr->value)
         deleteNode(item, nodePtr->left);
      else if (item > nodePtr->value)
         deleteNode(item, nodePtr->right);
      else
         makeDeletion(nodePtr);
   }
}

//***********************************************************
// makeDeletion takes a reference to a pointer to the node  *
// that is to be deleted. The node is removed and the       *
// branches of the tree below the node are reattached.      *
//***********************************************************
template <class T>
void BinaryTree<T>::makeDeletion(TreeNode *&nodePtr)
{
   // Define a temporary pointer to use in reattaching
   // the left subtree.
   TreeNode *tempNodePtr = nullptr;

   if (nodePtr == nullptr)
      cout << "Cannot delete empty node.\n";
   else if (nodePtr->right == nullptr)
   {
      tempNodePtr = nodePtr;
      nodePtr = nodePtr->left;   // Reattach the left child
      delete tempNodePtr;
   }
   else if (nodePtr->left == nullptr)
   {
      tempNodePtr = nodePtr;
      nodePtr = nodePtr->right;  // Reattach the right child
      delete tempNodePtr;
   }
   // If the node has two children.
   else
   {
      // Move one node the right.
      tempNodePtr = nodePtr->right;
      // Go to the end left node.
      while (tempNodePtr->left)
         tempNodePtr = tempNodePtr->left;
      // Reattach the left subtree.
      tempNodePtr->left = nodePtr->left;
      tempNodePtr = nodePtr;
      // Reattach the right subtree.
      nodePtr = nodePtr->right;
      delete tempNodePtr;
   }
}

//****************************************************************
// The displayInOrder member function displays the values        *
// in the subtree pointed to by nodePtr, via inorder traversal.  *
//****************************************************************
template <class T>
void BinaryTree<T>::displayInOrder(TreeNode *nodePtr) const
{
   if (nodePtr)
   {
      displayInOrder(nodePtr->left);
      cout << nodePtr->value << endl;
      displayInOrder(nodePtr->right);
   }
}

//****************************************************************
// The displayPreOrder member function displays the values       *
// in the subtree pointed to by nodePtr, via preorder traversal. *
//****************************************************************
template <class T>
void BinaryTree<T>::displayPreOrder(TreeNode *nodePtr) const
{
   if (nodePtr)
   {
      cout << nodePtr->value << endl;
      displayPreOrder(nodePtr->left);     
      displayPreOrder(nodePtr->right);
   }
}

//****************************************************************
// The displayPostOrder member function displays the values      *
// in the subtree pointed to by nodePtr, via postorder traversal.*
//****************************************************************
template <class T>
void BinaryTree<T>::displayPostOrder(TreeNode *nodePtr) const
{
   if (nodePtr)
   {
      displayPostOrder(nodePtr->left);    
      displayPostOrder(nodePtr->right);
      cout << nodePtr->value << endl;
   }
}

/*
Description: Recursively loads an array into the tree in order
Parameters:
            (TreeNode) *nodePtr: Node starting at
            (T) A[]: Array to load in
            (int) &pos: Position of item in the array to load in
Return:
            None
Notes:
*/
template <class T>
void BinaryTree<T>::loadInOrderRec(TreeNode *nodePtr, T A[], int &pos){
   if(nodePtr){
      loadInOrderRec(nodePtr->left, A, pos);
      A[pos] = nodePtr->value;
      pos++;
      loadInOrderRec(nodePtr->right, A, pos);
   }
}

/*
Description: Imports an array into the tree, and then recursive exports the tree into an array, in numerical order
Parameters:
            (T) A[]: Array to load
            (int) size: Size of the array
Return:
            None
Notes:
*/
template <class T>
void BinaryTree<T>::treeSort(T A[], int size){
   //
   for(int i = 0; i < size; i++){
      insertNode(A[i]);
   }

   loadInOrder(A);

}
//****************************************************************
// Simple helper function to do the indentations for the tree
// printing algorithm.
//****************************************************************

template <class T>
void BinaryTree<T>::IndentBlock(int num) {
	for (int i = 0; i < num; i++)
		cout << " ";
}

//****************************************************************
// This function recursively prints the tree contents to the
// console using a reverse inorder traversal with indenting.
//****************************************************************

template <class T>
void BinaryTree<T>::PrintTree(TreeNode *t, int Indent, int Level) {
	if (t != NULL) {
		PrintTree(t->right, Indent, Level + 1);
		IndentBlock(Indent * Level);
		cout << t->value << "\n";
		PrintTree(t->left, Indent, Level + 1);
	}
}

//****************************************************************
// This function initiates the recursive printing function to
// print the contents of the tree in tree form sideways with the
// root at the far left.
//****************************************************************

template <class T>
void BinaryTree<T>::PrintTree(int Indent, int Level) {
	if (root != NULL)
		PrintTree(root, Indent, Level);
}

/*
Description: Recursively counts the number of nodes in the tree
Parameters:
            (TreeNode *nodePtr): Node to count;
            (int) &s: Number to increment per node
Return:
            (int) &s: Number of nodes in the tree
Notes:
*/
template <class T>
int BinaryTree<T>::countNodes(TreeNode *nodePtr, int &s){
   if(nodePtr){
      s++;
      countNodes(nodePtr->left, s);
      countNodes(nodePtr->right, s);
   } else {
      return s;
   }
}

/*
Description: Counts the number of nodes in a tree that do not have any children
Parameters:
            (TreeNode) *nodePtr: Node to check
            (int) &s: number to increment per leaf
Return:
            (int) &s: number of leaves
Notes:
*/
template <class T>
void BinaryTree<T>::countLeaves(TreeNode *nodePtr, int &s){
   if(nodePtr){
      if(nodePtr->left || nodePtr->right){
         countLeaves(nodePtr->left, s);
         countLeaves(nodePtr->right, s);
      } else {
         s++;
      }
   }
}

/*
Description: Counts the number of layers in the tree
Parameters:
            (TreeNode) *nodePtr: Node to count
Return:
            (int): Height of tree
Notes:
*/
template <class T>
int BinaryTree<T>::countHeight(TreeNode *nodePtr){
   if(nodePtr){

      int l = countHeight(nodePtr->left);
      int r = countHeight(nodePtr->right);

      if(r > l) return (r+1);
      else return (l+1);
   } else return 0;
}

/*
Description: Recursively clears and deletes every node in the tree
Parameters:
            (TreeNode) *nodePtr: Node to delete
Return:
            None
Notes:
*/
template <class T>
void BinaryTree<T>::clearTree(TreeNode *nodePtr){
   if(nodePtr){
      clearTree(nodePtr->left);
      clearTree(nodePtr->right);
      nodePtr->left = nullptr;
      nodePtr->right = nullptr;
      delete nodePtr;
   }
}

/*
Description: Recursively copies the the input node and then its child nodes
Parameters:
            (TreeNode) *nodePtr: Node to copy
Return:
            None
Notes:
*/
template <class T>
void BinaryTree<T>::copyTree(TreeNode *nodePtr){
   if(nodePtr){
      insertNode(nodePtr->value);
      copyTree(nodePtr->right);
      copyTree(nodePtr->left);
   }
}
#endif
