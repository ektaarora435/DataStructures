#include <iostream>
#define MAX_SIZE 100
using namespace std;
void getch();
void clrscr();
template <class T>
void swapElements(T &a, T &b)
{
T t = a;
a = b;
b = t;
}
template <class T>
T *bubbleSort(T *arr, int size)
{
for (int i = 0; i < size - 1; i++)
for (int j = 0; j < size - i - 1; j++)
if (arr[j] > arr[j + 1])
swapElements<T>(arr[j], arr[j + 1]);
return arr;
}
template <class T>
T *insertionSort(T *arr, int size)
{
T key;
int i, j;
for (i = 1; i < size; i++)
{
key = arr[i];
j = i - 1;
while (j >= 0 && arr[j] > key)
{
arr[j + 1] = arr[j--];
}
arr[j + 1] = key;
}



return arr;
}
template <class T>
T *selectionSort(T *arr, int size)
{
int min;
for (int i = 0; i < size - 1; i++)
{
min = i;
for (int j = i + 1; j < size; j++)
if (arr[j] < arr[min])
min = j;
swapElements<T>(arr[min], arr[i]);
}
return arr;
}
template <class T>
void display(T *arr, int size)
{
for (int i = 0; i < size; i++)
cout << arr[i] << " ";
}
int main(void)
{
int ch = 1, size, arr[MAX_SIZE];
cout << "Enter Number of Elements: ";
cin >> size;
cout << "Enter Array Elements: ";
for (int i = 0; i < size; i++)
cin >> arr[i];
clrscr();
do
{
cout << "\t\tMenu\n========================================\n"
<< " (1) Bubble Sort (2) Insertion Sort\n"
<< " (3) Selection Sort (0) Exit\n\n";
cout << "Enter Choice: ";
cin >> ch;
switch (ch)
{
case 1:



cout << endl;
cout << "Original Array: ";
display<int>(arr, size);
cout << endl;
cout << "Bubble Sort: ";
display<int>(bubbleSort<int>(arr, size), size);
cout << endl;
break;
case 2:
cout << endl;
cout << "Original Array: ";
display<int>(arr, size);
cout << endl;
cout << "Insertion Sort: ";
display<int>(insertionSort<int>(arr, size), size);
cout << endl;
break;
case 3:
cout << endl;
cout << "Original Array: ";
display<int>(arr, size);
cout << endl;
cout << "Selection Sort: ";
display<int>(selectionSort<int>(arr, size), size);
cout << endl;
break;
default:
break;
}
getch();
clrscr();
} while (ch != 0);
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
