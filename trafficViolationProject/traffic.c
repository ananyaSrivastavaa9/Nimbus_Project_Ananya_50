#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char plate[20];
    char violation_type[60];
    float base_fine;
    int paid;
    int repeat_count;
} Record;

void insertRecord(Record *list, int *size) {
    printf("\n--Add New Violation--\n");
    printf("License Number: ");
    scanf("%s", list[*size].plate);

    printf("Offense Description: ");
    scanf(" %[^\n]", list[*size].violation_type);

    printf("Initial Fine Amount: ");
    scanf("%f", &list[*size].base_fine);

    list[*size].paid = 0;
    list[*size].repeat_count = 1;

    (*size)++;
    printf("Record added successfully.\n");
}

void updatePenalties(Record *list, int size) {
    for (int i = 0; i < size; i++) {
        if (list[i].repeat_count > 1) {
            float newFine = list[i].base_fine * list[i].repeat_count;
            list[i].base_fine = newFine;
        }
    }
    printf("Penalties updated for repeat offenders.\n");
}

void setPaymentStatus(Record *list, int size, const char *plateNo) {
    for (int i = 0; i < size; i++) {
        if (strcmp(list[i].plate, plateNo) == 0) {
            list[i].paid = 1;
            printf("Payment status updated to PAID.\n");
            return;
        }
    }
    printf("No record found for the given license.\n");
}

void showSummary(const Record *list, int size) {
    float revenue = 0;

    printf("\n== Violation Summary Report ==\n");

    for (int i = 0; i < size; i++) {
        printf("License: %-12s | Offense: %-20s | Fine: ₹%.2f | Status: %s\n",
            list[i].plate,
            list[i].violation_type,
            list[i].base_fine,
            list[i].paid ? "Paid" : "Unpaid"
        );

        if (list[i].paid)
            revenue += list[i].base_fine;
    }

    printf("\nTotal Revenue Collected: ₹%.2f\n", revenue);
}

void saveToDisk(Record *list, int size) {
    FILE *fp = fopen("traffic_data.txt", "w");

    if (!fp) {
        printf("Unable to open file for writing.\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        fprintf(fp, "%s,%s,%.2f,%d,%d\n",
                list[i].plate,
                list[i].violation_type,
                list[i].base_fine,
                list[i].paid,
                list[i].repeat_count);
    }

    fclose(fp);
    printf("Data saved successfully to traffic_data.txt\n");
}

int main() {
    Record *records = malloc(sizeof(Record) * 120);
    int total = 0;
    int option;
    char searchPlate[20];

    printf("== Traffic Violation & Penalty System ==\n");

    do {
        printf("\nMenu:\n");
        printf("1. Add Violation Record\n");
        printf("2. Apply Repeat-Offender Penalties\n");
        printf("3. Mark Violation as Paid\n");
        printf("4. Display Summary Report\n");
        printf("5. Save Data & Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                insertRecord(records, &total);
                break;

            case 2:
                updatePenalties(records, total);
                break;

            case 3:
                printf("Enter license to update payment: ");
                scanf("%s", searchPlate);
                setPaymentStatus(records, total, searchPlate);
                break;

            case 4:
                showSummary(records, total);
                break;

            case 5:
                saveToDisk(records, total);
                break;

            default:
                printf("Invalid option. Try again.\n");
        }

    } while (option != 5);

    free(records);
    return 0;
}