#include <iostream>
#define MAX_SIZE 100
using namespace std;
void getch();
void clrscr();
template <class T>
class Queue
{
protected:
T arr[MAX_SIZE];
int front, rear, size;
public:
Queue(int size = 5)
{
this->front = -1;
this->rear = -1;
this->size = size;
}
bool enqueue(T ele)
{
if (this->isFull())
{
cerr << "ERROR: Queue Filled\n";
return false;
}
else
{
if (this->rear == this->size - 1 ||
this->rear == -1)
{
this->arr[0] = ele;
this->rear = 0;
if (this->isEmpty())
this->front = 0;
}
else
this->arr[++(this->rear)] = ele;


return true;
}
}
T dequeue()
{
if (this->isEmpty())
{
cout << "ERROR: Queue Empty\n";
return (T)(NULL);
}
else
{
T temp = this->arr[this->front];
if (this->front == this->rear)
this->clear();
else if (this->front == this->size - 1)
this->front = 0;
else
this->front++;
return temp;
}
}
T frontEl()
{
if (this->isEmpty())
{
cout << "Queue Empty";
return (T)(NULL);
}
return this->arr[this->front];
}
bool isFull()
{
return this->front == 0 &&
this->rear == this->size - 1 ||
this->front == this->rear + 1;
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
if (this->rear >= this->front)
{
for (i = this->front; i < this->rear; i++)
cout << this->arr[i] << " <- ";
cout << this->arr[i] << endl;
}
else
{
for (i = this->front; i < this->size; i++)
cout << this->arr[i] << " <- ";
for (i = 0; i < this->rear; i++)
cout << this->arr[i] << " <- ";
cout << this->arr[i] << endl;
}
return;
}
};
int main(void)
{
int n, el, res, choice;
cout << "Enter Size of Queue: ";
cin >> n;
Queue<int> q(n);
do
{
cout << "\tCircular Queue - Array\n"
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
