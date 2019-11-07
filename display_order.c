//
// Created by Irina on 07-Nov-19.
//

#include <stdio.h>
#include "constants.h"

void signingIn(char username[20], char password[20]){
    printf("Please sign in to continue!\n");
    printf("---Username:\n");
    gets(username);
    printf("---Password:\n");
    gets(password);
}
void displayFoodType( char food[][10] ){
    printf("Please choose the food you feel like eating today:\n");
    for (int i = 0; i < NR_FOODS; i++) {
        putchar('a' + i);
        printf(") %s\n", food[i]);
    }
    printf("%c) Go back\n", 'a' + NR_FOODS);
}
void displayFoodChoice(char food[][10], int foodChoice, int prices[3][4], int noFoodTypes[], char foodTypes[3][4][20]){
    printf("Please choose the type of %s:\n", food[foodChoice]);
    for (int i = 0; i < noFoodTypes[foodChoice]; i++) {
        putchar('a' + i);
        printf(") %s (%d)\n", foodTypes[foodChoice][i], prices[foodChoice][i]);
    }
    printf("%c) Go back\n", 'a' + noFoodTypes[foodChoice]);
}
void displayDrinks(char food[][10], char drinks[][20],  int pricesDrinks[5], int foodChoice){
    printf("Please choose a drink to go with your %s\n", food[foodChoice]);
    for (int i = 0; i <NR_DRINKS; i++) {
        putchar('a' + i);
        printf(") %s (%d)\n", drinks[i],pricesDrinks[i]);
    }
    printf("%c) Go back\n", 'a' + NR_DRINKS);
}
void displayCutlery(){
    printf("Do you want cutlery?\n");
    printf("a) Yes\nb) No, thanks!\nc) Go back\n");
}
void displayConfirmingOrder(){
    printf("a) Confirm order\n");
    printf("b) Go back\n");
}
void displayPaymentInfo(int prices[3][4], int foodChoice, int foodTypeChoice, int pricesDrinks[5], int drinkChoice){
    printf("Payment amount: %d\n", prices[foodChoice][foodTypeChoice] + pricesDrinks[drinkChoice]);
    printf("-------------\n");
}
void displayOrder(char username [20],char food[][10], int foodChoice, char foodTypes[3][4][20], int foodTypeChoice, int prices[3][4], int drinkChoice, char drinks[][20], int pricesDrinks[5]){
    printf("This is your order:\n");
    printf("-------------\n");
    printf("Name: %s\n", username);
    printf("Food items:\n");
    printf("--- %s %s (%d)\n", food[foodChoice], foodTypes[foodChoice][foodTypeChoice],prices[foodChoice][foodTypeChoice]);
    if (drinkChoice != NR_DRINKS - 1) {
        printf("--- %s (%d)\n", drinks[drinkChoice], pricesDrinks[drinkChoice]);
    }
}
void displayCutleryOrder(int cutleryChoice, char addInfo[200]){
    printf("Cutlery:");
    if (cutleryChoice == 1)
    printf("yes\n");
    else
    printf("no\n");
    if (addInfo[0] != NULL) {
    printf("Additional info: ");
    puts(addInfo);
}
}
