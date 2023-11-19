/*L'algoritmo di ordinamento a inserimento funziona confrontando l'elemento corrente con gli elementi precedenti nell'array. 
Se l'elemento corrente è minore di un elemento precedente, gli elementi vengono scambiati. 
Questo processo viene ripetuto fino a quando l'elemento corrente non si trova nella sua posizione corretta.

L'algoritmo di ordinamento a inserimento è efficiente per array di piccole dimensioni. 
La sua complessità temporale è O(n^2), dove n è la dimensione dell'array.*/

template <typename T>
void ft_insertion_sort(T *array, int n) {
  
  for (int i = 1; i < n; i++) {
    int key = array[i];
    int j = i - 1;
    
    while (j >= 0 && array[j] > key) {
      array[j + 1] = array[j];
      j--;
    }
    array[j + 1] = key;
  }
}

