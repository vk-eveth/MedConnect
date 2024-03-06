#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATIENTS 20
#define MAX_DOCTORS 10
#define MAX_MESSAGES 30
#define MAX_CHECK_UPS 10
#define MAX_ARTICLES 20

//Profile Structure
struct Profile {
    char name[50];
    int age;
    char medical_history[200];
};

//Articles structure
struct Article {
    char title[100];
    char content[500];
};

//Message structure
struct Message {
    char sender[20];
    char content[200];
};

struct CheckUp {
    int doctor_id;
    char report[200];
};

struct Patient {
    int patient_id;
    struct Profile profile;
    char username[20];
    char password[20];
    struct Message messages[MAX_MESSAGES];
    int message_count;
    struct CheckUp check_ups[MAX_CHECK_UPS];
    int check_up_count;
    int consultation_status[MAX_DOCTORS]; // 0: Pending, 1: Accepted, -1: Declined
};

struct Doctor {
    int doctor_id;
    struct Profile profile;
    char username[20];
    char password[20];
    char specialization[50];
    struct Message messages[MAX_MESSAGES];
    int message_count;
    struct Article articles[MAX_ARTICLES];
    int article_count;
    int consultations[MAX_PATIENTS]; // 0: Pending, 1: Accepted, -1: Declined
};


struct Admin {
    char username[20];
    char password[20];
};

struct Patient patients[MAX_PATIENTS];
struct Doctor doctors[MAX_DOCTORS];
int patient_count = 0;
int doctor_count = 0;
struct Admin admin = {"victor", "1234Admin"};

int authenticate();
int authenticate_doctor();
int authenticate_patient();
void admin_menu();
void doctor_menu(int doctor_index);
void patient_menu(int patient_index);
void add_patient();
void add_doctor();
void view_patient_doctor_list();
void delete_patient();
void delete_doctor();
void display_admin_menu();
//void view_articles(int doctor_index);
void fill_medical_check_up(int doctor_index);
void view_medical_check_ups(int patient_index);
void accept_decline_consultation(int doctor_index);
void view_patient_information(int doctor_index);
void view_doctor_information(int patient_index);
void request_consultation(int patient_index);
void chat_with_user(int doctor_index, int patient_index);
void chat_with_doctor(int patient_index, int doctor_index);
void view_consultation_status_patient(int patient_index);
void view_requested_consultations_doctor(int doctor_index);
void write_article(int doctor_index);
void view_articles(int patient_index);


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

int authenticate() {
    char username[20], password[20];

    printf("Enter admin username: ");
    scanf("%s", username);
    printf("Enter admin password: ");
    scanf("%s", password);

    return (strcmp(username, admin.username) == 0 && strcmp(password, admin.password) == 0);
}

int authenticate_doctor() {
    char username[20], password[20];

    printf("Enter doctor username: ");
    scanf("%s", username);
    printf("Enter doctor password: ");
    scanf("%s", password);

    for (int i = 0; i < doctor_count; i++) {
        if (strcmp(username, doctors[i].username) == 0 && strcmp(password, doctors[i].password) == 0) {
            return i;
        }
    }

    return -1;
}

int authenticate_patient() {
    char username[20], password[20];

    printf("Enter patient username: ");
    scanf("%s", username);
    printf("Enter patient password: ");
    scanf("%s", password);

    for (int i = 0; i < patient_count; i++) {
        if (strcmp(username, patients[i].username) == 0 && strcmp(password, patients[i].password) == 0) {
            return i;
        }
    }

    return -1;
}

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
    printf("Enter patient name: ");
    scanf("%s", patients[patient_count].profile.name);
    printf("Enter patient age: ");
    scanf("%d", &patients[patient_count].profile.age);
    printf("Enter patient medical history: ");
    scanf("%s", patients[patient_count].profile.medical_history);
    printf("Enter patient username: ");
    scanf("%s", patients[patient_count].username);
    printf("Enter patient password: ");
    scanf("%s", patients[patient_count].password);

    patients[patient_count].patient_id = patient_count + 1;
    patient_count++;

    printf("\nPatient added successfully!\n");
}

