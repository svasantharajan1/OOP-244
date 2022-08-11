/*
Student Name: Vasantharajan Sharmilann
SID: 142642180
Milestone 5
File: LibApp.cpp

All the code done in this milestone is done purely by me, as i have only used resouces from previous lecture and notes.


*/
#define _CRT_SECURE_NO_WARNINGS
#include "LibApp.h"
#include "Book.h"
#include "PublicationSelector.h"
#include "Utils.h"
#include "Date.h"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
namespace sdds {
	bool LibApp::confirm(const char* message) {
		Menu confirm(message);
		confirm << "Yes";
		return !!(~confirm);
	}
	void LibApp::load() {
		char type{};
		cout << "Loading Data" << endl;
		ifstream infile;
		infile.open(P_name);
		for (int i = 0; infile; i++) {
			infile >> type;
			infile.ignore();
			if (infile)
			 {
				if (type == 'B')
				 {
					P_p[i] = new Book;
				}
				else if (type == 'P') 
				{
					P_p[i] = new Publication;
				}
				if (P_p[i])
				 {
					infile >> *P_p[i];
					P_total++;
				}   
			}
		}
		P_last= P_p[P_total - 1]->getRef();
	}
	void LibApp::save() {
		cout << "Saving Data" << endl;
		ofstream outfile(P_name);
		for (int i = 0; i < P_total; i++) 
		{
			if (P_p[i]->getRef() != 0)
			 {
				outfile << *P_p[i] << endl;
			}
		}
	}
	int LibApp::search(int searchMode) {  
		int select{};
		char title[256]{};
		PublicationSelector ps("Select one of the following found matches:");
		int matches = 0;
		int ref{};
		select = ~P_menu;
		cout << "Publication Title: ";
		cin.getline(title, 256);
		if (select) {
			for (int i = 0; i < P_total; i++) 
			{
				if (P_p[i]->getRef() != 0) 
				{  
					if (select == 1) 
					{ 
						if (P_p[i]->type() == 'B') 
						{ 
							if (strstr(*P_p[i], title)) 
							{
								if (searchMode == 2) 
								{
									if (P_p[i]->onLoan()) 
									{
										ps << P_p[i];
										matches++;
									}
								}
								else if (searchMode == 3)
								 {
									if (!P_p[i]->onLoan()) 
									{
										ps << P_p[i];
										matches++;
									}
								}
								else {
									ps << P_p[i];
									matches++;
								}
							}
						}
					}
					else if (select == 2) 
					{  
						if (P_p[i]->type() == 'P') 
						{
							if (strstr(*P_p[i], title)) 
							{
								if (searchMode == 2) 
								{
									if (P_p[i]->onLoan()) 
									{
										ps << P_p[i];
										matches++;
									}
								}
								else if (searchMode == 3) 
								{
									if (!P_p[i]->onLoan())
									 {
										ps << P_p[i];
										matches++;
									}
								}
								else {
									ps << P_p[i];
									matches++;
								}
							}
						}
					}
				}
			}
			if (matches)
			 {
				ps.sort();
				ref = ps.run();
				if (!ref) select = 0;
			}
			else
			 {
				cout << "No matches found!" << endl;
			}
		}
		if (!select) 
		{
			cout << "Aborted!" << endl;

		}
		return ref;
	}
	void LibApp::returnPub()
	 {
		int ref{};
		int index{};
		int loanDays{};
		double penaltyFee{};
		Date setoday;
		cout << "Return publication to the library" << endl;
		ref = search(2);
		if (ref) 
		{
			for (int i = 0; i < P_total; i++)
			 {
				if (P_p[i]->getRef() == ref) 
				{
					index = i;
					i = P_total;
				}
			}
			cout << *P_p[index] << endl;
			if (confirm("Return Publication?")) 
			{
				loanDays = setoday - P_p[index]->checkoutDate();
				if (loanDays > 15) 
				{
					penaltyFee = (loanDays - 15) * 0.50;
					cout << "Please pay $";
					cout.setf(ios::fixed);
					cout.precision(2);
					cout << penaltyFee << " penalty for being "
						<< (loanDays - 15) << " days late!" << endl;
				}
				P_p[index]->set(0);
				cout << "Publication returned" << endl;
				m_changed = true;
			}
		}
	}
	void LibApp::newPublication() 
	{
		int select{};
		Publication* pub{};
		if (P_total == SDDS_LIBRARY_CAPACITY)
		 {
			cout << "Library is at its maximum capacity!" << endl;
		}
		else {
			cout << "Adding new publication to the library" << endl;
			select = ~P_menu;
			if (select == 1) {
				pub = new Book;
			}
			else if (select == 2)
			 {
				pub = new Publication;
			}

			if (select) {
				cin >> *pub;
				if (cin.fail()) {
					cin.clear();
					cin.ignore(1000, '\n');
					cout << "Aborted!";
				}
				else {
					if (confirm("Add this publication to the library?")) {
						if (pub) {
							P_last++;
							pub->setRef(P_last);
							P_p[P_total] = pub;
							P_total++;
							m_changed = true;
							cout << "Publication added" << endl;
						}
						else {
							cout << "Failed to add publication!";
							delete pub;
						}
					}
					else {
						select = 0;
					}
				}
			}
			if (!select) cout << "Aborted!" << endl;
		}
	}
	void LibApp::removePublication() {
		int ref{};
		int index{};
		cout << "Removing publication from the library" << endl;
		ref = search(1);
		if (ref) {
			for (int i = 0; i < P_total; i++) {
				if (P_p[i]->getRef() == ref) {
					index = i;
					i = P_total;
				}
			}
			cout << *P_p[index] << endl;
			if (confirm("Remove this publication from the library?")) {
				P_p[index]->setRef(0);
				m_changed = true;
				cout << "Publication removed" << endl;
			}
		}
	}
	void LibApp::checkOutPub() {
		int ref{};
		int index{};
		int membership{};
		cout << "Checkout publication from the library" << endl;
		ref = search(3);
		if (ref) {
			for (int i = 0; i < P_total; i++) {
				if (P_p[i]->getRef() == ref) {
					index = i;
				}
			}
			cout << *P_p[index] << endl;
			if (confirm("Check out publication?")) {
				cout << "Enter Membership number: ";
				do {
					membership = getInt();
				} while (!(membership > 9999 && membership < 100000) && cout << "Invalid membership number, try again: ");
				P_p[index]->set(membership);
				m_changed = true;
				cout << "Publication checked out" << endl;
			}
		}
	}
	LibApp::LibApp(const char* filename) : 
		P_menu("Choose the type of publication:"),
		P_mainMenu("Seneca Library Application"),
		P_exitMenu("Changes have been made to the data, what would you like to do?") 
		{
		strcpy(P_name, filename);
		P_total = 0;
		m_changed = false;
		P_menu  << "Book" 
				   << "Publication";
		P_mainMenu << "Add New Publication"
				   << "Remove Publication"
				   << "Checkout publication from library"
				   << "Return publication to library";
		P_exitMenu << "Save changes and exit"
				   << "Cancel and go back to the main menu";
		load();
	}

