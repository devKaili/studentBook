#include <stdio.h>
#include <stdlib.h>

void intro();

int main() {
    intro();
}


void intro() {
    system("CLS");
    printf("\033[1;36m--- ZAKOVSKA KNIHA ---\033[0;37m\n");
    printf("\nTento program slouzi jako elektronicka Zakovska kniha,\numoznuje zapsani znamky, zobrazeni prehledu znamek, prumeru \na vypis predmetu ze kterych zak propada.\n");
}