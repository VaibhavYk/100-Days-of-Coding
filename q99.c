// Change the date format from dd/04/yyyy to dd-Apr-yyyy.

#include <stdio.h>
#include <stdlib.h>

int main() {
    char input[11];          
    char output[12];         
    int day, month, year;
    const char* months[] = {
        "Jan", "Feb", "Mar", "Apr",
        "May", "Jun", "Jul", "Aug",
        "Sep", "Oct", "Nov", "Dec"
    };
    printf("Enter date (dd/mm/yyyy): ");
    scanf("%10s", input);

    sscanf(input, "%2d/%2d/%4d", &day, &month, &year);

    if(month < 1 || month > 12) {
        printf("Invalid month in date.\n");
        return 1;
    }
    snprintf(output, sizeof(output), "%02d-%s-%04d", day, months[month - 1], year);

    printf("Formatted date: %s\n", output);

    return 0;
}
