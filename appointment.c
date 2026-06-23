#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "appointment.h"

static int nextID = 1;

Appointment *bookAppointment(Appointment *head, Patient *p) {
    if (!p) {
        printf("Invalid patient.\n");
        return head;
    }

    Appointment *newA = (Appointment *)malloc(sizeof(Appointment));
    if (!newA) {
        printf("Memory error!\n");
        return head;
    }

    newA->id = nextID++;

    strcpy(newA->hospital, p->hospital);
    strcpy(newA->doctor, p->doctor);

    printf("Enter appointment date (DD/MM/YYYY): ");
    scanf("%s", newA->date);

    newA->next = NULL;

    // INSERT AT TAIL (FIFO order)
    if (!head) {
        head = newA;
    } else {
        Appointment *temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newA;
    }

    printf("Appointment booked! ID = %d\n", newA->id);
    return head;
}


// ------------------ LIST APPOINTMENTS USING STACK ------------------
void listAppointments(Appointment *head) {
    if (!head) {
        printf("No appointments.\n");
        return;
    }

    Appointment *stack[100];
    int top = -1;

    Appointment *temp = head;

    // Push to stack
    while (temp) {
        stack[++top] = temp;
        temp = temp->next;
    }

    printf("\n--- Appointment List ---\n");

    // Pop & display
    while (top >= 0) {
        Appointment *a = stack[top--];

        printf("Appointment ID: %d\n", a->id);
        printf("Hospital: %s\n", a->hospital);
        printf("Doctor: %s\n", a->doctor);
        printf("Date: %s\n", a->date);
        printf("---------------------------------------\n");
    }
}


// ------------------ CANCEL APPOINTMENT ------------------
Appointment *cancelAppointment(Appointment *head, int id) {
    Appointment *curr = head, *prev = NULL;

    while (curr) {
        if (curr->id == id) {
            if (prev) prev->next = curr->next;
            else head = curr->next;

            free(curr);
            printf("Appointment %d cancelled.\n", id);
            return head;
        }
        prev = curr;
        curr = curr->next;
    }

    printf("Appointment ID not found.\n");
    return head;
}


// ------------------ FREE ALL APPOINTMENTS ------------------
void freeAppointments(Appointment *head) {
    while (head) {
        Appointment *temp = head;
        head = head->next;
        free(temp);
    }
}
