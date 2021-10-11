#include "Sequence.h"
int inaltime(Sequence sec)
{
    if (sec == NULL)
        return 0;
    return sec->height;
}
// functie ce imi calculeaza maximul dintre 2 numere intregi
int max(int a, int b)
{
    if (a > b) return a;
    return b;
}
// functie ce creeaza un nou element al structurii, pe baza datelor primite ca parametru
Sequence newElem(int value, int index)
{
    Sequence node = malloc(sizeof(struct sequence));
    node->value = value;
    node->index = index;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}
// urmatoarele 2 functii de rotatie sun asemenatoare
// singurele diferente dintre ele fiind reprezentate
// de cum se schimba relatiile de mostenire intre
// nodurile partinti si cele fii

// functie ce efectueaza o rotatie la dreapta
Sequence Dreapta(Sequence root)
{
    // left este copilul din stanga
    // p este "nepotul" lui root si copilul din dreapta
    // al lui left
    Sequence left = root->left, p = left->right;
    // se inverseaza rolurile copil-parinte
    left->right = root;
    // root va deveni nodul parinte pentru nepotul p
    root->left = p;
    // se reactualizeaza inaltimile lui root si left
    root->height = max(inaltime(root->left), inaltime(root->right));
    left->height = max(inaltime(left->left), inaltime(left->right));
    root->height++;
    left->height++;
    // se returneaza noua radacina
    return left;
}
// functie ce efectueaza o rotatie la stanga
Sequence Stanga(Sequence root)
{
    // right este copilul din dreapta
    // p este "nepotul" lui root si copilul din stanga
    // al lui right
    Sequence right = root->right, p = right->left;
    // se inverseaza rolurile copil-parinte
    right->left = root;
    // root va deveni nodul parinte pentru nepotul p
    root->right = p;
    // se reactualizeaza inaltimile lui root si right
    root->height = max(inaltime(root->left), inaltime(root->right));
    right->height = max(inaltime(right->left), inaltime(right->right));
    root->height++;
    right->height++;
    // se returneaza noua radacina
    return right;
}
// functie ce verifica daca un arbore primit ca parametru
// este echilibrat sau nu; returneaza valori de 0,1,-1
// in caz afirmativ, si alte valori in caz negativ
int echilibru(Sequence sec)
{
    if (sec == NULL)
        return 0;
    return inaltime(sec->left) - inaltime(sec->right);
}
// functie folosita da functia "delete",
// ce are rolul de a echilibra (balansa),
// un arore ca acesta sa devina avl
void Balance (int ok, Sequence *root) {
    int balance = echilibru((*root));
    // se trateaza cele patru cazuri:
    // - Left Left
    // - Left Right
    // - Right Right
    // - Right Left
    // acestea sunt 4 cazuri ce au nevoie de una sau
    // doua rotatii pentru ca arborele primit ca parametru
    // sa devina avl

    // Cazul Left-Left
    if (balance > 1 && echilibru((*root)->left) >= 0)
        return Dreapta((*root));

    // Cazul Left-Right
    if (balance > 1 && echilibru((*root)->left) < 0) {
        (*root)->left =  Stanga((*root)->left);
        return Dreapta((*root));
    }

    // Cazul Right-Right
    if (balance < -1 && echilibru((*root)->right) <= 0)
        return Stanga((*root));

    // Cazul Right-Right
    if (balance < -1 && echilibru((*root)->right) > 0) {
        (*root)->right = Dreapta((*root)->right);
        return Stanga((*root));
    }
}
// functie pe care am folosit-o penru a afisa arborii
// am facut-o pentru verificare
void inOrder(Sequence root)
{
    if(root != NULL)
    {
        inOrder(root->left);
        printf("(%d %d) ", root->value, root->index);
        inOrder(root->right);
    }
}
// functie folosita de functia "concat"
// sa stocheze valorile din data_structure2
// intr-un vector
void in(Sequence root, int *v, int *poz)
{
    if(root != NULL)
    {
        //v[(*poz)++] = root->key;
        in(root->left, v, poz);
        v[(*poz)++] = root->value;
        //printf("(%d %d) ", root->key, root->index);
        in(root->right, v, poz);
    }
}
// functie ce obtine nodul cu urmatorul index
// ca valoare dintr-o structura
// functia este folosite de "delete"
Sequence nextIndex(Sequence node)
{
    Sequence current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}


