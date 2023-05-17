int Myid;
vector<Users> users_vec;
unordered_map<int, Users>users;
set<int> usersID;
queue<Users>waiting_list;
queue<Users>SecDoseWaitingList;
float TOTALUSERS = 0;
Users u;
fstream myfile;
//--------------------------------------------





void Register(string user_name, int user_id, string user_pass, string user_gender, int user_age, string user_govern, string user_vaccinted, string num_of_dose);
void Login(string, string);
void Password_validation(string);
bool CheckRegisteredID(int id);
void DisplayMyRecord();
void edit_user_data();
void Delete_MyACC();
void vaccinationState_stat();
void load();
void save();
void accepting_vaccinated(int number_of_user);
void get_vaccinted_user();

//--------------------- admin ------------------------------

void display_perc_of_gender(char kind);
void display_perc_of_doses(int dose_num);
void display_record(int id);
void display_records_filterd(string num_doses, int age);
void delete_record(int id);


//----------------------------------------------------------






int main() {

    Register("moaz", 1, "27007447", "male", 19, "cairo", "yes", "1");
    Register("maryam", 4, "142003", "girl", 20, "cairo", "yes", "3");
    Register("omnia", 6, "27007576", "girl", 20, "cairo", "yes", "2");
    Register("nada", 2, "27007511", "girl", 18, "cairo", "yes", "3");
    Register("saleh", 5, "27007555", "male", 19, "sudan", "yes", "3");
    Register("youssef", 9, "27007787", "male", 20, "cairo", "no", "0");
    Register("malak", 8, "27007333", "girl", 19, "cairo", "no", "0");
    Register("kiro", 7, "27007444", "male", 21, "cairo", "yes", "2");
    Register("menna", 3, "27007123", "girl", 21, "cairo", "no", "0");
    display_perc_of_gender('m');
    display_perc_of_gender('f');
    cout << "------------------------\n";

    display_perc_of_doses(0);
    display_perc_of_doses(1);
    display_perc_of_doses(2);
    cout << "------------------------\n";

    display_record(4);
    cout << "------------------------\n";
    display_records_filterd("2", 20);
    cout << "------------------------\n";
    delete_record(5);
    display_record(5);

    /*cout << users[0].id << endl;*/

    cout << TOTALUSERS << endl;



    int choice;
    int option;
    int your_choice;
    string x;
    string id;
    string password;
    string username;
    cout << endl;
    cout << "               ***********************************************           " << endl;
    cout << "                    WELCOME TO VACCINE TRACKING SYSTEM                    " << endl;
    cout << "               ***********************************************           " << endl;
    cout << endl;
    cout << endl;
    cout << "\t1. Log in as an admin or user" << endl;
    cout << "\t2. Register as a new user" << endl;
    cout << "\t3. Exit Program" << endl;
    cout << "\tPlease enter number of your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:

        //login function
        cout << "\t\t\t\t\t ===================================" << endl;
        cout << "\t\t\t\t\t Welcome to our Vaccine Tracking System!!!! " << endl;
        cout << "\t\t\t\t\t ===================================\n\n";
        cout << "\t1. Log in as an admin or user" << endl;
        cout << "\t2. Register as a new user" << endl;
        cout << "\t3. Exit Program" << endl;
        cout << "\tPlease enter number of your choice: ";
        system("cls");
        Login(id, password);
        system("cls");//clearing the console
        break;

    case 2:

        //Registeration function
        system("cls");
        Registeration();
        //insert user

        system("PAUSE");
        system("cls");
        //clearing the console
        break;

    case 3:

        //exit program
        //clearing the console
        system("CLS");
        cout << "               ***********************************************           " << endl;
        cout << "                      THANKS FOR USING OUR APPLICATION                  " << endl;
        cout << "                              HAVE A NICE DAY !             " << endl;
        cout << "               ***********************************************           " << endl;
        exit(0);
        break;

    default:
        //displayTitle();
        cout << "\tInvalid Choice" << endl;

    }
    return 0;
}






void Registeration()
{

    cout << "\tMake sure the National ID you are using aren't already registered." << endl;
    cout << "\tPlease fill in the following information to create your record:" << endl;
    cout << endl;
lab:
    cout << "\tEnter the First name: ";
    cin >> u.fullName;
    for (int i = 0; i < u.fullName.size(); i++) {
        if (isalpha(u.fullName[i]) == 0) {
            cout << "\tInvalid, name must contain letters only." << endl;
            goto lab;
            break;
        }
    }

    //id
    cout << "Enter the id:";
    while (u.id < 13) {
        cout << "\tInvalid ID , please re-enter your ID: " << endl;
    }
    do
    {
        CheckRegisteredID(u.id);
        cin >> u.id;
    } while (CheckRegisteredID(u.id) == false);
    CheckRegisteredID(u.id);


    createPass();

    cout << endl;


    cout << "\tPlease enter your age: ";
    while (!(cin >> u.age)) {
        cout << "\tInvalid Age\n ";
        cin.clear();
        cin.ignore(123, '\n');
        cout << "\tplease enter a correct age: ";

    }

    cout << endl;

    cout << "\tPlease choose gender F for female or M for male: ";
    cin >> u.gender;
    while (u.gender != 'F' && u.gender != 'M' && u.gender != 'm' && u.gender != 'f') {
        cout << "\tInvalid value, please re-enter: ";
        cin >> u.gender;

    }


    getGovernorate();



    myfile.open("all.txt", ios::app);

    myfile << u.id << endl;
    myfile.close();
    string fn = u.id + ".txt";

    myfile.open(fn, ios::app);
    myfile << u.fullName << endl;
    myfile << u.id << endl;
    myfile << u.passConfirm << endl;
    myfile << u.age << endl;
    myfile << u.gender << endl;
    myfile << u.governorate << endl;

    gotVaccine();

    myfile << u.num_of_dose << endl;
    myfile.close();

    cout << "\tYour record is successfully saved." << endl;

}

