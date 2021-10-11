#include<stdio.h>
#include<stdlib.h>
typedef int Type;
typedef struct sequence {
    int value; //valoarea din nod
    int height; //inaltimea la care se afla nodul
    int index; //pozitia pe care se afla nudul in structura
    struct sequence *left; //pointer la stanga
    struct sequence *right; //pointer la dreapta
} *Sequence;

Sequence init();

Sequence insert(Sequence data_structure, Type item, int index);

Sequence delete(Sequence data_structure, int index);

Type lookup(Sequence data_structure, int index);

Sequence set(Sequence data_structure, Type item, int index);

int size(Sequence data_structure);

Sequence* split(Sequence data_structure, int index);

Sequence concat(Sequence data_structure1, Sequence data_structure2);

void inOrder(Sequence root);