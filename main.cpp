#include <iostream>
#include <queue>
#include <string>
#define cap 3

using namespace std;

// Structure to store a patient
struct Patient
{
    string name;
    int age;
    string gender;
    string condition; // severity of the patient's condition

    // Overload the < operator to compare patients based on their condition
    bool operator<(const Patient& other) const
    {
      // Patients with more severe conditions have higher priority
      return condition < other.condition;
    }
};

// Hospital management system class
class Hospital
{
    public:
    // Add a new patient to the queue
    void AddPatient(const Patient& patient)
    {
        patient_queue_.push(patient);
    }
    
    // Remove the next patient from the queue and return their information
    Patient GetNextPatient()
    {
        Patient patient = patient_queue_.top();
        patient_queue_.pop();
        return patient;
    }

// Check if the queue is empty
    bool IsEmpty() const
    {
        return patient_queue_.empty();
    }  
    private:
    // Priority queue to store the patient queue
    priority_queue<Patient> patient_queue_;
};

int main()
{
// Create a hospital management system
    Hospital hospital[cap];//array of struct so we can have multiple patients

    string patient_name;
    int patient_age;
    int patient_gender;
    int condition;
    
    vector <string> cond =   {"Serious","Moderate","Mild"};//A vector to store the patient's condition
    vector <string> gender = {"MALE","FEMALE"};//A vector to store the patient's gender


    for (int i = 0; i < cap; i++)
    {
        cout<<"\nEnter patient name: ";
        cin>>patient_name;          //getting the patients name
        //cin.ignore();

        cout<<"\nEnter patient age: ";
        cin>>patient_age;           //getting the patients age

        cout<<"\nSelect patient gender: ";
        cout<<"\n1.Male\t2.Female\n";
        cin>>patient_gender;        //getting the patients gender

        cout<<"\nSelect patient's condition: ";
        cout<<"\n1.Serious\t2.Moderate\t3.Mild\n";
        cin>>condition;             //getting the patients condition

        hospital[i].AddPatient({patient_name,patient_age,gender[patient_gender - 1],cond[condition - 1]});//adding patient's data to struct
    }


    // Process the patient queue
    for (int i = 0; i < cap; i++)
    {
        while (!hospital[i].IsEmpty())//process till queue is empty
        {
        Patient patient = hospital[i].GetNextPatient();
        cout << "Processing patient: " << patient.name << endl;
        }
    }

    return 0;
}
