#include <iostream>
using namespace std;
void getch();
void clrscr();
int max(int, int);
template <class T>
class Node
{
public:
T data;
int height;
int balanceFactor;
Node *left, *right, *parent;
Node()
{
left = nullptr;
right = nullptr;
parent = nullptr;
height = 1;
balanceFactor = 0;
}
};
class AVLTree
{
public:
Node<int> *root;
AVLTree()
{
root = nullptr;
}
int getBalanceFactor(Node<int> *node)
{
if (node == nullptr)
return 0;
return height(node->right) - height(node->left);
}


Node<int> *rightRotate(Node<int> *y)
{
Node<int> *x = y->left;
y->left = x->right;
if (x->right != nullptr)
x->right->parent = y;
x->parent = y->parent;
if (y->parent == nullptr)
root = x;
else if (y == y->parent->right)
y->parent->right = x;
else
y->parent->left = x;
x->right = y;
y->parent = x;
y->height = 1 + max(height(y->left),
height(y->right));
x->height = 1 + max(height(x->left),
height(x->right));
x->balanceFactor = getBalanceFactor(x);
y->balanceFactor = getBalanceFactor(y);
return x;
}
Node<int> *leftRotate(Node<int> *x)
{
Node<int> *y = x->right;
x->right = y->left;
if (y->left != nullptr)
y->left->parent = x;
y->parent = x->parent;
if (x->parent == nullptr)
root = y;
else if (x == x->parent->left)
x->parent->left = y;
else
x->parent->right = y;
y->left = x;



x->parent = y;
y->height = 1 + max(height(y->left),
height(y->right));
x->height = 1 + max(height(x->left),
height(x->right));
x->balanceFactor = getBalanceFactor(x);
y->balanceFactor = getBalanceFactor(y);
return y;
}
Node<int> *insert(int data, Node<int> *current)
{
Node<int> *temp;
if (current == nullptr)
{
temp = new Node<int>;
temp->data = data;
return temp;
}
if (data < current->data)
{
current->left = insert(data, current->left);
current->left->parent = current;
}
else
{
current->right = insert(data, current->right);
current->right->parent = current;
}
current->height = 1 + max(height(current->left),
height(current->right));
current->balanceFactor = getBalanceFactor(current);
if (current->balanceFactor < -1 &&
data < current->left->data)
return rightRotate(current);
if (current->balanceFactor > 1 &&
data > current->right->data)
return leftRotate(current);


if (current->balanceFactor < -1 &&
data > current->left->data)
{
current->left = leftRotate(current->left);
return rightRotate(current);
}
if (current->balanceFactor > 1 &&
data < current->right->data)
{
current->right = rightRotate(current->right);
return leftRotate(current);
}
return current;
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
cout << root->data << " (" << root->balanceFactor << ") ";
inOrderRecursive(root->right);
}
}
void preOrderRecursive(Node<int> *root)
{
if (root != nullptr)
{
cout << root->data << " (" << root->balanceFactor << ") ";
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
cout << root->data << " (" << root->balanceFactor << ") ";
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
Node<int> *deleteByCopying(Node<int> *current, int key)
{
if (key < current->data)
current->left = deleteByCopying(current->left, key);
else if (key > current->data)
current->right = deleteByCopying(current->right, key);
else
{
// node with only one child or no child
if ((current->left == nullptr) ||
(current->right == nullptr))
{
Node<int> *temp = current->left ? current->left : current->right;
if (temp == nullptr)
{
temp = current;
current = nullptr;


}
else
*current = *temp;
delete temp;
}
else
{
// copy inorder predecessor
Node<int> *temp = current->left;
while (temp->right != nullptr)
temp = temp->right;
current->data = temp->data;
current->right = deleteByCopying(current->right,
temp->data);
}
}
if (current == nullptr)
return current;
current->height = 1 + max(height(current->left),
height(current->right));
current->balanceFactor = getBalanceFactor(current);
// R(0) and R(-1)
if (current->balanceFactor < -1 &&
getBalanceFactor(current->left) <= 0)
return rightRotate(current);
// R(+1)
if (current->balanceFactor < -1 &&
getBalanceFactor(current->left) > 0)
{
current->left = leftRotate(current->left);
return rightRotate(current);
}
// L(0) and L(+1)
if (current->balanceFactor > 1 &&
getBalanceFactor(current->right) >= 0)
return leftRotate(current);
// L(-1)
if (current->balanceFactor > 1 &&
getBalanceFactor(current->right) < 0)
{
current->right = rightRotate(current->right);



return leftRotate(current);
}
return current;
}
};
int main(void)
{
AVLTree tree;
int choice, data, data2;
do
{
cout << " MENU \n"
<< "=======================\n"
<< "(1) Insert a Node\n"
<< "(2) Search a Node\n"
<< "(3) Display Traversals\n"
<< "(4) Delete a Node\n"
<< "(0) Exit\n\n";
cout << "Enter Choice: ";
cin >> choice;
switch (choice)
{
case 1:
cout << "\nEnter Node Data: ";
cin >> data;
tree.root = tree.insert(data, tree.root);
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
cout << "\nEnter Node to Delete: ";
cin >> data;
tree.root = tree.deleteByCopying(tree.root, data);
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
int max(int a, int b)
{
return (a > b) ? a : b;
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
