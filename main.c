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
void programIntroduction(), personalization(), personalizationConfirm(int personalizationMenuSelect), invalidInput(), mainMenu(), markInput(), nextMark(int markInputMenuSelect, int mark), markOverview(), passedWithDistinction(), failingClasses(), programExit();

char greetUserAccordingToTime();

int inputCheck(int userInput, int maxValue);

float averageCalculation(int markTotal, int counter);

// Global variable declaration for the personalization() function.
char name[100];
int gender;

// Global variable declaration for mark averages, i dont think this is the best way, but if it works, it works...
int markMathCount, markPhysicsCount, markChemistryCount, markEnglishCount, markComputerScienceCount;
int markMathTotal, markPhysicsTotal, markChemistryTotal, markEnglishTotal, markComputerScienceTotal;
float markMath, markPhysics, markChemistry, markEnglish, markComputerScience;

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
    printf("\nPrejes si...\n1 - Zadat novou znamku\n2 - Zobrazit tabulku prumeru\n3 - Zobrazit celkovy prumer a zda-li zak ukonci skolni rok s vyznamenanim\n4 - Zobrazit predmety ze kterych zak propada\n"RED"5 - Ukoncit program\n"WHITE);
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
        markInput();
        break;
    case 2:
        markOverview();
        break;
    case 3:
        passedWithDistinction();
        break;
    case 4:
        failingClasses();
        break;
    case 5:
        programExit();
        break;
    }

}

// Allows the user to input marks for further functionality of the app
void markInput()
{
    int markInputMenuSelect;
    int mark = 0;

    CLEAR
    
    printf(CYAN"----- ZADANI ZNAMKY -----\n\n"WHITE);
    printf("Zvol predmet do ktereho chces zadavat znamku:\n1 - Matematika\n2 - Fyzika\n3 - Chemie\n4 - Anglictina\n5 - Informatika\n"RED"6 - Navrat do hlavniho menu\n"WHITE);
    printf("Zvol operaci zadanim odpovidajiciho cisla: ");
    scanf("%d", &markInputMenuSelect);
    printf("Zadana hodnota: "YELLOW"%d"WHITE, markInputMenuSelect);
    sleep(1);

    if (inputCheck(markInputMenuSelect, 6))
    {
        invalidInput();
        markInput();
    }
    if (markInputMenuSelect == 6)
    {
        CLEAR
        printf(GREEN"NAVRAT DO HLAVNIHO MENU\n"WHITE);
        sleep(2);
        mainMenu();
    }

    CLEAR
    printf("Zadej znamku (pouze cela cisla od 1 do 5): ");
    scanf("%d", &mark);
    printf("Zadana hodnota: "YELLOW"%d"WHITE, mark);
    sleep(1);

    if (inputCheck(mark, 5))
    {
        CLEAR
        printf(RED"Zadana znamka je neodpovida rozmezi 1-5!"WHITE);
        sleep(2);
        markInput();
    }

    CLEAR

    switch (markInputMenuSelect)
    {
    case 1:
        printf(YELLOW"Znamka zadana do predmetu 'Matematika'."WHITE);
        break;
    case 2:
        printf(YELLOW"Znamka zadana do predmetu 'Fyzika'."WHITE);
        break;
    case 3:
        printf(YELLOW"Znamka zadana do predmetu 'Chemie'."WHITE);
        break;
    case 4:
        printf(YELLOW"Znamka zadana do predmetu 'Anglictina'."WHITE);
        break;
    case 5:
        printf(YELLOW"Znamka zadana do predmetu 'Informatika'."WHITE);
        break;
    }

    nextMark(markInputMenuSelect, mark);
}
void nextMark(int markInputMenuSelect, int mark)
{
    int nextMarkMenuSelect;
    printf("\nPrejes si:\n1 - Ulozit a zadat dalsi znamku\n2 - Zrusit a opakovat zadani\n3 - Ulozit vratit se do hlavniho menu\n");
    printf("Zvol operaci zadanim odpovidajiciho cisla: ");
    scanf("%d", &nextMarkMenuSelect);
    printf("Zadana hodnota: "YELLOW"%d"WHITE, nextMarkMenuSelect);
    sleep(1);

    if (inputCheck(nextMarkMenuSelect, 3))
    {
        invalidInput();
        nextMark(markInputMenuSelect, mark);
    }
    if (nextMarkMenuSelect == 2)
    {
        CLEAR
        printf(YELLOW"Zadani znamky vymazano!"WHITE);
        sleep(2);
        markInput();
    }

    // Save the inputed mark to a corresponding variable
    switch (markInputMenuSelect)
    {
    case 1:
        markMathCount ++;
        markMathTotal += mark;
        markMath = averageCalculation(markMathTotal, markMathCount);
        break;
    case 2:
        markPhysicsCount ++;
        markPhysicsTotal += mark;
        markPhysics = averageCalculation(markPhysicsTotal, markPhysicsCount);
        break;
    case 3:
        markChemistryCount ++;
        markChemistryTotal += mark;
        markChemistry = averageCalculation(markChemistryTotal, markChemistryCount);
        break;
    case 4:
        markEnglishCount ++;
        markEnglishTotal += mark;
        markEnglish = averageCalculation(markEnglishTotal, markEnglishCount);
        break;
    case 5:
        markComputerScienceCount ++;
        markComputerScienceTotal += mark;
        markComputerScience = averageCalculation(markComputerScienceTotal, markComputerScienceCount);
        break;
    }

    CLEAR
    printf(YELLOW"Znamka ulozena!"WHITE);
    sleep(2);

    switch (nextMarkMenuSelect)
    {
    case 1:
        markInput();
        break;
    case 3:
        CLEAR
        printf(GREEN"NAVRAT DO HLAVNIHO MENU\n"WHITE);
        sleep(2);
        mainMenu();
        break;
    }
}
float averageCalculation(int markTotal, int counter)
{
    return markTotal / counter;
}

