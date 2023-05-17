#pragma once

#include <iostream>
#include<vector>
using namespace std;

class functions
{
public:
	
	
	static void Register(string user_name, int user_id, string user_pass, string user_gender, int user_age, string user_govern, string user_vaccinted, string num_of_dose);
	static void Login(string, string);
	static void Password_validation(string);
	static void ID_validation(string);
	static void DisplayMyRecord();
	static void edit_user_data();
	static void Delete_MyACC();
	static void vaccinationState_stat();
	static void load();
	
};
	



