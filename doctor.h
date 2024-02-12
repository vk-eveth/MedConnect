#ifndef DOCTOR_H
#define DOCTOR_H

void doctor_menu(int doctor_index);
int authenticate_doctor();
void fill_medical_check_up(int doctor_index);
void view_articles(int patient_index);
void accept_decline_consultation(int doctor_index);
void view_requested_consultations_doctor(int doctor_index);
void view_patient_information(int doctor_index);
void write_article(int doctor_index);
void chat_with_user(int doctor_index, int patient_index);

#endif
