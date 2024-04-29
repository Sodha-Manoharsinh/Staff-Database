#include <iostream>
using namespace std;

// Classes

class Staff
{
private:
    int code;
    string name;

public:
    virtual void put_action() = 0;
    virtual void get_action() = 0;

    void putStaffData()
    {
        cout << "Enter code: ";
        cin>>code;
        cout<< "Enter name: ";
        cin>>name;
    }
    void getStaffData()
    {
        cout<<"Code = "<<code<<endl;
        cout<<"Name = "<<name<<endl;
    }
};

class Teacher : public Staff
{
private:
    string subject;
    string publication;

public:
    void put_action()
    {
        cout<<"Enter data of Teacher:- "<<endl;
        putTeacherData();
        cout << "---------------------------------------------------------" << endl;
    }
    void get_action()
    {
        cout << "\n---------------------------------------------------------" << endl;
        cout << "                      Teacher Data                        " << endl;
        cout << "---------------------------------------------------------" << endl;
        getTeacherData();
        cout << "---------------------------------------------------------" << endl;
    }
    void putTeacherData()
    {
        putStaffData();
        cout << "Enter Subject: ";
        cin>>subject;
        cout<< "Enter Publication: ";
        cin>>publication;
    }
    void getTeacherData()
    {
        getStaffData();
        cout<<"Subject = "<<subject<<endl;
        cout<<"Publication = "<<publication<<endl;
    }
};

class Typist : public Staff
{
private:
    int speed;

public:
    void putTypistData()
    {
        putStaffData();
        cout << "Enter speed: ";
        cin>>speed;
    }
    void getTypistData()
    {
        getStaffData();
        cout<<"Speed = "<<speed<<endl;
    }
};

class Officer : public Staff
{
private:
    char grade;

public:
    void put_action()
    {
        cout<<"Enter data of Officer:- "<<endl;
        putOfficerData();
        cout << "---------------------------------------------------------" << endl;
    }
    void get_action()
    {
        cout << "\n---------------------------------------------------------" << endl;
        cout << "                       Officer Data                       " << endl;
        cout << "---------------------------------------------------------" << endl;
        getOfficerData();
        cout << "---------------------------------------------------------" << endl;
    }
    void putOfficerData()
    {
        putStaffData();
        cout << "Enter grade: ";
        cin>>grade;
    }
    void getOfficerData()
    {
        getStaffData();
        cout<<"Grade = "<<grade<<endl;
    }
};

class Regular : public Typist
{
public:
    void put_action()
    {
        cout<<"Enter data of regular typist:- "<<endl;
        putTypistData();
        cout << "---------------------------------------------------------" << endl;
    }
    void get_action()
    {
        cout << "\n---------------------------------------------------------" << endl;
        cout << "                     Regular Typist Data                  " << endl;
        cout << "---------------------------------------------------------" << endl;
        getTypistData();
        cout << "---------------------------------------------------------" << endl;
    }
};

class Casual : public Typist
{
private:
    double daily_wages;
public:
    void put_action()
    {
        cout<<"Enter data of casual typist:- "<<endl;
        putTypistData();
        putCasualTypistData();
        cout << "---------------------------------------------------------" << endl;
    }
    void get_action()
    {
        cout << "\n---------------------------------------------------------" << endl;
        cout << "                     Casual Typist Data                   " << endl;
        cout << "---------------------------------------------------------" << endl;
        getTypistData();
        getCasualTypistData();
        cout << "---------------------------------------------------------" << endl;
    }
    void putCasualTypistData()
    {
        cout<<"Enter daily wages: ";
        cin>>daily_wages;
    }
    void getCasualTypistData()
    {
        cout<<"Daily wages = "<<daily_wages<<endl;
    }
};

// Functions

string get_commands()
{
    string command;
    cout << "Enter a command to follow (put/fetch/exit): ";
    cin >> command;
    return command;
}


int get_paths()
{
    int p;

    string paths[4] = {"Teacher","Regular Typist","Casual Typist","Officer"};

    int length = sizeof(paths) / sizeof(paths[0]);

    for(int i = 0; i<length; i++)
    {
        cout<<"Enter "<<i+1<<" for path of "<<paths[i]<<endl;
    }
    cout<<"Enter a path:- ";
    cin>>p;

    return p;
}

void follow_command(string command,Staff *a1)
{
    switch (command[0])
    {
    case 'p':
        a1->put_action();
        break;
    case 'f':
        a1->get_action();
        break;
    default:
        cout<<"Invalid command"<<endl;
    }
}

int main()
{
    string command="put";
    int path;
    Teacher t1;
    Regular r1;
    Casual c1;
    Officer o1;

    cout << "---------------------------------------------------------" << endl;
    cout << "               Welcome to Staff Management                " << endl;
    cout << "---------------------------------------------------------" << endl;

    do
    {
        command=get_commands();
        if(command=="exit")
        {
            cout << "---------------------------------------------------------" << endl;
            cout << "                      Program Ends                       " << endl;
            cout << "---------------------------------------------------------" << endl;
            return 0;
        }
        path=get_paths();

        switch (path)
        {
        case 1:
            follow_command(command,&t1);
            break;
        case 2:
            follow_command(command,&r1);
            break;
        case 3:
            follow_command(command,&c1);
            break;
        case 4:
            follow_command(command,&o1);
            break;

        default:
            cout<<"Invalid path";
            break;
        }
    }
    while(command=="put"||command=="fetch");

    return 0;
}

