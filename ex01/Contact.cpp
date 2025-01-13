#include <iostream>
#include "Contact.class.hpp"

Contact::Contact(void){
	this->first_name = "";
	this->last_name = "";
	this->nickname = "";
	this->darkest_secret = "";
	this->phone_number = -1;
	return ;
}

Contact::Contact( std::string fn, std::string ln, std::string nm, std::string ds, int pn):
first_name(fn), last_name(ln), nickname(nm), darkest_secret(ds), phone_number(pn)
{
	return ;
}

Contact::~Contact(void){
	return ;
}