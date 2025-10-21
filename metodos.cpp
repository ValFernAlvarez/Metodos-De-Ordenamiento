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

// MÉTODO 5: MERGE SORT
// -- Divide la lista en dos mitades, las ordena recursivamente y luego las mezcla en una sola lista ordenada.
void merge(int vec[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    // Copiamos los datos a arreglos temporales
    for (int i = 0; i < n1; i++)
        L[i] = vec[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = vec[mid + 1 + j];

    int i = 0, j = 0, k = left;

    // Mezclamos los subarreglos ordenados
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            vec[k] = L[i];
            i++;
        } else {
            vec[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiamos los elementos restantes
    while (i < n1) {
        vec[k++] = L[i++];
    }
    while (j < n2) {
        vec[k++] = R[j++];
    }
}

void mergeSort(int vec[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(vec, left, mid);
        mergeSort(vec, mid + 1, right);
        merge(vec, left, mid, right);
    }
}


// MÉTODO 6: HEAP SORT
// -- Convierte el arreglo en un “montón” (heap) y luego extrae el mayor elemento, ordenando de forma descendente.
void heapify(int vec[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && vec[left] > vec[largest])
        largest = left;

    if (right < n && vec[right] > vec[largest])
        largest = right;

    if (largest != i) {
        swap(vec[i], vec[largest]);
        heapify(vec, n, largest);
    }
}

void heapSort(int vec[], int n) {
    // Construimos el heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(vec, n, i);

    // Extraemos los elementos del heap uno a uno
    for (int i = n - 1; i > 0; i--) {
        swap(vec[0], vec[i]);
        heapify(vec, i, 0);
    }
}

// MÉTODO 7: COMB SORT
// -- Mejora del método burbuja, usa “saltos” grandes que van reduciéndose en cada pasada.
void combSort(int vec[], int n) {
    int gap = n;
    bool swapped = true;

    while (gap != 1 || swapped) {
        // Reducimos el gap
        gap = (gap * 10) / 13;
        if (gap < 1)
            gap = 1;

        swapped = false;

        // Comparamos y cambiamos elementos separados por gap
        for (int i = 0; i + gap < n; i++) {
            if (vec[i] > vec[i + gap]) {
                swap(vec[i], vec[i + gap]);
                swapped = true;
            }
        }
    }
}
