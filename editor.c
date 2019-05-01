#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Heather.h"

int main(void)//(int argc, char** argv)
{
    /*text_location = fopen(argv[1] , "r");
    operatii = fopen(argv[2],"r");
    scriere = fopen(argv[3], "w");
*/
    scriere = fopen("rezultat1.out", "w");
    operatii = fopen("operatii15.in", "r");
    text_location = fopen("date15.in", "r");

    capete.capat_parte_copiata = NULL;
    capete.capat_lista_originala = NULL;
    capete.capat_parte_inserata = NULL;


    if(text_location==NULL||operatii==NULL||scriere==NULL)
    {
        printf("Eroare la initializare.");
        exit(1);
    }

    /*

    Crearea cozii si punerea in aceasta a elementelor din text_location

    */
    editor *curent, *q;
    char comanda[20], last_comand[20];

    capete.capat_lista_originala=alocare_memorie(capete.capat_lista_originala);
    curent=capete.capat_lista_originala;
    curent -> letter = fgetc(text_location);
    while(feof(text_location)==0)
    {
        q = alocare_memorie(q);
        curent -> next = q;
        q -> last = curent;
        curent=q;
        curent -> letter = fgetc(text_location);
    }
    fclose(text_location);
    curent = capete.capat_lista_originala;
    /*

    Se va prelua comanda aferenta unui subprogram

    */
    int n;
    fscanf(operatii, "%d", &n);
    while(n--)
    {
        fscanf(operatii, "%s", comanda);
        curent = rulare_program(comanda, last_comand, curent);
        if(strcmp(comanda,"undo") && strcmp(comanda,"redo"))
            strcpy(last_comand, comanda);

    }
    afisare(capete.capat_lista_originala);
    eliberare(capete.capat_lista_originala);
    if(capete.capat_parte_copiata != NULL)
        eliberare(capete.capat_parte_copiata);
    if(capete.capat_parte_inserata != NULL)
        eliberare(capete.capat_parte_inserata);
    fclose(operatii);
    fclose(scriere);
}

editor* alocare_memorie(editor *curent)
{
    curent = (editor*)malloc(sizeof(editor));
    curent -> next = NULL;
    curent -> last = NULL;
    return curent;
}
void afisare(editor *capat)
{
    editor *curent = capat;
    while(curent->next != NULL)
    {
        fprintf(scriere,"%c",curent->letter);
        curent = curent->next;
    }
}
void eliberare(editor *capat)
{
    editor *q, *curent=capat;
    while(curent!=NULL)
    {
        q=curent->next;
        free(curent);
        curent=q;
    }
}
editor* rulare_program(char *comanda, char *last_command, editor *poz_curenta)
{
    int n;
    if(strcmp(comanda,"move")==0)
    {
        fscanf(operatii, "%d", &n);
        poz_curenta = editor_move(poz_curenta, n);

    }
    else if(strcmp(comanda,"insert")==0)
    {
        editor_insert(poz_curenta);

    }
    else if(strcmp(comanda,"del")==0)
    {
        fscanf(operatii, "%d", &n);
        poz_curenta = editor_delete(poz_curenta, n);

    }
    else if(strcmp(comanda,"copy")==0)
    {

        fscanf(operatii, "%d", &n);
        editor_copy(poz_curenta, n);
    }
    else if(strcmp(comanda,"paste")==0)
    {
        editor_paste(poz_curenta, 'p');

    }
    else if(strcmp(comanda,"undo")==0)
    {
        poz_curenta = editor_undo(last_command, poz_curenta);
    }
    else if(strcmp(comanda,"redo")==0)
    {


    }
    else if(strcmp(comanda,"backspace")==0)
    {
        poz_curenta = editor_backspace(poz_curenta);
    }
    else if(strcmp(comanda,"replacer")==0)
    {


    }

    else
    {
        printf("Eroare. Mai incercati o data.");
    }
    return poz_curenta;
}

