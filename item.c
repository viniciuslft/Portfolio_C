#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100

struct Item {
    char ID[6], nome[50];
    float unitario, total_item;
    int qtde;
};

int main() {
    struct Item itens[MAX_ITEMS];
    int num_itens, i, j;
    float total_final = 0.0;

    printf("Quantos itens deseja inserir? ");
    scanf("%d", &num_itens);

    if (num_itens <= 0 || num_itens > MAX_ITEMS) {
        printf("Número inválido de itens.\n");
        return 1;
    }

    for (i = 0; i < num_itens; ) {
        int id_duplicado = 0;

        printf("\nItem %d:\n", i + 1);

        printf("ID (Codigo do item): ");
        scanf("%s", itens[i].ID);

        for (j = 0; j < i; j++) {
            if (strcmp(itens[i].ID, itens[j].ID) == 0) {
                printf("ID já inserido. Insira um novo ID.\n");
                id_duplicado = 1;
                break;
            }
        }

        if (id_duplicado) {
            continue; 
        }

        printf("Nome: ");
        scanf("%s", itens[i].nome);

        printf("Valor Unitário: ");
        scanf("%f", &itens[i].unitario);

        printf("Quantidade: ");
        scanf("%d", &itens[i].qtde);

        itens[i].total_item = itens[i].unitario * itens[i].qtde;
        total_final += itens[i].total_item;

        i++; 
    }

    printf("\nCODIGO\tNOME\t\tQTDE\tUNIT\tTOTAL\n");

    for (i = 0; i < num_itens; i++) {
        printf("%s\t%s\t\t%d\t%.2f\t%.2f\n", itens[i].ID, itens[i].nome, itens[i].qtde, itens[i].unitario, itens[i].total_item);
    }

    printf("\n\t\t\t\tTOTAL FINAL\t%.2f\n", total_final);

    return 0;
}

