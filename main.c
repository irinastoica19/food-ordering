#include <stdio.h>

void signingIn(char username[20], char password[20]);
void displayFoodType(int noOfFoods, char food[][10] );
void displayFoodChoice(char food[][10], int foodChoice, int prices[3][4], int noFoodTypes[], char foodTypes[3][4][20]);
void displayDrinks(char food[][10], int noDrinks, char drinks[][20],  int pricesDrinks[5], int foodChoice);
int getChoiceIndex(int noOfFoods, int *state);

int main() {
    printf("Welcome to Food Thingies!\n");
    int noOfFoods= 3, noDrinks= 5;
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
                // Signing in
                signingIn(username, password);
                state++;
                break;
            }
            case 1: {
                displayFoodType(noOfFoods,food);
                getchar();
                foodChoice = getChoiceIndex(noOfFoods, &state);
                break;
            }
            case 2: {
                // Selecting specific food
                displayFoodChoice(food, foodChoice, prices, noFoodTypes, foodTypes);
                choice = getchar();

                getchar();
                if (choice == 'a' + noFoodTypes[foodChoice]) {
                    state--;
                    break;
                }
                foodTypeChoice = choice - 'a';
                state++;
                break;
            }
            case 3: {
                //Selecting drink
                displayDrinks(food,noDrinks, drinks, pricesDrinks, foodChoice);
                choice = getchar();

                getchar();
                if (choice == 'a' + noDrinks) {
                    state--;
                    break;
                }
                drinkChoice = choice -'a';
                state++;
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
                if(drinkChoice != noDrinks-1){
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
void signingIn(char username[], char password[]){
    printf("Please sign in to continue!\n");
    printf("---Username:\n");
    gets(username);
    printf("---Password:\n");
    gets(password);
}

void displayFoodType(int noOfFoods, char food[][10] ){
    printf("Please choose the food you feel like eating today:\n");
    for (int i = 0; i < noOfFoods; i++) {
        putchar('a' + i);
        printf(") %s\n", food[i]);
    }
    printf("%c) Go back\n", 'a' + noOfFoods);
}
void displayFoodChoice(char food[][10], int foodChoice, int prices[3][4], int noFoodTypes[], char foodTypes[3][4][20]){
    printf("Please choose the type of %s:\n", food[foodChoice]);
    for (int i = 0; i < noFoodTypes[foodChoice]; i++) {
        putchar('a' + i);
        printf(") %s (%d)\n", foodTypes[foodChoice][i], prices[foodChoice][i]);
    }
    printf("%c) Go back\n", 'a' + noFoodTypes[foodChoice]);
}

void displayDrinks(char food[][10], int noDrinks, char drinks[][20],  int pricesDrinks[5], int foodChoice){
    printf("Please choose a drink to go with your %s\n", food[foodChoice]);

    for (int i = 0; i <noDrinks; i++) {
        putchar('a' + i);
        printf(") %s (%d)\n", drinks[i],pricesDrinks[i]);
    }

    printf("%c) Go back\n", 'a' + noDrinks);
}
int getChoiceIndex(int noOfFoods, int *state) {
    int choiceIndex;
    char choice = getchar();
    getchar();
    if(choice == 'a'+noOfFoods) {
        (*state)--;
    } else {
        choiceIndex = choice - 'a';
        (*state)++;
    }
    return choiceIndex;
}