#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <random>
#include <string>

using namespace std;

//Линейный поиск
int Search(int *arr, int size, int requiredValue)
{
  for (int i = 0; i < size; ++i)
  {
    if (arr[i] == requiredValue)
      return arr[i];
  }
  return -1337;
}

void Swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

int Partition(int *arr, int begin, int end)
{
  int x = arr[end];
  int i = begin - 1;

  for (int j = begin; j <= end - 1; j++)
  {
    if (arr[j] <= x)
    {
      i++;
      Swap(&arr[i], &arr[j]);
    }
  }
  Swap(&arr[i + 1], &arr[end]);
  return (i + 1);
}

//Нерекурсивная быстрая сортировка
void QuickSort(int *arr, int size)
{
  const int MAXSTACK = 1024;
  int i, j, lb, ub, lbstack[MAXSTACK], ubstack[MAXSTACK], stackpos = 1, ppos, pivot;
  lbstack[1] = 0;
  ubstack[1] = size - 1;

  do
  {
    lb = lbstack[stackpos];
    ub = ubstack[stackpos];
    stackpos--;
    do
    {
      ppos = (lb + ub) >> 1;
      i = lb;
      j = ub;
      pivot = arr[ppos];
      do
      {
        while (arr[i] < pivot)
          i++;
        while (pivot < arr[j])
          j--;

        if (i <= j)
        {
          Swap(&arr[i], &arr[j]);
          i++;
          j--;
        }
      } while (i <= j);

      if (i < ppos)
      {
        if (i < ub)
        {
          stackpos++;
          lbstack[stackpos] = i;
          ubstack[stackpos] = ub;
        }
        ub = j;
      }
      else
      {
        if (j > lb)
        {
          stackpos++;
          lbstack[stackpos] = lb;
          ubstack[stackpos] = j;
        }
        lb = i;
      }
    } while (lb < ub);
  } while (stackpos != 0);
}

//Рекурсивная быстрая сортировка
void QuickSortRecursive(int *arr, int begin, int end)
{
  if (begin < end)
  {
    int q = Partition(arr, begin, end);
    QuickSortRecursive(arr, begin, q - 1);
    QuickSortRecursive(arr, q + 1, end);
  }
}

//Бинарный поиск
int BinarySearch(const int *arr, int value, int left, int right)
{
  while (right >= left)
  {
    int mid = (right + left) / 2;
    if (arr[mid] == value)
      return mid;
    if (arr[mid] > value)
      right = mid;
    if (arr[mid] < value)
      left = mid + 1;
  }
  return -1;
}

//Рекурсивный бинарный поиск
int RecursiveBinarySearch(int *arr, int value, int left, int right)
{
  int mid = (right + left) / 2;
  if (arr[mid] == value)
    return mid;
  if (arr[mid] > value)
    return RecursiveBinarySearch(arr, value, left, mid);
  if (arr[mid] < value)
    return RecursiveBinarySearch(arr, value, mid + 1, right);
  return -1;
}

//Заполнение массива случайными числами
void FillArrayRnd(int *arr, int size, int min, int max)
{
  std::default_random_engine generator(time(0));
  std::uniform_int_distribution<int> random(min, max);
  for (int i = 0; i < size; ++i)
  {
    arr[i] = random(generator);
  }
}

//Вывод нужного количества элементов
void PrintElem(int *arr, int num)
{
  cout << "First " << num << " elements : ";
  for (int i = 0; i < num; ++i)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main()
{
  int testSearch[10000];
  FillArrayRnd(testSearch, 10000, -1000, 1000);
  cout << "Linear search result: " << Search(testSearch, 10000, 322) << endl;

  int testQuickSort[100];
  FillArrayRnd(testQuickSort, 100, -10, 10);
  PrintElem(testQuickSort, 50);
  QuickSort(testQuickSort, 100);
  PrintElem(testQuickSort, 50);

  int testQuickSortRecursive[100];
  FillArrayRnd(testQuickSortRecursive, 100, -10, 10);
  PrintElem(testQuickSortRecursive, 50);
  QuickSortRecursive(testQuickSortRecursive, 0, 99);
  PrintElem(testQuickSortRecursive, 50);

  int testBinarySearch[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  cout << "Binary search result: " << BinarySearch(testBinarySearch, 6, 0, 3)
       << endl;
  cout << "Recursive binary search result: "
       << RecursiveBinarySearch(testBinarySearch, 1, 0, 9) << endl;

  int timeComparsionTestArray[100];
  FillArrayRnd(timeComparsionTestArray, 100, -10, 10);

  auto startTimeLS = chrono::steady_clock::now();
  Search(timeComparsionTestArray, 100, 6);
  auto endTimeLS = chrono::steady_clock::now();

  auto startTimeBS = chrono::steady_clock::now();
  BinarySearch(timeComparsionTestArray, 6, 0, 100);
  auto endTimeBS = chrono::steady_clock::now();

  auto startTimeRBS = chrono::steady_clock::now();
  RecursiveBinarySearch(timeComparsionTestArray, 6, 0, 100);
  auto endTimeRBS = chrono::steady_clock::now();

  auto benchmarkTimeLS =
      chrono::duration_cast<chrono::nanoseconds>(endTimeLS - startTimeLS);
  auto benchmarkTimeBS =
      chrono::duration_cast<chrono::nanoseconds>(endTimeBS - startTimeBS);
  auto benchmarkTimeRBS =
      chrono::duration_cast<chrono::nanoseconds>(endTimeRBS - startTimeRBS);

  cout << "Linear search benchmark time: " << benchmarkTimeLS.count() << " ns"
       << endl;
  cout << "Binary search benchmark time: " << benchmarkTimeBS.count() << " ns"
       << endl;
  cout << "Recursive binary search benchmark time: " << benchmarkTimeRBS.count()
       << " ns" << endl;
  return 0;
}