#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

char name[100];

void intro(), personalization(), menu(), greet_the_user(), menu_select_confirmation(int menu_select_one), program_path_select(int menu_select_one);
int input_verification(int max_value, int input);

// ------------------------------ MAIN FUNCTOIN ---------------------------------
int main()
{
    intro();
    personalization();
}

// introduction to the program, wait for Enter at the end
void intro()
{ 
    system("CLS");
    printf("\033[1;36m--- ZAKOVSKA KNIHA ---\033[0;37m\n"); // cyan colored heading
    printf("\nTento program slouzi jako elektronicka Zakovska kniha,\numoznuje zapsani znamky, zobrazeni prehledu znamek, prumeru \na vypis predmetu ze kterych zak propada.\n");
    printf("Nevyhodou tohoto programu je ztrata dat po ukonceni\n");
    printf("Stiskni Enter pro pokracovani...");
    getchar();
}
// personalize the app by specifying your name
void personalization()
{ 
    printf("Zadejte sve jmeno: ");
    scanf("%s", name);
    printf("Zadane jmeno: %s\n", name);
    sleep(0.5);
    printf("Data ulozena.\n");
    menu();
}

// main menu
void menu()
{ 
    int menu_select_one;
    system("CLS");
    printf("\033[1;36m--- ZAKOVSKA KNIHA ---\033[0;37m\n\n"); // cyan colored heading
    greet_the_user();
    printf("\n\n\033[1;36m--- HLAVNI MENU ---\033[0;37m\n");
    printf("\n1) Zadat novou znamku\n2) Zobrazit prehled prumeru\n3) Zobrazit prumer vsech predmetu\n4) Zobrazit predmety, ze kterych zak propada\n5) Ukoncit program\n");
    printf("\nZadejte odpovidajici cislo a stisknete Enter: ");
    scanf("%d", &menu_select_one);

    // check if the selected option is available
    if (input_verification(5, menu_select_one))
    { // if the user selected an available option, the program will proceed
        menu_select_confirmation(menu_select_one);
    }
    else
    { // if the user selected an unavailable option, the program will spit out an error and ask for menu select again
        printf("\n\n\033[1;31mZadana hodnota neodpovida moznostem v nabidce, zkuste to znovu...\033[0;37m\n\n");
        sleep(2);
        menu();
    }
}
// print out user's input and ask if he/she wants to continue or change the option
void menu_select_confirmation(int menu_select_one)
{ 
    char menu_option[50];
    int menu_select_two;
    system("CLS");
    switch (menu_select_one)
    {
    case 1:
        strcpy(menu_option, "\n1 - Zadat novou znamku.");
        break;
    case 2:
        strcpy(menu_option, "\n2 - Zobrazit prehled znamek.");
        break;
    case 3:
        strcpy(menu_option, "\n3 - Zobrazit prumery predmetu.");
        break;
    case 4:
        strcpy(menu_option, "\n4 - Zobrazit predmety, ze kterych zak propada.");
        break;
    case 5:
        strcpy(menu_option, "\n5 - Ukoncit program.");
        break;
    }
    printf("\n\033[0;33mVase volba:\033[0;37m%s\n", menu_option);
    printf("\nPotvrdit nebo upravit volbu:\n1) Potvrdit volbu\n2) Upravit volbu");
    printf("\nZadejte odpovidajici cislo a stisknete Enter: ");
    scanf("%d", &menu_select_two);
    if (input_verification(2, menu_select_two))
    { // if the user selected an available option, the program will proceed
        switch (menu_select_two)
        {
        case 1:
            program_path_select(menu_select_one);
            break;
        case 2:
            menu();
            break;
        }
    }
    else
    { // if the user selected an unavailable option, the program will spit out an error and ask for menu select again
        printf("\n\n\033[1;31mZadana hodnota neodpovida moznostem v nabidce, zkuste to znovu...\033[0;37m\n\n");
        sleep(2);
        menu_select_confirmation(menu_select_one);
    }
}
// check if user input exceeds min and max values
int input_verification(int max_value, int input)
{ 
    if (input >= 1 && input <= max_value)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// greet the user according to current time and his/her name
void greet_the_user()
{ 
    char greet[50];

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    // check current hour
    int hour = tm.tm_hour;

    // greet the user according to current time
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

    printf("%s, %s.", greet, name);
}

void program_path_select(int menu_select_one)
{
    switch (menu_select_one)
    {
    case 1:
        printf("OPTION ONE");
        break;
    case 2:
        printf("OPTION TWO");
        break;
    case 3:
        printf("OPTION THREE");
        break;
    case 4:
        printf("OPTION FOUR");
        break;
    case 5:
        printf("OPTION FIVE");
        break;
    }
}

void mark_input()
{
}