#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

char name[100];

void intro(), personalization(), menu(), greet_the_user();

int main() {
    intro();
    personalization();
}

void intro() { // introduction to the program, wait for Enter at the end
    system("CLS");
    printf("\033[1;36m--- ZAKOVSKA KNIHA ---\033[0;37m\n"); //cyan colored heading
    printf("\nTento program slouzi jako elektronicka Zakovska kniha,\numoznuje zapsani znamky, zobrazeni prehledu znamek, prumeru \na vypis predmetu ze kterych zak propada.\n");
    printf("Nevyhodou tohoto programu je ztrata dat po ukonceni\n");
    printf("Stiskni Enter pro pokracovani...");
    getchar();
}

void personalization() { // personalize the app by specifying your name
    printf("Zadej sve jmeno: ");
    scanf("%s", name);
    printf("Zadane jmeno: %s\n", name);
    sleep(0.5);
    printf("Data ulozena.\n");
    menu();
}

void menu() { // main menu
    int menu_select;
    system("CLS");
    printf("\033[1;36m--- ZAKOVSKA KNIHA ---\033[0;37m\n\n"); //cyan colored heading
    greet_the_user();
    printf("\n\n\033[1;36m--- HLAVNI MENU ---\033[0;37m\n");
    printf("\n1) Zadat novou znamku\n2) Zobrazit prehled znamek\n3) Zobrazit prumery predmetu\n4) Zobrazit predmety, ze kterych zak propada\n4) Ukoncit program\n");
    printf("\nZadej odpovidajici cislo a stiskni Enter: ");
    scanf("%d", &menu_select);

    
}

void greet_the_user() {
    char greet[50];

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