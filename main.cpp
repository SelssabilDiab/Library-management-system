#include "users.h"
#include "student.h"
#include "teacher.h"
#include "employee.h"
#include "resources.h"
#include "books.h"
#include "articals.h"

void try_system()
{
    cout << "enter 1 to add a user \n";
    cout << "enter 2 to add a resource \n";
    int choice;
    while (cin >> choice)
    {
        cout << "enter 1 to add a user \n";
        cout << "enter 2 to add a resource \n";
        switch (choice)
        {
        case 1:
            int user;
            cout << "3 to create a student \n";
            cout << "4 to create a teacher \n";
            cout << "5 to create an employee \n";
            cout << "6 to remove a student \n";
            cout << "7 to remove a teacher \n";
            cout << "8 to remove an employee \n";
            cout << "9 to print all the students \n";
            cout << "10 to print all the teachers \n";
            cout << "11 to print all the employees \n";

            cin >> user;
            if (user == 3)
            {
                string fname, lname;
                int year;
                cout << "enter the first name than the second name and the academic year \n";
                cin >> fname >> lname >> year;
                student::add_student(fname, lname, year);
                break;

            }
            else if (user == 4)
            {
                string fname, lname;
                cout << "enter the first name than the second name  \n";
                cin >> fname >> lname;
                teacher::addTeacher(fname, lname);
                break;

            }
            else if (user == 5)
            {
                string fname, lname;
                cout << "enter the first name than the second name  \n";
                cin >> fname >> lname;
                employee::add_employee(fname, lname);
                break;

            }
            else if (user == 6)
            {
                string fname, lname;
                student::remove_student(fname, lname);
                break;

            }
            else if (user == 7)
            {
                string fname, lname;
                teacher::remove_teacher(fname, lname);
                break;

            }
            else if (user == 8)
            {
                string fname, lname;
                employee::remove_employee(fname, lname);
                break;

            }
            else if (user == 9)
            {
                student::print_students_list();
                break;

            }
            else if (user == 10)
            {
                teacher::print_teachers_list();
                break;

            }
            else if (user == 11)
            {
                employee::print_employee_list();
                break;

            }

        case 2:

            int resource;
            cout << "12 to create a book \n";
            cout << "13 to create an artical \n";
            cout << "14 to borrow a book \n";
            cout << "15 to borrow an artical \n";
            cout << "16 to return a book \n";
            cout << "17 to return an artical \n";
            cout << "18 to print all the history of books \n";
            cout << "19 to print all the history of articals \n";
            cout << "20 to search for a book \n";
            cout << "21 to search for an artical \n";
            cin >> resource;
            if (resource == 12)
            {
                string tit, auth;
                int year, nb;
                cout << "enter the title of the book than the name of the author , date of publication and number of books \n";
                cin >> tit >> auth >> year >> nb;
                books::add_book(tit, auth, year, nb);
                break;

            }

            else if (resource == 13)
            {
                string tit, auth;
                int year, nb;
                cout << "enter the title of the artical than the name if the author , date of publication and number of articals \n";
                cin >> tit >> auth >> year >> nb;
                articals::add_artical(tit, auth, year, nb);
                break;

            }
            else if (resource == 14)
            {
                string tit, auth;
                int year;
                cout << "enter the title of the book than the name if the author and the date of publication\n";
                cin >> tit >> auth >> year;
                books::Borrow_book(tit, auth, "book", year);
                break;

            }
            else if (resource == 15)
            {
                string tit, auth;
                int year;
                cout << "enter the title of the artical than the name of the author and the date of publication\n";
                cin >> tit >> auth >> year;
                articals::Borrow_Artical(tit, auth, "artical", year);
                break;

            }
            else if (resource == 16)
            {
                string tit, auth, name;
                int year;
                cout << "enter the title of the book than the name of the author and the date of publication and your name \n";
                cin >> tit >> auth >> year >> name;
                books::returning_book(tit, auth, year, "book", name);
                break;

            }
            else if (resource == 17)
            {
                string tit, auth, name;
                int year;
                cout << "enter the title of the artical than the name of the author and the date of publication and your name \n";
                cin >> tit >> auth >> year >> name;
                articals::returning_artical(tit, auth, year, "artical", name);
                break;

            }
            else if (resource == 18)
            {
                books::all_history_of_books();
                break;
            
            }
            else if (resource == 19)
            {
                articals::all_history_of_articals();
                break;
                
            }
            else if (resource == 20)
            {
                string word;
                cout << "enter the word that has a relation with the book that you are serching for \n";
                cin >> word;
                resources<books>::search(word);
                break;
                
            }

            else if (resource == 21)
            {
                string word2;
                cout << "enter the word that has a relation with the artical that you are serching for \n";
                cin >> word2;
                resources<articals>::search(word2);
                break;
            }
        default:
            break;
        }
    }
}

int main()
{
    try_system();
    /*
    teacher T1("Ali","Omar");
    student s1("ahmad","ali","student",4);
    employee e1("sali","fateh");
    users<teacher>::print_list();
    users<student>::print_list();
    users<employee>::print_list();
    books::add_book("Maths","Reiman",1959,5);
    books::add_book("Sience","John" , 2001,3);
    books::add_book("AI","Steiven",2019,2);
    resources<books>::print();
    books::Borrow_book("Maths","Reiman", "book"  , 1959);
    books::Borrow_book("Sience","John", "book"  , 2001);
    books::Borrow_book("Maths","Reiman", "book"  , 1959);
    books::Borrow_book("Maths","Reiman" , "book" , 1959);
    books::Borrow_book("AI","Steiven", "book" , 2019 );
    resources<books>::print();
    books::all_history_of_books();

    books::returning_book("Maths","Reiman" , 1959 , "book" , "ss");
    resources<books>::print();
    books::all_history_of_books();
    resources<books>::remove("Maths","Reiman",1959 , "book");
    resources<books>::remove("Sience","John", 2001, "book" );
    resources<books>::remove("AI","Steiven", 2019, "book");
    student::remove_student("ahmad","ali");
    teacher::remove_teacher("Ali","Omar");
    employee::remove_employee("sali","fateh");
    */

    return 0;
}