#ifndef MONTY_H
#define MONTY_H
#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK 0
#define QUEUE 1
#define DELIM " \t"

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_s - a global struct to hold info regarding the entire project
 * @head: head of the stack
 * @tail: tail of the stack
 * @mode: mode of the data LIFO or FIFO
 * @quit: variable for exit
 * @arg: argument if any
 */
typedef struct global_s
{
	stack_t *head;
	stack_t *tail;
	int mode;
	int quit;
	char *arg;
} global_t;

/* ========== Globals =========== */
extern global_t global;

/* =========== Handlers ============ */
void push_handler(stack_t **, unsigned int);
void pall_handler(stack_t **, unsigned int);
void pop_handler(stack_t **, unsigned int);
void swap_handler(stack_t **, unsigned int);
void add_handler(stack_t **, unsigned int);
void nop_handler(stack_t **, unsigned int);
void sub_handler(stack_t **, unsigned int);
void mul_handler(stack_t **, unsigned int);
void div_handler(stack_t **, unsigned int);
void mod_handler(stack_t **, unsigned int);
void pint_handler(stack_t **, unsigned int);
void rotl_handler(stack_t **, unsigned int);
void pstr_handler(stack_t **, unsigned int);
void pchr_handler(stack_t **, unsigned int);
void rotr_handler(stack_t **, unsigned int);
instruction_t _get_handler(const char *);

/* =========== Stack Ops =========== */
void push(int);
int pop(void);
void print_stack(void);

/* =========== Queue Ops =========== */
int dequeue(void);
void print_queue(void);
void enqueue(int);

/* =========== custome Ops =========== */
void swap(void);
void calculator(char, char *,  int);

/* ========== File handlers ========= */
char *read_file(const char *);

/* ========== Parse functions ========= */
void parse_instructions(char **);
int simple_opcodes(char **);

/* ========== Helpers ========== */
int is_delim(char, char *);
char **strtow(char *, char *);
int _isdigit(int);
int is_number(char *);
int arrlen(char **);
void truncate_on_empty_line(char *);

/* ========== Memory functions ========== */
void clear_memory(void);
void free_tokenized(char **);

#endif /* MONTY_H */
