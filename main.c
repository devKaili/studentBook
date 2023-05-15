/*
    Project: Electronic Student Book
    Name: Rostislav Kaili Otevrel
    Class: 2EAs1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// define color setting for console output
#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define PURPLE "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"

// clear the console output
#define CLEAR printf("\e[1;1H\e[2J");

void programIntroduction(), personalization(), mainMenu();


char name[100];
int gender;

// ------------------------------- MAIN FUNC STARTS HERE ---------------------------
int main()
{
    personalization();

}
// ------------------------------- MAIN FUNC ENDS HERE ---------------------------

// introduction to the app with explanation of what it does and also it's shortcomings
void programIntroduction()
{
    system("CLS");
    printf("Tento program slouzi jako elektronicka zakovska knizka.\nUmoznuje uzivateli zadat novou znamku, zobrazit prehled prumeru v tabulce,\nzobrazit celkovy prumer pripadny narok na vyznamenani\na zobrazit prehled predmetu ze kterych zak propada.\n");
    printf("Upozorneni: Tato aplikace je ve sve stavajici verzi neschopna ulozit znamky do souboru, takze po ukonceni dojde ke ztrate dat.\n");
    printf("Pokracujte stisknutim Enter...");
    getchar();
}

// this enables the user to personalize the app by specifying their name and gender, this info will be used for addressing the user correctly
void personalization()
{
    CLEAR
    int personalizationMenuSelect;
    printf(CYAN"----- PRIZPUSOBENI -----\n\n"WHITE);
    printf("Zadejte sve jmeno: ");
    scanf("%s", name);
    printf("Zadana hodnota: "YELLOW"%s\n"WHITE, name);
    printf("Zvolte sve pohlavi(1 pro Muz, 2 pro Zena): ");
    scanf("%d", &gender);
    printf("Zadana hodnota: "YELLOW"%d\n"WHITE, gender);
    
    printf("\nJsi ");
    (gender == 1) ? printf("spokojen ") : printf("spokojena ");
    printf("se zadanymi hodnotami?\n1 - Ano, pokracovat do aplikace\n2 - Ne, upravit zadani\nZvol moznost a stiskni enter: ");
    scanf("%d", &personalizationMenuSelect);
    printf("Zadana hodnota: "YELLOW"%d\n"WHITE, personalizationMenuSelect);
    sleep(1);
    switch (personalizationMenuSelect)
    {
    case 1:
        mainMenu();
        break;

    default:
        personalization();
        break;
    }
}

// main menu for the app, enables the user to select their desired action
void mainMenu()
{
    print(CYAN"----- HLAVNI MENU -----\n\n"WHITE);
    

}