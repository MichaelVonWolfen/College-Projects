#define MAX_COST 100000
#define MAX_LENGHT 1000
FILE *locatii;
FILE *avarii;
FILE *destinatie;
FILE *coordonate_iesire;
FILE *rezultate_iesire;
typedef struct graph{
    unsigned int num_locatii;
    int **cost;
}graph;

typedef struct satellite{
    unsigned int r, y, x;
    struct satelit *next;
} satellite;

typedef struct location{
    char *location_name;
    satellite *satellites;
    unsigned int y, x;
    struct location *next;
}location;

struct locations{
    location *first;
    unsigned int locations_number;
}locations;
satellite* satellite_read( ){
    int i;
    char name[MAX_LENGHT];
    satellite *help, *help_2, *head;
    for(i = 0;i<3;i++){
        help = (satellite*)malloc(sizeof(satellite));
        help->next = NULL;
        fscanf(locatii,"%s", name);
        fscanf(locatii, "%u %u %u", &help->x, &help->y, &help->r);
        if(!i) head = help;
        else help_2->next = help;
        help_2 = help;
    }
    return head;
}
location *memory_alloc(){
    location *p;
    p = (location*)malloc(sizeof(location));
    p->location_name = NULL;
    p->next = NULL;
    p->satellites = NULL;
    return p;
}
void locations_read(){
    int i;
    char word[MAX_LENGHT];
    location *help_1, *help_2;
    fscanf(locatii, "%u", &locations.locations_number);

    if(!locations.locations_number)
        return ;

    for(i = 0; i<locations.locations_number; i++){
        help_2 = memory_alloc();

        if(i) help_1->next = help_2;
            else locations.first = help_2;

        help_1 = help_2;
        fscanf(locatii,"%s",word);
        help_1->location_name = malloc(sizeof(char)*(strlen(word) + 1));
        strcpy(help_1->location_name,word);
        help_1->satellites = satellite_read();

    }
}
void afisare_locatii();
void freer();
graph *graph_read(const char *locatii);
void floyd_warshall(graph *graf);
void dijkstra(graph *graf, int start_node);
