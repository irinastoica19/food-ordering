//
// Created by Irina on 07-Nov-19.
//

#ifndef FOOD_ORDERING_CHOICES_H
#define FOOD_ORDERING_CHOICES_H

int getChoiceIndex( int nrOfTypes, int *state);
int getCutleryChoiceIndex(int choice, int *state);
int finishingOrder(int choice, int orderPrinted , int *state);

#endif //FOOD_ORDERING_CHOICES_H
