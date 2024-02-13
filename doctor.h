#ifndef DOCTOR_H
#define DOCTOR_H

#include "common.h"

struct Doctor {
    int doctor_id;
    struct Profile profile;
    char username[20];
    char password[20];
    struct Message messages[MAX_MESSAGES];
    int message_count;
    struct Article articles[MAX_ARTICLES];
    int article_count;
    int consultations[MAX_PATIENTS]; // 0: Pending, 1: Accepted, -1: Declined
};

void doctor_menu(int doctor_index);
int authenticate_doctor();
void fill_medical_check_up(int doctor_index);
void accept_decline_consultation(int doctor_index);
void view_requested_consultations_doctor(int doctor_index);
void view_patient_information(int doctor_index);
void write_article(int doctor_index);
void chat_with_user(int doctor_index, int patient_index);

#endif /* DOCTOR_H */
