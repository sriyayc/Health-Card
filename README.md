# Health-Card
# Health Card Management System

A terminal-based patient management system written in C. Supports patient registration, hospital/doctor assignment, and appointment booking using linked lists.

---

## Features

- Register patients with Aadhaar validation (12-digit numeric)
- Assign hospitals and doctors from a predefined list
- Book and cancel appointments (FIFO queue)
- View all patients and appointments

---

## Project Structure

```
├── main.c            # Entry point and menu loop
├── patient.c/.h      # Patient linked list operations
├── appointment.c/.h  # Appointment booking and cancellation
├── hospital.c/.h     # Hospital and doctor assignment
```

---

## How to Compile

**Linux / macOS:**
```bash
gcc main.c patient.c appointment.c hospital.c -o health
./health
```

**Windows (MinGW):**
```bash
gcc main.c patient.c appointment.c hospital.c -o health.exe
health.exe
```

---

## Usage

```
===== Health Card Management System =====
1. Register new patient
2. Assign hospital & doctor
3. Book appointment
4. Cancel appointment
5. List patients
6. List appointments
7. Exit
```

- **Register** a patient using their name, Aadhaar number, age, and gender
- **Assign** a hospital and doctor before booking an appointment
- **Book** an appointment by entering the patient's Aadhaar number
- **Cancel** an appointment using its ID
- **List** all registered patients or booked appointments

---

## Data Structures Used

| Structure | Usage |
|---|---|
| Singly Linked List | Patient records |
| Singly Linked List (FIFO) | Appointment queue |
| Stack (array-based) | Reverse display of appointments |

---

## Known Limitations

- Data is not persisted — all records are lost on exit
- Appointment IDs reset to 1 on each run
- Fixed list of 3 hospitals and 4 doctors
- No multi-patient appointment support per session

---

## Requirements

- GCC or any C99-compatible compiler
- Standard C libraries only (no external dependencies)

---

## Author

> Add your name and contact here
