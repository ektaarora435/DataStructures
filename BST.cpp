// stack.hpp
#include <iostream>
#define MAX_SIZE 100
using namespace std;
template <class T>
class Stack
{
protected:
int tos, size;
T arr[MAX_SIZE];
public:
Stack(int size = 30)
{
this->tos = -1;
this->size = size;
}
bool push(T ele)
{
if (this->tos >= (this->size - 1))
{
cerr << "ERROR: Stack Overflow\n";
return false;
}
this->arr[++(this->tos)] = ele;
return true;
}
T pop()
{
if (this->isEmpty())



{
cout << "ERROR: Stack Underflow\n";
return (T)(NULL);
}
return this->arr[(this->tos)--];
}
T top()
{
if (this->isEmpty())
{
cout << "Stack Empty";
return (T)(NULL);
}
return this->arr[this->tos];
}
bool isEmpty()
{
return this->tos == -1;
}
void clear()
{
while (!this->isEmpty())
this->pop();
}
};
// queue.hpp
#include <iostream>
#define MAX_SIZE 100
using namespace std;
template <class T>
class Queue
{
protected:
T arr[MAX_SIZE];
int front, rear, size;
public:
Queue(int size = 100)
{
this->front = -1;
this->rear = -1;
this->size = size;



}
bool enqueue(T ele)
{
if (this->rear >= (this->size - 1))
{
cerr << "ERROR: Queue Filled\n";
return false;
}
else if (this->isEmpty())
{
this->rear++;
this->front++;
this->arr[this->front] = ele;
}
else
this->arr[++(this->rear)] = ele;
return true;
}
T dequeue()
{
if (this->front >= this->size)
{
cout << "ERROR: Queue Finished\n";
return (T)(NULL);
}
else if (this->isEmpty())
{
cout << "ERROR: Queue Empty\n";
return (T)(NULL);
}
else if (this->front == this->rear)
{
T temp = this->arr[this->front];
this->clear();
return temp;
}
return this->arr[(this->front)++];
}
T frontEl()
{
if (this->isEmpty())
{
cout << "Queue Empty";
return (T)(NULL);
}

Page 95 of 166

return this->arr[this->front];
}
bool isEmpty()
{
return this->front == -1;
}
void clear()
{
this->front = this->rear = -1;
}
void display()
{
if (this->isEmpty())
{
cout << "Queue Empty";
return;
}
int i;
for (i = this->front; i < this->rear; i++)
cout << this->arr[i] << " <- ";
cout << this->arr[i] << endl;
return;
}
};
// main.cpp
#include "stack.hpp"
#include "queue.hpp"
void getch();
void clrscr();
template <class T>
class Node
{
public:
T data;
Node *left, *right;
Node()
{
left = nullptr;
right = nullptr;
}
};



