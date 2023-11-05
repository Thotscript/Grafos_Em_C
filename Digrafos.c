#include <stdlib.h>
#include <stdio.h>
#include <time.h>

struct recebe {
    int valor;
    struct recebe* modifica;
};
//struct vertice onde possui os atribuitos do vertice
struct vertice {
    int Valor;
    struct vertice* proximo_vertice;
};
// struct para criar um vertice novo
struct vertice* criar_vertice(int Valor) {
    struct vertice* novo_vertice = (struct vertice*)malloc(sizeof(struct vertice));
    novo_vertice->Valor = Valor;
    novo_vertice->proximo_vertice = NULL;
    return novo_vertice;
}

// Função auxiliar para imprimir os vértices visitados durante a busca em profundidade
void dfsPrint(struct vertice* vertice, int valorBuscado, int* visitados) {
    if (vertice == NULL) {
        return;
    }

   // visita de vertices
    visitados[vertice->Valor] = 1;
    printf("\nVisitando Valor: %d\n", vertice->Valor);

    if (vertice->Valor == valorBuscado) {
        printf("Vértice %d encontrado, Valor: %d\n", vertice->Valor, vertice->Valor);
        return;
    }

    // Recursivamente visite os vértices 
    struct vertice* vizinho = vertice->proximo_vertice;
    while (vizinho != NULL) {
        if (!visitados[vizinho->Valor]) {
            dfsPrint(vizinho, valorBuscado, visitados);
        }
        vizinho = vizinho->proximo_vertice;
    }
}

int main() {
    int a;
    // define os vertices a serem criados
    printf("Quantidade de Vertices: ");
    scanf("%d", &a);

    struct vertice* primeiro = NULL; // define o primeiro vertice como null indicado que não possui outros vertices

    srand(time(NULL)); 

    for (int i = 1; i <= a; i++) {
        printf("\nVertice[%d]\n\n", i);
        // valor aleatorio para a aresta do vertice de 1 a 50
        int valorAleatorio = 1 + (rand() % 50);
        struct vertice* novo = criar_vertice(valorAleatorio);

        if (primeiro == NULL) {
            primeiro = novo;
        } else {
            struct vertice* temp = primeiro;
            while (temp->proximo_vertice != NULL) {
                temp = temp->proximo_vertice;
            }
            temp->proximo_vertice = novo;
        }
        printf("Valor: %d\n\n", valorAleatorio);
    }
    // Buscar o vertice
    int verticeBuscado;
    printf("Digite o vértice a ser buscado: ");
    scanf("%d", &verticeBuscado);

    int* visitados = (int*)calloc(a + 1, sizeof(int));

    dfsPrint(primeiro, verticeBuscado, visitados);

    free(visitados);

    struct vertice* temp = primeiro;
    while (temp != NULL) {
        struct vertice* proximo = temp->proximo_vertice;
        free(temp);
        temp = proximo;
       
    }
    printf("\n");
    return 0;
}