void add_doctor() {
    printf("Enter doctor name: ");
    scanf("%s", doctors[doctor_count].profile.name);
    printf("Enter doctor age: ");
    scanf("%d", &doctors[doctor_count].profile.age);
    printf("Enter doctor specialization: ");
    scanf("%s", doctors[doctor_count].specialization);
    printf("Enter doctor username: ");
    scanf("%s", doctors[doctor_count].username);
    printf("Enter doctor password: ");
    scanf("%s", doctors[doctor_count].password);

    doctors[doctor_count].doctor_id = doctor_count + 1;
    doctor_count++;

    printf("Doctor added successfully!\n");
}

void view_patient_doctor_list() {
    printf("\n--- Patient List ---\n");
    for (int i = 0; i < patient_count; i++) {
        printf("%d. %s\n", patients[i].patient_id, patients[i].profile.name);
    }

    printf("\n--- Doctor List ---\n");
    for (int i = 0; i < doctor_count; i++) {
        printf("%d. %s\n", doctors[i].doctor_id, doctors[i].profile.name);
    }
}

void delete_patient() {
    int patient_id;
    printf("Enter patient ID to delete: ");
    scanf("%d", &patient_id);

    if (patient_id >= 1 && patient_id <= patient_count) {
        
        for (int i = patient_id - 1; i < patient_count - 1; i++) {
            patients[i] = patients[i + 1];
        }
        patient_count--;

        printf("Patient ID %d deleted successfully!\n", patient_id);
    } else {
        printf("Invalid patient ID. Please try again.\n");
    }
}

void delete_doctor() {
    int doctor_id;
    printf("Enter doctor ID to delete: ");
    scanf("%d", &doctor_id);

    if (doctor_id >= 1 && doctor_id <= doctor_count) {
        
        for (int i = doctor_id - 1; i < doctor_count - 1; i++) {
            doctors[i] = doctors[i + 1];
        }
        doctor_count--;

        printf("Doctor ID %d deleted successfully!\n", doctor_id);
    } else {
        printf("Invalid doctor ID. Please try again.\n");
    }
}

