#include <stdio.h>
#include <string.h>
#include "patient.h"
#include "hospital.h"

const char *hospitals[] = {"City Hospital", "GreenCare Clinic", "HealthPlus Center"};
const char *doctors[] = {"Dr. Smith", "Dr. Sharma", "Dr. Patel", "Dr. Reddy"};

void assignHospitalAndDoctor(struct Patient *head) {
    char aadhaar[13];
    printf("Enter Aadhaar to assign hospital and doctor: ");
    scanf("%s", aadhaar);

    Patient *p = findPatient(head, aadhaar);
    if (!p) {
        printf("Patient not found!\n");
        return;
    }

    printf("Available Hospitals:\n");
    for (int i = 0; i < 3; i++) printf("%d. %s\n", i + 1, hospitals[i]);
    int hChoice;
    printf("Choose hospital: ");
    scanf("%d", &hChoice);
    if (hChoice < 1 || hChoice > 3) {
        printf("Invalid choice.\n");
        return;
    }
    strcpy(p->hospital, hospitals[hChoice - 1]);

    printf("Available Doctors:\n");
    for (int i = 0; i < 4; i++) printf("%d. %s\n", i + 1, doctors[i]);
    int dChoice;
    printf("Choose doctor: ");
    scanf("%d", &dChoice);
    if (dChoice < 1 || dChoice > 4) {
        printf("Invalid choice.\n");
        return;
    }
    strcpy(p->doctor, doctors[dChoice - 1]);

    printf("Hospital and doctor assigned successfully!\n");
}
