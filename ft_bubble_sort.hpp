/*L'algoritmo bubble sort ha una complessità temporale di O(n^2) in media e nel caso peggiore. 
È un algoritmo semplice da implementare, ma non è molto efficiente in termini di tempo.*/

template <typename T>
static void bubble_swap(T *a, T *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

template <typename T>
void ft_bubble_sort(T *arr, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        bubble_swap(&arr[j], &arr[j + 1]);
      }
    }
  }
}