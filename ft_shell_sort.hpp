/*L'algoritmo di ordinamento Shell è un algoritmo di ordinamento di tipo di scambio. 
Funziona spostando gli elementi dell'array in base a un gap. 
Il gap inizia a metà della dimensione dell'array e viene ridotto a metà ad ogni iterazione.

L'algoritmo di ordinamento Shell è efficiente per array di dimensioni medie e grandi. 
La sua complessità temporale è O(n log n), dove n è la dimensione dell'array.

L'algoritmo di ordinamento Shell è simile all'ordinamento a inserimento, ma funziona spostando gli elementi dell'array in base a un gap. 
Questo rende l'algoritmo di ordinamento Shell più efficiente per array di dimensioni medie e grandi.*/

template <typename T>
void ft_shell_sort(T *array, int n) {
  // Inizializza il gap
  int gap = n / 2;

  // Finché il gap è maggiore di 1
  while (gap > 0) {
    // Per ogni elemento nell'array
    for (int i = gap; i < n; i++) {
      // Inizializza l'elemento corrente
      int temp = array[i];
      int j;
      // Per ogni elemento precedente, a partire dal gap
      for (j = i - gap; j >= 0 && array[j] > temp; j -= gap) {
        // Sposta l'elemento precedente a destra
        array[j + gap] = array[j];
      }

      // Inserisci l'elemento corrente nella sua posizione corretta
      array[j + gap] = temp;
    }

    // Riduci il gap
    gap /= 2;
  }
}