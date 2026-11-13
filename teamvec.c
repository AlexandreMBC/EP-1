#include "teamvec.h"
#include <stdlib.h>

// TODO: defina aqui os campos de "struct teamvec" -- pense no que o TAD
// precisa guardar para saber quantos times tem e quanto espaço ainda sobra
struct teamvec {
    Team **teams; 
    int size;
    int capacity;
};

TeamVec *tv_create(void) {
    //Cria a variável e aloca a "caixa" principal do vetor
    TeamVec *tv = malloc(sizeof(struct teamvec));
    
    //Verificação de segurança (boa prática)
    if (tv == NULL) return NULL;

    //Preenche os dados iniciais
    tv->capacity = 4;
    tv->size = 0;
    
    //Aloca as "vagas" do array interno para guardar os ponteiros de Team
    tv->teams = malloc(tv->capacity * sizeof(Team *));

    return tv;
}

void tv_insert(TeamVec *tv, Team *t) {
    if (tv->size == tv->capacity) {

        tv->capacity = tv->capacity * 2;
        
        tv->teams = realloc(tv->teams, tv->capacity * sizeof(Team *));
    }
    
    tv->teams[tv->size] = t;

    tv->size++;
}

int tv_size(TeamVec *tv) {
    if (tv == NULL) return 0;
    return tv->size;
}

Team *tv_get(TeamVec *tv, int i) {
    //Verifica se o índice pedido é válido (maior ou igual a 0 e menor que o tamanho atual)
    if (tv == NULL || i < 0 || i >= tv->size) {
        return NULL;
    }
    return tv->teams[i];
}

void tv_free(TeamVec *tv) {
    if (tv == NULL) return;
    
    //Liberta cada time guardado chamando a função do team.c
    for (int i = 0; i < tv->size; i++) {
        team_free(tv->teams[i]);
    }
    
    //Liberta o vetor dinâmico interno
    free(tv->teams);
    
    //Liberta a caixa principal do TAD TeamVec
    free(tv);
}