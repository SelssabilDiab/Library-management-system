#ifndef RESOURCES_H
#define RESOURCES_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include"date.h"
using namespace std;

template <typename T>
class resources
{
private:
    string title;
    string author;
    int publication_year;
    bool availability;
    int nbofAvailable;
    string type;
    static vector<T *> list;
    static int nbOfResources;
    vector<string> borrowers;
    vector<date> date_of_borrowing;
    vector<date> date_of_returning;
    int nbof_borrowing;
    int nbof_returning;

public:
    resources(const string &tit, const string &auth, int year, const string &typ, int nb) : title(tit), author(auth), publication_year(year), type(typ)
    {
        if (nb> 0){
            nbofAvailable=nb;
            availability = true;
        }
        else if (nb==0){
            nbofAvailable=nb;
            availability = false;
        }
        list.push_back(static_cast<T *>(this));
        nbOfResources++;
        nbof_borrowing=0;
    }

    static void add(const string &tit, const string &auth, int year, const string &typ, int nb)
    {
        resources rs(tit, auth, year, typ, nb);
    }

    virtual void set_availability()
    {
        if (nbofAvailable > 0)
        {
            availability = true;
        }
        else
        {
            availability = false;
        }
    }
    

    // getters

    string get_title() const { return title; }
    string get_author() const { return author; }
    int get_publication_year() const { return publication_year; }
    string get_type() const { return type; }
    bool get_availability() const { return availability; }
    int get_nbof_available() const { return nbofAvailable; }
    int get_nbofborrowing(){return nbof_borrowing;}
    static void print()
    {
        cout << "title        author          date of publiacation          number of avilables    type \n";
        for (auto rs = list.begin(); rs != list.end(); ++rs)
        {
            cout << (*rs)->get_title() << "      " << (*rs)->get_author() << "       " << (*rs)->get_publication_year() << "     " << (*rs)->get_nbof_available() << "     " << (*rs)->get_type() << '\n';
        }
    }


    static void remove(const string &tit, const string &auth, int year, const string &typ){
        for(auto rs=list.begin() ; rs != list.end() ; ++rs){
            if ((*rs)->get_title() == tit && (*rs)->get_author() == auth && (*rs)->get_publication_year() == year && (*rs)->get_type() == typ ){
                delete *rs;
                list.erase(rs);
            }
        }
    }

    void set_availability(bool b) { availability = b; }
    void set_nbofavailable(int b) { nbofAvailable = b; }
    void set_nb_of_borrowing(int n){if(n>=0)nbof_borrowing=n;}
    void add_date_of_borrowing(date& d){date_of_borrowing.push_back(d);}
    void add_date_of_returning(date& d){date_of_returning.push_back(d);}
    void add_borrower(const string& name){borrowers.push_back(name);}
    void remove_date_of_borrowing(int position){date_of_borrowing.erase(date_of_borrowing.begin()+position);}
    void remove_date_of_returning(int position){date_of_returning.erase(date_of_returning.begin()+position);}
    void remove_borrower(int position){borrowers.erase(borrowers.begin()+position);}

    void print_date_of_borrowing(int position){date_of_borrowing[position].printDate();}
    void print_date_of_returning(int position){date_of_returning[position].printDate();}
    string print_borrower(int position){return borrowers[position];}

    void print_date_of_borrowing(int position , ostream& os){date_of_borrowing[position].printDate(os);}
    void print_date_of_returning(int position , ostream& os){date_of_returning[position].printDate(os);}


    static void Borrow(const string &tit, const string &auth, int year , const string& typ , T* ptr) //vector<T*> listof)
    {
        int count =0;
        for (auto rs : list)
        {
            if (rs->get_title() == tit && rs->get_author() == auth && rs->get_publication_year() == year && rs->get_type() == typ && rs->get_availability() == true)
            {
                cout << "enter your first name and your last name in this form firstname_lastname \n";
                string n;
                cin >> n;
                rs->add_borrower(n);
                int available = rs->get_nbof_available();
                available--;
                rs->set_nbofavailable(available);
                rs->nbof_borrowing++;
                rs->set_availability();
                int a, b, c;
                cout << "enter the date of returning (dd/mm/yyyy) : \n";

                date d1; // current date
                rs->add_date_of_borrowing(d1);
                cout << "date of borrowing is : ";
                d1.printDate();
                cout << '\n';
                cin >> a >> b >> c;
                date d2(a, b, c);
                while (d2 < d1)
                {
                    cout << "the date that you entered is not valid, you have to enter a date after the borrowing one \n";
                    cin >> a >> b >> c;
                    d2 = date(a, b, c);
                }
                rs->add_date_of_returning(d2);
                ptr = rs;
                return;
            }
            count++;
        }
        cout << "the"<<typ <<"is not avilable\n";
    }

    static void returning(const string &tit,const string &auth, int year, const string &typ,const string &name , T* ptr)//, vector<T>listof)
    {
        cout<<"you "<<name<<" are returning the "<<typ<<"  "<<tit<<"  "<<auth<<"  "<<year<<'\n';
        int count = 0;
        for (auto rs = list.begin() ; rs != list.end() ; ++rs)
        {
            if ((*rs)->get_title() == tit && (*rs)->get_author() == auth && (*rs)->get_publication_year() == year)
            {
                for (auto n : (*rs)->borrowers)
                {
                    if (n == name)
                    {
                        (*rs)->remove_borrower(count);
                        (*rs)->remove_date_of_borrowing(count);
                        (*rs)->remove_date_of_returning(count);
                        int b = (*rs)->get_nbof_available() + 1;
                        (*rs)->set_nbofavailable(b);
                        (*rs)->set_availability();
                        (*rs)->nbof_borrowing--;
                        ptr = *rs;
                        return;
                    }
                    count++;
                }
                
            }
            else cout<<"you are not a borrower \n";
        }
    }

    virtual void history()
    {
        for (int i = 0; i < nbof_borrowing; i++)
        {
            cout << "date_of_borrowing :  ";
            print_date_of_borrowing(i);
            cout << "          date_of_returning :  ";
            print_date_of_returning(i);
            cout << "   borrower :   " ;
            print_borrower(i);
            cout << '\n';
        }
    }

    static void all_history()
    {
        for (auto bk : list)
        {
            cout << bk->get_title() << "       " << bk->get_author() << "        " << bk->get_publication_year() << "    number of available books   " << bk->get_nbof_available() << '\n';
            bk->history();
        }
    }
    
    static void search(const string &word){
        for(auto rs=list.begin() ; rs!=list.end() ; ++rs){
            if((*rs)->get_title() == word || (*rs)->get_author() == word){
                cout<<" title : "<<(*rs)->get_title()<<" wuthor : "<<(*rs)->get_author()<<" publication_year : "<<(*rs)->get_publication_year()<<'\n';
            }
        }
    }

};

template <typename T>
int resources<T>::nbOfResources = 0;

template <typename T>
vector<T *> resources<T>::list;
#endif