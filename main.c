#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "display_order.h"
#include "choices.h"
#include "constants.h"


void appendCharAtBeginning(char * str, char c);
void readFood(char *foodName, int * noOfSpecificFood, char loadingFood[MAX_LINE]);
void readPricesAndSpecificFood(double *prices, char **specificFood, char loadingFood[MAX_LINE]);

int main() {

    int noOfFoodTypes;
    printf(LOAD_DATA"\n");
    scanf("%d:", &noOfFoodTypes);
    getchar();
    printf("%d\n", noOfFoodTypes);

    int *noOfSpecificFood = (int*)malloc(noOfFoodTypes * sizeof(int));
    char *** specificFood = (char***)malloc(noOfFoodTypes * sizeof(char**));
    char ** food = (char**)malloc(noOfFoodTypes * sizeof(char*));
    double **prices = (double**)malloc(noOfFoodTypes * sizeof(double*));
    for(int i=0; i< noOfFoodTypes; i++) {
        food[i] = (char *) malloc(MAX_FOOD_LENGTH * sizeof(char));
        char loadingFood[MAX_LINE];
        char copyLoadingFood[MAX_LINE];
        gets(loadingFood);
        strcpy(copyLoadingFood,loadingFood);
        printf("\n%s", loadingFood);
        appendCharAtBeginning( loadingFood, ' ');
        readFood(food[i], &noOfSpecificFood[i], loadingFood);

        specificFood[i] = (char **) malloc(noOfSpecificFood[i] * sizeof(char *));
        prices[i] = (double *) malloc(*noOfSpecificFood * sizeof(double));

        const char needle[10] = "(";
        char *ret;
        ret = strstr(copyLoadingFood, needle);
        strcpy(loadingFood,ret);
        printf("\nloading Food: %s\n", loadingFood);
        for (int j = 0; j < noOfSpecificFood[i]; j++) {
            // read model name & model price
            specificFood[i][j] = (char *) malloc(MAX_FOOD_LENGTH * sizeof(char));
        }
        readPricesAndSpecificFood(prices[i], specificFood[i], copyLoadingFood);

    }

    printf("Welcome to Food Thingies!\n");

    char drinks[][20] = {"Coca Cola", "Fanta", "Lipton", "Water", "No, thanks!"};
    char username[20], password[20];
    char addInfo[200];
    int pricesDrinks[5] = {5, 5, 5, 4, 0};
    int noFoodTypes[] = {3,2,4};
    int choice = 0;
    int foodChoice = 0;
    int foodTypeChoice = 0;
    int drinkChoice = 0;
    int cutleryChoice = 0;
    int state =0, orderPrinted = 0;
    while(!orderPrinted){
        switch (state) {
            case 0: {
                signingIn(username, password);
                state++; break;
            }
            case 1: {
                displayFoodType(food[foodChoice]);
                foodChoice = getChoiceIndex(NR_FOODS, &state); break;
            }
            case 2: {
                displayFoodChoice(food[foodChoice], foodChoice, prices, noFoodTypes, specificFood);
                foodTypeChoice = getChoiceIndex(noFoodTypes[foodChoice], &state); break;
            }
            case 3: {
                displayDrinks(food[foodChoice], drinks, pricesDrinks, foodChoice);
                drinkChoice = getChoiceIndex(NR_DRINKS, &state); break;
            }
            case 4: {
                displayCutlery();
                cutleryChoice = getCutleryChoiceIndex (choice, &state);break;
            }
            case 5:{
                printf("Any additional info?\n");
                gets(addInfo);
            }
            case 6:{
                displayOrder(username, food[foodChoice], foodChoice, specificFood[foodChoice][foodTypeChoice], foodTypeChoice, prices, drinkChoice, drinks, pricesDrinks, cutleryChoice);
                displayAddInfo(addInfo);
                displayPaymentInfo(prices, foodChoice, foodTypeChoice, pricesDrinks, drinkChoice);
                displayConfirmationOrder();
                choice = getchar();
                if(choice=='a') {
                    orderPrinted = 1;
                } else {
                    state--;
                }
                getchar(); break;
            }
        }
    }
    return 0;
}
void appendCharAtBeginning(char * str, char c) {
    // +1 to include string terminator
    int len = strlen(str) + 1;
    memmove(str + 1, str, len);
    str[0] = c;
}
void readFood(char *foodName, int * noOfSpecificFood, char loadingFood[MAX_LINE]){
    const char delim[2] = ":";
    char * token;
    char copyLoadingFood[MAX_LINE];
    strcpy(copyLoadingFood,loadingFood);
    token = strtok(loadingFood, delim);
    strcpy(foodName,token);
    printf("\n%s", foodName);
    token = strtok(NULL,delim);
    //int atoi(const char *token);
    *noOfSpecificFood = atoi(token);
    printf("\n%d", noOfSpecificFood);
}

void readPricesAndSpecificFood(double *prices, char **specificFood, char loadingFood[MAX_LINE]){

    char *token = strtok(loadingFood, "(");
    int k=0;
    while (token!=NULL) {
        // read model name (until - )
        token = strtok(NULL, "-");
        strcpy(specificFood[k], token);
        printf("\n%s", &specificFood[k]);
        // read price (until ")" )
        token = strtok(NULL, ")");
        sscanf(token, "%.2lf", &prices[k]);
        printf("\n%.2lf", &prices[k]);
        k++;
        // read space until "("
        token = strtok(NULL, "(");
    }
}



