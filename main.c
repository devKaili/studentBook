/*
    Project: Electronic Student Book
    Name: Rostislav Kaili Otevrel
    Class: 2EAs1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

// Define color setting for console output.
#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define PURPLE "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"

// Clear the console output.
#define CLEAR printf("\e[1;1H\e[2J");

// Function declaration.
void programIntroduction(), personalization(), personalizationConfirm(int personalizationMenuSelect), invalidInput(), mainMenu(), programExit();

char greetUserAccordingToTime();

int inputCheck(int userInput, int maxValue);

// Global variable declaration for the personalization() function.
char name[100];
int gender;


// ------------------------------- MAIN FUNC STARTS HERE ---------------------------
int main()
{
    personalization();


    return 0;
}
// ------------------------------- MAIN FUNC ENDS HERE ---------------------------


// Introduction to the app with explanation of what it does and also it's shortcomings.
void programIntroduction()
{
    system("CLS");
    printf("Tento program slouzi jako elektronicka zakovska knizka.\nUmoznuje uzivateli zadat novou znamku, zobrazit prehled prumeru v tabulce,\nzobrazit celkovy prumer pripadny narok na vyznamenani\na zobrazit prehled predmetu ze kterych zak propada.\n");
    printf("Upozorneni: Tato aplikace je ve sve stavajici verzi neschopna ulozit znamky do souboru, takze po ukonceni dojde ke ztrate dat.\n");
    printf("Pokracujte stisknutim Enter...");
    getchar();
}

// This enables the user to personalize the app by specifying their name and gender, this info will be used for addressing the user correctly.
void personalization()
{
    CLEAR
    int personalizationMenuSelect;
    printf(CYAN"----- PRIZPUSOBENI -----\n\n"WHITE);
    printf("Zadejte sve jmeno: ");
    scanf("%s", name);
    printf("Zadana hodnota: "YELLOW"%s\n"WHITE, name);
    printf("Zvolte sve pohlavi(1 - Muz, 2 - Zena): ");
    scanf("%d", &gender);
    printf("Zadana hodnota: "YELLOW"%d\n"WHITE, gender);  

    if (inputCheck(gender, 2))
    {
        invalidInput();
        personalization();
    }

    personalizationConfirm(personalizationMenuSelect);
    
}

// Makes sure if the user is satisfied with the personalization settings.
void personalizationConfirm(int personalizationMenuSelect)
{
    CLEAR
    printf("Zvolene jmeno: "YELLOW"%s"WHITE"\nZvolene pohlavi: "YELLOW"%s"WHITE"\n\n", name, (gender == 1) ? "Muz" : "Zena");
    printf("Jsi spokojen%c", (gender == 1) ? '\0' : 'a');
    printf(" se zadanymi hodnotami?\n1 - Ano, pokracovat do aplikace\n2 - Ne, upravit zadani\nZvol moznost a stiskni enter: ");
    scanf("%d", &personalizationMenuSelect);
    printf("Zadana hodnota: "YELLOW"%d\n"WHITE, personalizationMenuSelect);
    sleep(1);

    if (inputCheck(personalizationMenuSelect, 2))
    {
        invalidInput();
        personalizationConfirm(personalizationMenuSelect);
    }

    (personalizationMenuSelect == 1) ? mainMenu() : personalization();
}

// Check if the user input is in specified range, return 0 if input is ok and 1 if it's not.
int inputCheck(int userInput, int maxValue)
{
    return (userInput >= 1 && userInput <= maxValue) ? 0 : 1;
}

// Prints an error message indicating that the input is invalid.
void invalidInput()
{
    CLEAR
    printf(RED"Zadana hodnota neodpovida moznostem v nabidce"WHITE);
    sleep(2);
    CLEAR
}

// Greet the user according to current time. AI generated.
char greetUserAccordingToTime()
{
    char greet[20];
    time_t t = time(NULL);
    struct tm *currentTime = localtime(&t);
    int hour = currentTime->tm_hour;

    if (hour >= 5 && hour < 12) 
    {
        strcpy(greet, "Dobre rano");
    } 
    else if (hour >= 12 && hour < 18) 
    {
        strcpy(greet, "Dobre odpoledne");
    } 
    else 
    {
        strcpy(greet, "Dobry vecer");
    }
    printf("%s %s!\n", greet, name);
}

// Main menu for the app, enables the user to select their desired action.
void mainMenu()
{ 
    int mainMenuSelect;
    CLEAR
    printf(CYAN"----- HLAVNI MENU -----\n\n"WHITE);
    greetUserAccordingToTime();
    printf("\nPrejes si...\n1 - Zadat novou znamku\n2 - Zobrazit tabulku prumeru\n3 - Zobrazit celkovy prumer a zda-li zak ukonci skolni rok s vyznamenanim\n4 - Zobrazit predmety ze kterych zak propada\n5 - Ukoncit program\n");
    printf("Zvol operaci zadanim odpovidajiciho cisla: ");
    scanf("%d", &mainMenuSelect);
    printf("Zadana hodnota: "YELLOW"%d"WHITE, mainMenuSelect);
    sleep(1);

    if (inputCheck(mainMenuSelect, 5))
    {
        invalidInput();
        mainMenu();
    }

    switch (mainMenuSelect)
    {
    case 1:
        // markInput();
        break;
    case 2:
        // TBD
        break;
    case 3:
        // TBD
        break;
    case 4:
        // TBD
        break;
    case 5:
        programExit();
        break;
    }

}

void programExit()
{
    int progExitMenuSelect;
    CLEAR
    printf(RED"OPRAVDU SI PREJETE PROGRAM UKONCIT?"WHITE"\n\n1 - Ano, ukoncit (ztrata dat)\n2 - Ne, navrat do hlavniho menu\nZvol operaci zadanim odpovidajiciho cisla: ");
    scanf("%d", &progExitMenuSelect);
    printf("Zadana hodnota: "YELLOW"%d"WHITE, progExitMenuSelect);
    sleep(1);

    if (inputCheck(progExitMenuSelect, 2))
    {
        invalidInput();
        programExit();
    }

    CLEAR
    if (progExitMenuSelect == 1)
    {
        printf(RED"UKONCENI PROGRAMU\n"WHITE);
        exit(0);
    }
    else
    {
        printf(GREEN"NAVRAT DO HLAVNIHO MENU\n"WHITE);
        sleep(2);
        mainMenu();
    }
}