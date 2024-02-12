#include <stdio.h>
#include <string.h>
#include "patient.h"
#include "main.h"

void patient_menu(int patient_index) {
    int choice;

    do {
        printf("\n--- Patient Menu ---\n");
        printf("1. View Articles\n");
        printf("2. View Medical Check-ups\n");
        printf("3. Request Consultation\n");
        printf("4. View Consultation Status\n");
        printf("5. Chat with Doctor\n");
        printf("6. View Chat History\n");
        printf("7. View Doctor Information\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                view_articles(patient_index);
                break;
            case 2:
                view_medical_check_ups(patient_index);
                break;
            case 3:
                request_consultation(patient_index);
                break;
            case 4:
                view_consultation_status_patient(patient_index);
                break;
            case 5:
                {
                    int doctor_index;
                    printf("Enter doctor ID to chat with: ");
                    scanf("%d", &doctor_index);
                    chat_with_doctor(patient_index, doctor_index);
                }
                break;
            case 6:
                {
                    printf("\n--- Chat History ---\n");
                    for (int i = 0; i < patients[patient_index].message_count; i++) {
                        printf("%s: %s\n", patients[patient_index].messages[i].sender, patients[patient_index].messages[i].content);
                    }
                }
                break;
            case 7:
                view_doctor_information(patient_index);
                break;    
            case 0:
                printf("Exiting patient menu.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);
}

int authenticate_patient() {
    // Patient authentication implementation
}

void view_articles(int patient_index) {
    // View articles implementation
}

void view_medical_check_ups(int patient_index) {
    // View medical check-ups implementation
}

void request_consultation(int patient_index) {
    // Request consultation implementation
}

void view_consultation_status_patient(int patient_index) {
    // View consultation status implementation
}

void chat_with_doctor(int patient_index, int doctor_index) {
    // Chat with doctor implementation
}

void view_doctor_information(int patient_index) {
    // View doctor information implementation
}
