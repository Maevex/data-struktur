#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

#define SIZE 1007

struct Data{
    char medicineID[20]; // Medicine ID
    char medicineName[51]; // 50 characters + 1 for null terminator
    char manufacturerName[56]; // 50 characters + " Ltd." + null terminator
    char registrationNumber[11]; // 10 digits + null terminator
    char batchLotNumber[100]; // Assumed to be large enough
    struct Data *next;
};

// Function to validate if a string consists of only digits
int isNumeric(const char *str) {
    while (*str) {
        if (!isdigit(*str)) {
            return 0;
        }
        str++;
    }
    return 1;
}

// Function to generate unique Medicine ID
void generateMedicineID(struct Data *data) {
    static int lastMedicineID = 0; // Last inserted Medicine ID number
    lastMedicineID++; // Increase Medicine ID number
    sprintf(data->medicineID, "M%05d-%s-%c%c", lastMedicineID, data->registrationNumber, toupper(data->manufacturerName[0]), toupper(data->medicineName[0]));
}

void insert(struct Data **table)
{
    char medicineName[51];
    char manufacturerName[56];
    char registrationNumber[11];
    char batchLotNumber[100];
    
    // Input Medicine Name
    do {
        printf("Medicine Name (between 5 and 50 characters): ");
        scanf("%50s", medicineName);
        if (strlen(medicineName) < 5 || strlen(medicineName) > 50) {
            printf("Medicine Name must be between 5 and 50 characters.\n");
        }
    } while (strlen(medicineName) < 5 || strlen(medicineName) > 50);

    // Input Manufacturer Name
    printf("Manufacturer Name: ");
    scanf("%50s", manufacturerName);

    // Input Registration Number
    do {
        printf("Registration Number (10 digits): ");
        scanf("%10s", registrationNumber);
        if (strlen(registrationNumber) != 10 || !isNumeric(registrationNumber)) {
            printf("Registration Number must be numeric and its length must be 10 digits.\n");
        }
    } while (strlen(registrationNumber) != 10 || !isNumeric(registrationNumber));

    // Input Batch/Lot Number
    do {
        printf("Batch/Lot Number (at least 16 characters): ");
        scanf("%99s", batchLotNumber);
        if (strlen(batchLotNumber) < 16) {
            printf("Batch/Lot Number must be at least 16 characters.\n");
        }
    } while (strlen(batchLotNumber) < 16);
    
    // Allocate memory for new data
    struct Data *newData = (struct Data*)malloc(sizeof(struct Data));
    if (newData == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    
    // Copy data into new node
    strcpy(newData->medicineName, medicineName);
    strcpy(newData->manufacturerName, manufacturerName);
    strcpy(newData->registrationNumber, registrationNumber);
    strcpy(newData->batchLotNumber, batchLotNumber);
    generateMedicineID(newData); // Generate unique Medicine ID
    
    // Calculate hash index
    int key = 0;
    for (int i = 0; newData->medicineID[i] != '\0'; i++) {
        key += newData->medicineID[i]; // Sum of ASCII values of Medicine ID
    }
    key %= SIZE; // Apply hash function
    
    // Insert data into the hash table
    newData->next = table[key];
    table[key] = newData;
    
    printf("Insert Success\n");
}

void view(struct Data **table)
{
    int hasData = 0; // Flag to mark if there's any data available

    printf("The data\n");
    printf("Medicine ID    | Medicine Name           | Manufacturer Name      | Registration Number  | Batch/Lot Number\n");
    printf("------------------------------------------------------------------------------------------------------------\n");

    // Traverse the hash table
    for(int i = 0; i < SIZE; i++){
        struct Data *ptr = table[i];
        while(ptr != NULL)
        {
            printf("%-15s | %-23s | %-21s | %-19s | %s\n", ptr->medicineID, ptr->medicineName, ptr->manufacturerName, ptr->registrationNumber, ptr->batchLotNumber);
            ptr = ptr->next;
            hasData = 1;
        }
    }

    if (!hasData) {
        printf("There is no medicine(s)\n");
    }
}

// Function to remove data by Medicine ID
void removeByMedicineID(struct Data **table, const char *medicineID) {
    int key = 0;
    for (int i = 0; medicineID[i] != '\0'; i++) {
        key += medicineID[i]; // Sum of ASCII values of Medicine ID
    }
    key %= SIZE; // Apply hash function
    
    struct Data *prev = NULL;
    struct Data *current = table[key];
    
    while (current != NULL && strcmp(current->medicineID, medicineID) != 0) {
        prev = current;
        current = current->next;
    }
    
    if (current == NULL) {
        printf("Medicine ID %s not found.\n", medicineID);
        return;
    }
    
    if (prev == NULL) {
        table[key] = current->next;
    } else {
        prev->next = current->next;
    }
    
    free(current);
    printf("Medicine ID %s removed successfully.\n", medicineID);
}

int main()
{
    struct Data *table[SIZE] = {NULL}; // Initialize hash table
    
    int pilih;
    do
    {
        system("cls");
        printf("Sunib Hospital\n");
        printf("==============\n");
        printf("1. View Medicines\n");
        printf("2. Insert Medicines\n");
        printf("3. Remove Medicines\n");
        printf("4. Exit\n");
        printf("Choose >> ");
        scanf("%d", &pilih);
        
        switch(pilih)
        {
            case 1:{
                view(table);    
                getch();
                break;
            }
            case 2:{
                insert(table);
                getch();
                break;
            }
            case 3:{
                char medicineID[20];
                printf("Enter Medicine ID to remove: ");
                scanf("%19s", medicineID);
                removeByMedicineID(table, medicineID);
                getch();
                break;
            }
            default:{
                break;
            }
        }
            
    }while(pilih != 4);    
    
    return 0;
}
