/*Questo algoritmo funziona suddividendo l'array da ordinare in due metà. Quindi, chiama ricorsivamente se stesso per ordinare le due metà.
Infine, unisce le due metà ordinate in un unico array ordinato.

La complessità temporale dell'algoritmo merge sort è O(n log n), dove n è la dimensione dell'array da ordinare. 
La complessità spaziale è O(n), poiché l'algoritmo utilizza un vettore temporaneo di dimensione n per ogni chiamata ricorsiva.*/

template <typename T>
static void merge(T *arr, int begin, int mid, int end)
{
    int const subArrayOne = mid - begin + 1;
    int const subArrayTwo = end - mid;
    T *leftArray = new T[subArrayOne];
    T *rightArray = new T[subArrayTwo];
    for (int i = 0; i < subArrayOne; i++)
        leftArray[i] = arr[begin + i];
    for (int j = 0; j < subArrayTwo; j++)
        rightArray[j] = arr[mid + 1 + j];
    int indexOfSubArrayOne = 0;
    int indexOfSubArrayTwo = 0;
    int indexOfMergedArray = begin;
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
    {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
        {
            arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else
        {
            arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    while (indexOfSubArrayOne < subArrayOne)
    {
        arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    while (indexOfSubArrayTwo < subArrayTwo)
    {
        arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

template <typename T>
void ft_merge_sort(T *arr, int begin, int end)
{
    if (begin >= end)
        return;
    int mid = begin + (end - begin) / 2;
    ft_merge_sort(arr, begin, mid);
    ft_merge_sort(arr, mid + 1, end);
    merge(arr, begin, mid, end);
}