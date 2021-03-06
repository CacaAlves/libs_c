#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue_double.h"

QueueDouble *new_node_queue_double(double data)
{
    QueueDouble *node = (QueueDouble *)malloc(sizeof(QueueDouble));
    node->data = data;
    node->next = NULL;

    return node;
}

void enqueue_queue_double(QueueDouble **queue, double data)
{
    if ((queue) == NULL)
        return;

    QueueDouble *node = new_node_queue_double(data);

    if ((*queue) == NULL)
    {
        (*queue) = (QueueDouble *)malloc(sizeof(QueueDouble));

        (*queue) = node;
        (*queue)->next = node;
    }
    else
    {
        QueueDouble *last = (*queue);
        node->next = last->next;
        last->next = node;
        (*queue) = node;
    }
}

void dequeue_queue_double(QueueDouble **queue)
{
    if ((queue) == NULL || (*queue) == NULL)
    {
        printf("Can't dequeue! Queue is empty.\n");
        return;
    }

    if ((*queue)->next == (*queue))
    {
        free((*queue));
        (*queue) = NULL;
    }
    else
    {
        QueueDouble *first = (*queue)->next;
        (*queue)->next = first->next;
        free(first);
        first = NULL;
    }
}

double peek_queue_double(QueueDouble *queue)
{
    if (queue == NULL)
    {
        printf("Can't peek queue! Queue is empty.\n");
    }
    else
    {
        return ((queue->next)->data);
    }
}

bool is_empty_queue_double(QueueDouble *queue)
{
    return (queue == NULL);
}

void print_queue_double(QueueDouble **queue)
{
    if (queue == NULL || (*queue) == NULL) 
    {
        printf("Can't print queue! Queue is empty.\n");
        return;
    }

    QueueDouble *aux = (*queue)->next;
    while (aux != (*queue))
    {
        printf("%f ", peek_queue_double(*queue));
        aux = aux->next;
        dequeue_queue_double(queue);
    }
    printf("%f\n", peek_queue_double((*queue)));
    dequeue_queue_double(queue);
}