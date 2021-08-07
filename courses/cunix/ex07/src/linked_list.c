#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	void *data;
    struct node *next;
} node_t;

node_t *list_create(void *data)
{
    node_t *head = (node_t *) malloc(sizeof(node_t));
    if (head == NULL)
    {
        // error
    }
    head -> data = &data;
    head -> next = NULL;
    return head;
}


void list_destroy(node_t **head, void (*fp)(void *data))
{
    node_t *prev = *head;
    node_t *next;
    if ((next = prev -> next) == NULL)
    {
        // error
    }
    while (next -> next != NULL)
    {
        (*fp)(prev -> data);
        free(prev++);
        next = next -> next;
    }
    free(next);
}

void list_push(node_t *head, void *data)
{
    node_t *nd = head;
    while (nd -> next != NULL)
        nd++;
    nd -> next = (node_t*) malloc(sizeof(node_t));
    nd -> next -> data = &data;
    nd -> next -> next = NULL;
}

void list_unshift(node_t **head, void *data)
{
    node_t *new = (node_t *) malloc(sizeof(node_t));
    new -> next = *head;
    new -> data = data;
    (*head) = new;
}


void *list_pop(node_t **head)
{
    node_t *hd = *head;
    node_t *prev = hd;
    if (hd -> next == NULL)
    {
    // error
    }

    while ((++hd) -> next != NULL)
        prev++;
    
    void *res = prev -> next -> data;
    prev -> next = NULL;
    return res;
}

void *list_shift(node_t **head)
{
    if ((*head) -> next == NULL)
    {
        // error
    }
    void *res = (*head) -> data;
    (*head)++;
    return res;
}

void *list_remove(node_t **head, int pos)
{
    if (pos == 0)
        list_shift(head);
    node_t *prev = *head;
    node_t *nd;
    if ((nd = prev -> next) == NULL)
    {
        // error
    }
    int cur = 1;
    while (cur != pos)
    {
        if (nd == NULL) 
        {
            // error
        }
        nd = nd -> next;
        prev = prev -> next;
        cur++;
    }
    prev -> next = nd -> next;
    void *res = nd -> next -> data;
    nd -> next = NULL;
    return res;
}


void list_print(node_t *head)
{
    node_t *nd = head;
    while (nd != NULL)
    {
        printf(nd -> data);
        nd++;
    }
}

void list_visitor(node_t *head, void (*fp)(void *data))
{
    node_t *hd = head;
    while (hd != NULL)
    {
        (*fp)(hd -> data);
        hd++;
    }
}

