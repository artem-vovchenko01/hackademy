#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct  node 
{
  char          *key;
  void          *data;
  struct node   *left;
  struct node   *right;
}               node_t;

node_t  *allocnode()
{
    node_t *node = (node_t *) malloc(sizeof(node_t));
    node -> left = NULL;
    node -> right = NULL;
    node -> key = NULL;
    node -> data = NULL;
    return node;
}

node_t  *insert(node_t *root, char *key, void *data)
{
    if (root == NULL)
    {
        node_t *new_node;
        new_node = allocnode();
        new_node -> key = key;
        new_node -> data = data;
        return new_node;
    }
    int cmp = strcmp(key, root -> key);
    if (cmp > 0)
    {
        root -> right = insert(root -> right, key, data);
    } else if (cmp < 0)
    {
        root -> left = insert(root -> left, key, data);
    }
    return root;
}

void    print_node(node_t *node)
{
    if (node != NULL)
    {
        printf("%s\n", node -> key);
        printf("%s\n", (char *) node -> data);
    }
}

void    visit_tree(node_t *node, void (*fp)(node_t *root))
{
    if (node != NULL)
    {
        visit_tree(node -> left, fp);
        fp(node);
        visit_tree(node -> right, fp);
    }
}

void    destroy_tree(node_t *node, void (*fdestroy)(node_t *root))
{
    if (node != NULL)
    {
        destroy_tree(node -> left, fdestroy);
        fdestroy(node);
        destroy_tree(node -> right, fdestroy);
    }
}

