#include <stdio.h>

const float MAX = 100.00f;
const float MIN = 0.00f;

int main(void)
{
    float scores;
    float sum = 0.00f;
    int number_of_student = 0;

    float min_score = MAX;  //for the first time update 
    float max_score = MIN;  //

    printf("Plz enter the score of students: \n");
    while (scanf("%f", &scores) == 1)
    {
        
        if (scores < MIN || scores > MAX)
        {
            printf("You enter a invalid scores, plz enter again.\n");
            continue;
        }
        printf("Accepting %0.2f: \n", scores);
       
        min_score = (scores < min_score) ? scores : min_score;
        max_score = (scores > max_score) ? scores : max_score;
        number_of_student ++;
        sum += scores;
        
        printf("Enter the next score: \n");
        
    }
    
    if (number_of_student > 0)
    {
        printf("The average of %d students' scores is: %0.2f\n",number_of_student, sum / number_of_student);
        printf("The lowest score: %0.2f \nThe highest score:%0.2f \n", min_score, max_score);
    } 
    else
        printf("No valid scores were entered.\n");  
    
    return 0;

}