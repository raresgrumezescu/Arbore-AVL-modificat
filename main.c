#include "Sequence.h"
int main()
{
    Sequence tree = init();
    tree = insert(tree, 13, 0);
    tree = insert(tree, 5, 1);
    tree = insert(tree, 11, 2);
    tree = insert(tree, 8, 3);
    tree = insert(tree, 23, 4);
    tree = insert(tree, 17, 5);
    tree = insert(tree, 64, 6);

    Sequence tree2 = init();
    tree2 = insert(tree2, 1212, 0);
    tree2 = insert(tree2, 25, 1);
    tree2 = insert(tree2, 110, 2);
    tree2 = insert(tree2, 38, 3);
    tree2 = insert(tree2, 43, 4);
    tree2 = insert(tree2, 7, 5);
    tree2 = insert(tree2, 10, 6);
    /*
    tree = insert (tree, 14, 7);
    tree = insert (tree, 25, 8);
    tree = insert (tree, 110, 9);
    tree = insert (tree, 38, 10);
    tree = insert (tree, 43, 11);
    tree = insert (tree, 7, 12);
    tree = insert (tree, 10, 13);*/
    //printf ("(%d %d)\n", tree->key, tree->index);
    inOrder(tree);
    printf("\n");
    tree = delete (tree, 0);
    //printf ("%d\n", lookup(tree, 3));
    tree = set(tree, 65, 3);
    inOrder(tree);
    printf("\n");

    Sequence tree3 = concat (tree, tree2);
    inOrder(tree3);
    printf("%d\n", lookup(tree, 3));
    printf("%d\n", size(tree));

    return 0;
}