// Allows the user to view student's total mark average and if they passed with distinction
void markOverview()
{
    int markOverviewMenuSelect;

    CLEAR

    printf(CYAN"----- PREHLED PRUMERU -----\n\n"WHITE);
    printf("Matemetika: "YELLOW"%f"WHITE"\nFyzika: "YELLOW"%f"WHITE"\nChemie: "YELLOW"%f"WHITE"\nAnglictina: "YELLOW"%f"WHITE"\nInformatika: "YELLOW"%f"WHITE"\n\n", markMath, markPhysics, markChemistry, markEnglish, markComputerScience);
    printf("1 - Navrat do hlavniho menu\n");
    printf("Zvol operaci zadanim odpovidajiciho cisla: ");
    scanf("%d", &markOverviewMenuSelect);
    
    if (inputCheck(markOverviewMenuSelect, 1))
    {
        invalidInput();
        markOverview();
    } 
    if (markOverviewMenuSelect == 1)
    {
        CLEAR
        printf(GREEN"NAVRAT DO HLAVNIHO MENU\n"WHITE);
        sleep(2);
        mainMenu();
    }
}

void passedWithDistinction()
{
    char distinctionYesNo[4];
    int passedWithDistinctionMenuSelect;
    
    float overallAverage = (markMath + markPhysics + markChemistry + markEnglish + markComputerScience) / (markMathCount + markPhysicsCount + markChemistryCount + markEnglishCount + markComputerScienceCount);
    
    CLEAR

    printf(CYAN"----- CELKOVY PRUMER A VYZNAMENANI -----\n\n"WHITE);
    printf("Celkovy prumer: %f\n", overallAverage);
    
    strcpy(distinctionYesNo, "ANO");
    if (markMath > 2)
    {
        strcpy(distinctionYesNo, "NE");
    }
    if (markPhysics > 2)
    {
        strcpy(distinctionYesNo, "NE");
    }
    if (markChemistry > 2)
    {
        strcpy(distinctionYesNo, "NE");
    }
    if (markEnglish > 2)
    {
        strcpy(distinctionYesNo, "NE");
    }
    if (markComputerScience > 2)
    {
        strcpy(distinctionYesNo, "NE");
    }

    if (overallAverage > 1.5)
    {
        strcpy(distinctionYesNo, "NE");
    }

    printf("Prospeje %s s vyznamenanim: "YELLOW"%s\n\n"WHITE, name, distinctionYesNo);

    printf("1 - Navrat do hlavniho menu\n");
    printf("Zvol operaci zadanim odpovidajiciho cisla: ");
    scanf("%d", &passedWithDistinctionMenuSelect);
    
    if (inputCheck(passedWithDistinctionMenuSelect, 1))
    {
        invalidInput();
        markOverview();
    } 
    if (passedWithDistinctionMenuSelect == 1)
    {
        CLEAR
        printf(GREEN"NAVRAT DO HLAVNIHO MENU\n"WHITE);
        sleep(2);
        mainMenu();
    }
}

void failingClasses()
{
    int failingClassesMenuSelect;

    CLEAR

    printf(CYAN"----- PREDMETY ZE KTERYCH ZAK PROPADA -----\n\n"WHITE);
    printf("%s propada z:\n", name);

    if (markMath > 4.5)
    {
        printf(YELLOW"Matematiky\n");
    }
    if (markPhysics > 4.5)
    {
        printf(YELLOW"Fyziky\n");
    }
    if (markChemistry > 4.5)
    {
        printf(YELLOW"Chemie\n");
    }
    if (markEnglish > 4.5)
    {
        printf(YELLOW"Anglictiny\n");
    }
    if (markComputerScience > 4.5)
    {
        printf(YELLOW"Informatiky\n");
    }
    else if (markMath < 4.5 && markPhysics < 4.5 && markChemistry < 4.5 && markEnglish < 4.5 && markComputerScience < 4.5)
    {
        printf(YELLOW"Neni zde nic k zobrazeni..."WHITE);
    }

    printf(WHITE"1 - Navrat do hlavniho menu\n");
    printf("Zvol operaci zadanim odpovidajiciho cisla: ");
    scanf("%d", &failingClassesMenuSelect);
    
    if (inputCheck(failingClassesMenuSelect, 1))
    {
        invalidInput();
        markOverview();
    } 
    if (failingClassesMenuSelect == 1)
    {
        CLEAR
        printf(GREEN"NAVRAT DO HLAVNIHO MENU\n"WHITE);
        sleep(2);
        mainMenu();
    }
}

void programExit()
{
    int progExitMenuSelect;
    CLEAR
    printf(RED"OPRAVDU SI PREJETE PROGRAM UKONCIT?"WHITE"\n\n"RED"1 - Ano, ukoncit (ztrata dat)\n"GREEN"2 - Ne, navrat do hlavniho menu"WHITE"\nZvol operaci zadanim odpovidajiciho cisla: ");
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