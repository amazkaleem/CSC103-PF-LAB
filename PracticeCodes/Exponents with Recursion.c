#include <stdio.h>

int power(int x, int y); //PROTOTYPING FOR THE POWER FUNCTION. Function to calculate x^y

int main() {
    int num1, num2, result;
    printf("Enter values of x and y: ");
    scanf("%d %d", &num1, &num2);
    result = power(num1, num2);
    printf("%d^%d = %d", num1, num2, result);
  return 0;
}

int power(int x, int y) {
    if(y==1){
        return x;
    }
    else{
        return x*power(x, y-1);
    }
}