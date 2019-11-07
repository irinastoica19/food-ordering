#include <stdio.h>
#include "display_order.h"
#include "choices.h"
#define NR_FOODS 3
#define NR_DRINKS 5
int main() {
    printf("Welcome to Food Thingies!\n");
    char food[][10] = {"Pizza","Pasta","Salad"};
    char foodTypes[3][4][20] = { {"Carbonara", "Diavola", "Margherita"}, {"Chicken alfredo", "Mac&cheese"}, {"Tuna", "Chicken", "Greek", "Cobb"} };
    char drinks[][20] = {"Coca Cola", "Fanta", "Lipton", "Water", "No, thanks!"};
    char addInfo[200], username[20], password[20];
    int prices[3][4] = {{21, 23, 19}, {23, 21}, {23, 22, 19, 21} };
    int pricesDrinks[5] = {5, 5, 5, 4, 0};
    int noFoodTypes[] = {3,2,4};
    int choice, foodChoice, foodTypeChoice, drinkChoice, cutleryChoice;
    int state =0, orderPrinted = 0;
    while(!orderPrinted){
        switch (state) {
            case 0: {
                signingIn(username, password);
                state++; break;
            }
            case 1: {
                displayFoodType(food);
                foodChoice = getChoiceIndex(NR_FOODS, &state); break;
            }
            case 2: {
                displayFoodChoice(food, foodChoice, prices, noFoodTypes, foodTypes);
                foodTypeChoice = getChoiceIndex(noFoodTypes[foodChoice], &state); break;
            }
            case 3: {
                displayDrinks(food, drinks, pricesDrinks, foodChoice);
                drinkChoice = getChoiceIndex(NR_DRINKS, &state); break;
            }
            case 4: {
                displayCutlery();
                cutleryChoice = getCutleryChoiceIndex (choice, &state); break;
            }
            case 5:{
                printf("Any additional info?\n");
                gets(addInfo);
            }
            case 6:{
                displayOrder(username, food,foodChoice,foodTypes,foodTypeChoice,prices,drinkChoice, drinks, pricesDrinks);
                displayCutleryOrder(cutleryChoice, addInfo);
                displayConfirmingOrder(prices, foodChoice,foodTypeChoice,pricesDrinks,drinkChoice);
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





