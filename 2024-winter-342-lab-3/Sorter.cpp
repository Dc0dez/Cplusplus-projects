#include <iostream> 
#include <vector> 
#include <string> 
#include "SortImpls.cpp" 
#include <sys/time.h> 
#include <ctime>
#include <algorithm>
using namespace std;

void InitArray(vector<int> &array, int randMax) 
{ 
  if (randMax < 0) 
  { 
    return; 
  } 
  vector<int> pool(randMax); 
  for (int i = 0; i < randMax; i++) 
  { 
    pool[i] = i; 
  } 
  int spot; 
  for (int i = 0; i < randMax; i++) 
  { 
    spot = rand() % (pool.size()); 
    array[i] = pool[spot]; 
    pool.erase(pool.begin() + spot); 
  } 
} 

void InitArrayMid(vector<int> &array, int randMax) 
{ 
  if (randMax < 0) 
  { 
    return; 
  } 
  vector<int> pool(randMax); 
  for (int i = 0; i < randMax; i++) 
  { 
    pool[i] = i; 
    array[i] = i; 
  } 
  int spot; 
  int i1 = 0.01*randMax; 
  int i2 = 0.99*randMax; 
  for (int i = i1; i < i2; i++) 
  { 
    spot = rand() % (pool.size()); 
    array[i] = pool[spot]; 
    pool.erase(pool.begin() + spot); 
  } 
} 

void PrintArrayDetails(const vector<int> &array, string name) 
{ 
  int size = array.size(); 
  for (int i = 0; i < size; i++) 
      cout << name << "[" << i << "] = " << array[i] << endl; 
} 
  // Function to calculate elapsed time if using gettimeofday (Linux) 
int Elapsed( timeval &startTime, timeval &endTime ) 
{ 
  return ( endTime.tv_sec - startTime.tv_sec ) * 1000000 + ( endTime.tv_usec - startTime.tv_usec ); 
}

bool Reverse(int i, int j) 
{
  return (i > j); 
}

int main(int argc, char *argv[]) 
{ 
  int size = 0; 
  string sortName = ""; 
  bool printOut = true; 
  if ((argc != 3) && (argc != 4)) 
  { 
    cerr << "Usage: Sorter SORT_TYPE ARRAY_SIZE [YES|NO]" << endl; 
    return -1; 
  } 
  sortName = string(argv[1]); 
  size = atoi(argv[2]);
  if (size <= 0) 
  { 
    cerr << "Array size must be positive" << endl; 
    return -1; 
  }
  if (argc == 4) 
  { 
    string printArr = string(argv[3]); 
    if (printArr == "NO") 
    { 
      printOut = false; 
    }else if (printArr == "YES") 
    { 
      printOut = true; 
    }else 
    { 
      cerr << "Usage: Sorter SORT_TYPE ARRAY_SIZE [YES|NO]" << endl; 
      return -1; 
    } 
  } 
  srand(1); 
  vector<int> randomItems(size); 
  vector<int> orderedItems(size);
  vector<int> reversedItems(size);
  vector<int> partialItems(size);
  InitArrayMid(randomItems, size); 
  InitArrayMid(orderedItems, size);
  InitArrayMid(reversedItems, size); 
  InitArrayMid(partialItems, size); 
  sort(orderedItems.begin(), orderedItems.end());
  sort(reversedItems.begin(), reversedItems.end(), Reverse);
  sort(partialItems.begin() + (size / 2), partialItems.end());
  if (printOut) 
  { 
    cout << "Random initial:" << endl; 
    PrintArrayDetails(randomItems, string("items")); 
    cout << "Ordered initial:" << endl; 
    PrintArrayDetails(orderedItems, string("items")); 
    cout << "Reversed initial:" << endl; 
    PrintArrayDetails(reversedItems, string("items")); 
    cout << "Partial initial:" << endl; 
    PrintArrayDetails(partialItems, string("items")); 
  } 
  struct timeval startTime, endTime; 
  gettimeofday(&startTime, 0); // Linux 
  if (sortName == "BubbleSort1") 
  { 
    BubbleSort1(randomItems, size);
    BubbleSort1(orderedItems, size);
    BubbleSort1(reversedItems, size);
    BubbleSort1(partialItems, size);
  } 
  if (sortName == "BubbleSort2") 
  { 
    BubbleSort2(randomItems, size);
    BubbleSort2(orderedItems, size);
    BubbleSort2(reversedItems, size);
    BubbleSort2(partialItems, size);
  } 
  if (sortName == "BubbleSort3") 
  { 
    BubbleSort3(randomItems, 0, size - 1);
    BubbleSort3(orderedItems, 0, size - 1);
    BubbleSort3(reversedItems, 0, size - 1);
    BubbleSort3(partialItems, 0, size - 1);
  } 
  if (sortName == "InsertionSort") 
  { 
    InsertionSort(randomItems, 0, size - 1); 
    InsertionSort(orderedItems, 0, size - 1); 
    InsertionSort(reversedItems, 0, size - 1); 
    InsertionSort(partialItems, 0, size - 1); 
  } 
  if (sortName == "MergeSort") 
  { 
    MergeSort(randomItems, 0, size - 1); 
    MergeSort(orderedItems, 0, size - 1);
    MergeSort(reversedItems, 0, size - 1);  
    MergeSort(partialItems, 0, size - 1); 
  } 
  if (sortName == "QuickSort") 
  { 
    srand(time(NULL));
    QuickSort(randomItems, 0, size - 1); 
    QuickSort(orderedItems, 0, size - 1);
    QuickSort(reversedItems, 0, size - 1);
    QuickSort(partialItems, 0, size - 1);
  } 
  if (sortName == "ShellSort")   
  { 
    ShellSort(randomItems, 0, size - 1);
    ShellSort(orderedItems, 0, size - 1); 
    ShellSort(reversedItems, 0, size - 1); 
    ShellSort(partialItems, 0, size - 1);  
  } 
  gettimeofday(&endTime, 0); 
  if (printOut) 
  { 
    cout << "Sorted random:" << endl; 
    PrintArrayDetails(randomItems, string("item"));
    cout << "Sorted ordered:" << endl;  
    PrintArrayDetails(orderedItems, string("items")); 
    cout << "Sorted reversed:" << endl; 
    PrintArrayDetails(reversedItems, string("items"));
    cout << "Sorted partial:" << endl; 
    PrintArrayDetails(partialItems, string("items"));
  } 
  int elapsedSecs = Elapsed(startTime,endTime); 
  cout << "Time (ms): " << elapsedSecs << endl; 
  return 0; 
} 