//
// Created by Irina on 07-Nov-19.
//

#include <stdio.h>

int getChoiceIndex(int nrOfTypes, int *state) {
    int choiceIndex;
    char choice = getchar();
    getchar();
    if(choice == 'a'+ nrOfTypes ) {
        (*state)--;
    } else {
        choiceIndex = choice - 'a';
        (*state)++;
    }
    return choiceIndex;
}
int getCutleryChoiceIndex(int choice, int *state){
    int cutleryChoiceIndex;
    choice = getchar();
    getchar();
    if(choice=='c')
        (*state)--;
    else {
        if (choice == 'a')
            cutleryChoiceIndex = 1;
        if (choice == 'b')
            cutleryChoiceIndex = 0;
        (*state)++;
    }
    return cutleryChoiceIndex;
}

