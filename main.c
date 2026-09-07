#include <stdio.h>

// ===== FUNÇÕES DE PERSISTÊNCIA =====
void carregarTarefas() {

}

void salvarTarefas() {

}


// ===== COMANDOS =====
void view_tasks() {

}

void add_task(int argc, char *argv[]) {

}

void remove_task(int argc, char *argv[]) {

}

void complete_task(int argc, char *argv[]) {

}

void edit_task(int argc, char *argv[]) {

}

// ===== AJUDA =====
void show_help() {

}

// ===== MAIN =====
int main(int argc, char *argv[]) {
    carregarTarefas();
    
    if (argc < 2) {
        show_help();
        return 0;
    }
    
    if (strcmp(argv[1], "view-tasks") == 0) {
        view_tasks();
    } 
    else if (strcmp(argv[1], "add-task") == 0) {
        add_task(argc, argv);
    } 
    else if (strcmp(argv[1], "remove-task") == 0) {
        remove_task(argc, argv);
    } 
    else if (strcmp(argv[1], "complete-task") == 0) {
        complete_task(argc, argv);
    } 
    else if (strcmp(argv[1], "edit-task") == 0) {
        edit_task(argc, argv);
    } 
    else if (strcmp(argv[1], "help") == 0 || strcmp(argv[1], "--help") == 0) {
        show_help();
    } else {
        printf("Comando desconhecido: %s\n", argv[1]);
        printf("Use 'todo help' para ajuda.\n");
    }
    
    return 0;
}