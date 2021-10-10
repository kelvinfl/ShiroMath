#ifndef INC_1_ARITHMETICSEQUENCE_H
#define INC_1_ARITHMETICSEQUENCE_H

#include <stdio.h>

typedef struct ArithmeticSequence {
    double* ddata;
    int* idata;
    int size;
} ArithmeticSequence;

ArithmeticSequence ArithmeticSequence_DNew(double* data, int size);
ArithmeticSequence ArithmeticSequence_INew(int* data, int size);

double ArithmeticSequence_DGetDifference(ArithmeticSequence *self);
int ArithmeticSequence_IGetDifference(ArithmeticSequence *self);

double ArithmeticSequence_DGetNextTerm(ArithmeticSequence *self);
int ArithmeticSequence_IGetNextTerm(ArithmeticSequence *self);

double ArithmeticSequence_DGetValueFromIndex(ArithmeticSequence *self, int n);
int ArithmeticSequence_IGetValueFromIndex(ArithmeticSequence *self, int n);

double ArithmeticSequence_DGetIndexFromValue(ArithmeticSequence *self, double value);
int ArithmeticSequence_IGetIndexFromValue(ArithmeticSequence *self, int value);

double ArithmeticSequence_DGetSum(ArithmeticSequence *self);
int ArithmeticSequence_IGetSum(ArithmeticSequence *self);

double ArithmeticSequence_DFGetSum(ArithmeticSequence *self, double start, double end);
int ArithmeticSequence_IFGetSum(ArithmeticSequence *self, int start, int end);

void ArithmeticSequence_PrintAll(ArithmeticSequence *self);

#endif
