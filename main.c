#include <stdio.h>
#include "display_order.h"
#define NR_FOODS 3
#define NR_DRINKS 5

int getDrinkChoice (int *state);
int getChoiceIndex(int *state);

int main() {
    printf("Welcome to Food Thingies!\n");
    char food[][10] = {"Pizza","Pasta","Salad"};
    int noFoodTypes[] = {3,2,4};
    char foodTypes[3][4][20] = { {"Carbonara", "Diavola", "Margherita"}, {"Chicken alfredo", "Mac&cheese"}, {"Tuna", "Chicken", "Greek", "Cobb"} };
    int prices[3][4] = {{21, 23, 19}, {23, 21}, {23, 22, 19, 21} };
    char drinks[][20] = {"Coca Cola", "Fanta", "Lipton", "Water", "No, thanks!"};
    int pricesDrinks[5] = {5, 5, 5, 4, 0};
    char addInfo[200], username[20], password[20];
    int choice, foodChoice, foodTypeChoice, drinkChoice, cutleryChoice;
    int state =0, orderPrinted = 0;
    while(!orderPrinted){
        switch (state) {
            case 0: {
                signingIn(username, password);
                state++;
                break;
            }
            case 1: {
                displayFoodType(food);
                foodChoice = getChoiceIndex(&state);
                break;
            }
            case 2: {
                displayFoodChoice(food, foodChoice, prices, noFoodTypes, foodTypes);
                choice = getchar();
                getchar();
                if (choice == 'a' + noFoodTypes[foodChoice]) {
                    state--;
                } else {
                    foodTypeChoice = choice - 'a';
                    state++;
                }
                break;
            }
            case 3: {
                displayDrinks(food, drinks, pricesDrinks, foodChoice);
                drinkChoice = getDrinkChoice (&state);
                break;
            }
            case 4: {
                //cutlery
                printf("Do you want cutlery?\n");
                printf("a) Yes\nb) No, thanks!\nc) Go back\n");
                choice = getchar();
                getchar();
                if(choice=='c')
                    state--;
                else {
                    if (choice == 'a')
                        cutleryChoice = 1;
                    if (choice == 'b')
                        cutleryChoice = 0;
                    state++;
                }
                break;
            }
            case 5:{
                //Additional info
                printf("Any additional info?\n");
                gets(addInfo);
            }
            case 6:{
                // Printing order
                printf("This is your order:\n");
                printf("-------------\n");
                printf("Name: %s\n", username);
                printf("Food items:\n");
                printf("--- %s %s (%d)\n",food[foodChoice],foodTypes[foodChoice][foodTypeChoice],prices[foodChoice][foodTypeChoice]);
                if(drinkChoice != NR_DRINKS-1){
                    printf("--- %s (%d)\n", drinks[drinkChoice], pricesDrinks[drinkChoice]);
                }
                printf("Cutlery:");
                if(cutleryChoice==1)
                    printf("yes\n");
                else
                    printf("no\n");
                if(addInfo[0]!=NULL){
                    printf("Additional info: ");
                    puts(addInfo);
                }
                printf("Payment amount: %d\n", prices[foodChoice][foodTypeChoice] + pricesDrinks[drinkChoice]);
                printf("-------------\n");
                printf("a) Confirm order\n");
                printf("b) Go back\n");
                choice = getchar();
                if(choice=='a') {
                    orderPrinted = 1;
                } else {
                    state--;
                }

                getchar();
                break;
            }
        }
    }
    return 0;
}

int getChoiceIndex( int *state) {
    int choiceIndex;
    char choice = getchar();
    getchar();
    if(choice == 'a'+ NR_FOODS) {
        (*state)--;
    } else {
        choiceIndex = choice - 'a';
        (*state)++;
    }
    return choiceIndex;
}
int getDrinkChoice (int *state){
    int choiceIndexDrinks;
    char choice = getchar();
    getchar();
    if (choice == 'a' + NR_DRINKS) {
        (*state)--;
    } else {
        choiceIndexDrinks = choice - 'a';
        (*state)++;
    }
    return choiceIndexDrinks;
}



