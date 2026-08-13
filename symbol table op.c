#include <stdio.h>
#include <string.h>

struct Symbol
{
    char name[20];
    char type[20];
    int address;
};

struct Symbol table[50];
int count = 0;

void insert()
{
    printf("Enter symbol name: ");
    scanf("%s", table[count].name);

    printf("Enter symbol type: ");
    scanf("%s", table[count].type);

    printf("Enter address: ");
    scanf("%d", &table[count].address);

    count++;

    printf("Symbol inserted successfully.\n");
}

void display()
{
    int i;

    if (count == 0)
    {
        printf("Symbol table is empty.\n");
        return;
    }

    printf("\nSymbol Table\n");
    printf("-----------------------------\n");
    printf("Name\tType\tAddress\n");
    printf("-----------------------------\n");

    for (i = 0; i < count; i++)
    {
        printf("%s\t%s\t%d\n",
               table[i].name,
               table[i].type,
               table[i].address);
    }
}

void search()
{
    char name[20];
    int i, found = 0;

    printf("Enter symbol to search: ");
    scanf("%s", name);

    for (i = 0; i < count; i++)
    {
        if (strcmp(table[i].name, name) == 0)
        {
            printf("Symbol found.\n");
            printf("Name: %s\n", table[i].name);
            printf("Type: %s\n", table[i].type);
            printf("Address: %d\n", table[i].address);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Symbol not found.\n");
}

void deleteSymbol()
{
    char name[20];
    int i, j, found = 0;

    printf("Enter symbol to delete: ");
    scanf("%s", name);

    for (i = 0; i < count; i++)
    {
        if (strcmp(table[i].name, name) == 0)
        {
            for (j = i; j < count - 1; j++)
                table[j] = table[j + 1];

            count--;
            found = 1;

            printf("Symbol deleted successfully.\n");
            break;
        }
    }

    if (!found)
        printf("Symbol not found.\n");
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n--- SYMBOL TABLE ---\n");
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Search\n");
        printf("4. Delete\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insert();
                break;

            case 2:
                display();
                break;

            case 3:
                search();
                break;

            case 4:
                deleteSymbol();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}