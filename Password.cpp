#include<iostream>

using namespace std;

int checkp(string password) {
    if(password.size() > 8) {
        return 1;
    } else {
        return 0;
    }
}

void list(string* name, string* password, int user) {

    for(int i = 0; i < user; i++) {
        cout << "   Employee no." << i+1 << endl;
        cout << "Name: " << name[i+1] << endl;
        cout << endl;

    }
    

}

void namepassword(string *name, string *password, int user)
{

    for (int i = 0; i < user; i++)
    {
        cout << "   Employee no." << i + 1 << endl;
        cout << "Name: " << name[i + 1] << endl;
        cout << "Password: " << password[i + 1] << endl;
        cout << endl;
    }
}

int main() {

    string name[100];
    string password[100];
    string mname;
    string mpassword;

    int i = 1;
    int user;
    int status;
    int ans;

    ans = 1;

    while(ans == 1) {

    cout << "Are you a Manager(1) or the Director (2): ";
    cin >> status;

    if(status  == 1) {

    cout << "How many Employee accounts do you want to create:  ";
    cin >> user;

    for(int j = 0; j < user; j++) {

        cout << "Enter a name: ";
        cin >> name[i];

        while (checkp(password[i]) != 1)
        {

            cout << "Enter a password: ";
            cin >> password[i];

            if (checkp(password[i]) != 1)
            {
                cout << "Password didn't meet the requirement. Please Choose another password" << endl;
            }
        }

        cout << "Password Created! - User no." << i << endl;
        i++;
        
    }

    } else if (status == 2)
    {
        cout << "Name: ";
        cin >> mname;
        cout << "Password: ";
        cin >> mpassword;

        while (mname != "Wael" || mpassword != "Tatakaye") {
            if(mname != "Wael" && mpassword != "Tatakaye") {
                cout << "Incorrect name and password!";
            } else if (mname != "Wael") {
                cout << "Incorrect name!" << endl;
            } else if (mpassword != "Tatakaye") {
                cout << "Incorrect password!" << endl;
            }
            cout << "Name: ";
            cin >> mname;
            cout << "Password: ";
            cin >> mpassword;
    }
    int ans;

    if (mname == "Wael" && mpassword == "Tatakaye")
    {
        cout << "Welcome, Wael" << endl;
        cout << "Employee list(1), Employee count(2), Employee's name and password(3): ";
        cin >> ans;

        if (ans == 1)
        {
            list(name, password, user);
        }
        else if (ans == 2)
        {
            cout << "There are " << user << " number of employees. " << endl;
        }
        else if (ans == 3)
        {
            namepassword(name, password, user);
        }
    }
    }
    
    
    cout << "Do you want to quit the program? Yes(2)/No(1): ";
    cin >> ans;

    }

    return 0;
}