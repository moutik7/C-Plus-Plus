
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "LibApp.h"
#include "Menu.h"

using namespace std;
namespace sdds {
	LibApp::LibApp() {
		m_changed = false;
		m_fileName[0] = '\0';
		m_mainMenu << "Add New Publication" << "Remove Publication" << "Checkout publication from library" << "Return publication to library";
		m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";
		m_totalNum = 0;
		m_lrn = 0;
		m_pubType << "Book" << "Publication";
		load();
	}
	LibApp::LibApp(const char* fileName) {
		m_changed = false;
		m_fileName[0] = '\0';
		m_mainMenu << "Add New Publication" << "Remove Publication" << "Checkout publication from library" << "Return publication to library";
		m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";
		m_totalNum = 0;
		m_lrn = 0;
		m_pubType << "Book" << "Publication";
		strcpy(m_fileName, fileName);
		load();
	}
	bool LibApp::confirm(const char* message) {
		bool flag = false;
		Menu menu(message);
		menu << "Yes";
		if (menu.run() == 1) {
			flag = true;
		}
		return flag;
	}
	void LibApp::load() {
		for (int i = 0; i < m_totalNum; i++) delete m_p[i];
		char type{};
		cout << "Loading Data" << endl;
		Publication* publication = nullptr;
		ifstream filein(m_fileName);
		m_totalNum = 0;
		while(filein) {
			publication = nullptr;
			filein >> type;
			filein.ignore();
			switch (type) {
			case 'B':
				publication = new Book;
				break;
			case 'P':
				publication = new Publication;
				break;
			}
			if (publication) {
				filein >> *publication;
				if (filein) {
					m_p[m_totalNum++] = publication;
				}
			}
		}
		if(m_totalNum != 0)
			m_lrn = m_p[m_totalNum - 1]->getRef();
		delete publication;
	}
	void LibApp::save() {
		cout << "Saving Data" << endl;
		ofstream fileout(m_fileName);
		for (int i = 0; i < m_totalNum; i++) {
			if (m_p[i]->getRef() != 0) 
				fileout << *m_p[i] << endl;
		}
	}
	int LibApp::search(int option) {
		PublicationSelector selector("Select one of the following found matches:");
		char type{};
		int ref = -1;
		char title[256];
		int menuSel = m_pubType.run();
		switch (menuSel) {
		case 1:
			type = 'B';
			break;
		case 2:
			type = 'P';
			break;
		}
		cin.ignore(1024, '\n');
		cout << "Publication Title: ";
		cin.getline(title, 256, '\n');
		switch (option) {
		case 1: 
			for (int i = 0; i < m_totalNum; i++) {
				if (strstr(*m_p[i], title) && m_p[i]->getRef() != 0 && type == m_p[i]->type())
					selector << m_p[i];
			}
			break;
		case 2:
			for (int i = 0; i < m_totalNum; i++) {
				if (strstr(*m_p[i], title) && m_p[i]->onLoan() && m_p[i]->getRef() != 0 && type == m_p[i]->type())
					selector << m_p[i];
			}
			break;
		case 3:
			for (int i = 0; i < m_totalNum; i++) {
				if (strstr(*m_p[i], title) && !m_p[i]->onLoan() && m_p[i]->getRef() != 0 && type == m_p[i]->type())
					selector << m_p[i];
			}
			break;
		}
		if (selector) {
			selector.sort();
			ref = selector.run();
			if (ref) {
				for (int i = 0; i < m_totalNum; i++) {
					if (ref == m_p[i]->getRef()) {
						cout << *m_p[i] << endl;
						i = m_totalNum;
					}
				}
			}
			else
				cout << "Aborted!" << endl;
		}
		else
			cout << "No matches found!" << endl;
		return ref;
	}
	Publication* LibApp::getPub(int refNum) {
		Publication* publication = nullptr;
		for (int i = 0; i < m_totalNum; i++) {
			if (refNum == m_p[i]->getRef()) {
				publication = m_p[i];
			}
		}
		return publication;
	}
	void LibApp::returnPub() {
		cout << "Return publication to the library" << endl;
		int refNum = search(2);
		if (refNum > 0 && confirm("Return Publication?")) {
			float price = 0;
			Date checkoutDate = getPub(refNum)->checkoutDate();
			Date today;
			int dueDays = (today - checkoutDate);
			if (dueDays > 15) {
				price = 0.50 * float(dueDays - 15);
				cout << "Please pay $" << fixed << setprecision(2) << price << " penalty for being " << (dueDays - 15) << " days late!" << endl;
			}
			getPub(refNum)->set(0);
			m_changed = true;
			cout << "Publication returned" << endl;
		}
	}
	void LibApp::newPublication() {
		if (m_totalNum == SDDS_LIBRARY_CAPACITY)
			cout << "Library is at its maximum capacity!" << endl;
		else {
			cout << "Adding new publication to the library" << endl;
			int menuSel = m_pubType.run();
			Publication* publication = nullptr;
			switch (menuSel) {
			case 1:
				publication = new Book;
				break;
			case 2:
				publication = new Publication;
				break;
			}
			if(menuSel) 
				cin >> *publication;
			if (!cin) {
				cin.clear();
				cin.ignore(1000, '\n');
			}
			else {
				if (menuSel && confirm("Add this publication to the library?")) {
					if (publication) {
						publication->setRef(++m_lrn);
						m_p[m_totalNum++] = publication;
						m_changed = true;
						cout << "Publication added" << endl;
					}
					else {
						cout << "Failed to add the publication!" << endl;
						delete publication;
					}
				}
				else {
					cout << "Aborted!" << endl;
				}
			}
		}
	}
	void LibApp::removePublication() {
		cout << "Removing publication from the library" << endl;
		int refNum = search(1);
		if (refNum > 0 && confirm("Remove this publication from the library?")) {
			getPub(refNum)->setRef(0);
			cout << "Publication removed" << endl;
			m_changed = true;
		}
	}
	void LibApp::checkOutPub() {
		cout << "Checkout publication from the library" << endl;
		int refNum = search(3);
		if (refNum > 0 && confirm("Check out publication?")) {
			int membership = 0;
			cout << "Enter Membership number: ";
			cin >> membership;
			while (membership < 0 || membership > 99999) {
				cout << "Invalid membership number, try again: ";
				cin >> membership;
			}
			getPub(refNum)->set(membership);
			m_changed = true;
			cout << "Publication checked out" << endl;
		}
	}
	void LibApp::run() {
		bool flag = false;
		do {
			int sel = m_mainMenu.run();
			if (sel == 1) {
				newPublication();
			}
			else if (sel == 2) {
				removePublication();
			}
			else if (sel == 3) {
				checkOutPub();
			}
			else if (sel == 4) {
				returnPub();
			}
			else if (sel == 0) {
				if (m_changed == true) {
					int exitSel = m_exitMenu.run();
					if (exitSel == 1) {
						save();
						flag = true;
					}
					else if (exitSel == 2) {
						flag = false;
					}
					else if (exitSel == 0) {
						bool answer = confirm("This will discard all the changes are you sure?");
						if (answer) {
							flag = true;
						}
						else {
							flag = false;
						}
					}
				}
				else {
					flag = true;
				}
			}
			cout << endl;
		} while (!flag);
		cout << "-------------------------------------------" << endl;
		cout << "Thanks for using Seneca Library Application" << endl;
	}
	LibApp::~LibApp() {
		for (int i = 0; i < m_totalNum; i++) {
			delete m_p[i];
		}
	}
}
