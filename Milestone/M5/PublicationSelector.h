#ifndef SDDS_PUBLICATION_SELECTOR_H
#define SDDS_PUBLICATION_SELECTOR_H
#include "Publication.h"
namespace sdds {
	class PublicationSelector {
		const int units{ 10 };
		const int pSize{};
		const Publication** m_pub{};
		char ps_title[81]{};
		int ps_cpage{ 1 };
		int ps_array{};
		int ps_total{};
		void display(int pg)const;
		int select() const;
	public:
		PublicationSelector(const char* ps_title = "Select a publication: ", int psize = 15);
		~PublicationSelector();
		PublicationSelector(const PublicationSelector&) = delete;
		PublicationSelector& operator<<(const Publication* pp);
		PublicationSelector& operator<<(const Publication& pp);
		operator bool() const;
		void neww();
		void sort();
		int run();
		
	};
}
#endif // !SDDS_PUBLICATION_SELECTOR_H
