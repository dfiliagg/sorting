/*Questa funzione funziona iterativamente, analizzando l'array dall'inizio alla fine. 
In ogni iterazione, trova il minimo elemento nell'intervallo [i, n) e lo scambia con l'elemento in posizione i.*/

template <typename T>
void ft_selection_sort(T *array, int n) {
  for (int i = 0; i < n - 1; i++) {
    // Trova il minimo elemento nell'intervallo [i, n)
    int min_index = i;
    for (int j = i + 1; j < n; j++) {
      if (array[j] < array[min_index]) {
        min_index = j;
      }
    }

    // Scambia array[i] con array[min_index]
    T temp = array[i];
    array[i] = array[min_index];
    array[min_index] = temp;
  }
}