//-----------------------------------------------------------------------------------------------------------------
//In continuare sunt functiile cerute in enunt

//Returneaza structura vida
Sequence init() {
    Sequence structure = NULL;
    return structure;
}

//Insereaza un element in structura pe pozitia index
Sequence insert (Sequence data_structure, Type item, int index) {
    // functia este recursiva
    // am pornit de la implementarea clasica a unei insertii
    // intr-un BST simplu, care nu respecta proprietatile unui avl.
    // am adaptat aceasta functie conform cerintei

    // cauta recursiv in arbore locul potrivit pentru
    // elementul ce ar trbui plasat pe pozitia index.

    // cazul in care structura primita ca parametru este nula
    if (data_structure == NULL)
        return newElem(item, index);
    // se cauta loc in subarborele stang
    if (index < data_structure->index)
        data_structure->left  = insert(data_structure->left, item, index);
    // se cauta loc in subarborele drept
    else if (index > data_structure->index)
        data_structure->right = insert(data_structure->right, item, index);
    // cazul in care pe pozitia index exista deva ceva;
    // in cazul acesta, nu se va insera nimic la index,
    // pentru ca exista ceva ce va fi returnat.
    else
        return data_structure;

    // se actualizeaza valoarea inaltimii lui data_structure
    data_structure->height = 1 + max(inaltime(data_structure->left), inaltime(data_structure->right));

    // se verifica daca dupa insertie se pastreaza proprietatea de avl
    // se ia un indice de balansare
    int balance = echilibru(data_structure);
    // se verifica numai cazul Right-Right, deoarece
    // am inteles ca se va considera ca indicii se vor succeda in ordine
    // crescatoare, adica 0, 1, 2, 3, ...
    // motiv pentru care daca arborele se va dezechilibra,
    // va fi din cauza modului in care este organizat
    // subarborele drept
    if (balance < -1 && index > data_structure->right->index)
        return Stanga(data_structure);
    // se returneaza structura nou-obtinuta
    // prin insertia elementului
    return data_structure;
}

//Sterge elementul de pe pozitia index din structura
Sequence delete (Sequence data_structure, int index) {

    // am pornit de la stergerea traditionala dintr-un BST
    // normal, pe care am adaptat-o cerintei
    int ind = index;

    // daca data_structure este NULL
    if (data_structure == NULL)
        return data_structure;
    // se cauta elementul ce vrem sa fie sters in
    // subarborele stang
    if (index < data_structure->index)
        data_structure->left = delete (data_structure->left, index);
    // se cauta elementul ce vrem sa fie sters in
    // subarborele drept
    else if(index > data_structure->index)
        data_structure->right = delete (data_structure->right, index);
    // s-a gasit pozitia pe care o cautam
    // pentru a sterge elementul din ea
    else
    {
        // cazul in care nodul are numai un fiu
        // pe rand tratata situatia in care fiul este
        // in stanga, si apoi in dreapta

        // situatia "doar fiu stanga"
        if (data_structure->left != NULL && data_structure->right == NULL) {
            Sequence p = data_structure->left;
            *data_structure = *p;
            free (p);
        }
        // situatia "doar fiu dreapta"
        if (data_structure->left == NULL && data_structure->right != NULL) {
            Sequence p = data_structure->right;
            *data_structure = *p;
            free (p);
        }

        // situatie "Nodul este frunza"
        if (data_structure->left == NULL && data_structure->right == NULL) {
            free (data_structure);
            return NULL;
        }

        // situatia "nodul are 2 fii"
        if (data_structure->left != NULL && data_structure->right != NULL) {
            //Se cauta nodul cu indexul urmator
            // prin apelul functiei "nextIndex"
            Sequence p = nextIndex (data_structure->right);
            // nodul curent primeste valoarea si indexul
            // nodului gasit
            data_structure->value = p->value;
            data_structure->index = p->index;
            // se sterge recursiv nodul gasit din subarborele
            // din care provine, adica cel drept
            data_structure->right = delete (data_structure->right, p->index);
        }
    }
    if (data_structure == NULL)
        return data_structure;
    //se actaulizeaza inaltimea lui data_structure
    data_structure->height = 1 + max(inaltime(data_structure->left), inaltime(data_structure->right));
    // se apeleaza functia "Balance" pentru a echilibra arborele
    // obtinut prin stergerea nodului;
    // astfel, arborele va indeplini conditiile de avl
    Balance (1, &data_structure);
    return data_structure;
}
//Returneaza valoarea elementului de pe pozitia index
// functia parcurge structura si cauta unde este pozitia index
Type lookup (Sequence data_structure, int index) {
    // se va executa doar daca nodul este diferit de NULL
    if (data_structure != NULL) {
        // daca indexul este cel cautat, atunci se returneaza valoarea
        if (data_structure->index == index)
            return data_structure->value;
        // altfel daca indexul nodului curent este mai mare ca
        // al celui cautat, deplasare in subarborele stang
        else if (data_structure->index > index)
            // altfel daca indexul nodului curent este mai mic ca
            // al celui cautat, deplasare in subarborele drept
            return lookup (data_structure->left, index);
            else
                return lookup (data_structure->right, index);
    }
}

