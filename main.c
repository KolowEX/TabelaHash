#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "hash.h"

int main()
{
    hash *carlinhos = criar_tabela(10); 
    produto p1 = {2001, "Teclado Mecânico", 199.90, 15};
    produto p2 = {2012, "Mouse Gamer", 149.50, 30};
    produto p3 = {2023, "Monitor 24hz", 899.00, 10};
    produto p4 = {2011, "Controle de churrasqueira", 899.00, 10};
    
    inserir_tabela(carlinhos, &p1); // 2001 % 10 == 1
    inserir_tabela(carlinhos, &p2);
    inserir_tabela(carlinhos, &p3);
    inserir_tabelaColisao(carlinhos, &p4); // 2011 % 10 == 1
    
    for (int i = 0; i < carlinhos->table_size; i++) {
        if (carlinhos->itens[i] == NULL) {
            printf("Posicao %d: Sem produto!\n", i + 1);
        } else {
            printf("Posicao %d: %s!\n", i + 1, carlinhos->itens[i]->nome);
        }
    }
    
    if (!buscar_tabelaColisao(carlinhos, 2001)) {
        printf("\n\nProduto nao encontrado!\n");
    } else {
        printf("\n\nProduto encontrado na posição %d!\n", calcular_hash(carlinhos->table_size, 2001) + 1);
    }
    
    if (!buscar_tabela(*carlinhos, 2011)) {
        printf("\nNão está na posição!\n");
    } else {
        printf("\nEstá na posição!\n");
    }

    return 0;
}
