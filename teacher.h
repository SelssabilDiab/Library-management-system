#ifndef TEACHER_H
#define TEACHER_H
#include"users.h"

class teacher :public users<teacher>
{
private:
    static int numberOfTeachers;
    static ofstream Teachers;
public:
    teacher(const string& firstname , const string& lastname):users<teacher>(firstname , lastname , "teacher"){}


    static void addTeacher(const string& firstname , const string& lastname){
        teacher t(firstname , lastname );
        storeTeachers(&t);
        numberOfTeachers++;
    }

    void print()const override{
        users::print();
    }

    static void print_teachers_list() {
        users::print_list;
    }

    static void remove_teacher(const string& firstname, const string& lastname){
        users::remove(firstname , lastname);
    }
    static void storeTeachers(teacher * e)
    {
        Teachers.open("teachers.txt", ios::app);

        if (Teachers.is_open())
        {
            Teachers << e->get_first_name() << "    " << e->get_last_name() <<'\n';
            Teachers.close(); // Close the file after writing
        }
        else
        {
            cout << "Error opening file.\n";
        }
    }

};

int teacher::numberOfTeachers =0;
std::ofstream teacher::Teachers;

#endif