//Inlocuiestea valoarea elementului de pe pozitia index
// functie asemenatoare cu lookup, insa aceasta schimba valoarea de
// la index, nu o returneaza
Sequence set (Sequence data_structure, Type item, int index) {
    if (data_structure != NULL) {
        // daca indexul este cel cautat, atunci schimba valoarea de la el
        if (data_structure->index == index) {
            data_structure->value = item;
            return data_structure;
        }
        // altfel cauta in subarborele stang dupa el
        else if (data_structure->index > index) {
            data_structure->left = set (data_structure->left, item, index);
            return data_structure;
        }
            // altfel cauta in cel drept
            else {
                data_structure->right = set (data_structure->right, item, index);
                return data_structure;
            }
    }
}

//Returneaza dimensiunea structurii
// daca am considerat ca indicii sunt in ordine inserati,
// inseamna ca in arborele format, in
// subarborele stang al unui nod vor fi
// elemente cu indecsi mai mici ca el, si in cel drept
// cu indexi mai mari.
// Deci, daca facem o deplasare in cel mai din dreapta nod, cautam
// cat ii este indexul, si apoi valoarea acelui index o adunam cu 1,
//retulatul va fi chia dimensiunea structurii
// adica numarul de elemente din ea
int size (Sequence data_structure) {
    // deplasare cat mai in dreapta
    if (data_structure != NULL) {
        if (data_structure->right == NULL)
            return 1 + data_structure->index;
        // returneaza dimensiunea
        else return size (data_structure->right);
    }
    // daca data_structure este NULL, inseamna ca are dimensiunea
    // egala cu 0
    return 0;
}

//Returneaza cele doua structuri rezultate in urma divizarii
//(rezultatul este retinut \EEntr-un Sequence* cu 2 elemente)

// aceasta functie nu am reusit sa o termin
Sequence* split (Sequence data_structure, int index);

//Returneaza structura rezultata dupa concatenare
Sequence concat (Sequence data_structure1, Sequence data_structure2) {
    // consideram o noua structura, numita "sec"
    Sequence sec = malloc (sizeof (struct sequence));
    // initial sec este data_structure1
    sec = data_structure1;
    int size1 = size(data_structure1);
    int size2 = size(data_structure2);
    // stocam in v toate elementele lui data_structure2
    int *v = malloc (size2 * sizeof (int));
    int pos = 0;
    // elementele le obtinem prin apelul functiei "in"
    in (data_structure2, v, &pos);
    // pentru toate elementele din vector,
    // inseram la pozitia size1 + i elementul v[i];
    for (int i = 0; i < pos; i++) {
        int k = size1 + i;
        //printf ("%d\n", k);
        insert (sec, v[i], k);
    }
    // returnam noua structura
    return sec;
}