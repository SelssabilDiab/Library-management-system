#ifndef STUDENT_H
#define STUDENT_H
#include"users.h"

class student : public users<student>
{
private:
static vector<student*>studentsList;
    int Academic_year;
    static int numberOfStudents;
    static ofstream students;
public:

    student(const string& firstname , const string& lastname , int year):users(firstname,lastname,"student"){
        if(year>0 && year<6)Academic_year=year;
        else Academic_year=1;
        studentsList.push_back(this);
         numberOfStudents++;
        
    }

    static void add_student(const string& firstname , const string& lastname , int year){
        student s(firstname , lastname , year);
        storeStudents(&s);
       
    }
    
    void print()const override{
        users::print();
        cout<<"        "<<Academic_year<<'\n';
    }

    static void print_students_list(){
        cout<<"who "<<"        "<<"first name "<<"        "<<"last name "<<"        "<<"academic year \n";
        for(const student* s: studentsList){
            s->print();
        }
    }

    static void remove_student(const string& firstname, const string& lastname){
        for (auto s = studentsList.begin(); s!= studentsList.end(); ++s)
        {
            if ((*s)->get_first_name() == firstname && (*s)->get_last_name() == lastname)
            {
                delete *s;
                studentsList.erase(s);
                numberOfStudents--;
                users::remove(firstname , lastname);
                cout <<(*s)->get_who()<<firstname<<" "<<lastname<<" removed successfully.\n";
                
            }
        }
        cout <<"student "<<firstname<<"  "<<lastname<<" not found.\n";
      
    }
    static void storeStudents(student * e)
    {
        students.open("students.txt", ios::app);

        if (students.is_open())
        {
            students << e->get_first_name() << "    " << e->get_last_name() <<"  Academic_year " <<e->Academic_year<<'\n';
            students.close(); // Close the file after writing
        }
        else
        {
            cout << "Error opening file.\n";
        }
    }
};


int student::numberOfStudents = 0;
vector<student*> student::studentsList; 
ofstream student::students;

#endif