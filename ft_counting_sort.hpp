/*Questa implementazione funziona creando un array di contatori, dove ogni contatore tiene traccia del numero di elementi con quel valore. 
Quindi, l'array viene ordinato iterando sui contatori e inserendo gli elementi nell'array ordinato in base alla loro posizione nel array di contatori.

L'algoritmo counting sort ha una complessità temporale di O(n + k), dove k è il numero di possibili valori che un elemento dell'array può assumere. 
È un algoritmo efficiente in termini di tempo per gli array con valori non negativi e con un numero limitato di possibili valori.

La differenza principale tra questa implementazione e il radix sort è che questa implementazione non itera sulla cifra di ogni elemento dell'array. 
Invece, crea un array di contatori che tiene traccia del numero di elementi con ogni possibile valore. 
Quindi, l'array viene ordinato iterando sui contatori e inserendo gli elementi nell'array ordinato in base alla loro posizione nel array di contatori.*/

template <typename T>
void ft_counting_sort(T *array, int n) {

  // Calcola la dimensione dell'array di contatori
  int max_value = array[0];
  for (int i = 1; i < n; i++) {
    if (array[i] > max_value) {
      max_value = array[i];
    }
  }

  // Alloca dinamicamente l'array di contatori
  T *count_array = new T[max_value + 1];

  // Verifica se l'allocazione è riuscita
  if (count_array == 0) {
    // Gestisci l'errore di allocazione
    return;
  }

  // Inizializza l'array di contatori a 0
  for (int i = 0; i <= max_value; i++) {
    count_array[i] = 0;
  }

  // Conta il numero di occorrenze di ogni valore
  for (int i = 0; i < n; i++) {
    count_array[array[i]]++;
  }

  // Ordina l'array
  int i = 0;
  for (int j = 0; j <= max_value; j++) {
    for (int k = 0; k < count_array[j]; k++) {
      array[i++] = j;
    }
  }
  delete count_array;
}
