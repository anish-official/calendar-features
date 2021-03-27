#include "notesOptions.c"


int main(){
    int start;
    printf("Enter ret --> ");
    scanf("%d", &start);
    int j = 1;
    printf("|SU||MO||TU||WE||TH||FR||SA|\n");
    //for loop for blank spaces 
    if (start <= 7)
    {
        for (int i = 1; i < start; i++)
        {
            printf("%4s", " ");
        }
        j = start;
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