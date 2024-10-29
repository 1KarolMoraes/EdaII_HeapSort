#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void heapify(int arr[], int n, int i) {
    int Maior = i;
    int Esquerda = 2 * i + 1;
    int Direita = 2 * i + 2;

    if (Esquerda < n && arr[Esquerda] > arr[Maior])
        Maior = Esquerda;

    if (Direita < n && arr[Direita] > arr[Maior])
        Maior = Direita
;

    if (Maior != i) {
        int temp = arr[i];
        arr[i] = arr[Maior];
        arr[Maior] = temp;
        heapify(arr, n, Maior
);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void fillArray(int arr[], int n, int opcao) {
    if (opcao == 1) { // Vetor totalmente ordenado decrescentemente
        for (int i = 0; i < n; i++)
            arr[i] = n - i;
    } else if (opcao == 2) { // Vetor totalmente ordenado crescentemente
        for (int i = 0; i < n; i++)
            arr[i] = i + 1;
    } else if (opcao == 3) { // Primeira metade crescente, segunda metade decrescente
        for (int i = 0; i < n / 2; i++)
            arr[i] = i + 1;
        for (int i = n / 2; i < n; i++)
            arr[i] = n - i + n / 2;
    } else if (opcao == 4) { // Primeira metade decrescente, segunda metade crescente
        for (int i = 0; i < n / 2; i++)
            arr[i] = n / 2 - i;
        for (int i = n / 2; i < n; i++)
            arr[i] = i - n / 2 + 1;
    } else if (opcao == 5) { // Elementos totalmente desordenados
        srand(time(0));
        for (int i = 0; i < n; i++)
            arr[i] = rand() % n;
    }
}

void evaluateHeapSort(int arr[], int n, int opcao) {
    fillArray(arr, n, opcao);
    clock_t start = clock();
    heapSort(arr, n);
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    printf("Tempo para opção %d: %.6f segundos\n", opcao, time_taken);
}

int main() {
    int n = 100000;
    int arr[n];

    printf("Vetor totalmente ordenado decrescentemente:\n");
    evaluateHeapSort(arr, n, 1);

    printf("Vetor totalmente ordenado crescentemente:\n");
    evaluateHeapSort(arr, n, 2);

    printf("Primeira metade ordenada crescente, segunda metade ordenada decrescentemente:\n");
    evaluateHeapSort(arr, n, 3);

    printf("Primeira metade ordenada decrescente, segunda metade ordenada crescentemente:\n");
    evaluateHeapSort(arr, n, 4);

    printf("Elementos totalmente desordenados:\n");
    evaluateHeapSort(arr, n, 5);

    return 0;
}