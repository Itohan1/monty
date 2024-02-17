#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

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
 * struct mine_s - different variable
 * @arg: variable parameter
 * @file: file pointer
 * @value: content value
 * Description: carry these values ih the program
 */

typedef struct mine_s
{
	char *arg;
	char *arg2;
	FILE *file;
	char *value;
	int LIFI;
} mine_t;
extern mine_t mine;

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

void fpush(stack_t **stack, unsigned int line_number);
void addn(stack_t **head, int n);
void addq(stack_t **head, int n);
void fpall(stack_t **head, unsigned int line_number);
void freestack(stack_t *head);
int execute(char *value, stack_t **stack, unsigned int count, FILE *file);
void fstack(stack_t **stack, unsigned int line_number);
char *token(char *argv, unsigned int Lcount);
#endif
