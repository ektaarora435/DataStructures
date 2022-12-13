#include <iostream>
using namespace std;
template <class T>
class Node
{
public:
T info;
Node *ptr;
};
template <class T>
class CircularSinglyLinkedList
{
public:
Node<T> *tail;
// Constructor
CircularSinglyLinkedList()
{
tail = NULL;
}
// Destructor
~CircularSinglyLinkedList()
{
if (this->isEmpty())
return;
Node<T> *ptr, *temp = tail->ptr;
while (temp != tail)
{
ptr = temp;
temp = ptr->ptr;
delete ptr;
}
delete temp;
tail = NULL;
return;
}

// Checks if the list is empty - O(1)
bool isEmpty()
{
return tail == NULL;
}
// Inserts a node at the beginning - O(1)
void insertFront(T info)
{
Node<T> *temp = new Node<T>();
temp->info = info;
if (this->isEmpty())
{
temp->ptr = temp;
tail = temp;
}
else
{
temp->ptr = tail->ptr;
tail->ptr = temp;
}
return;
}
// Inserts a node at a specified location - O(n)
void insertAtLoc(int loc, T info)
{
if (loc == 1)
{
this->insertFront(info);
return;
}
int size = this->count();
if (loc > size + 1 || loc < 1)
{
cout << "Invalid location...\n";
return;
}
if (loc == size + 1)
{
this->insertBack(info);
return;
}
Node<T> *temp = tail->ptr;
for (int i = 1; temp->ptr != tail && i < loc - 1; i++)
temp = temp->ptr;
Node<T> *node = new Node<T>();
node->info = info;


node->ptr = temp->ptr;
temp->ptr = node;
return;
}
// Inserts a node at the end - O(1)
void insertBack(T info)
{
Node<T> *temp = new Node<T>();
temp->info = info;
if (this->isEmpty())
temp->ptr = temp;
else
{
temp->ptr = tail->ptr;
tail->ptr = temp;
}
tail = temp;
return;
}
// Removes a node from the beginning - O(1)
void deleteFront()
{
if (this->isEmpty())
{
cout << "\nList is empty...\n";
return;
}
else if (tail->ptr == tail)
{
delete tail;
tail = NULL;
}
else
{
Node<T> *temp;
temp = tail->ptr->ptr;
delete tail->ptr;
tail->ptr = temp;
}
return;
}
// Removes a node at a specified location - O(n)
void deleteAtLoc(int loc)
{
if (this->isEmpty())


{
cout << "\nList is empty...\n";
return;
}
int size = this->count();
if (loc > size || loc < 1)
{
cout << "Invalid location...\n";
return;
}
if (loc == size)
{
this->deleteBack();
return;
}
Node<T> *node, *temp = tail->ptr;
for (int i = 1; temp->ptr != tail && i < loc - 1; i++)
temp = temp->ptr;
node = temp->ptr->ptr;
delete temp->ptr;
temp->ptr = node;
return;
}
// Removes a node at the end - O(n)
void deleteBack()
{
if (this->isEmpty())
{
cout << "\nList is empty...\n";
return;
}
else if (tail->ptr == tail)
{
delete tail;
tail = NULL;
}
else
{
Node<T> *temp = tail->ptr;
while (temp->ptr != tail)
temp = temp->ptr;
temp->ptr = tail->ptr;
delete tail;
tail = temp;
}
return;
}


// Traverses the list and prints all nodes - O(n)
void display()
{
if (this->isEmpty())
{
cout << "\nList is empty...\n";
return;
}
Node<T> *temp = tail->ptr;
while (temp != tail)
{
cout << temp->info << " -> ";
temp = temp->ptr;
}
cout << temp->info << endl;
return;
}
};
// main.cpp
#include "circularSinglyLinkedList.hpp"
using namespace std;
void getch();
void clrscr();
template <class T>
class Queue
{
protected:
Node<T> *front, *rear;
CircularSinglyLinkedList<T> list;
public:
Queue()
{
this->front = this->list.tail;
this->rear = this->list.tail;
}
bool enqueue(T ele)
{
this->list.insertBack(ele);
this->front = this->list.tail->ptr;
this->rear = this->list.tail;
return true;

}
T dequeue()
{
if (this->isEmpty())
{
cout << "ERROR: Queue Empty\n";
return (T)(NULL);
}
T temp = this->front->info;
this->list.deleteFront();
if (this->isEmpty())
this->front = this->list.tail;
else
this->front = this->list.tail->ptr;
this->rear = this->list.tail;
return temp;
}
T frontEl()
{
if (this->isEmpty())
{
cout << "Queue Empty";
return (T)(NULL);
}
return this->front->info;
}
bool isEmpty()
{
return this->list.isEmpty();
}
void clear()
{
while (!this->isEmpty())
this->dequeue();
}
void display()
{
if (this->isEmpty())
{
cout << "Queue Empty";
return;
}
this->list.display();


return;
}
};
int main(void)
{
int el, res, choice;
Queue<int> q;
do
{
cout << "\tCircular Queue - CSLList\n"
<< "===================================\n"
<< " (1) Enqueue (2) Dequeue\n"
<< " (3) Front (4) Clear\n"
<< " (5) Display (0) Exit\n\n";
cout << "Enter Choice: ";
cin >> choice;
switch (choice)
{
case 1:
cout << "\nEnter Element: ";
cin >> el;
res = q.enqueue(el);
if (res)
{
cout << "\nEnqueued " << el << "...\n";
cout << "Queue: ";
q.display();
}
break;
case 2:
res = q.dequeue();
if (res)
{
cout << "\nDequeued " << res << "...\n";
cout << "Queue: ";
q.display();
}
break;
case 3:
cout << "\nFront Element: "
<< q.frontEl() << endl;
break;
case 4:
q.clear();
break;
case 5:
cout << "\nQueue: ";


q.display();
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
