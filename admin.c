#include <stdio.h>
#include <string.h>
#include "admin.h"

//admin structure
struct Admin {
    char username[20];
    char password[20];
};

struct Admin admin = {"victor", "1234Admin"};

//Admin menu
void admin_menu() {
    int choice;

    do {
        display_admin_menu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_patient();
                break;
            case 2:
                add_doctor();
                break;
            case 3:
                view_patient_doctor_list();
                break;
            case 4:
                delete_patient();
                break;
            case 5:
                delete_doctor();
                break;
            case 0:
                printf("Exiting admin menu.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);
}

void add_patient() {
    // Add patient implementation
}

void add_doctor() {
    // Add doctor implementation
}

void view_patient_doctor_list() {
    // View patient/doctor list implementation
}

void delete_patient() {
    // Delete patient implementation
}

void delete_doctor() {
    // Delete doctor implementation
}

void display_admin_menu() {
    // Display admin menu implementation
}

int authenticate() {
    // Admin authentication implementation
}
