#include <stdio.h>
#include <stdlib.h>
//#include<string.h>
//#include "Heather.h"
#include "calcul_coordonate.h"

int main(){
    //locatii = fopen("C:\\Users\\Mihai\\Desktop\\Checker local - tema2 GPS tracker\\in\\coordonate\\coordonate1.in", "r");
    /*avarii = fopen( ,'r');
    destinatie = fopen( ,'r');
    coordonate_iesire = ( ,'w');
    rezultate_iesire  = ( ,'w');

    locations_read();
    afisare_locatii();
    */
    calc();
    return 0;
}
/*void afisare_locatii(){
    location *help_1, *help_2;
    satellite *s1, *s2;
    int u=0;
    help_1 = locations.first;
    help_2 = help_1;
    while(help_2){
        s1 = help_1->satellites;
        printf("%s\n",help_1->location_name);
        s2 = s1;
        while(s2){
            printf("\tSatelit%d: %d %d %d\n", u++, s1->x, s1->y, s1->r);
            s1 = s1->next;
            free(s2);
            s2 = s1;
        }
        u=0;
        help_1 = help_1->next;
        free(help_2);
        help_2 = help_1;
    }
}
void freer(){
    location *help_1, *help_2;
    satellite *s1, *s2;
    help_1 = locations.first;
    help_2 = help_1;
    while(help_2){
        s1 = help_1->satellites;
        s2 = s1;
        while(s2!=NULL){
            s1 = s1->next;
            free(s2);
            s2 = s1;
        }
        help_1 = help_1->next;
        free(help_2);
        help_2 = help_1;
    }
}
*/
