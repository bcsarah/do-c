#include "tasks.h"
#include <stdio.h>


/* ===== COMANDOS DE TAREFA ===== */
void view_tasks(void) {
    printf("Listando tarefas...\n");
}

void add_task(void) {
    printf("Adicionando tarefa...\n");
}

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