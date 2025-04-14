#include <stdio.h>
#include <stdlib.h>

'''
int main(){
  
    int myarray[5] = {10, 20, 30, 40, 50};
    
    a == &a[0];

    //&a[i] = starting adress + i * sizeof(int) (no. of bytes);


    return 0;
}
'''


'''
// PASSING BY VALUE

void main(){
    int a = 6, b = 12;
    printf("%d", c1sum(a,b));
}

int c1sum(int x, int y){
    return x + y;
}
'''

'''
// PASSING BY REFERENCE
int c_sum(int [], int);
void main(){
    int a[3] = {10, 20, 30, 40, 50};
    int sum;
    sum = c_sum(a, 5);
    printf("Sum = %d", sum);
}

int c_sum(int z[], int size){
    int i=0, sum = 0;
    for(i=0; i<size; i++){
        sum += z[i];
    }
    return sum;
}
'''


'''
// 2D ARRAYS:

int mat[2][3] = {{10, 20, 30}, {40, 50, 60}}; // 2 rows, 3 columns

printf("%d", mat[0][1]); // 20

mat == &mat[0][0]; // address of first element
mat[0] == &mat[0][0]; // address of first row

// Formula to calculate memory location: &mat[i][j] = starting_address + ( i * n + j) * size of each element 
// where i is number of rows, n is no. of elements in each row, j is the no. of coloumns
'''


'''
// better practice to define rows n cols as constants so when we want to change array size we can only change constant
#define rows 3
#define cols 3 
int main(){
    mat[rows][cols]; 
}
'''


'''
// 2D ARRAY EXAMPLE:
#define rows 10
#define cols 2

int main(){
    float A[rows][cols]; // 2D array of float type
    int i=0, j=0;
    do{
        printf("Enter roll no. and marks: ");
        scanf("%f %f", &A[i][0], &A[i][1]); // 0th column for roll no. and 1st column for marks
    }while(A[i++][0] > 0); // loop until roll no. is 0

    for(j=0; j<i-1; j++){
        printf("%f %f", A[j][0], A[j][1]); // print roll no. and marks
    }
}
'''

for(i = 0; i<rows; i++){
    for(j = 0; j<cols; j++){
        scanf("%d", &B[i][j]); // input elements of 2D array
    }