#include <stdio.h>
int main(){
    int start;
    printf("Enter ret --> ");
    scanf("%d", &start);
    int j = start;
    printf("|SUN|MON|TUE|WED|THURS|FRI|SAT\n");
    //for loop for blank spaces 
    for (int i = 0; i < start; i++)
    {
        printf("| |");
    }
    

    for (int i = 0, count = 31; i <= count; i++)
    {
        for (; j <= 7; j++,i++)
        {
            printf("|%d|", i);
        }
        printf("\n");
        j=0;
    }
    
    return 0;
}