editor* editor_move(editor *poz_curenta, int n)
{
    capete.atribuit = n;
    if(n>0)
        while(poz_curenta->next!=NULL){
                poz_curenta = poz_curenta->next;
                printf("%c\n", poz_curenta->letter);
                n--;
                if(n == 0) break;
        }
    else while(poz_curenta->last != NULL) {
            poz_curenta = poz_curenta->last;
            printf("%c\n", poz_curenta->letter);
            n++;
            if(n == 0) break;
    }
    return poz_curenta;
}
editor* editor_backspace(editor *poz_curenta)
{
    editor *de_sters, *inainte_de_sters;
    if(poz_curenta->last == NULL)
        return poz_curenta;
    else
    {
        de_sters=poz_curenta->last;
        if(de_sters->last == NULL)
        {
            poz_curenta->last = NULL;
            free(de_sters);
            return poz_curenta;
        }
        else
        {
            inainte_de_sters = de_sters->last;
            poz_curenta->last = inainte_de_sters;
            inainte_de_sters->next = poz_curenta;
            free(de_sters);
            return poz_curenta;
        }
    }
}
void editor_insert(editor* poz_curenta)
{
    char h;
    capete.atribuit=0;
    editor *help, *tmp;
    eliberare(capete.capat_parte_inserata);
    fscanf(operatii,"%c", &h);
    help = alocare_memorie(help);
    fscanf(operatii,"%c",&h);
    help ->letter = h;
    capete.atribuit++;
    capete.capat_parte_inserata = help;
    do
    {
        fscanf(operatii, "%c", &h);
        if(h == '\n' || feof(operatii))
            break;
        tmp = alocare_memorie(tmp);
        tmp->letter = h;
        help->next = tmp;
        tmp->last = help;
        help = tmp;
        capete.atribuit++;
    }while(feof(operatii) == 0);
    editor_paste(poz_curenta, 'i');
}
editor* editor_delete(editor *poz_curenta, int n)
{
    capete.atribuit = n;

    editor *urmator, *anterior;
    while(n-- && poz_curenta != NULL)
    {
        urmator = poz_curenta->next;
        if(poz_curenta->last != NULL)
                anterior = poz_curenta->last;
        else anterior = NULL;
        urmator->last = anterior;
        if(anterior != NULL)
            anterior->next = urmator;
        free(poz_curenta);
        poz_curenta = urmator;
    }
    if(poz_curenta->last == NULL)
        capete.capat_lista_originala = poz_curenta;
    return poz_curenta;
}
void editor_copy(editor *poz_curenta, int n)
{
    editor *temporar1, *temporar2;
    capete.atribuit = n;
    if(capete.capat_parte_copiata != NULL)
    {
        eliberare(capete.capat_parte_copiata);
        capete.capat_parte_copiata = NULL;
    }
    temporar2 = NULL;
    while(n--)
    {
        temporar1 = alocare_memorie(temporar1);
        temporar1->letter = poz_curenta->letter;
        if(temporar2 != NULL)
            {
                temporar1->last = temporar2;
                temporar2->next = temporar1;
            }
        temporar2 = temporar1;
        poz_curenta = poz_curenta->next;
        if(capete.capat_parte_copiata == NULL)
            capete.capat_parte_copiata = temporar1;
    }
}

void editor_paste(editor *poz_curenta, char del)
{
    editor *help_1, *help_2, *help_3;
    help_2 = NULL;
    help_3 = NULL;
    capete.atribuit=0;
    if(del == 'i')
        help_1 = capete.capat_parte_inserata;
    else help_1 = capete.capat_parte_copiata;
    while(help_1 != NULL)
    {
        help_2 = alocare_memorie(help_2);
        help_2->letter = help_1->letter;
        help_1 = help_1->next;
        help_2->next = poz_curenta;
        help_2->last = poz_curenta->last;
        if(poz_curenta->last != NULL) (poz_curenta->last)->next = help_2;
        if(help_3!= NULL) help_3->next = help_2;
        if(poz_curenta ->last == NULL) capete.capat_lista_originala = help_2;
        poz_curenta->last = help_2;
        help_3 = help_2;
        capete.atribuit++;
    }
}
editor* editor_undo(char *last_command, editor *poz_curenta){
    if(strcmp(last_command,"move") == 0) poz_curenta = editor_move(poz_curenta, capete.atribuit * (-1));
    else if(strcmp(last_command,"paste") == 0|| strcmp(last_command, "insert") == 0){
        poz_curenta = editor_move(poz_curenta, capete.atribuit * (-1));
        poz_curenta = editor_delete(poz_curenta, capete.atribuit * (-1));
    }
    return poz_curenta;
}

