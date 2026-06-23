#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include "patient.h"

typedef struct Appointment {
    int id;
    char hospital[50];
    char doctor[50];
    char date[20];
    struct Appointment *next;
} Appointment;

Appointment *bookAppointment(Appointment *head, Patient *p);
Appointment *cancelAppointment(Appointment *head, int id);
void listAppointments(Appointment *head);
void freeAppointments(Appointment *head);

#endif
