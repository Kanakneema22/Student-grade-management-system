#include <stdio.h>
#include <stdlib.h>

struct student {
    int roll;
    char name[15];
    char surname[15];
    float subject1, subject2, subject3, subject4, subject5;
    float avg;
    float highest;
    float lowest;
    float total;
};

struct student *p;

char getGrade(float average) {
    if (average > 85)
        return 'A';
    else if (average > 70)
        return 'B';
    else if (average > 50)
        return 'C';
    else if (average > 35)
        return 'D';
    else
        return 'F';
}

int main() {
    int i, n;
    printf("Enter number of students: ");
    scanf("%d", &n);
    p = (struct student *)malloc(n * sizeof(struct student));
    for (i = 0; i < n; i++) {
        printf("Enter name of %d student: ", i + 1);
        scanf("%s", p[i].name);
        printf("Enter surname of %d student: ", i + 1);
        scanf("%s", p[i].surname);
        printf("Enter roll number of %d student: ", i + 1);
        scanf("%d", &p[i].roll);
        printf("Enter marks of Science: ");
        scanf("%f", &p[i].subject1);
        printf("Enter marks of Maths: ");
        scanf("%f", &p[i].subject2);
        printf("Enter marks of English: ");
        scanf("%f", &p[i].subject3);
        printf("Enter marks of Hindi: ");
        scanf("%f", &p[i].subject4);
        printf("Enter marks of History: ");
        scanf("%f", &p[i].subject5);

        // Calculate total marks
        p[i].total = p[i].subject1 + p[i].subject2 + p[i].subject3 + p[i].subject4 + p[i].subject5;

        // Calculate average marks
        p[i].avg = p[i].total / 5;

        // Calculate highest and lowest
        p[i].highest = p[i].subject1;
        p[i].lowest = p[i].subject1;
        if (p[i].subject2 > p[i].highest)
            p[i].highest = p[i].subject2;
        if (p[i].subject2 < p[i].lowest)
            p[i].lowest = p[i].subject2;
        if (p[i].subject3 > p[i].highest)
            p[i].highest = p[i].subject3;
        if (p[i].subject3 < p[i].lowest)
            p[i].lowest = p[i].subject3;
        if (p[i].subject4 > p[i].highest)
            p[i].highest = p[i].subject4;
        if (p[i].subject4 < p[i].lowest)
            p[i].lowest = p[i].subject4;
        if (p[i].subject5 > p[i].highest)
            p[i].highest = p[i].subject5;
        if (p[i].subject5 < p[i].lowest)
            p[i].lowest = p[i].subject5;
    }

    printf("\nYou have entered:\n");
    printf("Roll  | Science| Maths | English | Hindi | History | Total  | Average| Grade| Highest | Lowest   | Name\n");
    printf("-------------------------------------------------------------------------------------------------------------\n");
    for (i = 0; i < n; i++) {
        char grade = getGrade(p[i].avg);
        printf("%-6d|  %-6.2f| %-6.2f| %-6.2f  | %-6.2f| %-6.2f  | %-6.2f | %-7.2f| %-5c| %-7.2f |  %-6.2f  |   %s %s\n",
               p[i].roll, p[i].subject1, p[i].subject2, p[i].subject3, p[i].subject4, p[i].subject5,
               p[i].total, p[i].avg, grade, p[i].highest, p[i].lowest, p[i].name, p[i].surname);
    }

    free(p);
    return 0;
}
