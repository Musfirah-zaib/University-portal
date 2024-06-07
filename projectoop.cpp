#include <iostream>
#include <cstring>
using namespace std;
const int MAX_COURSES = 10;
const int MAX_DEPARTMENTS = 5;
const int MAX_STUDENTS = 50;
const int MAX_TEACHERS = 20;

class Course {
public:
    Course() : name(NULL), creditHours(0) {}
    Course(const char* name, int creditHours) : creditHours(creditHours) {
        setName(name);
    }

    Course(const Course& other) : creditHours(other.creditHours) {
        setName(other.name);
    }

    ~Course() {
        delete[] name;
    }

    const char* getName() const {
        return name;
    }

    int getCreditHours() const {
        return creditHours;
    }

    void setName(const char* newName) {
        if (name != NULL) {
            delete[] name;
        }
        int length = std::strlen(newName);
        name = new char[length + 1];

    }

private:
    char* name;
    int creditHours;
};

class Department {
public:
    Department() : name(0), numCourses(0) {}
    Department(const char* name) : numCourses(0) {
        setName(name);
    }

    Department(const Department& other) : numCourses(other.numCourses) {
        setName(other.name);

        for (int i = 0; i < numCourses; ++i) {
            this->courses[i] = other.courses[i];
        }
    }

    ~Department() {
        delete[] name;
    }

    const char* getName() const {
        return name;
    }

    void setName(const char* newName) {
        if (name != NULL) {
            delete[] name;
        }
        int length = std::strlen(newName);
        name = new char[length + 1];

    }

    void addCourse(const Course& course) {
        if (numCourses < MAX_COURSES) {
            courses[numCourses++] = course;
        }
        else {
            std::cerr << "Cannot add more courses. Maximum limit reached." << std::endl;
        }
    }

    void displayInfo() const {
        cout << "Department: " << name << endl;
        cout << "Courses:" << endl;
        for (int i = 0; i < numCourses; ++i) {
            cout << "  - " << courses[i].getName() << " (Credit Hours: " << courses[i].getCreditHours() << ")" << endl;
        }
    }

private:
    char* name;
    Course courses[MAX_COURSES];
    int numCourses;
};

class Person {
public:
    Person() : name(NULL), age(0) {}
    Person(const char* name, int age) : age(age) {
        setName(name);
    }

    Person(const Person& other) : age(other.age) {
        setName(other.name);
    }

    ~Person() {
        delete[] name;
    }

    const char* getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    void setName(const char* newName) {
        if (name != NULL) {
            delete[] name;
        }
        int length = std::strlen(newName);
        name = new char[length + 1];

    }

private:
    char* name;
    int age;
};

class Student : public Person {
public:
    Student() : studentID(NULL), numEnrolledCourses(0) {}
    Student(const char* name, int age, const char* studentID) : numEnrolledCourses(0), Person(name, age) {
        setStudentID(studentID);
    }

    Student(const Student& other) : numEnrolledCourses(other.numEnrolledCourses), Person(other) {
        setStudentID(other.studentID);

        for (int i = 0; i < numEnrolledCourses; ++i) {
            this->enrolledCourses[i] = other.enrolledCourses[i];
        }
    }

    ~Student() {
        delete[] studentID;
    }

    const char* getStudentID() const {
        return studentID;
    }

    void setStudentID(const char* newStudentID) {
        if (studentID != NULL) {
            delete[] studentID;
        }
        int length = strlen(newStudentID);
        studentID = new char[length + 1];

    }

    void enrollCourse(const Course& course) {
        if (numEnrolledCourses < MAX_COURSES) {
            enrolledCourses[numEnrolledCourses++] = course;
        }
        else {
            cerr << "Cannot enroll in more courses. Maximum limit reached." << endl;
        }
    }

    void displayInfo() const {
        cout << "Student: " << getName() << " (ID: " << studentID << ", Age: " << getAge() << ")" << endl;
        cout << "Enrolled Courses:" << endl;
        for (int i = 0; i < numEnrolledCourses; ++i) {
            cout << "  - " << enrolledCourses[i].getName() << " (Credit Hours: " << enrolledCourses[i].getCreditHours() << ")" << endl;
        }
    }

private:
    char* studentID;
    Course enrolledCourses[MAX_COURSES];
    int numEnrolledCourses;
};

class Teacher : public Person {
public:
    Teacher() : teacherID(NULL), numTaughtCourses(0) {}
    Teacher(const char* name, int age, const char* teacherID) : numTaughtCourses(0), Person(name, age) {
        setTeacherID(teacherID);
    }

    Teacher(const Teacher& other) : numTaughtCourses(other.numTaughtCourses), Person(other) {
        setTeacherID(other.teacherID);

        for (int i = 0; i < numTaughtCourses; ++i) {
            this->taughtCourses[i] = other.taughtCourses[i];
        }
    }

    ~Teacher() {
        delete[] teacherID;
    }

