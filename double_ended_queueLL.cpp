#include <iostream>
using namespace std;
void getch();
void clrscr();
template <class T>
class Node
{
public:
T info;
Node *prev;
Node *next;
};
template <class T>
class DoublyLinkedList
{
public:
Node<T> *head, *tail;
// Constructor
DoublyLinkedList()
{
head = tail = NULL;
}
// Destructor
~DoublyLinkedList()
{
if (this->isEmpty())
return;
Node<T> *ptr;
for (; !isEmpty();)
{
ptr = head->next;
delete head;
head = ptr;
}
head = tail = ptr;


return;
}
// Checks if the list is empty - O(1)
bool isEmpty()
{
return (head == NULL || tail == NULL);
}
// Inserts a node at the beginning - O(1)
void insertFront(T info)
{
Node<T> *temp = new Node<T>();
temp->info = info;
temp->next = head;
temp->prev = NULL;
if (this->isEmpty())
tail = temp;
else
head->prev = temp;
head = temp;
return;
}
// Inserts a node at the end - O(1)
void insertBack(T info)
{
Node<T> *temp = new Node<T>();
temp->info = info;
temp->next = NULL;
temp->prev = tail;
if (this->isEmpty())
head = tail = temp;
else
tail->next = temp;
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
Node<T> *temp = head;



head = temp->next;
if (this->isEmpty())
tail = NULL;
else
head->prev = NULL;
delete temp;
return;
}
// Removes a node at the end - O(1)
void deleteBack()
{
if (this->isEmpty())
{
cout << "\nList is empty...\n";
return;
}
Node<T> *temp = tail;
tail = temp->prev;
if (this->isEmpty())
head = NULL;
else
tail->next = NULL;
delete temp;
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
Node<T> *temp = head;
while (temp->next != NULL)
{
cout << temp->info << " -> ";
temp = temp->next;
}
cout << temp->info << endl;
return;
}
};
// main.cpp



#include "doublyLinkedList.hpp"
using namespace std;
void getch();
void clrscr();
template <class T>
class DoublyEndedQueue
{
protected:
Node<T> *front, *rear;
DoublyLinkedList<T> list;
public:
DoublyEndedQueue()
{
this->front = this->list.head;
this->rear = this->list.tail;
}
void enqueueFront(T ele)
{
this->list.insertFront(ele);
this->front = this->list.head;
this->rear = this->list.tail;
}
void enqueueRear(T ele)
{
this->list.insertBack(ele);
this->front = this->list.head;
this->rear = this->list.tail;
}
T dequeueFront()
{
if (this->isEmpty())
{
cout << "ERROR: Queue Empty\n";
return (T)(NULL);
}
T temp = this->front->info;
this->list.deleteFront();
this->front = this->list.head;
this->rear = this->list.tail;
return temp;
}

T dequeueRear()
{
if (this->isEmpty())
{
cout << "ERROR: Queue Empty\n";
return (T)(NULL);
}
T temp = this->rear->info;
this->list.deleteBack();
this->front = this->list.head;
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
DoublyEndedQueue<int> q;
do
{
cout << "\tDoubly Ended Queue - Deque\n"
<< "====================================\n"
<< " (1) EnqueueBack (2) DequeueRear\n"
<< " (3) EnqueueFront (4) DequeueFront\n"
<< " (5) Front (6) Display\n"
<< " (0) Exit\n\n";
cout << "Enter Choice: ";
cin >> choice;
switch (choice)
{
case 1:
cout << "\nEnter Element: ";
cin >> el;
q.enqueueRear(el);
cout << "\nEnqueued " << el << " at rear...\n";
cout << "Queue: ";
q.display();
break;
case 2:
res = q.dequeueRear();
if (res)
{
cout << "\nDequeued " << res << " from rear...\n";
cout << "Queue: ";
q.display();
}
break;
case 3:
cout << "\nEnter Element: ";
cin >> el;
q.enqueueFront(el);
cout << "\nEnqueued " << el << " at front...\n";
cout << "Queue: ";
q.display();
break;
case 4:
res = q.dequeueFront();
if (res)
{
cout << "\nDequeued " << res << " from front...\n";
cout << "Queue: ";
q.display();
}


break;
case 5:
cout << "\nFront Element: "
<< q.frontEl() << endl;
break;
case 6:
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
