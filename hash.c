#include "hash.h"

hash *criar_tabela(int table_size) {
    hash *tabelahash = malloc(sizeof(hash));
    if (tabelahash) {
        tabelahash->table_size = table_size;
        tabelahash->itens = malloc(table_size * sizeof(produto*));
        if (!tabelahash->itens) {
            free(tabelahash);
            return NULL;
        }
        tabelahash->quantidade = 0;
        for (int i = 0; i < table_size; i++) {
            tabelahash->itens[i] = NULL;
        }
    }
    
    return tabelahash;
}

int calcular_hash(int table_size, int chave) {
    return (chave & 0x7FFFFFFF)%table_size;
}

bool inserir_tabela(hash *tabelahash, produto *carlos) {
    int posicao = calcular_hash(tabelahash->table_size, carlos->codigo);
    if(tabelahash->quantidade < tabelahash->table_size && !tabelahash->itens[posicao]) { // Ou seja, não está cheia
        tabelahash->itens[posicao] = carlos;
        tabelahash->quantidade++;
        return true;
    }
    return false;
}

bool buscar_tabela(hash tabelahash, int codigo) {
    int posicao = calcular_hash(tabelahash.table_size, codigo);
    return tabelahash.itens[posicao] && tabelahash.itens[posicao]->codigo == codigo;
}

bool inserir_tabelaColisao(hash *tabelahash, produto *carlos) {
    int i;
    if(tabelahash->quantidade < tabelahash->table_size) {
        int posicao = calcular_hash(tabelahash->table_size, carlos->codigo);
        for (i = posicao; i < tabelahash->table_size && tabelahash->itens[i]; i++); // Ou seja, vai ir de onde estaria o hash até o final.
        if (i < tabelahash->table_size) {
            tabelahash->itens[i] = carlos;
            tabelahash->quantidade++;
            return true;
        }
        for (i = 0; i < posicao && tabelahash->itens[i]; i++);
        if (i < posicao) {
            tabelahash->itens[i] = carlos;
            tabelahash->quantidade++;
            return true;
        }
    }
    return false; // Ou seja, nao tem lugar nenhum para inserir;
}

bool buscar_tabelaColisao(hash *tabelahash, int codigo) {
    int i;
    int posicao = calcular_hash(tabelahash->table_size, codigo);
    for (i = posicao; i < tabelahash->table_size && tabelahash->itens[i] && tabelahash->itens[i]->codigo != codigo; i++);
    if (i < tabelahash->table_size && tabelahash->itens[i] && tabelahash->itens[i]->codigo == codigo) {
        return true;
    }
    for (i = 0; i < posicao && tabelahash->itens[i] && tabelahash->itens[i]->codigo != codigo; i++);
    if (i < posicao && tabelahash->itens[i] && tabelahash->itens[i]->codigo == codigo) {
        return true;
    }
    return false;
    
}