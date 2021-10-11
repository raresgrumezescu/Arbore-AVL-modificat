# Arbore-AVL-modificat
 Implementati o structură de date care permită realizarea unui număr mare de operatii cu o complexitate cât mai bună (putetti considera drept referint,a O(log n))


m considerat ca structura de date un Arbore AVL, pe care l-am 
modificat, astfel incat fiecare element din el sa aiba
si un indice dupa care sa fie identificat. Am ales sa pornesc de la un 
Arbore AVL, deoarece in cazul operatiior de cautare,
stergere si inserare, complexitatea in cazul cel mai defovorabil este 
egala cu O(log n).
Pentru elaborarea functiilor cerute in enunt, m-am folosit de o 
serie de functii ajutatoare, care nu se cereau neaparat a fi
implementate, insa de care m-am folosit pentru a implementa functiile 
cerute. Aceste functii sunt: inaltime(Sequence sec),
max(int a, int b), newElem(int value, int index), Dreapta(Sequence root), 
Stanga(Sequence root), echilibru(Sequence sec),
Balance (int ok, Sequence *root), inOrder(Sequence root), in(Sequence 
root, int *v, int *poz), respectiv nextIndex(Sequence node).
Despre acestea vorbesc mai in amanunt in comentariile pe care le-am atasat 
la codul pe care l-am scris.
Cu ajutorul comentariilor de care imi insotesc codul, am vorbit mai 
in amanunt depre fiecare dintre functiile cerute,
motiv pentru care in acest README vorbesc si despre complexitatile 
fiecarei functii in parte.
Complexitatile pentru functiile cerute mi-au dat:
- init(): O(1);
- insert: O(log n); O (log n) este complexitatea inserarii 
traditionale intr-un BST; cu toate ca in interiorul functiei
insert trebuie sa executam si o serie de operatii pentru a echilibra 
arborele nou obtinut, aceste operatii nu reperzinta decat
niste verificari si niste schimbari de pointeri ce se realizeaza toate 
intr-un timp constant, ceea ce duce la complexitate
O (timp_constant) din partea lor. Asa ca complexitatea functiei insert va 
fi egala cu O(log n) + O (constanta) = O (log n)
conform proprietatilor lui O.
- delete: O(log n); O (log n) este complexitatea stergerii 
traditionale intr-un BST; cu toate ca in interiorul functiei
delete trebuie sa executam si o serie de operatii pentru a echilibra 
arborele nou obtinut dupa stergere, aceste operatii nu reperzinta decat
niste verificari si niste schimbari de pointeri ce se realizeaza toate 
intr-un timp constant, ceea ce duce la complexitate
O (timp_constant) din partea lor. Asa ca complexitatea functiei delete va 
fi egala cu O(log n) + O (constanta) = O (log n),
conform proprietatilor lui O. Tin sa precizez ca nu am reusit sa fac 
actualzarea indicilor la aceasta functie, motiv pentru care
nu am luat-o in caonsiderare cand am calculat complexitatea
- lookup: O (log n); aceasta functie practic parcurge fiecare nivel 
din arbore, iar cum inaltimea intr-un AVL este
egala cu log n, unde n este numarul nodurilor, inseamna ca complexitatea 
acestei functii va fi O (log n)
- set: O (log n); aceasta functie practic parcurge fiecare nivel din 
arbore pentru a gasi pozitia cautata, iar cum
inaltimea intr-un AVL este egala cu log n, unde n este numarul nodurilor, 
inseamna ca complexitatea acestei functii va fi O (log n)
- size: O (log n); cautand mereu nodul din dreapta, parcurge pe 
nivel inaltimea intr-un avl, deci cand ajunge la nodul
cel mai din dreapta, atunci cautarea s-a incheiat. Ca atare, complexitatea 
va fi egala cu inaltimea arborelui, deci O (log n)
- split: nu am reusit sa o termin, si din aceasta cauza nu o pot 
prezenta
- concat: O (n log m); n este numarul de noduri ai lui 
data_structure2 si dimensiunea vectorului pe care il obtin. m este numarul
elementelor din data_structure1. Facand insert pentru fiecare element din 
data_structure2, atunci apelez functia insert de
complexitate O(log m) de n ori. Impreuna cu O(n), adica complexiatea 
rezultata cand parcurg arborele 2 pentru a obtine vectorul
de elemente, atunci complexitatea va fi O (n + nlog m), adica O(nlog m).
