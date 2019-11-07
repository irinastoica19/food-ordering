//
// Created by Irina on 07-Nov-19.
//

#ifndef FOOD_ORDERING_DISPLAY_ORDER_H
#define FOOD_ORDERING_DISPLAY_ORDER_H

void signingIn(char username[20], char password[20]);
void displayFoodType(char food[][10] );
void displayFoodChoice(char food[][10], int foodChoice, int prices[3][4], int noFoodTypes[], char foodTypes[3][4][20]);
void displayDrinks(char food[][10], char drinks[][20],  int pricesDrinks[5], int foodChoice);
void displayCutlery();
void displayConfirmingOrder();
void displayOrder(char username [20],char food[][10], int foodChoice, char foodTypes[3][4][20], int foodTypeChoice, int prices[3][4], int drinkChoice, char drinks[][20], int pricesDrinks[5]);
void displayCutleryOrder(int cutleryChoice, char addInfo[200]);
void displayPaymentInfo(int prices[3][4], int foodChoice, int foodTypeChoice, int pricesDrinks[5], int drinkChoice);

#endif //FOOD_ORDERING_DISPLAY_ORDER_H
