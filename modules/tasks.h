#ifndef TASKS_H
#define TASKS_H

/* ===== COMANDOS DE TAREFA ===== */
void view_tasks(void);
void add_task(char nome[32]);
void remove_task(void);
void complete_task(void);
void edit_task(void);

/* ===== AJUDA ===== */
void show_help(void);

#endif