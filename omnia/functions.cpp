#include <iostream>
#include "Users.h"
#include <fstream>
#include <vector>
#include "functions.h"
#include "global.h"

using namespace std;




void functions::Register(string user_name, int user_id, string user_pass, string user_gender, int user_age, string user_govern, string user_vaccinted, string num_of_dose)
{
	ofstream file;
	ofstream file2;
	file.open("users\\"+ to_string(user_id) +".txt");
	if (file.is_open()) {
		file << user_name << " " << user_id << " " <<user_pass << " " << user_gender << " " << user_age << " " << user_govern << " " << user_vaccinted << " " << num_of_dose;
	}
	file.close();
	file2.open("users\\USERSID.txt");
	if (file2.is_open())
	{
		file2 << user_id;
	}
	file2.close();
	Users temp(user_name, user_id, user_pass, user_gender, user_age, user_govern, user_vaccinted, num_of_dose);
	global::usersID.push_back(user_id);
	global::users.push_back(temp);
}
void functions::Login(string, string) {

}
void functions::Password_validation(string) {

}
void functions::ID_validation(string) {

}
void functions::DisplayMyRecord() {

}
void functions::edit_user_data() {

}
void functions::Delete_MyACC() {

}
void functions::vaccinationState_stat() {

}
void functions::load()
{

	string fullName;
	int id;
	string password;
	string gender;;
	string governorate;
	string vaccinated;
	string num_of_dose;
	int age;





	ifstream file("users\\USERSID.txt");
	string ids;
	
	while (!file.eof())
	{
		global::TOTALUSERS++;
		getline(file, ids);
		global::usersID.push_back(stoi(ids));
		
	}
	file.close();
	for (int i = 0; i < global::TOTALUSERS; i++)
	{
		ifstream file2("users\\" + to_string(global::usersID[i]) + ".txt");
		while (file >> fullName >> id >> password >> gender >> age >> governorate >> vaccinated >> num_of_dose)
		{
			Users temp(fullName, id, password, gender, age, governorate, vaccinated, num_of_dose);
			global::users.push_back(temp);
		}
		file2.close();
	}


}
