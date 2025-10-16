# include <iostream>
//
using namespace std;
//

// METODO 1: BUBBLE SORT
// -- Va construyendo una lista ordenada insertando cada elemento en su posición correcta.
void bubbleSort(int n, int vec[]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (vec[j] > vec[j + 1])
                swap(vec[j], vec[j + 1]);
        }
    }
}


// METODO 2: INSERTION SORT
// -- Compara cada par de elementos adyacentes y los intercambia si están en el orden incorrecto.
void insertionSort(int n, int vec[]) {
    for (int i = 1; i < n; i++) {
        int key = vec[i];
        int j = i - 1;
        while (j >= 0 && vec[j] > key) {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = key;
    }
}

// METODO 3: SELECTION SORT
// -- Encuentra el elemento más pequeño y lo coloca en su posición final, repitiendo para el resto.

void selectionSort(int n, int vec[]) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (vec[j] < vec[minIdx])
                minIdx = j;
        }
        swap(vec[i], vec[minIdx]);
    }
}

// METODO 4: QUICK SORT
// -- Divide la lista usando un “pivote”; coloca los menores a la izquierda y mayores a la derecha, luego ordena recursivamente.
int partition(int n, int vec [], int low, int high) {
    int pivot = vec[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (vec[j] < pivot) {
            i++;
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[i + 1], vec[high]);
    return i + 1;
}

void quickSort( int n, int vec [], int low, int high) {
    if (low < high) {
        int pi = partition(n,vec, low, high);
        quickSort(n, vec, low, pi - 1);
        quickSort(n, vec, pi + 1, high);
    }
}
