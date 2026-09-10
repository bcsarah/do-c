#include "tasks.h"
#include <stdio.h>
#include <string.h>

/* ===== TYPEDEF DAS TAREFAS ===== */
typedef struct { // ainda não sei como funciona exatamente. vou ver no curso ou no livro, imagino eu
    int id;
    char nome[32];
    int concluida; // 0 sim, 1 não
} Tarefa;


/* ===== COMANDOS DE TAREFA ===== */
void view_tasks(void) {
    printf("Listando tarefas...\n");
}

void add_task(char nome[32]) {
    printf("Adicionando tarefa...\n");

    Tarefa lista[100];
    int total = 0;
    
    lista[total].id = total + 1;
    strcpy(lista[total].nome, nome);
    lista[total].concluida = 0;
    total++;

    for (int i = 0; i < total; i++) {
        printf("%d - %s\n", lista[i].id, lista[i].nome);
    }
};

void remove_task(void) {
    printf("Removendo tarefa...\n");
}

void complete_task(void) {
    printf("Completando tarefa...\n");
}

void edit_task(void) {
    printf("Editando tarefa...\n");
}


/* ===== AJUDA ===== */
void show_help(void) {
    printf("Comandos disponíveis:\n");
    printf("  add      - Adiciona uma tarefa\n");
    printf("  view     - Lista as tarefas\n");
    printf("  remove   - Remove uma tarefa\n");
    printf("  complete - Marca como concluída\n");
    printf("  edit     - Edita uma tarefa\n");
    printf("  help     - Mostra esta ajuda\n");
}