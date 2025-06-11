#ifndef BOOKS_H
#define BOOKS_H
#include "resources.h"
#include "date.h"
#include "users.h"
class books : public resources<books>
{
private:
    static ofstream Books;
    static ofstream Books_borrow;
    static ofstream Books_return;

    static int nbofBooks;
    //static vector<books *> listof_books;

public:
    books(const string &tit, const string &auth, int year, int nb) : resources<books>(tit, auth, year, "book", nb){}

    static void add_book(const string &tit, const string &auth, int year, int nb)
    {
        books *b = new books(tit, auth, year, nb);
        nbofBooks++;
        storebooks(b);
    }

    static void Borrow_book(const string &tit, const string &auth, const string& typ , int year)
    {
        books* b;
        resources::Borrow(tit , auth , year , typ , b );
        store_borrow(b , b->get_nbofborrowing());
    }

    void set_availability()override
    {
        resources::set_availability();
    }

    void history()override
    {
        resources::history();
    }

    static void all_history_of_books()
    {
        resources::all_history();
    }

    static void returning_book(const string &tit,const string &auth, int year, const string &typ,const string &name)
    {
        books* B;
        resources::returning(tit , auth , year , typ , name , B);
        store_return_books(B , name);

    }

    static void storebooks(books *b)
    {
        Books.open("books.txt", ios::app);

        if (Books.is_open())
        {
            Books << b->get_title() << "    " << b->get_author() << "    " << b->get_publication_year() << "    " << b->get_availability() << '\n';
            Books.close(); // Close the file after writing
        }
        else
        {
            cout << "Error opening file.\n";
        }
    }

     static void store_borrow(books *b , int pos )
    {
        Books_borrow.open("books_borrow.txt", ios::app);

        if (Books_borrow.is_open())
        {
            Books_borrow << b->get_title() << "    " << b->get_author() << "    " << b->get_publication_year() << "    " << b->get_availability() << '\n';
            Books_borrow <<"date_of_borrowing : " ;
            b->print_date_of_borrowing(pos , Books_borrow);
            Books_borrow<<"date_of_returnin : ";
            b->print_date_of_returning(pos , Books_borrow);
            Books_borrow<<"  borrower : ";
            Books_borrow<<b->print_borrower(pos );
            Books_borrow<<'\n';
            Books_borrow.close(); // Close the file after writing
        }
        else
        {
            cout << "Error opening file.\n";
        }
    }
     static void store_return_books(books* A , const string& name )
    {
        Books_return.open("Books_return.txt", ios::app);

        if (Books_return.is_open())
        {
            Books_return << A->get_title() << "    " << A->get_author() << "    " << A->get_publication_year() << "    " << A->get_availability() << '\n';
            Books_return<<"date_of_returnin : " ;
            date d;
            d.printDate(Books_return);
            Books_return<<" borrower : "<<name<<"\n";
            Books_return.close(); // Close the file after writing
        }
        else
        {
            cout << "Error opening file.\n";
        }
    }
    
};
    


int books::nbofBooks = 0;
inline std::ofstream books::Books;
inline std::ofstream books::Books_borrow;
inline std::ofstream books::Books_return;



#endif