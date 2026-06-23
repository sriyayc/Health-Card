#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "patient.h"

int isAadhaarValid(const char *aadhaar) {
    if (strlen(aadhaar) != 12) return 0;
    for (int i = 0; i < 12; i++) {
        if (aadhaar[i] < '0' || aadhaar[i] > '9') return 0;
    }
    return 1;
}

Patient *addPatient(Patient *head) {
    Patient *newP = (Patient *)malloc(sizeof(Patient));
    if (!newP) {
        printf("Memory allocation failed!\n");
        return head;
    }

    printf("Enter patient name: ");
    scanf(" %[^\n]", newP->name);
    printf("Enter Aadhaar number (12 digits): ");
    scanf("%s", newP->aadhaar);

    if (!isAadhaarValid(newP->aadhaar)) {
        printf("Invalid Aadhaar number!\n");
        free(newP);
        return head;
    }

    if (findPatient(head, newP->aadhaar)) {
        printf("Patient already registered!\n");
        free(newP);
        return head;
    }

    printf("Enter age: ");
    scanf("%d", &newP->age);
    printf("Enter gender: ");
    scanf("%s", newP->gender);

    strcpy(newP->hospital, "Not assigned");
    strcpy(newP->doctor, "Not assigned");
    newP->next = head;
    head = newP;

    printf("Patient registered successfully!\n");
    return head;
}

void listPatients(Patient *head) {
    if (!head) {
        printf("No patients found.\n");
        return;
    }
    printf("\n--- Patient List ---\n");
    while (head) {
        printf("Name: %s | Aadhaar: %s | Age: %d | Gender: %s | Hospital: %s | Doctor: %s\n",
               head->name, head->aadhaar, head->age, head->gender, head->hospital, head->doctor);
        head = head->next;
    }
}

Patient *findPatient(Patient *head, const char *aadhaar) {
    while (head) {
        if (strcmp(head->aadhaar, aadhaar) == 0) return head;
        head = head->next;
    }
    return NULL;
}

void freePatients(Patient *head) {
    while (head) {
        Patient *temp = head;
        head = head->next;
        free(temp);
    }
}
