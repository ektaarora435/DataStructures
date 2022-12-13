#include <iostream>
#define MAX_SIZE 20
using namespace std;
void getch();
void clrscr();
class Heap
{
public:
int *heap;
int heapSize;
Heap(int *&A, int n)
{
heap = A;
heapSize = n;
}
int parent(int i)
{
return (i - 1) / 2;
}
int left(int i)
{
return 2 * i + 1;
}
int right(int i)
{
return 2 * i + 2;
}
void maxHeapify(int *&A, int n, int i)
{
int temp;
int largest;
int l = left(i);
int r = right(i);



if (l < n && A[l] > A[i])
{
largest = l;
}
else
{
largest = i;
}
if (r < n && A[r] > A[largest])
{
largest = r;
}
if (largest != i)
{
temp = A[i];
A[i] = A[largest];
A[largest] = temp;
maxHeapify(A, n, largest);
}
}
void buildMaxHeap()
{
for (int i = heapSize / 2; i >= 0; i--)
maxHeapify(heap, heapSize, i);
}
};
class MaxPriorityQueue
{
public:
Heap *heap;
MaxPriorityQueue(int A[], int n)
{
heap = new Heap(A, n);
heap->buildMaxHeap();
}
~MaxPriorityQueue()
{
delete heap;
}
int size()
{
return heap->heapSize;
}



void display()
{
if (heap->heapSize == 0)
{
cerr << "ERROR: Heap Empty";
return;
}
for (int i = 0; i < heap->heapSize; i++)
cout << heap->heap[i] << " ";
}
void heapIncreaseKey(int i, int key)
{
int temp;
if (key < heap->heap[i])
{
cerr << "ERROR: New Key is smaller than Existing Key";
return;
}
heap->heap[i] = key;
while (i > 0 && heap->heap[heap->parent(i)] < heap->heap[i])
{
temp = heap->heap[heap->parent(i)];
heap->heap[heap->parent(i)] = heap->heap[i];
heap->heap[i] = temp;
i = heap->parent(i);
}
}
void maxHeapInsert(int key)
{
heap->heapSize++;
heap->heap[heap->heapSize - 1] = INT8_MIN;
heapIncreaseKey(heap->heapSize - 1, key);
}
int heapMaximum()
{
if (heap->heapSize == 0)
{
cerr << "ERROR: Heap Empty";
return -1;
}
return heap->heap[0];
}
int heapExtractMax()



{
if (heap->heapSize < 0)
{
cerr << "ERROR: Heap Underflow";
return -1;
}
else if (heap->heapSize == 0)
{
cerr << "ERROR: Heap Empty";
return -1;
}
int max = heap->heap[0];
heap->heap[0] = heap->heap[heap->heapSize];
heap->maxHeapify(heap->heap, --heap->heapSize, 0);
return max;
}
};
int main(void)
{
int idx, key;
int n, choice = 1, A[MAX_SIZE] = {INT8_MAX};
cout << "Initial Data\n============\n";
cout << "Enter Number of Nodes: ";
cin >> n;
cout << "Enter Keys of the Nodes: ";
for (int i = 0; i < n; i++)
cin >> A[i];
clrscr();
MaxPriorityQueue queue(A, n);
do
{
cout << "\t Max Priority Queue\n"
<< "===========================================\n"
<< " (1) HeapIncreaseKey (2) MaxHeapInsert\n"
<< " (3) HeapMaximum (4) HeapExtractMax\n"
<< " (5) Display (0) Exit\n\n";
cout << "Enter Choice: ";
cin >> choice;
cout << endl;
switch (choice)
{
case 1:
cout << endl;
cout << "Enter Position: ";



cin >> idx;
cout << "Enter New Key: ";
cin >> key;
queue.heapIncreaseKey(idx - 1, key);
cout << endl;
break;
case 2:
cout << endl;
cout << "Enter Key: ";
cin >> key;
queue.maxHeapInsert(key);
break;
case 3:
cout << endl;
key = queue.heapMaximum();
if (key != -1)
cout << "Heap Maximum: "
<< key << endl;
break;
case 4:
cout << endl;
key = queue.heapExtractMax();
if (key != -1)
{
cout << "After Heap Extract Max: ";
queue.display();
cout << endl;
}
break;
case 5:
cout << endl;
queue.display();
cout << endl;
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
