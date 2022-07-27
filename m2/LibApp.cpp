/*---------------------------------------------------------
Name:        Samarth Sunilkumar Patel
Student ID:  150061208
Seneca Email:sspatel65@myseneca.ca
Section:     NBB
Date:	     21 July,2022
------------------------------------------------------------*/



#include "LibApp.h"

using namespace std;

namespace sdds
{
    // constructor
    LibApp::LibApp() : m_changed(false), m_mainMenu("Seneca Library Application"), m_exitMenu("Changes have been made to the data, what would you like to do?")
    {
        m_mainMenu << "Add New Publication"
                   << "Remove Publication"
                   << "Checkout publication from library"
                   << "Return publication to library";
        m_exitMenu << "Save changes and exit"
                   << "Cancel and go back to the main menu";
        load();
    }
    // destructor
    LibApp::~LibApp()
    {
    }
    // bool confirm(const char* message);
    bool LibApp::confirm(const char *message)
    {
        Menu confirmMenu(message);
        confirmMenu << "Yes";
        if (confirmMenu.run())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
// void newPublication();
    void LibApp::newPublication()
    {
        cout << "Adding new publication to library" << endl;
        if (confirm("Add this publication to library?"))
        {
            cout << "Publication added" << endl;
            m_changed = true;
        }
    }

// void search();
    void LibApp::search()
    {
        cout << "Searching for publication" << endl;
    }
    // void returnPub();
    void LibApp::returnPub()
    {
        search();
        cout << "Returning publication" << endl;
        cout << "Publication returned" << endl;
        m_changed = true;
    }

    // void load();
    void LibApp::load()
    {
        cout << "Loading Data" << endl;
    }
    // void save();
    void LibApp::save()
    {
        cout << "Saving Data" << endl;
    }

    
    

// void checkOutPub();
    void LibApp::checkOutPub()
    {
        search();
        if (confirm("Check out publication?"))
        {
            cout << "Publication checked out" << endl;
            m_changed = true;
        }
    }

    // void removePublication();
    void LibApp::removePublication()
    {
        cout << "Removing publication from library" << endl;
        search();
        if (confirm("Remove this publication from the library?"))
        {
            cout << "Publication removed" << endl;
            m_changed = true;
        }
    }

    
    // void exitMessage();
    void LibApp::exitMessage()
    {
        cout << "-------------------------------------------\n";
        cout << "Thanks for using Seneca Library Application\n";
    }
    // void run();
    void LibApp::run()
    {
        int choice = -1;
        while (choice != 0)
        {
            choice = m_mainMenu.run();
            switch (choice)
            {
	   case 0:
                if (m_changed)
                {
                    choice = m_exitMenu.run();
                    switch (choice)
                    {
                    case 1:
                        save();
                        cout << "\n";
                        exitMessage();
                        return;
                    case 2:
                        break;
                    case 0:
                        if (confirm("This will discard all the changes are you sure?"))
                        {
                            cout << "\n";
                            exitMessage();
                            return;
                        }
                    }
                }
                else
                {
                    cout << "\n";
                    exitMessage();
                    return;
                }
                break;
            case 1:
                newPublication();
                break;
            case 2:
                removePublication();
                break;
            case 3:
                checkOutPub();
                break;
            case 4:
                returnPub();
                break;
            
            }
            cout << "\n";
        }
    }

} // namespace sdds
