#include <stdio.h>
#include <string.h>
#include "doctor.h"
#include "main.h"

void doctor_menu(int doctor_index) {
    int choice;

    do {
        printf("\n--- Doctor Menu ---\n");
        printf("1. Record Check-up\n");
        printf("2. Write article\n");
        printf("3. View Articles\n");
        printf("4. Accept/Decline Consultation\n");
        printf("5. View Requested Consultations\n");
        printf("6. Chat with Patient\n");
        printf("7. View Chat History\n");
        printf("8. View Patient Information\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                fill_medical_check_up(doctor_index);
                break;
            case 2:
                write_article(doctor_index);
                break;
            case 3:
                view_articles(doctor_index);
                break;
            case 4:
                accept_decline_consultation(doctor_index);
                break;
            case 5:
                view_requested_consultations_doctor(doctor_index);
                break;
            case 6:
                {
                    int patient_index;
                    printf("Enter patient ID to chat with: ");
                    scanf("%d", &patient_index);
                    chat_with_user(doctor_index, patient_index);
                }
                break;
            case 7:
                {
                    printf("\n--- Chat History ---\n");
                    for (int i = 0; i < doctors[doctor_index].message_count; i++) {
                        printf("%s: %s\n", doctors[doctor_index].messages[i].sender, doctors[doctor_index].messages[i].content);
                    }
                }
                break;
            case 8:
                view_patient_information(doctor_index);
                break;    
            case 0:
                printf("Exiting doctor menu.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);
}

int authenticate_doctor() {
    // Doctor authentication implementation
}

void fill_medical_check_up(int doctor_index) {
    // Fill medical check-up implementation
}

void view_articles(int doctor_index) {
    // View articles implementation
}

void accept_decline_consultation(int doctor_index) {
    // Accept/decline consultation implementation
}

void view_requested_consultations_doctor(int doctor_index) {
    // View requested consultations implementation
}

void view_patient_information(int doctor_index) {
    // View patient information implementation
}

void write_article(int doctor_index) {
    // Write article implementation
}

void chat_with_user(int doctor_index, int patient_index) {
    // Chat with patient implementation
}
