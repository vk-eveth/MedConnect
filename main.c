#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "admin.h"
#include "doctor.h"
#include "patient.h"

int main() {
    int user_type;
   
    do {
        printf("\n--- HealthConnect Main Menu ---\n");
        printf("1. Admin Login\n");
        printf("2. Doctor Login\n");
        printf("3. Patient Login\n");
        printf("0. Exit\n");
        printf("\nEnter your choice: ");
        
        // Validate user input
        while (scanf("%d", &user_type) != 1 || (user_type < 0 || user_type > 3)) {
            printf("Invalid input. Please enter a valid choice: ");
            fflush(stdin);
        }

        switch (user_type) {
            case 1:
                if (authenticate()) {
                    admin_menu();
                } else {
                    printf("\nInvalid admin credentials. Please try again.\n");
                }
                break;
            case 2:
                {
                    int doctor_index = authenticate_doctor();
                    if (doctor_index >= 0) {
                        doctor_menu(doctor_index);
                    } else {
                        printf("\nInvalid doctor credentials. Please try again.\n");
                    }
                }
                break;
            case 3:
                {
                    int patient_index = authenticate_patient();
                    if (patient_index >= 0) {
                        patient_menu(patient_index);
                    } else {
                        printf("\nInvalid patient credentials. Please try again.\n");
                    }
                }
                break;
            case 0:
                printf("\nExiting program. Thank you!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (user_type != 0);

    return 0;
}
