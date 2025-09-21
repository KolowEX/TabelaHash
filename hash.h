#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED

typedef struct {
  int codigo;
  char nome[30];
  float preco;
  int quantidade;
}produto;

typedef struct {
  int quantidade, table_size;
  produto **itens;
}hash;

hash *criar_tabela(int table_size);
int calcular_hash(int table_size, int chave);
bool inserir_tabela(hash *tabelahash, produto *carlos);
bool buscar_tabela(hash tabelahash, int codigo);
bool inserir_tabelaColisao(hash *tabelahash, produto *carlos);
bool buscar_tabelaColisao(hash *tabelahash, int codigo);


#endif

