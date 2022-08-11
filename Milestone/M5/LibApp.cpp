/*
Student Name: Vasantharajan Sharmilann
SID: 142642180
Milestone 5
File: LibApp.cpp

All the code done in this milestone is done purely by me, as i have only used resouces from previous lecture and notes.


*/

#define _CRT_SECURE_NO_WARNINGS
#include"LibApp.h"
#include <fstream>
#include <cstring>
#include <iostream>
#include"PublicationSelector.h"
#include"Book.h"
#include"Date.h"
#include"Utils.h"
using namespace std;
namespace sdds {
	bool LibApp::confirm(const char* conf)
	{
		Menu confirm(conf);
		confirm << "Yes";
		return !! (~confirm);
	}
	void LibApp::load()
	{
		char type{};
		cout << "Loading Data" << endl;
		ifstream infile;
		infile.open(l_Name);
		for (int i = 0; infile; i++)
		{
			infile >> type;
			infile.ignore();
			if (infile)
			{
				if (type == 'B')
				{
					L_publication[i] = new Book;
				}
				else if (type == 'P')
				{
					L_publication[i] = new Publication;
				}
				if (L_publication[i])
				{
					infile >> *L_publication[i];
					L_total++;
				}
			}
		}
		L_last = L_publication[L_total - 1]->getRef();
	}
	void LibApp::save()
	{
		cout << "Saving Data" << endl;
		ofstream outfile(l_Name);
		for (int i = 0; i < L_total; i++)
		{
			if (L_publication[i]->getRef() != 0)
			{
				outfile << *L_publication[i] << endl;
			}
		}

	}
	int LibApp::search(int item)
	{
		int option{};
		char title[256]{};
		PublicationSelector p("Select one of the following found matches:");
		int choices = 0;
		int reff{};
		option = ~M_pubMenu;
		cout << "Publication Title: ";
		cin.getline(title, 256);
		if (option)
		{
			for (int i = 0; i < L_total; i++)
			{
				if (L_publication[i]->getRef() != 0)
				{
					if (option == 1)
					{
						if (L_publication[i]->type() == 'B')
						{
							if (strstr(*L_publication[i], title))
							{
								if (item == 2)
								{
									if (L_publication[i]->onLoan())
									{
										p << L_publication[i];
										choices++;

									}
								}
								else if (item == 3)
								{
									if (!L_publication[i]->onLoan())
									{
										p << L_publication[i];
										choices++;
									}
								}
								else
								{
									p << L_publication[i];
									choices++;
								}
							}
						}
					}
					else if (option == 2)
					{
						if (L_publication[i]->type() == 'P')
						{
							if (strstr(*L_publication[i], title))
							{
								if (item == 2)
								{
									if (L_publication[i]->onLoan())
									{
										p << L_publication[i];
										choices++;
									}
								}
								else if (item == 3)
								{
									if (!L_publication[i]->onLoan())
									{
										p << L_publication[i];
										choices++;
									}
								}
								else
								{
									p << L_publication[i];
									choices++;
								}
							}
						}
					}
				
				}

			}

			if (choices)
			{
				p.sort();
				reff = p.run();
				if (!reff)
				{
					option = 0;
				}
				
			}
			else
			{
				cout << "No matches found!" << endl;
			}

		}

		if (!option)
		{
			cout << "Aborted" << endl;
		}
		return reff;
	}
	void LibApp::returnToM()
	{
		int referrence{};
		int  loan{};
		int index{};
		double penlty{};
		Date setToday;
		cout << "Return publication to the library" << endl;
		referrence = search(2);
		if (referrence)
		{
			for (int i = 0; i < L_total; i++)
			{
				if (L_publication[i]->getRef() == referrence)
				{
					index = i;
					i = L_total;
				}
			}
			cout << *L_publication[index] << endl;
			if (confirm("Return publication?"))
			{
				loan = setToday - L_publication[index]->checkoutDate();
				if (loan > 15)
				{
					penlty = (loan - 15) * 0.50;
					cout << "Please pay $";
					cout.setf(ios::fixed);
					cout.precision(2);
					cout << penlty << " penalty for being " << (loan - 15) << " days late!" << endl;
				}
				L_publication[index]->set(0);
				cout << "Publication returned" << endl;
				changes = true;

			}
		}

	}
	void LibApp::newPublication()
	{
		int options{};
		Publication* pp{};
		if (L_total == SDDS_LIBRARY_CAPACITY)
		{
			cout << "Library  is at it's maximum capacity!" << endl;

		}
		else
		{
			cout << "Adding new publication to the library" << endl;
			options = ~M_pubMenu;
			if (options == 1)
			{
				pp = new Book;
			}
			else if (options == 2)
			{
				pp = new Publication;
			}
			if (options)
			{
				cin >> *pp;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(1000, '\n');
					cout << "Aborted!";
				}
				else
				{
					if (confirm("Add this publication to the library?"))
					{
						if (pp)
						{
							L_last++;
							pp->setRef(L_last);
							L_publication[L_total] = pp;
							L_total++;
							changes = true;
							cout << "Publication added" << endl;
						}
						else
						{
							cout << "Failed to add publication!";
							delete pp;
						}
					}
					else
					{
						options = 0;
					}
				}
			}
			if (!options)
			{
				cout << "Aborted!" << endl;
			}
		}
	}
	void LibApp::removePublication()
	{
		int reference{};
		int index{};
		cout << "Removing publication from the library" << endl;
		reference = search(1);
		if (reference)
		{
			for (int i = 0; i < L_total; i++)
			{
				if (L_publication[i]->getRef() == reference)
				{
					index = i;
					i = L_total;
				}
			}
			cout << *L_publication[index] << endl;
			if (confirm("Remove this publication from the library?"))
			{
				L_publication[index]->setRef(0);
				changes = true;
				cout << "Publication removed" << endl;
			}
		}
	}
	void LibApp::checkOutPub()
	{
		int references{};
		int memb{};
		int index{};
		cout << "Checkout publication from the library" << endl;
		references = search(3);
		if (references)
		{
			for (int i = 0; i < L_total; i++)
			{
				if (L_publication[i]->getRef() == references)
				{
					index = i;
				}
			}
			cout << *L_publication[index] << endl;
			if (confirm("Check out publicatoin?"))
			{
				cout << "Enter Membership Number: ";
				do
				{
					memb = getInt();
				} while (!(memb > 9999 && memb < 100000) && cout << "Invalid membership number, try again: ");
				L_publication[index]->set(memb);
				changes = true;
				cout << "Publication checked out" << endl;
			}
		}

	}
	LibApp::LibApp(const char* file) :

		M_pubMenu("Choose the type of publication:"),
		m_main("Seneca Library Application"),
		m_exit("Changes have been made to the data, what would you like to do?")
	{
		strcpy(l_Name, file);
		L_total = 0;
		changes = false;
		M_pubMenu << "Book" << "Publication";
		m_main << "Add New Publication" << "Remove Publication" << "Checkout publication from library" << "Return publication to library";
		m_exit << "Save changes and exit" << "Cancel and go back to the main menu";
		load();
	}
	
	void LibApp::run()
	{
		int options{};
		bool exit{};
		do {
			options = ~m_main;
			if (!options)
			{
				if (changes)
				{
					options = ~m_exit;
					switch (options)
					{
					case 1: 
						save();
						exit = true;
						break;

					case 2:
						cout << endl;
						exit = false;
						break;

					default:
						confirm("This will discard all the changes are you sure?") ? exit = true : exit = false;

					}
				}
				else {
					exit = true;
				}
			}
			else
			{
				exit = false;
				switch (options)
				{
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
					returnToM();
					cout << endl;
				}
			}
		} while (!exit);
		cout << endl << "-------------------------------------------" << endl << "Thanks for using Seneca Library Application" << endl;
	}
	Publication* LibApp::getPub(int lib)
	{
		int iii = -1;
		for (int i = 0; i < L_total && iii == -1; i++)
		{
			if (L_publication[i]->getRef() == lib)iii = i;
		}
		if (iii == -1)
		{
			iii = 0;
		}
		return L_publication[iii];
	}
	LibApp::~LibApp()
	{
		for (int i = 0; i < L_total; i++)
		{
			delete L_publication[i];
		}
	}
}