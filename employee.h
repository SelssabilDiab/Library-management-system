#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include"users.h"

class employee :public users<employee>
{
    private:
    static ofstream employees;
    //static vector<employee*> employee_list;
    static int numberOfEmployee;
    public:
    employee(const string& fn , const string& ln):users(fn , ln ,"Library_Employee"){}


    static void add_employee(const string& fn ,const string& ln){
        employee e(fn , ln);
        storeEmployees(&e);
        numberOfEmployee++;
    }

    void print()const override{
        users::print();
    }

    static void print_employee_list(){
        users::print_list();
    }

    static void remove_employee(const string& firstname, const string& lastname){
        users::remove(firstname , lastname);
    }
    static void storeEmployees(employee * e)
    {
        employees.open("employees.txt", ios::app);

        if (employees.is_open())
        {
            employees << e->get_first_name() << "    " << e->get_last_name() <<'\n';
            employees.close(); // Close the file after writing
        }
        else
        {
            cout << "Error opening file.\n";
        }
    }
};

int employee::numberOfEmployee = 0;
ofstream employee::employees;

//vector<employee*> employee::employee_list;

#endif