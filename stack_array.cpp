#include <iostream>
#define MAX_SIZE 100
using namespace std;
void getch();
void clrscr();
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
void display()
{
if (this->isEmpty())
{
cout << "Stack Empty";
return;
}
int i;
cout << "Stack: ";
for (i = 0; i < this->tos; i++)
cout << this->arr[i] << " -> ";
cout << this->arr[i] << endl;
return;
}
};
int main(void)
{
int n, el, res, choice;
cout << "Enter size of stack: ";
cin >> n;
Stack<int> stack(n);
do
{
cout << "\tStack - Arrays\n"
<< "=============================\n"

<< " (1) Push (2) Pop\n"
<< " (3) Top (4) Clear\n"
<< " (5) Display (0) Exit\n\n";
cout << "Enter Choice: ";
cin >> choice;
switch (choice)
{
case 1:
cout << "\nEnter Element: ";
cin >> el;
res = stack.push(el);
if (res)
{
cout << "\nPushed " << el << "...\n";
stack.display();
}
break;
case 2:
res = stack.pop();
if (res)
{
cout << "\nPopped " << res << "...\n";
stack.display();
}
break;
case 3:
cout << "\nTop Element: "
<< stack.top() << endl;
break;
case 4:
stack.clear();
break;
case 5:
stack.display();
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
