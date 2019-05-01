typedef struct ed
{
    char letter;
    struct ed *next;
    struct ed *last;
}editor;
struct existenta
{
    editor *capat_lista_originala;
    editor *capat_parte_copiata;
    editor *capat_parte_inserata;
    int atribuit;
}capete;



FILE *text_location;
FILE *operatii;
FILE *scriere;

/*

Coada ce contine tot textul

*/
editor* alocare_memorie(editor *p);
/*

Muta cursorul cu n pozitii fata de pozitia curenta

*/
editor* editor_move(editor *poz_curenta, int n);
/*

Insereaza un sir de caractere string in lista

*/
void editor_insert(editor *poz_curenta);
/*

Sterge n elemente din lista de la pozitia curenta

*/
editor* editor_delete(editor *poz_curenta, int n);
/*

Copiaza n elemente

*/

void editor_copy(editor *curent, int n);

/*

Insereaza textul copiat

*/
void editor_paste(editor *poz_curenta, char del);
/*

Anuleaza ultima actiune

*/
editor* editor_undo(char* ultima_command, editor* poz_curenta);
/*

Anuleaza ultimul undo

*/
char* redo();
/*

Sterge elementul anterior

*/
editor* editor_backspace(editor* poz_curenta);
/*

Inlocuieste cuvant cu cuvant_nou

*/
char* replacer(char *cuvant, char *cuvant_nou);

/*

Some programs that do magical sheet
DO NOT TOUCH THEM!

*/
void afisare(editor *capat);
editor* rulare_program(char *comanda, char *last_command, editor *poz_curenta);
void eliberare(editor *capat);

