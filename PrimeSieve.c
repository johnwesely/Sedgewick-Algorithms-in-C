#include <stdio.h>
#include <stdlib.h>

size_t* primeSieve(size_t n);

int main(void){
    size_t* primeToOneHundred = primeSieve(100);
    
    size_t i = 0;

    while (primeToOneHundred[i]) {
        printf("%zu\n", primeToOneHundred[i]);
        ++i;
    }
}

size_t* primeSieve(size_t n) {
    size_t sieveArr[n];  
    size_t primeCount = 2;

    for (size_t i = 0; i < n; ++i) sieveArr[i] = 1;

    for (size_t i = 2; i < n / 2; ++i) {
        for (size_t j = i + i; j < n; j += i) {
            sieveArr[j] = 0;
            ++primeCount;
        }
    }

    size_t* retArr = malloc(sizeof(size_t) * primeCount);

    for (size_t i = 1, count = 0; i < n; ++i) {
        if (sieveArr[i]) {
            retArr[count] = i;
            ++count;
        } 
    } 

    return retArr;
}