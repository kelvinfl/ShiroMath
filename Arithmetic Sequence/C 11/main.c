#include <stdio.h>
#include "ArithmeticSequence.h"

int main() {
    int d[] = {6, 9, 12, 15, 18, 21};
    int d_size = *(&d + 1) - d;

    ArithmeticSequence data = ArithmeticSequence_INew(d,d_size);
    ArithmeticSequence_PrintAll(&data);

    int v = 10, w = 30, y = 0, z = 1;

    if (data.ddata != (void *)0) {
        printf("Difference : %lf\n", ArithmeticSequence_DGetDifference(&data));
        printf("Next Term : %lf\n", ArithmeticSequence_DGetNextTerm(&data));
        printf("Value From Index(n) : %lf\n", ArithmeticSequence_DGetValueFromIndex(&data, v));
        printf("Index From Value(value) : %lf\n", ArithmeticSequence_DGetIndexFromValue(&data, w));
        printf("Sum : %lf\n", ArithmeticSequence_DGetSum(&data));
        printf("Sum in Range(start,end) : %lf\n", ArithmeticSequence_DFGetSum(&data, y, z));
    } else if (data.idata != (void *)0) {
        printf("Difference : %d\n", ArithmeticSequence_IGetDifference(&data));
        printf("Next Term : %d\n", ArithmeticSequence_IGetNextTerm(&data));
        printf("Value From Index(n) : %d\n", ArithmeticSequence_IGetValueFromIndex(&data, v));
        printf("Index From Value(value) : %d\n", ArithmeticSequence_IGetIndexFromValue(&data, w));
        printf("Sum : %d\n", ArithmeticSequence_IGetSum(&data));
        printf("Sum in Range(start,end) : %d\n", ArithmeticSequence_IFGetSum(&data, y, z));
    }

    getchar();
    return 0;
}
