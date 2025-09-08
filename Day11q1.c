//Write a program to display the month name and number of days using switch-case for a given month number.

#include <stdio.h>
int main()
{
    int mon;
    printf("Enter the month number: ");
    scanf("%d", &mon);

    switch (mon)
    {
    case 1:
    printf("Januay 31 Days");
    break;
    case 2:
    printf("February 28 Days");
    break;
    case 3:
    printf("March 31 Days");
    break;
    case 4:
    printf("April has 30 Days");
    break;
    case 5:
    printf("May has 31 Days");
    break;
    case 6:
    printf("June has 30 Days");
    break;
    case 7:
    printf("July has 31 Days");
    break;
    case 8:
    printf("August has 31 Days");
    break;
    case 9:
    printf("September has 30 Days");
    break;
    case 10:
    printf("October has 31 Days");
    break;
    case 11:
    printf("November has 30 Days");
    break;
    case 12:
    printf("December has 31 Days");
    break;
    default:
    printf("Invalid Input!");
    break;
    }
}