#ifndef  SDDS_NAME_H
#define SDDS_NAME_H
#include <iostream>
namespace sdds {
	class Name {
	private:
		char* m_valueN;
	public:
		Name();
		Name(const char* name);
		virtual ~Name();
		Name(const Name& name);
		Name& operator=(const Name& name);
		virtual operator const char* () const;
		virtual operator bool() const;
		virtual std::ostream& display(std::ostream& ostr = std::cout) const;
		virtual std::istream& read(std::istream& ist = std::cin);
	};
	std::ostream& operator<<(std::ostream& out, const Name& name);
	std::istream& operator>>(std::istream& in, Name& name);
}
#endif // ! SDDS_NAME_H
