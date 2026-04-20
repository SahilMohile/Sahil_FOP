#include <stdio.h>
#include <string.h>

struct EMPLOYEE 
{
    char name[50];
    char design[30];
    char gender; 
    char doj[15];
    float salary;
};

int main() 
{
    struct EMPLOYEE emp[100];
    int n, i;
    int male = 0, female = 0;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    
    for (i = 0; i < n; i++) 
	{
        printf("\nDetails for Employee %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", emp[i].name);
        printf("Designation: ");
        scanf("%s", emp[i].design);
        printf("Gender (M/F): ");
        scanf(" %c", &emp[i].gender);
        printf("Date of Joining (DD/MM/YYYY): ");
        scanf("%s", emp[i].doj);
        printf("Salary: ");
        scanf("%f", &emp[i].salary);
    }

   
    printf("\na) Total employees: %d\n", n);

    
    for (i = 0; i < n; i++) 
	{
        if (emp[i].gender == 'M' || emp[i].gender == 'm') male++;
        else if (emp[i].gender == 'F' || emp[i].gender == 'f') female++;
    }
    printf("b) Male: %d, Female: %d\n", male, female);

    
    printf("c) Employees with salary > 10,000: ");
    for (i = 0; i < n; i++) 
	{
        if (emp[i].salary > 10000) 
		{
            printf("%s ", emp[i].name);
        }
    }

    
    printf("\nd) Assistant Managers: ");
    for (i = 0; i < n; i++) 
	{
        if (strcmp(emp[i].design, "AsstManager") == 0) 
		{
            printf("%s ", emp[i].name);
        }
    }
    printf("\n");

    return 0;
}

