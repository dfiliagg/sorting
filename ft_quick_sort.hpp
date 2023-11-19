/*L'algoritmo quicksort è un algoritmo molto efficiente in termini di tempo, con una complessità media di O(n log n).
Tuttavia, la sua complessità peggiore è O(n^2), che si verifica nel caso peggiore, in cui la sequenza da ordinare è già ordinata o invertita.

L'algoritmo quicksort è un algoritmo molto popolare in ambito pratico, in quanto offre un buon compromesso tra efficienza e semplicità di implementazione.*/

template <typename T>
static void heap_swap(T *a, T *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

template <typename T>
static int ft_partition(T *arr, int low, int high) {
  T pivot = arr[high];
  int i = (low - 1);

  for (int j = low; j < high; j++) {
    if (arr[j] <= pivot) {
      i++;
      heap_swap(&arr[i], &arr[j]);
    }
  }

  heap_swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}

template <typename T>
void ft_quick_sort(T *arr, int low, int high) {
  if (low < high) {
    int pi = ft_partition(arr, low, high);

    ft_quick_sort(arr, low, pi - 1);
    ft_quick_sort(arr, pi + 1, high);
  }
}