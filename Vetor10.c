#include <stdio.h>

void heapify(int Vetor[], int n, int i) {
    int Maior = i;         // Inicializa o maior como a raiz
    int Esquerda = 2 * i + 1;    // Indice do filho à esquerda
    int Direita = 2 * i + 2;   // Indice do filho à direita

    if (Esquerda < n && Vetor[Esquerda] > Vetor[Maior])
        Maior = Esquerda;      // Atualiza maior se o filho à esquerda for maior

    if (Direita < n && Vetor[Direita] > Vetor[Maior])
        Maior = Direita;     // Atualiza maior se o filho à direita for maior

    if (Maior != i) {
        int temp = Vetor[i];
        Vetor[i] = Vetor[Maior];
        Vetor[Maior] = temp;  // Troca o elemento raiz com o maior encontrado

        heapify(Vetor, n, Maior); // Recursivamente faz heapify na subárvore afetada
    }
}

void heapSort(int Vetor[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(Vetor, n, i);  // Cria a estrutura heap (max-heap)

    for (int i = n - 1; i > 0; i--) {
        int temp = Vetor[0];
        Vetor[0] = Vetor[i];
        Vetor[i] = temp;        // Move o maior elemento para o final da lista não ordenada

        heapify(Vetor, i, 0);   // Reconstroi o heap para o restante da lista
    }
}

int main() {
    int Vetor[] = {4, 10, 3, 5, 1, 9, 2, 7, 6, 8};
    int n = sizeof(Vetor) / sizeof(Vetor[0]);

    printf("Vetor original: "); 
    for (int i = 0; i < n; i++)
        printf("%d ", Vetor[i]);
    printf("\n");

    heapSort(Vetor, n);    // Chama a função para ordenar o vetor

    printf("Vetor ordenado: ");
    for (int i = 0; i < n; i++)
        printf("%d ", Vetor[i]);
    printf("\n");

    return 0;
}