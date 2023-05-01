#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

void intro(), personalization(), personalization_check(), menu(), greet_the_user();

int main() {
    intro();
    personalization_check();
}

void intro() { // introduction to the program, wait for Enter at the end
    system("CLS");
    printf("\033[1;36m--- ZAKOVSKA KNIHA ---\033[0;37m\n"); //cyan colored heading
    printf("\nTento program slouzi jako elektronicka Zakovska kniha,\numoznuje zapsani znamky, zobrazeni prehledu znamek, prumeru \na vypis predmetu ze kterych zak propada.\n");
    printf("Stiskni Enter pro pokracovani...");
    getchar();
}

void personalization() { // personalize the app by specifying your name and gender
    char name[100];

    FILE *config_file = fopen("config.txt", "w");
    if (config_file == NULL) {
        printf("ERROR opening config file!");
        exit(1);
    }
    system("CLS");
    printf("\033[1;36m--- ZAKOVSKA KNIHA ---\033[0;37m\n"); //cyan colored heading
    printf("\nZadej sve jmeno a stiskni Enter: ");
    scanf("%s", name);

    fprintf(config_file, "%s", name);

    fclose(config_file);
    menu();
}
void personalization_check() { // check if personalization has been made before
    if (access("config.txt", F_OK) != -1) {
        menu();
    } else {
        personalization();
    }
}

void menu() { // main menu
    int menu_select;
    system("CLS");
    printf("\033[1;36m--- ZAKOVSKA KNIHA ---\033[0;37m\n\n"); //cyan colored heading
    greet_the_user();
    printf("\n\n\033[1;36m--- HLAVNI MENU ---\033[1;37m\n");
    printf("\n1) Zadat novou znamku\n2) Zobrazit prehled znamek\n3) Zobrazit prumery predmetu\n4) Zobrazit predmety, ze kterych zak propada\n4) Ukoncit program\n");
    printf("\nZadej odpovidajici cislo a stiskni Enter: ");
    scanf("%d", &menu_select);
}

void greet_the_user() {
    char greet[50];
    char *name;

    FILE *config_file = fopen("config.txt", "r");
    if (config_file == NULL) {
        printf("ERROR opening config file!");
        exit(1);
    }

    fscanf(config_file, "%s", name);
        
    fclose(config_file);

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    // check current hour
    int hour = tm.tm_hour;
    
    // greet the user according to current time
    if (hour >= 5 && hour < 12) {
        strcpy(greet, "Dobre rano");
    } else if (hour >= 12 && hour < 18) {
        strcpy(greet, "Dobre odpoledne");
    } else {
        strcpy(greet, "Dobry vecer");
    }

    printf("%s, %s.", greet, name);    
}