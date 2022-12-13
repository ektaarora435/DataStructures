DIAGONAL MATRIX
#include <climits>
#include <iostream>
#define MAX_SIZE 10
using namespace std;
void getch();
void clrscr();
class DiagonalMatrix
{
public:
int *arr;
int size;
int nrows;
int ncols;
DiagonalMatrix(int rows = MAX_SIZE,
int cols = MAX_SIZE)
{
if (rows != cols)
cerr << "ERROR: Invalid Dimensions" << endl;
else
{
size = rows;
nrows = ncols = rows;
arr = new int[size];
for (int i = 0; i < size; i++)
arr[i] = 0;
}
}
~DiagonalMatrix()
{
delete[] arr;
}


void store(int data, int row, int col)
{
if (row != col || row >= nrows || col >= ncols)
cerr << "ERROR: Invalid Location" << endl;
else
arr[row] = data;
}
int retrieve(int row, int col)
{
if (row >= nrows || col >= ncols)
return INT_MIN;
if (row != col)
return 0;
else
return arr[row];
}
void display()
{
for (int i = 0; i < nrows; i++)
{
for (int j = 0; j < ncols; j++)
if (i == j)
cout << arr[i] << " ";
else
cout << 0 << " ";
cout << endl;
}
}
};
int main(void)
{
int rows, cols, data, choice = 1;
cout << "Enter Number of Rows: ";
cin >> rows;
cout << "Enter Number of Columns: ";
cin >> cols;
clrscr();
DiagonalMatrix matrix(rows, cols);
do



{
cout << " MENU \n"
<< "================\n"
<< "(1) Display\n"
<< "(2) Store\n"
<< "(3) Retrieve\n"
<< "(0) Exit\n\n";
cout << "Enter Choice: ";
cin >> choice;
switch (choice)
{
case 1:
cout << "\nMatrix:\n";
matrix.display();
break;
case 2:
cout << "Enter Data: ";
cin >> data;
cout << "Enter Position: ";
cin >> rows >> cols;
matrix.store(data, rows, cols);
break;
case 3:
cout << "Enter Position: ";
cin >> rows >> cols;
data = matrix.retrieve(rows, cols);
if (data != INT_MIN)
cout << "Retrieved " << data << endl;
else
cerr << "ERROR: Invalid Location" << endl;
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


LOWER TRIANGULAR MATRIX
#include <climits>
#include <iostream>
#define MAX_SIZE 10
using namespace std;
void getch();
void clrscr();
class LowerTriangularMatrix
{
public:
int *arr;
int size;
int nrows;
int ncols;
LowerTriangularMatrix(int rows = MAX_SIZE,
int cols = MAX_SIZE)
{
if (rows != cols)
cerr << "ERROR: Invalid Dimensions" << endl;
else
{
size = rows * (rows + 1) / 2;
nrows = ncols = rows;

Page 125 of 166

arr = new int[size];
for (int i = 0; i < size; i++)
arr[i] = 0;
}
}
~LowerTriangularMatrix()
{
delete[] arr;
}
void store(int data, int row, int col)
{
if (col > row || row >= nrows || col >= ncols)
cerr << "ERROR: Invalid Location" << endl;
else
arr[row * (row + 1) / 2 + col] = data;
}
int retrieve(int row, int col)
{
if (row >= nrows || col >= ncols)
return INT_MIN;
if (col > row)
return 0;
else
return arr[row * (row + 1) / 2 + col];
}
void display()
{
for (int i = 0; i < nrows; i++)
{
for (int j = 0; j < ncols; j++)
if (i >= j)
cout << arr[i * (i + 1) / 2 + j] << " ";
else
cout << 0 << " ";
cout << endl;
}
}
};
int main(void)
{
int rows, cols, data, choice = 1;

Page 126 of 166

cout << "Enter Number of Rows: ";
cin >> rows;
cout << "Enter Number of Columns: ";
cin >> cols;
clrscr();
LowerTriangularMatrix matrix(rows, cols);
do
{
cout << " MENU \n"
<< "================\n"
<< "(1) Display\n"
<< "(2) Store\n"
<< "(3) Retrieve\n"
<< "(0) Exit\n\n";
cout << "Enter Choice: ";
cin >> choice;
switch (choice)
{
case 1:
cout << "\nMatrix:\n";
matrix.display();
break;
case 2:
cout << "Enter Data: ";
cin >> data;
cout << "Enter Position: ";
cin >> rows >> cols;
matrix.store(data, rows, cols);
break;
case 3:
cout << "Enter Position: ";
cin >> rows >> cols;
data = matrix.retrieve(rows, cols);
if (data != INT_MIN)
cout << "Retrieved " << data << endl;
else
cerr << "ERROR: Invalid Location" << endl;
break;
case 0:
default:
break;
}
getch();
clrscr();

Page 127 of 166

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


UPPER TRIANGULAR
#include <climits>
#include <iostream>
#define MAX_SIZE 10
using namespace std;
void getch();
void clrscr();
class UpperTriangularMatrix
{
public:
int *arr;
int size;
int nrows;
int ncols;
UpperTriangularMatrix(int rows = MAX_SIZE,
int cols = MAX_SIZE)
{
if (rows != cols)
cerr << "ERROR: Invalid Dimensions" << endl;
else
{
size = cols * (cols + 1) / 2;
nrows = ncols = rows;
arr = new int[size];

Page 130 of 166
for (int i = 0; i < size; i++)
arr[i] = 0;
}
}
~UpperTriangularMatrix()
{
delete[] arr;
}
void store(int data, int row, int col)
{
if (row > col || row >= nrows || col >= ncols)
cerr << "ERROR: Invalid Location" << endl;
else
arr[col * (col + 1) / 2 + row] = data;
}
int retrieve(int row, int col)
{
if (row >= nrows || col >= ncols)
return INT_MIN;
if (row > col)
return 0;
else
return arr[col * (col + 1) / 2 + row];
}
void display()
{
for (int i = 0; i < nrows; i++)
{
for (int j = 0; j < ncols; j++)
if (j >= i)
cout << arr[j * (j + 1) / 2 + i] << " ";
else
cout << 0 << " ";
cout << endl;
}
}
};
int main(void)
{
int rows, cols, data, choice = 1;
cout << "Enter Number of Rows: ";

Page 131 of 166

cin >> rows;
cout << "Enter Number of Columns: ";
cin >> cols;
clrscr();
UpperTriangularMatrix matrix(rows, cols);
do
{
cout << " MENU \n"
<< "================\n"
<< "(1) Display\n"
<< "(2) Store\n"
<< "(3) Retrieve\n"
<< "(0) Exit\n\n";
cout << "Enter Choice: ";
cin >> choice;
switch (choice)
{
case 1:
cout << "\nMatrix:\n";
matrix.display();
break;
case 2:
cout << "Enter Data: ";
cin >> data;
cout << "Enter Position: ";
cin >> rows >> cols;
matrix.store(data, rows, cols);
break;
case 3:
cout << "Enter Position: ";
cin >> rows >> cols;
data = matrix.retrieve(rows, cols);
if (data != INT_MIN)
cout << "Retrieved " << data << endl;
else
cerr << "ERROR: Invalid Location" << endl;
break;
case 0:
default:
break;
}
getch();
clrscr();

Page 132 of 166

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


SYMMETRIC MATRIX
#include <climits>
#include <iostream>
#define MAX_SIZE 10
using namespace std;
void getch();
void clrscr();
class SymmetricMatrix
{
public:
int *arr;
int size;
int nrows;
int ncols;
SymmetricMatrix(int rows = MAX_SIZE,
int cols = MAX_SIZE)
{
if (rows != cols)
cerr << "ERROR: Invalid Dimensions" << endl;
else
{
size = rows * (rows + 1) / 2;
nrows = ncols = rows;
arr = new int[size];
for (int i = 0; i < size; i++)
arr[i] = 0;
}
}

Page 135 of 166

~SymmetricMatrix()
{
delete[] arr;
}
void store(int data, int row, int col)
{
if (row >= nrows || col >= ncols)
cerr << "ERROR: Invalid Location" << endl;
else if (col > row)
arr[col * (col + 1) / 2 + row] = data;
else
arr[row * (row + 1) / 2 + col] = data;
}
int retrieve(int row, int col)
{
if (row >= nrows || col >= ncols)
return INT_MIN;
if (col > row)
return arr[col * (col + 1) / 2 + row];
else
return arr[row * (row + 1) / 2 + col];
}
void display()
{
for (int i = 0; i < nrows; i++)
{
for (int j = 0; j < ncols; j++)
if (i > j)
cout << arr[i * (i + 1) / 2 + j] << " ";
else
cout << arr[j * (j + 1) / 2 + i] << " ";
cout << endl;
}
}
};
int main(void)
{
int rows, cols, data, choice = 1;
cout << "Enter Number of Rows: ";
cin >> rows;
cout << "Enter Number of Columns: ";

Page 136 of 166

cin >> cols;
clrscr();
SymmetricMatrix matrix(rows, cols);
do
{
cout << " MENU \n"
<< "================\n"
<< "(1) Display\n"
<< "(2) Store\n"
<< "(3) Retrieve\n"
<< "(0) Exit\n\n";
cout << "Enter Choice: ";
cin >> choice;
switch (choice)
{
case 1:
cout << "\nMatrix:\n";
matrix.display();
break;
case 2:
cout << "Enter Data: ";
cin >> data;
cout << "Enter Position: ";
cin >> rows >> cols;
matrix.store(data, rows, cols);
break;
case 3:
cout << "Enter Position: ";
cin >> rows >> cols;
data = matrix.retrieve(rows, cols);
if (data != INT_MIN)
cout << "Retrieved " << data << endl;
else
cerr << "ERROR: Invalid Location" << endl;
break;
case 0:
default:
break;
}
getch();
clrscr();
} while (choice != 0);

Page 137 of 166

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


