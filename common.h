#ifndef COMMON_H
#define COMMON_H

#define MAX_PATIENTS 20
#define MAX_DOCTORS 10
#define MAX_MESSAGES 30
#define MAX_CHECK_UPS 10
#define MAX_ARTICLES 20

struct Profile {
    char name[50];
    int age;
    char medical_history[200];
};

struct Article {
    char title[100];
    char content[500];
};

struct Message {
    char sender[20];
    char content[200];
};

struct CheckUp {
    int doctor_id;
    char report[200];
};

#endif /* COMMON_H */
