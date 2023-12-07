#include <stdio.h>

void swap(void* a, void* b, size_t size){
    unsigned char* byteA = (unsigned char*)a;
    unsigned char* byteB = (unsigned char*)b;

    for(size_t i = 0; i < size; ++i){
        *byteA ^= *byteB;
        *byteB ^= *byteA;
        *byteA ^= *byteB;

        ++byteA;
        ++byteB;
    }
}

int main(){
    //with integers
    int num1 = 5;
    int num2 = 10;
    printf("Before swap: num1 = %d, num2 = %d\n", num1, num2);
    swap(&num1, &num2, sizeof(int));
    printf("\nAfter swap: num1 = %d, num2 = %d\n\n", num1, num2);

printf("----------x------------x------------x-----------x\n\n");

    //with doubles
    double d1 = 3.14;
    double d2 = 6.28;
    printf("Before swap: double1 = %.2f, double2 = %.2f\n", d1, d2);
    swap(&d1, &d2, sizeof(double));
    printf("\nAfter swap: double1 = %.2f, double2 = %.2f\n\n", d1, d2);
    
    printf("----------x------------x------------x-----------x\n\n");
    
    //with char
    char c1 = 'A';
    char c2 = 'B';
    printf("Before swap: char1 = %c, char2 = %c\n", c1, c2);
    swap(&c1, &c2, sizeof(char));
    printf("\nAfter swap: char1 = %c, char2 = %c\n\n", c1, c2);
}
