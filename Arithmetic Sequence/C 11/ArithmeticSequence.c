#include "ArithmeticSequence.h"

ArithmeticSequence ArithmeticSequence_DNew(double* data, int size) {
    ArithmeticSequence initialized = {data,'\0',size};
    return initialized;
}

ArithmeticSequence ArithmeticSequence_INew(int* data, int size) {
    ArithmeticSequence initialized = {'\0',data,size};
    return initialized;
}

double ArithmeticSequence_DGetDifference(ArithmeticSequence *self) {
    if (self->ddata != (void *)0) return self->ddata[1] - self->ddata[0];
    return 0.0;
}

int ArithmeticSequence_IGetDifference(ArithmeticSequence *self) {
    if (self->idata != (void *)0) return self->idata[1] - self->idata[0];
    return 0;
}

double ArithmeticSequence_DGetNextTerm(ArithmeticSequence *self) {
    if (self->ddata != (void *)0) return self->ddata[self->size-1] + ArithmeticSequence_DGetDifference(self);
    return 0.0;
}

int ArithmeticSequence_IGetNextTerm(ArithmeticSequence *self) {
    if (self->idata != (void *)0) return self->idata[self->size-1] + ArithmeticSequence_IGetDifference(self);
    return 0;
}

double ArithmeticSequence_DGetValueFromIndex(ArithmeticSequence *self, int n) {
    if (self->ddata != (void *)0) return self->ddata[0] + (ArithmeticSequence_DGetDifference(self) * (n-1));
    return 0.0;
}

int ArithmeticSequence_IGetValueFromIndex(ArithmeticSequence *self, int n) {
    if (self->idata != (void *)0) return self->idata[0] + (ArithmeticSequence_IGetDifference(self) * (n-1));
    return 0;
}

double ArithmeticSequence_DGetIndexFromValue(ArithmeticSequence *self, double value) {
    if (self->ddata != (void *)0) return ((value - self->ddata[0]) / ArithmeticSequence_DGetDifference(self)) + 1.0;
    return 0.0;
}

int ArithmeticSequence_IGetIndexFromValue(ArithmeticSequence *self, int value) {
    if (self->idata != (void *)0) return ((value - self->idata[0]) / ArithmeticSequence_IGetDifference(self)) + 1;
    return 0;
}

double ArithmeticSequence_DGetSum(ArithmeticSequence *self) {
    if (self->ddata != (void *)0) {
        double i = self->ddata[0];
        for (int j = 1; j < self->size; j++) {
            i += self->ddata[j];
        }
        return i;
    }
    return 0.0;
}

int ArithmeticSequence_IGetSum(ArithmeticSequence *self) {
    if (self->idata != (void *)0) {
        int i = self->idata[0];
        for (int j = 1; j < self->size; j++) {
            i += self->idata[j];
        }
        return i;
    }
    return 0;
}

double ArithmeticSequence_DFGetSum(ArithmeticSequence *self, double start, double end) {
    if (self->ddata != (void *)0) {
        double i = 0.0;
        for (int j = start; j <= end; j++) {
            i += self->ddata[j];
        }
        return i;
    }
    return 0.0;
}

int ArithmeticSequence_IFGetSum(ArithmeticSequence *self, int start, int end) {
    if (self->idata != (void *)0) {
        int i = 0;
        for (int j = start; j <= end; j++) {
            i += self->idata[j];
        }
        return i;
    }
    return 0;
}

void ArithmeticSequence_PrintAll(ArithmeticSequence *self) {
    if (self->idata != (void *)0) {
        for (int i = 0; i < self->size; i++) {
            printf("%d\n", self->idata[i]);
        }
    } else if (self->ddata != (void *)0) {
        for (int i = 0; i < self->size; i++) {
            printf("%lf\n", self->ddata[i]);
        }
    }
}
