#include <stdio.h>
#include <string.h>

struct medicine
{   
    int no;
    char medicineCode[50];
    char medicineName[100];
    char disease[50];
    int stock;
    float price;
};

void Input();
void Sell();


int main(int argc, char const *argv[])
{   


    int choice;
    int num_medicines = 0;
    int last_no = 0;

    struct medicine medicines[100];
    
    do
    {
         printf("                              Sunib Hospital\n");

         printf("\n");

    printf("+---------------------------------------------------------------------------+\n");
    printf("|No. |  Medicine Code |     Medicine Name    |  Disease | Stock |   Price   |\n");
    printf("+---------------------------------------------------------------------------+\n");

    for (int i = 0; i < num_medicines; i++) {
            printf("|%-4d|%-16s|%-22s|%-10s|%-7d|%-11.2f|\n", medicines[i].no, medicines[i].medicineCode,
                   medicines[i].medicineName, medicines[i].disease, medicines[i].stock,
                   medicines[i].price);
    printf("+---------------------------------------------------------------------------+\n");
        }
    printf("\n");

    printf("Menu :\n");

    printf("[1.] Add stock\n");
    printf("[2.] Sell\n");
    printf("[3.] Exit\n");

    printf("\n");

    printf("Input Choice (1-3)\n");
    

    scanf("%d",&choice);

    switch (choice)
    {
    case 1:
        Input(medicines, &num_medicines, &last_no);
        break;
    case 2:
        Sell(medicines, num_medicines);
        break;
    case 3:
        printf("Exited!\n");
        break;

    default:
        printf("Error[Invalid Choice]");
        break;
    }
    } while (choice != 3);
    
   

    return 0;
}

void Input(struct medicine *medicines, int *num_medicines, int *last_no) {
    printf("Enter Medicine Details:\n");
    printf("Medicine Code: ");
    scanf("%s", medicines[*num_medicines].medicineCode);
    printf("Medicine Name: ");
    scanf("%s", medicines[*num_medicines].medicineName);
    printf("Disease: ");
    scanf("%s", medicines[*num_medicines].disease);
    printf("Stock: ");
    scanf("%d", &medicines[*num_medicines].stock);
    printf("Price: ");
    scanf("%f", &medicines[*num_medicines].price);

   
    (*last_no)++;
    medicines[*num_medicines].no = *last_no;

    
    (*num_medicines)++;
}


void Sell(struct medicine *medicines, int num_medicines) {
    char code[50];
    int quantity;

    printf("Enter Medicine Code: ");
    scanf("%s", code);

   
    int found = 0;
    for (int i = 0; i < num_medicines; ++i) {
        if (strcmp(medicines[i].medicineCode, code) == 0) {
            found = 1;
            printf("Enter Quantity to sell: ");
            scanf("%d", &quantity);

          
            if (quantity <= medicines[i].stock) {
               
                medicines[i].stock -= quantity;
                printf("Total Price: %.2f\n", quantity * medicines[i].price);
            } else {
                printf("Insufficient Stock!\n");
            }
            break;
        }
    }

    if (!found)
        printf("Medicine not found!\n");
}
