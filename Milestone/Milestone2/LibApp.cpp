#include "LibApp.h"
#include <iostream>
using namespace std;
namespace sdds {
	bool LibApp::confirm(const char* message)
	{
		Menu mes(message);
		mes << "Yes";
		int runMenu = mes.run();
		if (runMenu)
		{
			return true;
		}
		else
		{
		return false;
		}
	}
	void LibApp::load()
	{
		cout << "Loading Data\n";
	}
	void LibApp::save()
	{
		cout << "Saving Data\n";
	}
	void LibApp::search()
	{
		cout << "Searching for publication\n";
	}
	void LibApp::returnPub()
	{
		search();
		cout << "Returning publication\n";
		cout << "Publication returned\n\n";
		m_changed = true;
	}
	void LibApp::newPublication()
	{
		cout << "Adding new publication to library\n";
		if (confirm("Add this publication to library?"))
		{
			m_changed = true;
			cout << "Publication added\n";
		}
			cout << '\n';
	}
	void LibApp::removePublication()
	{
		cout << "Removing publication from library\n";
		cout << "Searching for publication" << endl;
		if (confirm("Remove this publication from the library?"))
		{
			m_changed = true;
			cout << "Publication removed\n\n";
		}
	}
	void LibApp::checkOutPub()
	{
		search();
		if (confirm("Check out publication?"))
		{
			m_changed = true;
			cout << "Publication checked out\n\n";
		}
	}
	LibApp::LibApp()
	{
		m_mainMenu << "Add New Publication" << "Remove Publication" << "Checkout publication from library" << "Return publication to library";
		m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";
		load();
	}
	void LibApp::run()
	{
	
		while (1)
		{


			int choice = m_mainMenu.run();

			if (choice == 1)
			{
				newPublication();
			}
			else if (choice == 2)
			{
				removePublication();
			}
			else if (choice == 3)
			{
				checkOutPub();
			}
			else if (choice == 4)
			{
				returnPub();
			}
			else if (choice == 0)
			{

				

				if (m_changed)
				{
					int cc = m_exitMenu.run();

					if (cc == 1)
					{
						save();
						break;
					}
					else if (cc == 2)
					{
					cout <<'\n';
					;
					}
					else if (cc == 0)
					{

						if (confirm("This will discard all the changes are you sure?"))
						{
							break;
						}
					}
					
					
				}
				else {
					break;
				}

			}
			
			
		}
		cout << endl;
		cout << "-------------------------------------------" << endl;
		cout << "Thanks for using Seneca Library Application" << endl;
			
		
	}






}