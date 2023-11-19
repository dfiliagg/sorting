/*Questa implementazione funziona iterando sull'array, scorrendo ogni cifra da destra a sinistra. 
Per ogni cifra, viene utilizzata la funzione count_sort() per ordinare l'array in base a quella cifra. 
La funzione count_sort() funziona creando un array di contatori, dove ogni contatore tiene traccia del numero di elementi con quella cifra. 
Quindi, l'array viene ordinato iterando sui contatori e inserendo gli elementi nell'array ordinato in base alla loro posizione nel array di contatori.

L'algoritmo radix sort ha una complessità temporale di O(d * n), dove d è il numero di cifre in un elemento dell'array.
È un algoritmo efficiente in termini di tempo per gli array con valori interi o stringhe con caratteri alfabetici.*/

template <typename T>
static int get_max(T *arr, int n) {
  T max = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
}

template <typename T>
static void count_sort(T *arr, int n, int exp) {
  T *output = new T[n];
  T *count[10] = new T[];

  for (int i = 0; i < n; i++) {
    count[(arr[i] / exp) % 10]++;
  }

  for (int i = 1; i < 10; i++) {
    count[i] += count[i - 1];
  }

  for (int i = n - 1; i >= 0; i--) {
    output[count[(arr[i] / exp) % 10] - 1] = arr[i];
    count[(arr[i] / exp) % 10]--;
  }

  for (int i = 0; i < n; i++) {
    arr[i] = output[i];
  }
}

template <typename T>
void ft_radix_sort(T *arr, int n) {
  T max = get_max(arr, n);
  for (int exp = 1; max / exp > 0; exp *= 10) {
    count_sort(arr, n, exp);
  }
}
