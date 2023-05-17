#include "Users.h"
#include<iostream>
#include<string>


Users::Users(string user_name, int user_id, string user_pass, string user_gender, int user_age, string user_govern, string user_vaccinted, string user_num_of_dose)
{
	this->fullName = user_name;
	this->id = user_id;
	this->password = user_pass;
	this->gender = user_gender;
	this->age = user_age;
	this->governorate = user_govern;
	this->vaccinated = user_vaccinted;
	this->num_of_dose = user_num_of_dose;
}

Users::Users() {
	fullName  = password = gender = governorate = vaccinated = "";
	id = 0;
	age = 0;

}

Users::Users(int user_id, string user_pass)
{
	this->id = user_id;
	this->password = user_pass;
}


Users::~Users(void) {

}

