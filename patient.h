#ifndef PATIENT_H
#define PATIENT_H

#include "common.h"

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

void patient_menu(int patient_index);
int authenticate_patient();
void view_articles(int patient_index);
void view_medical_check_ups(int patient_index);
void request_consultation(int patient_index);
void view_consultation_status_patient(int patient_index);
void chat_with_doctor(int patient_index, int doctor_index);
void view_doctor_information(int patient_index);

#endif /* PATIENT_H */
