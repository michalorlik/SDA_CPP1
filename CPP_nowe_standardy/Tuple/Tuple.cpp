#include <iostream>
#include <tuple>
#include <vector>

std::tuple<std::string, int, float> zwrocTrzy(std::string str, int i, float f)
{
    return std::make_tuple(str, i, f);
}

struct Patient
{
    std::string name; //<-
    std::string surname;
    int pesel;
    float height; //<-
    int weight; //<-
    //std::vector<...> medicalHistory
};

class MedicalRecord
{
public:
    MedicalRecord() = default;
    virtual ~MedicalRecord() = default;

    void addPatient(Patient patient)
    {
        patients.push_back(patient);
    }

    std::tuple<std::string, float, int> getPatientData(int pesel)
    {
        auto patientIt = std::find_if(patients.cbegin(), patients.cend(), [pesel](auto patient) {return patient.pesel == pesel; });
        return std::make_tuple(patientIt->name, patientIt->height, patientIt->weight);
    }

private:
    std::vector<Patient> patients;
};

int main()
{
    auto krotka = zwrocTrzy("SDA", 42, 21.37);

    int var = std::get<1>(krotka);

    std::cout << std::get<0>(krotka) << "  f=" << std::get<2>(krotka);

    MedicalRecord nzozRzeznik;
    nzozRzeznik.addPatient(Patient{ "Michal","Orlikowski",123,1.8,100 });
    nzozRzeznik.addPatient(Patient{ "Stefan","Szczecina",111,1.9,60 });

    auto patientData = nzozRzeznik.getPatientData(111);
    auto name = std::get<0>(patientData);
    auto height = std::get<1>(patientData);
    auto weight = std::get<2>(patientData);

    auto bmi = weight / (height * height);

    std::cout << "BMI pacjenta: " << name << " wynosi: " << bmi <<std::endl;
}
