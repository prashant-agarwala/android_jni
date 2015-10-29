#ifndef __APAYI_EXCEPTION_
#define __APAYI_EXCEPTION_

#include <string>
#include <exception>

class apayi_exception : public std::exception
{
public:
	apayi_exception(const std::string& msg) : msg_(msg) {}
	virtual const char* what() const throw() { return msg_.c_str(); }
	virtual ~apayi_exception() throw() {}
private:
	std::string msg_;
};

class apayi_business_exception : public apayi_exception
{
public:
	apayi_business_exception(const std::string& field, const std::string& description)
	: description_(description),
	field_(field),
	apayi_exception(field + ": " + description)
	{}
	std::string get_field() {return field_;}
	std::string get_description() {return description_;}
	virtual ~apayi_business_exception() throw() {}
private:
	std::string field_;
	std::string description_;
};
#endif
