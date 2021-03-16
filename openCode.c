#include <stdio.h>
int main(){
    int start;
    printf("Enter ret --> ");
    scanf("%d", &start);
    int j = start;
    printf("|SU||MO||TU||WE||TH||FR||SA|\n");
    //for loop for blank spaces 
    for (int i = 1; i < start; i++)
    {
        printf("|%2s|", " ");
    }
     int i = 1, count = 31;

    for (; i <= count;)
    {
        for (; (j <= 7) && ( i <= count); j++,i++)
        {
            printf("|%2d|", i);
        }
        printf("\n"); 
        j=1;
    }
    
    return 0;
}