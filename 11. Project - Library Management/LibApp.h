
#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include "Menu.h"
#include "Publication.h"
#include "Book.h"
#include "PublicationSelector.h"
#include "Lib.h"

namespace sdds {

    class LibApp {
        char m_fileName[256];
        Publication* m_p[SDDS_LIBRARY_CAPACITY]{};
        int m_totalNum;
        int m_lrn;
        bool m_changed;
        Menu m_pubType{ "Choose the type of publication:" };
        Menu m_mainMenu{ "Seneca Library Application" };
        Menu m_exitMenu{ "Changes have been made to the data, what would you like to do?" };
        bool confirm(const char* message);
        void load();
        void save();
        int search(int option);
        Publication* getPub(int libRef);
        void returnPub();
        void newPublication();
        void removePublication();
        void checkOutPub();
    public:
        LibApp();
        LibApp(const char* name);
        void run();
        virtual ~LibApp();
    };
}
#endif 