#ifndef ADMIN_H
#define ADMIN_H

#include "common.h"

struct Admin {
    char username[20];
    char password[20];
};

void admin_menu();
int authenticate();
void add_patient();
void add_doctor();
void view_patient_doctor_list();
void delete_patient();
void delete_doctor();
void display_admin_menu();

#endif /* ADMIN_H */
