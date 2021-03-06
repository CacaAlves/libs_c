#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack_int.h"

StackInt *new_node_stack_int(int data)
{
    StackInt *node = (StackInt *)malloc(sizeof(StackInt));
    node->data = data;
    node->next = NULL;

    return node;
}

void push_stack_int(StackInt **stack, int data)
{
    if (stack == NULL)
        return;

    StackInt *node = new_node_stack_int(data);

    if ((*stack) == NULL)
    {
        (*stack) = node;
    }
    else
    {
        StackInt *aux = (*stack);
        (*stack) = node;
        node->next = aux;
    }
}

int top_stack_int(StackInt *stack)
{
    if (stack == NULL)
    {
        printf("Can't return top! Stack is empty.\n");
    } 
    else 
    {
        return stack->data;
    }
}

void pop_stack_int(StackInt **stack)
{
    if (stack == NULL || (*stack) == NULL)
    {
        printf("Can't pop! Empty stack.\n");
        return;
    }

    StackInt *aux = (*stack);
    (*stack) = (*stack)->next;
    free(aux);
    aux = NULL;
}

bool is_empty_stack_int(StackInt *stack)
{
    return (stack == NULL);
}

void print_stack_int(StackInt **stack)
{
    if (stack == NULL || (*stack) == NULL)
    {
        printf("Can't print! Empty stack.\n");
        return;
    }

    while ((*stack) != NULL)
    {
        printf("%d ", top_stack_int(*stack));
        pop_stack_int(stack);
    }
    printf("\n");
}