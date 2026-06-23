#include <stdio.h>
#include <stdlib.h>
#include "patient.h"
#include "appointment.h"
#include "hospital.h"

int main() {
    Patient *patients = NULL;
    Appointment *appointments = NULL;
    int choice;

    while (1) {
        printf("\n===== Health Card Management System =====\n");
        printf("1. Register new patient\n");
        printf("2. Assign hospital & doctor\n");
        printf("3. Book appointment\n");
        printf("4. Cancel appointment\n");
        printf("5. List patients\n");
        printf("6. List appointments\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            patients = addPatient(patients);
        } else if (choice == 2) {
            assignHospitalAndDoctor(patients);
        } else if (choice == 3) {
            char aadhaar[13];
            printf("Enter Aadhaar to book appointment: ");
            scanf("%s", aadhaar);
            Patient *p = findPatient(patients, aadhaar);
            if (!p) {
                printf("Patient not found!\n");
            } else {
                appointments = bookAppointment(appointments, p);
            }
        } else if (choice == 4) {
            int id;
            printf("Enter appointment ID to cancel: ");
            scanf("%d", &id);
            appointments = cancelAppointment(appointments, id);
        } else if (choice == 5) {
            listPatients(patients);
        } else if (choice == 6) {
            listAppointments(appointments);
        } else if (choice == 7) {
            printf("Exiting program...\n");
            freePatients(patients);
            freeAppointments(appointments);
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }
    return 0;
}