bool CheckRegisteredID(int id) {
    if (usersID.find(id) != usersID.end())
    {
        return true;
    }
    else
        return false;

}







//Verifying User Password
void createPass()
{
    bool msg = true;
    u.password = "";
    u.passConfirm = "";

    cout << "\tCreate a new password : ";
    cin >> u.password;

    cout << "\tConfirm your password : ";
    cin >> u.passConfirm;

    if (msg) {

        if (u.password == u.passConfirm) {
            cout << "\n\tPassword created successfully" << endl;

        }
        else {
            cout << "\n\tPasswords don't match , please try again" << endl;
            createPass();
        }
    }
}


void getGovernorate() {
    int choice;
    cout << endl;
    cout << "\tPlease enter number of governorate you are currently living at: ";
    cout << "\t1-Cairo " << endl;
    cout << "\t2-Giza " << endl;
    cout << "\t3-Alexandria  " << endl;
    cout << "\t4- Sharqia " << endl;
    cout << "\t5-Port Said " << endl;
    cout << "\t6- Other " << endl;
    cout << endl;
    cin >> choice;

    switch (choice) {
    case 1:
        u.governorate = "Cairo";
        break;
    case 2:
        u.governorate = "Alexandria";
        break;
    case 3:
        u.governorate = "Giza";
        break;
    case 4:
        u.governorate = "Sharqia";
        break;
    case 5:
        u.governorate = "PortSaid";
        break;
    case 6:
        u.governorate = "other";
        break;
    default:
    {
        cout << "\tInvalid value entered.\n\tPlease make sure to enter a value from the  options below." << endl;
        cout << endl;
        cout << "\tPlease enter number of governorate you are currently living at: ";
        cout << "\t1-Cairo " << endl;
        cout << "\t2-Giza " << endl;
        cout << "\t3-Alexandria  " << endl;
        cout << "\t4- Sharqia " << endl;
        cout << "\t5-Port Said " << endl;
        cout << "\t6- Other " << endl;
        cout << endl;
        cin >> choice;


    }
    }
}


//Managing User Vaccine
void gotVaccine() {
    char ans;
S:
    cout << "\tDid you get the COIVD-19 Vaccine? y/n : ";
    while (!(cin >> ans)) {
        cout << "\tInvalid Input.";
        cin.clear();
        cin.ignore(123, '\n');
        goto S;
        break;

    }

    switch (ans)
    {
    case 'y':
    case'Y':
    {
    label:
    E:
        cout << "\tHave you taken 1 or 2 doses? 1/2 : ";
        while (!(cin >> u.num_of_dose)) {
            cout << "\tInvalid Input. ";
            cin.clear();
            cin.ignore(123, '\n');
        }

        switch (u.num_of_dose) {
        case 1:
        {
            cout << "\tYou will be added on 2nd dose waiting list" << endl;
            //put them in the second dose waiting list
            SecDoseWaitingList.enQueue(u.id);
            break;
        }
        case 2:
        {
            u.fullyVaccinated = true;
            break;
        }
        default:
        {
            cout << "\tInvalid choice" << endl;
            goto label;
            break;
        }
        }

        break;
    }
    case 'n':
    case'N':
    {
        u.vaccinated = false;
        u.num_of_dose = 0; //in file
        cout << "\tYou will be registered into our waiting list" << endl;
        //put them is the first dose waiting list
        waiting_list.(u.id);
        break;
    }
    default:
        cout << "\tInvalid choice" << endl;
        gotVaccine();
        break;

    }

}


//Queues Implemented Using Linked List
void queue::enQueue(string id) {
    Node* temp = new Node(id);

    if (back == NULL) { //empty
        front = back = temp;
        return;
    }
    back->next = temp;
    back = temp;
}
void Queue::deQueue(string id)
{
    // If queue is empty, return NULL.
    if (front == NULL)
        return;

    // Store previous front and
    // move front one node ahead
    Node* temp = front;
    front = front->next;

    // If front becomes NULL, then
    // change rear also as NULL
    if (front == NULL)
        back = NULL;

    delete (temp);
}