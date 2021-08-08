#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
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
    head -> data = data;
    head -> next = NULL;
    return head;
}


void list_destroy(node_t **head, void (*fp)(void *data))
{
    node_t *nd = *head;
    node_t *after;
    while (nd != NULL)
    {
        after = nd -> next;
        (*fp)(nd -> data);
        //free(prev++);
        nd = after;
    }
}

void list_push(node_t *head, void *data)
{
    node_t *nd = head;
    while (nd -> next != NULL)
    {
        nd = nd -> next;
    }
    nd -> next = (node_t *) malloc(sizeof(node_t));
    nd -> next -> data = data;
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
        void *res = hd -> data;
        *head = NULL;
        return res;
    }

    while ((hd = hd -> next) -> next != NULL)
    {
        prev = prev -> next;
    }
    
    void *res = prev -> next -> data;
    prev -> next = NULL;
    free(prev -> next);
    return res;
}

void *list_shift(node_t **head)
{
    void *res = (*head) -> data;
    node_t *to_del = *head;
    (*head) = (*head) -> next;
    free(to_del);
    return res;
}

void *list_remove(node_t **head, int pos)
{
    if (pos == 0)
    {
        list_shift(head);
    }
    node_t *prev = *head;
    node_t *nd;
    if ((nd = prev -> next) == NULL)
    {
        return NULL;
    }
    int cur = 1;
    while (cur != pos)
    {
        if (nd == NULL) 
        {
            return nd;
        }
        nd = nd -> next;
        prev = prev -> next;
        cur++;
    }
    prev -> next = nd -> next;
    void *res = nd -> data;
    free(nd);
    return res;
}


void list_print(node_t *head)
{
    node_t *nd = head;
    while (nd != NULL)
    {
        printf("%s\n", (char *) nd -> data);
        nd = nd -> next;
    }
}

void list_visitor(node_t *head, void (*fp)(void *data))
{
    node_t *hd = head;
    while (hd != NULL)
    {
        (*fp)(hd -> data);
        hd = hd -> next;
    }
}

