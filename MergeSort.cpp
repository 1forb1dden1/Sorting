#include <iostream>

void merge(int a[], int first, int middle, int last)
{
  int* temp = new int[last + 1];

  int k = first;
  while (k <= last)
  {
    temp[k] = a[k];
    k++;
  }

  int i = first;
  int j = middle + 1;
  k = first;

  while (i <= middle && j <= last) // if the left side reaches middle and right side reaches the end
  {
    if (temp[i] <= temp[j])
    {
      a[k] = temp[i];
      i++;
    }
    else
    {
      a[k] = temp[j];
      j++;
    }
    k++;
  }

  // k is at first. We will iterate through until we reach the end inserting from left to right. 
  while (i <= middle)
  {
    a[k] = temp[i];
    i++;
    k++;
  }
  while (j <= last)
  {
    a[k] = temp[j];
    j++;
    k++;
  }

  delete[] temp;

}
void mergeSort(int a[], int first, int last)
{
  if (first >= last)
  {
    return; 
  }

  int middle = (first + last) / 2;
  mergeSort(a, first, middle);
  mergeSort(a, middle + 1, last);
  merge(a, first, middle, last);
}
void mergeSort(int a[], int n)
{
  mergeSort(a, 0, n - 1);
}
void printArray(int a[], int s)
{
  for (int i = 0; i < s; i++)
  {
    std::cout << a[i] << ", ";
  }
  std::cout << "\n";
}

int main()
{
  int array[] = { 102, 230, 1939, 1832, 11, 38, 434, 5823 };
  int size = sizeof(array) / sizeof(int);
  std::cout << "Array Before Sorting\n";
  printArray(array, size);
  mergeSort(array, size);
  std::cout << "Array after Sorting\n";
  printArray(array, size);
}
