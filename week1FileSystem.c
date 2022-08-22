#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct emp
{
    char name[50];
    float salary;
    int age;
    int id;
};
struct emp e , e1;
long int size = sizeof(e);
FILE *fp, *ft;

void addrecord()
{
    fseek(fp, 0, SEEK_END);

    printf("\nEnter Name : ");
    scanf("%s", e.name);

    printf("\nEnter Age : ");
    scanf("%d", &e.age);

    printf("\nEnter Salary : ");
    scanf("%f", &e.salary);

    printf("\nEnter id number ");
    scanf("%d", &e.id);

    fwrite(&e, size, 1, fp);
}

void deleterecord()
{

    char empname[50];

    printf("\nEnter employee "
           "name to delete : ");
    scanf("%s", empname);

    ft = fopen("dell.txt", "wb");
    rewind(fp);

    while (fread(&e, size, 1, fp) == 1)
    {
        if (strcmp(e.name, empname) != 0)
            fwrite(&e, size, 1, ft);
    }

    fclose(fp);
    fclose(ft);
    remove("data.txt");
    rename("dell.txt", "data.txt");
    fp = fopen("data.txt", "rb+");
}
void insert_by_name()
{
    char empname3[50];

    printf("\nEnter employee name after which new record need to insert : ");
    scanf("%s", empname3);

    ft = fopen("dell.txt", "wb");
    rewind(fp);

    while (fread(&e, size, 1, fp) == 1)
    {
        if (strcmp(e.name, empname3) != 0)
        {
            fwrite(&e, size, 1, ft);
        }
        else
        {
            fwrite(&e, size, 1, ft);
            printf("\nEnter new record Name : ");
            scanf("%s", e1.name);

            printf("\nEnter new record Age : ");
            scanf("%d", &e1.age);

            printf("\nEnter new record Salary : ");
            scanf("%f", &e1.salary);

            printf("\nEnter new record id number ");
            scanf("%d", &e1.id);
            fwrite(&e1, size, 1, ft);
        }
    }
    fclose(fp);
    fclose(ft);
    remove("data.txt");
    rename("dell.txt", "data.txt");
    fp = fopen("data.txt", "rb+");
}

void displayrecord()
{

    rewind(fp);
    printf("\nNAME\t\tAGE\t\tSALARY\t\tID\n");
    while (fread(&e, size, 1, fp) == 1)
    {
        printf("\n%s\t\t%d\t\t%.2f\t%10d", e.name, e.age, e.salary, e.id);

        printf("\n\n\n\t");
    }
}
void modifyrecord()
{

    char empname[50];
    printf("\nEnter employee name to modify : ");
    scanf("%s", empname);

    rewind(fp);
    while (fread(&e, size, 1, fp) == 1)
    {
        if (strcmp(e.name, empname) == 0)
        {
            printf("\nEnter new name:");
            scanf("%s", e.name);
            printf("\nEnter new age :");
            scanf("%d", &e.age);
            printf("\nEnter new salary :");
            scanf("%f", &e.salary);
            printf("\nEnter new id number :");
            scanf("%d", &e.id);

            fseek(fp, -size, SEEK_CUR);
            fwrite(&e, size, 1, fp);
            break;
        }
    }
}
void searchbyname()
{
    int option;
    int on = 0;
    printf("1.search by name\n2.search by salary\n3.search by age\n4.search by id\n enter your option\n");
    scanf("%d", &option);
    switch (option)
    {
    case 1:
    {
        char empname2[50];
        printf("\nEnter employee name to search : ");
        scanf("%s", empname2);
        rewind(fp);

        while (fread(&e, size, 1, fp) == 1)
        {
            if (strcmp(e.name, empname2) == 0)
                printf("\n%s\t\t%d\t\t%.2f\t%10d", e.name, e.age, e.salary, e.id);
            on = on + 1;
        }
    }
    break;

    case 2:
    {
        int emps;
        int k;
        int i;
        printf("\nEnter employee salary to search : ");
        scanf("%d", &emps);
        rewind(fp);

        while (fread(&e, size, 1, fp) == 1)
        {
            k = e.salary;

            if (k == emps)
            {
                on = on + 1;
                printf("\n%s\t\t%d\t\t%.2f\t%10d", e.name, e.age, e.salary, e.id);
            }
        }
    }
    break;
    case 3:
    {
        int emps;
        int k;
        int i;
        printf("\nEnter employee age to search : ");
        scanf("%d", &emps);
        rewind(fp);

        while (fread(&e, size, 1, fp) == 1)
        {
            k = e.age;

            if (k == emps)
            {
                on = on + 1;
                printf("\n%s\t\t%d\t\t%.2f\t%10d", e.name, e.age, e.salary, e.id);
            }
        }
    }
    break;
    case 4:
    {

        int emps;
        int k;
        int i;
        printf("\nEnter employee id to search : ");
        scanf("%d", &emps);
        rewind(fp);

        while (fread(&e, size, 1, fp) == 1)
        {
            k = e.id;

            if (k == emps)
            {
                on = on + 1;
                printf("\n%s\t\t%d\t\t%.2f\t%10d", e.name, e.age, e.salary, e.id);
            }
        }
    }
    break;
    default:
        printf("invalid option..\n");
        on=on+1;
        break;
    }
    if (on == 0)
    {
        printf("The given search item cannot be matched with any record");
    }
}

int main()
{
    int choice;

    fp = fopen("data.txt", "rb+");
    if (fp == NULL)
    {
        fp = fopen("data.txt", "wb+");
    }
    if (fp == NULL)
    {
        printf("\nCannot open file...");
        exit(1);
    }

    while (1)
    {
        printf("\n1. ADD RECORD\n");
        printf("2. DELETE RECORD\n");
        printf("3. DISPLAY RECORDS\n");

        printf("4. MODIFY RECORD\n");

        printf("6. SEARCH(by name,id,age...)\n7. INSERT DATA\n5. EXIT");
        printf("\nENTER YOUR CHOICE...\n");
        fflush(stdin);
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:

            addrecord();
            break;

        case 2:
            deleterecord();
            break;

        case 3:

            displayrecord();
            break;

        case 4:

            modifyrecord();
            break;

        case 5:
            fclose(fp);
            exit(0);
            break;
        case 6:
            searchbyname();
            break;
        case 7:
            insert_by_name();
            break;

        default:
            printf("\nINVALID CHOICE...\n");
        }
    }

    return 0;
}
