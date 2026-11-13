#include "team.h"
#include <stdlib.h>
#include <string.h>
//(vitórias, empates, derrotas, gols marcados, gols sofridos)
// TODO: defina aqui os campos de "struct team"
struct team {
    int id, wins, draws, loses, goals_scored, goals_conceded;
    char* name;
};

Team *team_create(int id, const char *name) {
    //Aloca o espaço na memória para um time completo
    Team *t = malloc(sizeof(struct team));
    
    //Verificação de segurança (boa prática em C)
    if (t == NULL) {
        return NULL;
    }

    //Preenche o ID
    t->id = id;

    //3. Duplica e guarda a string do nome na memória
    t->name = strdup(name);

    //Zera as 5 estatísticas
    t->wins = 0;
    t->draws = 0;
    t->loses = 0;
    t->goals_scored = 0;
    t->goals_conceded = 0;

    //Retorna o ponteiro para o time criado
    return t;
}

int team_id(Team *t) {
    if (t == NULL) return 0; // ou 0
    return t->id;
}

const char *team_name(Team *t) {
    if (t == NULL) return NULL; // ou 0
    return t->name;
}

int team_wins(Team *t) {
    if (t == NULL) return 0;
    return t->wins;
}

int team_draws(Team *t) {
    if (t == NULL) return 0;
    return t->draws;
}

int team_losses(Team *t) {
    if (t == NULL) return 0;
    return t->loses;
}

int team_goals_scored(Team *t) {
    if (t == NULL) return 0;
    return t->goals_scored;
}

int team_goals_conceded(Team *t) {
    if (t == NULL) return 0;
    return t->goals_conceded;
}

void team_free(Team *t) {
    if (t == NULL) return;

    free(t->name);
    
    free(t);
}