#pragma once
#include<string>

using namespace std;
class Users
{
    
public:
	string fullName;
	int id;
	string password;
	string gender;
	string governorate;
	string vaccinated;
	string num_of_dose;
	int age;
	Users();
	Users(string user_name, int user_id, string user_pass, string user_gender, int user_age, string user_govern, string user_vaccinted, string num_of_dose);
	Users(int user_id, string user_pass);

	~Users(void);

};

