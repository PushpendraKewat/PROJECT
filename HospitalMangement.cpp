#include <bits/stdc++.h>
using namespace std;

class Patient {
private:
    string name;
    int age;
    string disease;

public:
    Patient(string name, int age, string disease)
        : name(name), age(age), disease(disease) {}

    void display() const {
        cout << "Name: " << name << ", Age: " << age << ", Disease: " << disease << endl;
    }

    string getName() const { return name; }
    string getDisease() const { return disease; }
    int getAge() const { return age; }
};

class Doctor {
private:
    string name;
    string specialization;
    int experience;

public:
    Doctor(string name, string specialization, int experience)
        : name(name), specialization(specialization), experience(experience) {}

    void display() const {
        cout << "Name: " << name << ", Specialization: " << specialization << ", Experience: " << experience << " years" << endl;
    }

    string getName() const { return name; }
    string getSpecialization() const { return specialization; }
    int getExperience() const { return experience; }
};

class Appointment {
private:
    string patientName;
    string doctorName;
    string time;

public:
    Appointment(string patientName, string doctorName, string time)
        : patientName(patientName), doctorName(doctorName), time(time) {}

    void display() const {
        cout << "Patient: " << patientName << ", Doctor: " << doctorName << ", Time: " << time << endl;
    }

    string getPatientName() const { return patientName; }
    string getDoctorName() const { return doctorName; }
    string getTime() const { return time; }
};

class HospitalManagementSystem {
private:
    vector<Patient> patients;
    vector<Doctor> doctors;
    vector<Appointment> appointments;

public:
    void addPatient() {
        string name, disease;
        int age;
        cout << "Enter patient name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter age: ";
        cin >> age;
        cin.ignore();
        cout << "Enter disease: ";
        getline(cin, disease);
        patients.emplace_back(name, age, disease);
        cout << "Patient added successfully!" << endl;
    }

    void addDoctor() {
        string name, specialization;
        int experience;
        cout << "Enter doctor name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter specialization: ";
        getline(cin, specialization);
        cout << "Enter years of experience: ";
        cin >> experience;
        doctors.emplace_back(name, specialization, experience);
        cout << "Doctor added successfully!" << endl;
    }

    void scheduleAppointment() {
        string patientName, doctorName, time;
        cout << "Enter patient name: ";
        cin.ignore();
        getline(cin, patientName);
        cout << "Enter doctor name: ";
        getline(cin, doctorName);
        cout << "Enter appointment time (e.g., 10:30 AM): ";
        getline(cin, time);

        // Check if the patient and doctor exist
        bool patientExists = false, doctorExists = false;
        for (const auto& patient : patients) {
            if (patient.getName() == patientName) {
                patientExists = true;
                break;
            }
        }
        for (const auto& doctor : doctors) {
            if (doctor.getName() == doctorName) {
                doctorExists = true;
                break;
            }
        }

        if (!patientExists) {
            cout << "Error: Patient not found!" << endl;
            return;
        }
        if (!doctorExists) {
            cout << "Error: Doctor not found!" << endl;
            return;
        }

        appointments.emplace_back(patientName, doctorName, time);
        cout << "Appointment scheduled successfully!" << endl;
    }

    void viewPatients() const {
        if (patients.empty()) {
            cout << "No patients available." << endl;
            return;
        }
        cout << "\nPatient List:\n";
        for (const auto& patient : patients) {
            patient.display();
        }
    }

    void viewDoctors() const {
        if (doctors.empty()) {
            cout << "No doctors available." << endl;
            return;
        }
        cout << "\nDoctor List:\n";
        for (const auto& doctor : doctors) {
            doctor.display();
        }
    }

    void viewAppointments() const {
        if (appointments.empty()) {
            cout << "No appointments scheduled." << endl;
            return;
        }
        cout << "\nAppointment List:\n";
        for (const auto& appointment : appointments) {
            appointment.display();
        }
    }

    void searchPatient() const {
        string name;
        cout << "Enter patient name to search: ";
        cin.ignore();
        getline(cin, name);

        for (const auto& patient : patients) {
            if (patient.getName() == name) {
                cout << "Patient found:\n";
                patient.display();
                return;
            }
        }
        cout << "Patient not found!" << endl;
    }

    void searchDoctor() const {
        string name;
        cout << "Enter doctor name to search: ";
        cin.ignore();
        getline(cin, name);

        for (const auto& doctor : doctors) {
            if (doctor.getName() == name) {
                cout << "Doctor found:\n";
                doctor.display();
                return;
            }
        }
        cout << "Doctor not found!" << endl;
    }

    void saveToFile() const {
        ofstream file("hospital_data.txt");
        if (!file) {
            cout << "Error saving data!" << endl;
            return;
        }

        file << "Patients:\n";
        for (const auto& patient : patients) {
            file << patient.getName() << ", " << patient.getAge() << ", " << patient.getDisease() << "\n";
        }

        file << "\nDoctors:\n";
        for (const auto& doctor : doctors) {
            file << doctor.getName() << ", " << doctor.getSpecialization() << ", " << doctor.getExperience() << "\n";
        }

        file << "\nAppointments:\n";
        for (const auto& appointment : appointments) {
            file << "Patient: " << appointment.getPatientName() << ", Doctor: " << appointment.getDoctorName() << ", Time: " << appointment.getTime() << "\n";
        }

        file.close();
        cout << "Data saved successfully!" << endl;
    }
};

int main() {
    HospitalManagementSystem hms;
    int choice;

    do {
        cout << "\n--- Hospital Management System ---" << endl;
        cout << "1. Add Patient" << endl;
        cout << "2. Add Doctor" << endl;
        cout << "3. Schedule Appointment" << endl;
        cout << "4. View Patients" << endl;
        cout << "5. View Doctors" << endl;
        cout << "6. View Appointments" << endl;
        cout << "7. Search Patient" << endl;
        cout << "8. Search Doctor" << endl;
        cout << "9. Save Data to File" << endl;
        cout << "10. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                hms.addPatient();
                break;
            case 2:
                hms.addDoctor();
                break;
            case 3:
                hms.scheduleAppointment();
                break;
            case 4:
                hms.viewPatients();
                break;
            case 5:
                hms.viewDoctors();
                break;
            case 6:
                hms.viewAppointments();
                break;
            case 7:
                hms.searchPatient();
                break;
            case 8:
                hms.searchDoctor();
                break;
            case 9:
                hms.saveToFile();
                break;
            case 10:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 10);

    return 0;
}
