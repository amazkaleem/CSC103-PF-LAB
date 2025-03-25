#include <stdio.h> 
#include<stdlib.h> 
int main() 
{ 
    int James,Yulian,David;

    printf("Enter ages of James Yulian and David with spaces between them: "); 
    scanf("%d %d %d", &James, &Yulian, &David);

    if (James < Yulian && James < David) 
    { 
        printf("James is the youngest at %d years old",James); 
    } else if (Yulian < James && Yulian < David) 
    { 
        printf("Yulian is the youngest at %d years old",Yulian); 
    } else 
    { 
        printf("David is the youngest at %d years old",David); 
    } 
    return 0; 
}
