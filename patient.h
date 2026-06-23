#ifndef PATIENT_H
#define PATIENT_H

#define MAX_NAME 100
#define MAX_GENDER 10
#define AADHAAR_LEN 12

typedef struct Patient {
    char name[MAX_NAME];
    char aadhaar[AADHAAR_LEN + 1];
    int age;
    char gender[MAX_GENDER];
    char hospital[100];
    char doctor[100];
    struct Patient *next;
} Patient;

Patient *addPatient(Patient *head);
void listPatients(Patient *head);
Patient *findPatient(Patient *head, const char *aadhaar);
void freePatients(Patient *head);

#endif