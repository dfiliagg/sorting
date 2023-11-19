/*L'heapsort è un algoritmo di ordinamento efficiente. Ha una complessità temporale di O(n log n), che è la stessa del merge sort e del quick sort. 
Tuttavia, l'heapsort è leggermente più lento di questi algoritmi in caso medio.

L'heapsort è anche un algoritmo di ordinamento in-place, il che significa che non richiede memoria aggiuntiva per l'ordinamento.
Ciò lo rende un'opzione efficiente per l'ordinamento di grandi array.*/

template <typename T>
static void swap(T *a, T *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

template <typename T>
static void max_heapify(T *arr, int n, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && arr[left] > arr[largest]) {
    largest = left;
  }

  if (right < n && arr[right] > arr[largest]) {
    largest = right;
  }

  if (largest != i) {
    swap(&arr[i], &arr[largest]);
    max_heapify(arr, n, largest);
  }
}

template <typename T>
static void build_max_heap(T *arr, int n) {
  for (int i = n / 2 - 1; i >= 0; i--) {
    max_heapify(arr, n, i);
  }
}

template <typename T>
void ft_heap_sort(T *arr, int n) {
  build_max_heap(arr, n);

  for (int i = n - 1; i >= 0; i--) {
    swap(&arr[0], &arr[i]);
    n--;
    max_heapify(arr, n, 0);
  }
}