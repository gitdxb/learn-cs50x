#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *left;
    struct node *right;
} node;

// *tree is pointer to the root
bool search(node *tree)
{
    // Base case for recursion
    if (tree == NULL)
    {
        return false;
    }

    else if (50 < tree->number)
    {
        return search(tree->left);
    }
    else if (50 > tree->number)
    {
        return search(tree->right);
    }
    else
    {
        return true;
    }
}
