#ifndef PATIENT_H
#define PATIENT_H

void patient_menu(int patient_index);
int authenticate_patient();
void view_articles(int patient_index);
void view_medical_check_ups(int patient_index);
void request_consultation(int patient_index);
void view_consultation_status_patient(int patient_index);
void chat_with_doctor(int patient_index, int doctor_index);
void view_doctor_information(int patient_index);

#endif
