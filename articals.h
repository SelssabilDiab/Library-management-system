#ifndef ARTICALS_H
#define ARTICALS_H
#include "resources.h"
#include "date.h"
#include "users.h"
class articals : public resources<articals>
{
private:
    static ofstream Articals;
    static ofstream Articals_borrow;
    static ofstream Articals_returning;


    static int nbofArticals;
    //static vector<books *> listof_books;

public:
    articals(const string &tit, const string &auth, int year, int nb) : resources<articals>(tit, auth, year, "artical", nb){}

    static void add_artical(const string &tit, const string &auth, int year, int nb)
    {
        articals *A = new articals(tit, auth, year, nb);
        nbofArticals++;
        storeArticals(A);
    }

    static void Borrow_Artical(const string &tit, const string &auth, const string& typ , int year)
    {
        articals* A;
        resources::Borrow(tit , auth , year , typ , A);
        store_borrow_articals(A , A->get_nbofborrowing());
    }

    void set_availability()override
    {
        resources::set_availability();
    }

    void history()override
    {
        resources::history();
    }

    static void all_history_of_articals()
    {
        resources::all_history();
    }

    static void returning_artical(const string &tit,const string &auth, int year, const string &typ,const string &name)
    {
        articals* A;
        resources::returning(tit , auth , year ,"artical" , name , A );
        store_return_articals(A ,name);
    }

    static void storeArticals(articals* A)
    {
        Articals.open("Articals.txt", ios::app);

        if (Articals.is_open())
        {
            Articals << A->get_title() << "    " << A->get_author() << "    " << A->get_publication_year() << "    " << A->get_availability() << '\n';
            Articals.close(); // Close the file after writing
        }
        else
        {
            cout << "Error opening file.\n";
        }
    }
    //borrowing articals 

     static void store_borrow_articals(articals *A , int pos )
    {
        Articals_borrow.open("articals_borrow.txt", ios::app);

        if (Articals_borrow.is_open())
        {
            Articals_borrow << A->get_title() << "    " << A->get_author() << "    " << A->get_publication_year() << "    " << A->get_availability() << '\n';
            Articals_borrow <<"date_of_borrowing : " ;
            A->print_date_of_borrowing(pos, Articals_borrow);
            Articals_borrow<<"date_of_returnin : ";
            A->print_date_of_returning(pos , Articals_borrow);
            Articals_borrow<<" borrower : ";
            Articals_borrow<<A->print_borrower(pos);
            Articals_borrow<<'\n';
            Articals_borrow.close(); // Close the file after writing
        }
        else
        {
            cout << "Error opening file.\n";
        }
    }
    //returning articals 

    static void store_return_articals(articals *A , const string& name )
    {
        Articals_returning.open("articals_return.txt", ios::app);

        if (Articals_returning.is_open())
        {
            Articals_returning << A->get_title() << "    " << A->get_author() << "    " << A->get_publication_year() << "    " << A->get_availability() << '\n';
            Articals_returning <<"date_of_returnin : " ;
            date d;
            d.printDate(Articals_returning);
            Articals_returning<<" borrower : "<<name<<"\n";
            Articals_returning.close(); // Close the file after writing
        }
        else
        {
            cout << "Error opening file.\n";
        }
    }
    
};
    


int articals::nbofArticals = 0;
inline std::ofstream articals::Articals;
inline std::ofstream articals::Articals_borrow;
inline std::ofstream articals::Articals_returning;



#endif