    const char* getTeacherID() const {
        return teacherID;
    }

    void setTeacherID(const char* newTeacherID) {
        if (teacherID != NULL) {
            delete[] teacherID;
        }
        int length = strlen(newTeacherID);
        teacherID = new char[length + 1];

    }

    void teachCourse(const Course& course) {
        if (numTaughtCourses < MAX_COURSES) {
            taughtCourses[numTaughtCourses++] = course;
        }
        else {
            cerr << "Cannot teach more courses. Maximum limit reached." << endl;
        }
    }

    void displayInfo() const {
        cout << "Teacher: " << getName() << " (ID: " << teacherID << ", Age: " << getAge() << ")" << endl;
        cout << "Taught Courses:" << endl;
        for (int i = 0; i < numTaughtCourses; ++i) {
            cout << "  - " << taughtCourses[i].getName() << " (Credit Hours: " << taughtCourses[i].getCreditHours() << ")" << endl;
        }
    }

private:
    char* teacherID;
    Course taughtCourses[MAX_COURSES];
    int numTaughtCourses;
};

class University {
public:
    University() : numDepartments(0), numStudents(0), numTeachers(0) {}

    void addDepartment(const Department& department) {
        if (numDepartments < MAX_DEPARTMENTS) {
            departments[numDepartments++] = department;
        }
        else {
            cerr << "Cannot add more departments. Maximum limit reached." << endl;
        }
    }

    void addStudent(const Student& student) {
        if (numStudents < MAX_STUDENTS) {
            students[numStudents++] = student;
        }
        else {
            cerr << "Cannot add more students. Maximum limit reached." << endl;
        }
    }

    void addTeacher(const Teacher& teacher) {
        if (numTeachers < MAX_TEACHERS) {
            teachers[numTeachers++] = teacher;
        }
        else {
            cerr << "Cannot add more teachers. Maximum limit reached." << endl;
        }
    }

    void displayUniversityInfo() const {
        cout << "University Information:" << endl;

        // Display Departments
        cout << "Departments:" << endl;
        for (int i = 0; i < numDepartments; ++i) {
            departments[i].displayInfo();
            cout << endl;
        }

        // Display Students
        cout << "Students:" << endl;
        for (int i = 0; i < numStudents; ++i) {
            students[i].displayInfo();
            cout << endl;
        }

        // Display Teachers
        cout << "Teachers:" << endl;
        for (int i = 0; i < numTeachers; ++i) {
            teachers[i].displayInfo();
            cout << endl;
        }
    }

private:
    Department departments[MAX_DEPARTMENTS];
    Student students[MAX_STUDENTS];
    Teacher teachers[MAX_TEACHERS];

    int numDepartments;
    int numStudents;
    int numTeachers;
};

int main() {
    University university;

    while (true) {
        cout << "1. Add Department" << endl;
        cout << "2. Add Student" << endl;
        cout << "3. Add Teacher" << endl;
        cout << "4. Display University Info" << endl;
        cout << "5. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            // Add Departments
            int numDepartments;
            cout << "Enter the number of departments to add: ";
            cin >> numDepartments;

            for (int i = 0; i < numDepartments; ++i) {
                string departmentName;
                cout << "Enter Department Name: ";
                cin >> departmentName;

                Department newDepartment(departmentName.c_str());
                university.addDepartment(newDepartment);
            }

            cout << "Departments added successfully!" << endl;
            break;
        }
        case 2: {
            // Add Students
            int numStudents;
            cout << "Enter the number of students to add: ";
            cin >> numStudents;

            for (int i = 0; i < numStudents; ++i) {
                string studentName;
                int studentAge;
                string studentID;

                cout << "Enter Student Name: ";
                cin >> studentName;

                cout << "Enter Student Age: ";
                cin >> studentAge;

                cout << "Enter Student ID: ";
                cin >> studentID;

                Student newStudent(studentName.c_str(), studentAge, studentID.c_str());
                university.addStudent(newStudent);
            }

            cout << "Students added successfully!" << endl;
            break;
        }
        case 3: {
            // Add Teachers
            int numTeachers;
            cout << "Enter the number of teachers to add: ";
            cin >> numTeachers;

            for (int i = 0; i < numTeachers; ++i) {
                string teacherName;
                int teacherAge;
                string teacherID;

                cout << "Enter Teacher Name: ";
                cin >> teacherName;

                cout << "Enter Teacher Age: ";
                cin >> teacherAge;

                cout << "Enter Teacher ID: ";
                cin >> teacherID;

                Teacher newTeacher(teacherName.c_str(), teacherAge, teacherID.c_str());
                university.addTeacher(newTeacher);
            }

            cout << "Teachers added successfully!" << endl;
            break;
        }
        case 4:
            // Display University Information
            university.displayUniversityInfo();
            break;
        case 5:
            // Exit
            cout << "Exiting the program." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}