class BinarySearchTree
{
public:
Node<int> *root;
Stack<Node<int> *> stack;
Queue<Node<int> *> queue;
int countLeaf, countNonLeaf;
BinarySearchTree()
{
root = nullptr;
}
void insert(int data, Node<int> *current)
{
Node<int> *temp;
if (root == nullptr)
{
root = new Node<int>;
root->data = data;
root->left = root->right = nullptr;
}
else
{
if ((data < current->data) &&
(current->left == nullptr))
{
temp = new Node<int>;
temp->data = data;
temp->left = temp->right = nullptr;
current->left = temp;
}
else if ((data >= current->data) &&
(current->right == nullptr))
{
temp = new Node<int>;
temp->data = data;
temp->left = temp->right = nullptr;
current->right = temp;
}
else
{
if (data < current->data)
insert(data, current->left);
else
insert(data, current->right);
}
}


}
bool search(Node<int> *node, int key)
{
if (node == nullptr)
return false;
if (node->data == key)
return true;
bool left = search(node->left, key);
if (left)
return true;
bool right = search(node->right, key);
return right;
}
void inOrderRecursive(Node<int> *root)
{
if (root != nullptr)
{
inOrderRecursive(root->left);
cout << root->data << " ";
inOrderRecursive(root->right);
}
}
void preOrderRecursive(Node<int> *root)
{
if (root != nullptr)
{
cout << root->data << " ";
preOrderRecursive(root->left);
preOrderRecursive(root->right);
}
}
void postOrderRecursive(Node<int> *root)
{
if (root != nullptr)
{
postOrderRecursive(root->left);
postOrderRecursive(root->right);
cout << root->data << " ";
}
}
void inOrderIterative()


{
Node<int> *current = root;
while (current != nullptr ||
stack.isEmpty() == false)
{
while (current != nullptr)
{
stack.push(current);
current = current->left;
}
current = stack.pop();
cout << current->data << " ";
current = current->right;
}
}
void preOrderIterative()
{
Node<int> *node, *temp = root;
if (temp == nullptr)
return;
stack.push(temp);
while (!stack.isEmpty())
{
node = stack.pop();
cout << node->data << " ";
if (node->right)
stack.push(node->right);
if (node->left)
stack.push(node->left);
}
}
void postOrderIterative()
{
Node<int> *temp = root;
if (temp == nullptr)
return;
do
{
while (temp)
{
if (temp->right)
stack.push(temp->right);
stack.push(temp);
temp = temp->left;
}


temp = stack.pop();
if (temp->right && !stack.isEmpty() &&
stack.top() == temp->right)
{
stack.pop();
stack.push(temp);
temp = temp->right;
}
else
{
cout << temp->data << " ";
temp = nullptr;
}
} while (!stack.isEmpty());
}
void levelByLevelTraversal()
{
Node<int> *current = root;
if (current == nullptr)
return;
queue.enqueue(current);
while (!queue.isEmpty())
{
current = queue.dequeue();
cout << current->data << " ";
if (current->left)
queue.enqueue(current->left);
if (current->right)
queue.enqueue(current->right);
}
cout << endl;
}
void mirror(Node<int> *current)
{
if (current == nullptr)
return;
else
{
mirror(current->left);
mirror(current->right);
Node<int> *temp = current->left;

Page 100 of 166
current->left = current->right;
current->right = temp;
}
}
int height(Node<int> *current)
{
if (current == nullptr)
return 0;
else
{
int leftHeight = height(current->left);
int rightHeight = height(current->right);
if (leftHeight > rightHeight)
return (leftHeight + 1);
else
return (rightHeight + 1);
}
}
void countNodes(Node<int> *current)
{
if (current == nullptr)
return;
if (current->left != nullptr ||
current->right != nullptr)
countNonLeaf++;
if (current->left == nullptr &&
current->right == nullptr)
countLeaf++;
countNodes(current->left);
countNodes(current->right);
}
void deleteByMerging(Node<int> *temp, int key)
{
Node<int> *prev = nullptr;
while (temp != nullptr)
{
if (temp->data == key)
break;
prev = temp;
if (temp->data < key)
temp = temp->right;
else


temp = temp->left;
}
if (temp != nullptr && temp->data == key)
{
if (temp == root)
mergeHelper(root);
else if (prev->left == temp)
mergeHelper(prev->left);
else
mergeHelper(prev->right);
}
else if (root != nullptr)
cout << "\nNode Not Found...";
return;
}
void mergeHelper(Node<int> *&node)
{
Node<int> *temp = node;
if (node == nullptr)
return;
// no right child - single child
if (node->right == nullptr)
node = node->left;
// no left child - single chold
else if (node->left == nullptr)
node = node->right;
// node has both children
else
{
// find in-order predecessor
temp = node->left;
while (temp->right != nullptr)
temp = temp->right;
// merge subtree to predecessor
temp->right = node->right;
temp = node;
node = node->left;
}
// delete the node
delete temp;



return;
}
void deleteByCopying(Node<int> *temp, int key)
{
Node<int> *prev = nullptr;
while (temp != nullptr && temp->data != key)
{
prev = temp;
if (temp->data < key)
temp = temp->right;
else
temp = temp->left;
}
if (temp != nullptr && temp->data == key)
{
if (temp == root)
copyHelper(root);
else if (prev->left == temp)
copyHelper(prev->left);
else
copyHelper(prev->right);
}
else if (root != nullptr)
cout << "\nNode Not Found...";
return;
}
void copyHelper(Node<int> *&node)
{
Node<int> *prev, *temp = node;
// no right child - single child
if (node->right == nullptr)
node = node->left;
// no left child - single chold
else if (node->left == nullptr)
node = node->right;
// node has both children
else
{
prev = node;


// find the in-order predecessor
temp = node->left;
while (temp->right != nullptr)
{
prev = temp;
temp = temp->right;
}
// copy the prdecessor key
node->data = temp->data;
// handle dangling subtrees
if (prev == node)
prev->left = temp->left;
else
prev->right = temp->left;
}
// delete the node
delete temp;
return;
}
void searchAndReplace(int key, int newKey)
{
if (search(root, key))
{
deleteByMerging(root, key);
insert(newKey, root);
}
else
{
cout << "Node Not Found...";
}
}
};
int main(void)
{
BinarySearchTree tree;
int choice, data, data2;
do
{
cout << " MENU \n"
<< "================\n"
<< "(1) Insertion\n"
<< "(2) Searching a node\n"



<< "(3) Display its preorder, postorder and inorder traversals. (recu
rsive)\n"
<< "(4) Display its preorder, postorder and inorder traversals. (iter
ative)\n"
<< "(5) Display level-by-level traversal. (BFS)\n"
<< "(6) Create a mirror image of tree\n"
<< "(7) Count the non-leaf, leaf and total number of nodes \n"
<< "(8) Search for an element x in the BST and change its value to y
\n"
<< " and then place the node with value y at its appropriate posit
ion\n"
<< "(9) Display height of tree\n"
<< "(10) Perform deletion by merging\n"
<< "(11) Perform deletion by copying\n"
<< "(0) Exit\n\n";
cout << "Enter Choice: ";
cin >> choice;
switch (choice)
{
case 1:
cout << "\nEnter Node Data: ";
cin >> data;
tree.insert(data, tree.root);
break;
case 2:
cout << "\nEnter Search Data: ";
cin >> data;
cout << "Search Result: ";
if (tree.search(tree.root, data))
cout << "Found";
else
cout << "Not Found";
cout << endl;
break;
case 3:
cout << endl;
cout << "In-Order Recursive Traversal: ";
tree.inOrderRecursive(tree.root);
cout << endl;
cout << "Pre-Order Recursive Traversal: ";
tree.preOrderRecursive(tree.root);
cout << endl;
cout << "Post-Order Recursive Traversal: ";
tree.postOrderRecursive(tree.root);
cout << endl;
break;
case 4:



cout << endl;
cout << "In-Order Iterative Traversal: ";
tree.inOrderIterative();
cout << endl;
cout << "Pre-Order Iterative Traversal: ";
tree.preOrderIterative();
cout << endl;
cout << "Post-Order Iterative Traversal: ";
tree.postOrderIterative();
cout << endl;
break;
case 5:
cout << endl;
cout << "Level-by-level Traversal: \n";
tree.levelByLevelTraversal();
break;
case 6:
cout << endl;
tree.mirror(tree.root);
cout << "Tree converted to its Mirror Tree..."
<< endl;
break;
case 7:
tree.countLeaf = tree.countNonLeaf = 0;
tree.countNodes(tree.root);
cout << endl;
cout << "Leaf Nodes: "
<< tree.countLeaf << endl;
cout << "Non-Leaf Nodes: "
<< tree.countNonLeaf << endl;
cout << "Total Nodes: "
<< tree.countNonLeaf +
tree.countLeaf
<< endl;
break;
case 8:
cout << "\nEnter Search Data: ";
cin >> data;
cout << "Enter Replacement: ";
cin >> data2;
tree.searchAndReplace(data, data2);
break;
case 9:
cout << endl;
cout << "Height of Tree: "
<< tree.height(tree.root)
<< endl;



break;
case 10:
cout << "\nEnter Node to Delete: ";
cin >> data;
tree.deleteByMerging(tree.root, data);
break;
case 11:
cout << "\nEnter Node to Delete: ";
cin >> data;
tree.deleteByCopying(tree.root, data);
break;
case 0:
default:
break;
}
getch();
clrscr();
} while (choice != 0);
return 0;
}
void getch()
{
cout << "\nPress any key to continue...";
cin.ignore();
cin.get();
return;
}
void clrscr()
{
#ifdef _WIN32
system("cls");
#elif __unix__
system("clear");
#endif
return;
}
