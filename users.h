#ifndef USERS_H
#define USERS_H
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

template <typename T>
class users
{
private:
    string first_name;
    string last_name;
    string who;
    static vector<T *> usersList;
    static int usersnb;

public:
    users(const string &fn,const string &ln,const string &wh) : first_name(fn), last_name(ln), who(wh)
    {
        usersList.push_back(static_cast<T *>(this));
        usersnb++;
    }
    static void add_user(const string& firstname , const string& lastname , const string& wh){
        users(firstname , lastname ,wh );

    }

    virtual void print() const
    {
        cout << who << "        " << first_name << "        " << last_name;
    }

    static void print_list()
    {
        cout << "who " << "        " << "first name " << "        " << "last name \n";
        for (const T *user : usersList)
        {
            user->print();
            cout << endl;
        }
    }

    static void remove(const string &firstname, const string &lastname)
    {
        for (auto it = usersList.begin(); it != usersList.end(); ++it)
        {
            if ((*it)->get_first_name() == firstname && (*it)->get_last_name() == lastname)
            {
                delete *it;
                usersList.erase(it);
                usersnb--;
            }
        }
    }

    //getters
    string get_first_name(){return first_name;}
    string get_last_name(){return last_name;}
    string get_who(){return who;}
};

template <typename T>
vector<T *> users<T>::usersList;

template <typename T>
int users<T>::usersnb = 0;

#endif