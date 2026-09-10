#include <stdio.h>
#include <string.h>
#include "modules/tasks.h"
#include "modules/auxiliary.h"


/* ===== MAIN ===== */
int main(int argc, char *argv[]) {
    carregar_tarefas();
    
    if (argc < 2) {
        show_help();
        return 0;
    }
    
    /* usa strcmp para comparação de strings
    strcmp, ou string compare, retorna 0
    caso as duas strings na função sejam iguais. */
    if (strcmp(argv[1], "view-tasks") == 0) {
        view_tasks();
    } 
    else if (strcmp(argv[1], "add-task") == 0) {
        add_task();
    } 
    else if (strcmp(argv[1], "remove-task") == 0) {
        remove_task();
    } 
    else if (strcmp(argv[1], "complete-task") == 0) {
        complete_task();
    } 
    else if (strcmp(argv[1], "edit-task") == 0) {
        edit_task();
    } 
    else if (strcmp(argv[1], "help") == 0 || strcmp(argv[1], "--help") == 0) {
        show_help();
    } else {
        printf("Comando desconhecido: %s\n", argv[1]);
        printf("Use 'todo help' para ajuda.\n");
    }
    
    return 0;
}