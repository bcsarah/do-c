#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARQUIVO "todo.txt"
#define MAX_TAREFAS 100
#define MAX_NOME 100

typedef struct {
    char nome[MAX_NOME];
    int concluida;  // 0 = pendente, 1 = concluída
} Tarefa;

Tarefa lista[MAX_TAREFAS];
int total_tarefas = 0;

// ===== FUNÇÕES DE PERSISTÊNCIA =====

void carregarTarefas() {
    FILE *arquivo = fopen(ARQUIVO, "r");
    if (arquivo == NULL) return;
    
    total_tarefas = 0;
    
    while (fgets(lista[total_tarefas].nome, MAX_NOME, arquivo) != NULL && total_tarefas < MAX_TAREFAS) {
        // Remove o \n do final
        lista[total_tarefas].nome[strcspn(lista[total_tarefas].nome, "\n")] = '\0';
        
        // Lê o status (0 ou 1) da próxima linha
        fscanf(arquivo, "%d\n", &lista[total_tarefas].concluida);
        total_tarefas++;
    }
    
    fclose(arquivo);
}

void salvarTarefas() {
    FILE *arquivo = fopen(ARQUIVO, "w");
    if (arquivo == NULL) {
        printf("❌ Erro ao salvar!\n");
        return;
    }
    
    for (int i = 0; i < total_tarefas; i++) {
        fprintf(arquivo, "%s\n", lista[i].nome);
        fprintf(arquivo, "%d\n", lista[i].concluida);
    }
    
    fclose(arquivo);
}

// ===== COMANDOS =====

void view_tasks() {
    if (total_tarefas == 0) {
        printf("\n📭 Nenhuma tarefa cadastrada.\n");
        return;
    }
    
    printf("\n📋 LISTA DE TAREFAS\n");
    printf("┌────┬──────────┬────────────────────────────┐\n");
    printf("│ Nº │ Status   │ Tarefa                     │\n");
    printf("├────┼──────────┼────────────────────────────┤\n");
    
    for (int i = 0; i < total_tarefas; i++) {
        char *status = lista[i].concluida ? "✅" : "⬜";
        printf("│ %2d │   %s     │ %-26s │\n", 
               i + 1, status, lista[i].nome);
    }
    printf("└────┴──────────┴────────────────────────────┘\n");
    printf("Total: %d tarefas\n", total_tarefas);
}

void add_task(int argc, char *argv[]) {
    if (argc < 3) {
        printf("❌ Uso: ./todo add-task \"Nome da tarefa\"\n");
        return;
    }
    
    if (total_tarefas >= MAX_TAREFAS) {
        printf("❌ Lista cheia!\n");
        return;
    }
    
    strcpy(lista[total_tarefas].nome, argv[2]);
    lista[total_tarefas].concluida = 0;
    total_tarefas++;
    
    salvarTarefas();
    printf("✅ Tarefa adicionada: \"%s\"\n", argv[2]);
}

void remove_task(int argc, char *argv[]) {
    if (argc < 3) {
        printf("❌ Uso: ./todo remove-task <número>\n");
        return;
    }
    
    int pos = atoi(argv[2]) - 1;  // Converte para índice (começa em 0)
    
    if (pos < 0 || pos >= total_tarefas) {
        printf("❌ Número inválido!\n");
        return;
    }
    
    // Remove deslocando os elementos
    for (int i = pos; i < total_tarefas - 1; i++) {
        strcpy(lista[i].nome, lista[i + 1].nome);
        lista[i].concluida = lista[i + 1].concluida;
    }
    total_tarefas--;
    
    salvarTarefas();
    printf("🗑️ Tarefa removida!\n");
}

void complete_task(int argc, char *argv[]) {
    if (argc < 3) {
        printf("❌ Uso: ./todo complete-task <número>\n");
        return;
    }
    
    int pos = atoi(argv[2]) - 1;
    
    if (pos < 0 || pos >= total_tarefas) {
        printf("❌ Número inválido!\n");
        return;
    }
    
    lista[pos].concluida = !lista[pos].concluida;
    salvarTarefas();
    
    printf("✅ Tarefa \"%s\" %s!\n", 
           lista[pos].nome, 
           lista[pos].concluida ? "concluída" : "reaberta");
}

void edit_task(int argc, char *argv[]) {
    if (argc < 4) {
        printf("❌ Uso: ./todo edit-task <número> \"Novo nome\"\n");
        return;
    }
    
    int pos = atoi(argv[2]) - 1;
    
    if (pos < 0 || pos >= total_tarefas) {
        printf("❌ Número inválido!\n");
        return;
    }
    
    strcpy(lista[pos].nome, argv[3]);
    salvarTarefas();
    
    printf("✏️ Tarefa atualizada para: \"%s\"\n", argv[3]);
}

// ===== AJUDA =====

void show_help() {
    printf("\n📋 SISTEMA DE TAREFAS - COMANDOS\n");
    printf("═══════════════════════════════════════\n");
    printf("  ./todo view-tasks           - Listar tarefas\n");
    printf("  ./todo add-task \"Tarefa\"    - Adicionar tarefa\n");
    printf("  ./todo complete-task <N>    - Marcar como concluída\n");
    printf("  ./todo remove-task <N>      - Remover tarefa\n");
    printf("  ./todo edit-task <N> \"Novo\" - Editar tarefa\n");
    printf("  ./todo help                 - Mostrar ajuda\n");
    printf("═══════════════════════════════════════\n");
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
    }
    else {
        printf("❌ Comando desconhecido: %s\n", argv[1]);
        printf("Use './todo help' para ajuda.\n");
    }
    
    return 0;
}