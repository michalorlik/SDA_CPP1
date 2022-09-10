#include "Student.h"

namespace Zad {

    Student::Student(std::string newFirstName, std::string newLastName, int newStudentId)
        : firstName(newFirstName), lastName(newLastName), studentId(newStudentId)
    {};



    void to_json(json& j, const Student& s)
    {
        j = json{ {"firstName", s.getFirstName()} , {"lastName" , s.getLastName()}, {"studentId" , s.getStudentId()}};
    }

    void from_json(const json& j, Student& s)
    {
        s.setFirstName(j["firstName"].get<std::string>());
        s.setLastName(j["lastName"]);
        //s.setStudentId(j["studentId"].get<int>());

        int studentId;
        j["studentId"].get_to(studentId); //get_to sluzy do pobrania do zmiennej
        //j.at("studentId").get_to(studentId);  //obie linijki robi¹ to samo
        s.setStudentId(studentId);
    }
}