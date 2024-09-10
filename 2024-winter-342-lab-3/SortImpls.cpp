#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

void mySwap(int &s1, int &s2)
{
    int temp = s1;
    s1 = s2;
    s2 = temp;
}

void BubbleSort1(vector <int> &data, int size)
{
    for(int i = size - 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if(data[j] > data[j+1])
            {
                mySwap(data[j], data[j+1]);
            }
        }
    }
}

void BubbleSort2(vector <int> &data, int size)
{
    bool sortArray;
    for(int i = size - 1; i >= 0; i--)
    {
        sortArray = false;
        for (int j = 0; j < i; j++)
        {
            if(data[j] > data[j+1])
            {
                mySwap(data[j], data[j+1]);
                sortArray = true;
            }
        }
        if(!sortArray)
        {
            break;
        }
    }
}

void BubbleSort3(vector <int> &data, int index1, int index2)
{
    for (int i = index2; i >= index1; i--)
    {
        for (int j = i; j < index2; j++)
        {
            if(data[j] > data[j+1])
            {
                mySwap(data[j], data[j+1]);
            }
        }
    }
}

void InsertionSort(vector <int> &data, int first, int last)
{
    for (int i = first; i <= last; i++)
    {
        int v = data[i];
        int j = i - 1;
        while (j >= first && data[j] > v)
        {
            data[j+1] = data[j];
            j--;
        }
        data[j+1] = v;
    }
}

void Merge(vector <int> &data, int first, int mid, int last)
{
    int tempData[data.size()];
    int first1 = first;
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = last;
    int index = first1;
    while ((first1 <= last1) && (first2 <= last2))
    {
        if (data[first1] <= data[first2])
        {
            tempData[index] = data[first1];
            first1++;
        }else
        {
            tempData[index] = data[first2];
            first2++;
        }
        index++;
    }
    while (first1 <= last1)
    {
        tempData[index] = data[first1];
        first1++;
        index++;
    }
    while (first2 <= last2)
    {
        tempData[index] = data[first2];
        first2++;
        index++;
    }
    for (index = first; index <= last; index++)
    {
        data[index] = tempData[index];
    }
}

void MergeSort(vector <int> &data, int first, int last)
{
    if (first < last)
    {
        int mid = first + (last - first) / 2;
        MergeSort(data, first, mid);
        MergeSort(data, mid + 1, last);
        Merge(data, first, mid, last);
    }
}

int Partition(vector <int> &data, int first, int last)
{
    int pivotIndex = first + (rand() % (last - first + 1));
    if (pivotIndex != last)
    {
        mySwap(data[pivotIndex], data[last]);
    }
    int pivotValue = data[last];
    int i = first;
    for (int j = first; j < last; j++)
    {
        if (data[j] <= pivotValue)
        {
            mySwap(data[i], data[j]);
            i++;
        }
    }
    mySwap(data[i], data[last]);
    return i;
}

void QuickSort(vector <int> &data, int first, int last)
{
    if (first < last)
    {
        int pivotIndex = Partition(data, first, last);
        QuickSort(data, first, pivotIndex - 1);// Sorts left portion of vector.
        QuickSort(data, pivotIndex + 1, last);// Sorts right portion of vector. 
    }
}

void ShellSort (vector <int> &data, int first, int last)
{
    for (int gap = last/2; gap > first; gap /= 2)
    {
        for (int i = gap; i < last; i += 1)
        {
            int tempData = data[i];
            int j;
            for (j = i; j >= gap && data[j - gap] > tempData; j -= gap)
            {
                data[j] = data[j - gap];
            }
            data [j] = tempData;
        }
    }
}