void doctor_menu(int doctor_index) {
    int choice;

    do {
        printf("\n--- Doctor Menu ---\n");
        printf("1. Record Check-up\n");
        printf("2.Write article\n");
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

void view_articles(int patient_index) {
    printf("\n--- Health Articles ---\n");
    for (int i = 0; i < doctor_count; i++) {
        struct Doctor *doctor = &doctors[i];
        for (int j = 0; j < doctor->article_count; j++) {
            printf("Doctor: %s\nTitle: %s\nContent: %s\n", doctor->profile.name, doctor->articles[j].title, doctor->articles[j].content);
            printf("-----------------------------------\n");
        }
    }
}

void fill_medical_check_up(int doctor_index) {
    printf("\n--- Fill Medical Check-up ---\n");
    int patient_id;
    printf("Enter Patient ID: ");
    scanf("%d", &patient_id);

    if (patient_id >= 1 && patient_id <= patient_count) {
        printf("Enter Medical Report: ");
        scanf(" %[^\n]", patients[patient_id - 1].check_ups[patients[patient_id - 1].check_up_count].report);
        patients[patient_id - 1].check_ups[patients[patient_id - 1].check_up_count].doctor_id = doctors[doctor_index].doctor_id;
        patients[patient_id - 1].check_up_count++;
        printf("Medical check-up filled successfully.\n");
    } else {
        printf("Invalid Patient ID.\n");
    }
}

void view_medical_check_ups(int patient_index) {
    printf("\n--- Medical Check-ups ---\n");
    for (int i = 0; i < patients[patient_index].check_up_count; i++) {
        printf("Doctor ID: %d, Report: %s\n", patients[patient_index].check_ups[i].doctor_id, patients[patient_index].check_ups[i].report);
    }
}

void accept_decline_consultation(int doctor_index) {
    printf("\n--- Accept/Decline Consultation ---\n");
    int patient_id, status;
    printf("Enter Patient ID: ");
    scanf("%d", &patient_id);

    if (patient_id >= 1 && patient_id <= patient_count) {
        printf("Enter Status (0: Pending, 1: Accepted, -1: Declined): ");
        scanf("%d", &status);
        doctors[doctor_index].consultations[patient_id - 1] = status;
        printf("Consultation status updated successfully.\n");
    } else {
        printf("Invalid Patient ID.\n");
    }
}

void view_requested_consultations_doctor(int doctor_index) {
    printf("\n--- Requested Consultations ---\n");
    for (int i = 0; i < patient_count; i++) {
        if (doctors[doctor_index].consultations[i] == 0) {
            printf("Patient ID: %d, Status: Pending\n", i + 1);
        } else if (doctors[doctor_index].consultations[i] == 1) {
            printf("Patient ID: %d, Status: Accepted\n", i + 1);
        } else if (doctors[doctor_index].consultations[i] == -1) {
            printf("Patient ID: %d, Status: Declined\n", i + 1);
        }
    }
}

void view_patient_information(int doctor_index) {
    printf("\n--- Patient Information ---\n");
    int patient_id;
    printf("Enter Patient ID: ");
    scanf("%d", &patient_id);

    if (patient_id >= 1 && patient_id <= patient_count) {
        struct Patient patient = patients[patient_id - 1];
        printf("Name: %s\nAge: %d\nMedical History: %s\n", patient.profile.name, patient.profile.age, patient.profile.medical_history);
    } else {
        printf("Invalid Patient ID.\n");
    }
}

void view_doctor_information(int patient_index) {
     printf("\n--- Doctor Information ---\n");
    for (int i = 0; i < doctor_count; i++) {
        struct Doctor doctor = doctors[i];
        printf("Doctor ID: %d\nName: %s\nSpecialization: %s\n", doctor.doctor_id, doctor.profile.name, doctor.specialization);
        printf("----------------------------\n");
    }
}

void write_article(int doctor_index) {
    if (doctors[doctor_index].article_count >= MAX_ARTICLES) {
        printf("Maximum number of articles reached.\n");
        return;
    }

    printf("\n--- Write Article ---\n");
    struct Article *article = &doctors[doctor_index].articles[doctors[doctor_index].article_count];
    printf("Enter article title: ");
    scanf(" %[^\n]", article->title);
    printf("Enter article content: ");
    scanf(" %[^\n]", article->content);
    doctors[doctor_index].article_count++;
    printf("Article written successfully.\n");
}

void request_consultation(int patient_index) {
    printf("\n--- Request Consultation ---\n");
    int doctor_id;
    printf("Enter Doctor ID: ");
    scanf("%d", &doctor_id);

    if (doctor_id >= 1 && doctor_id <= doctor_count) {
        if (doctors[doctor_id - 1].consultations[patient_index] == 0) {
            doctors[doctor_id - 1].consultations[patient_index] = 1; // Set consultation status to Accepted
            printf("Consultation requested successfully.\n");
        } else {
            printf("Consultation request already sent or doctor not available.\n");
        }
    } else {
        printf("Invalid Doctor ID.\n");
    }
}

void chat_with_user(int doctor_index, int patient_index) {
    char message[200];
    printf("Enter message: ");
    scanf(" %[^\n]", message);

    strcpy(patients[patient_index - 1].messages[patients[patient_index - 1].message_count].sender, doctors[doctor_index].profile.name);
    strcpy(patients[patient_index - 1].messages[patients[patient_index - 1].message_count].content, message);
    patients[patient_index - 1].message_count++;

    printf("Message sent.\n");
}

void chat_with_doctor(int patient_index, int doctor_index) {
    char message[200];
    printf("Enter message: ");
    scanf(" %[^\n]", message);

    strcpy(doctors[doctor_index - 1].messages[doctors[doctor_index - 1].message_count].sender, patients[patient_index].profile.name);
    strcpy(doctors[doctor_index - 1].messages[doctors[doctor_index - 1].message_count].content, message);
    doctors[doctor_index - 1].message_count++;

    printf("Message sent.\n");
}

void view_consultation_status_patient(int patient_index) {
    printf("\n--- Consultation Status ---\n");
    for (int i = 0; i < doctor_count; i++) {
        if (doctors[i].consultations[patient_index] == 0) {
            printf("Doctor ID: %d, Status: Pending\n", i + 1);
        } else if (doctors[i].consultations[patient_index] == 1) {
            printf("Doctor ID: %d, Status: Accepted\n", i + 1);
        } else if (doctors[i].consultations[patient_index] == -1) {
            printf("Doctor ID: %d, Status: Declined\n", i + 1);
        }
    }
}

void display_admin_menu() {
    printf("\n--- Admin Menu ---\n");
    printf("1. Add Patient\n");
    printf("2. Add Doctor\n");
    printf("3. View Patient/Doctor List\n");
    printf("4. Delete Patient\n");
    printf("5. Delete Doctor\n");
    printf("0. Exit\n");
}