	void LibApp::run() {
		int select{};
		bool exit{};
		do {
			
			select = ~P_mainMenu;
			if (!select) {           
				if (m_changed) {
					
					select = ~P_exitMenu;
					switch (select) {
					case 1:
						save();
						exit = true;
						break;
					case 2:
						cout << endl;
						exit = false;
						break;
					default:
						confirm("This will discard all the changes are you sure?") ?
							exit = true : exit = false;
					}
				}
				else {
					exit = true;
				}
			}
			else {    
				exit = false;
				switch (select) {
				case 1:
					newPublication();
					cout << endl;
					break;
				case 2:
					removePublication();
					cout << endl;
					break;
				case 3:
					checkOutPub();
					cout << endl;
					break;
				default:
					returnPub();
					cout << endl;
				}
			}
		} while (!exit);
		cout << endl << "-------------------------------------------" << endl
			<< "Thanks for using Seneca Library Application" << endl;
	}

	Publication* LibApp::getPub(int libRef) {
		int index = -1;
		for (int i = 0; i < P_total && index == -1; i++) {
			if (P_p[i]->getRef() == libRef) index = i;
		}
		if (index == -1) index = 0;
		return P_p[index];
	}

	LibApp::~LibApp() {
		for (int i = 0; i < P_total; i++) {
			delete P_p[i];
		}
	}

}