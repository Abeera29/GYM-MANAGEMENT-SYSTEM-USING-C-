#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Function to search for a record
int search(string arr[], string f, int index)
{
    for (int i = 0; i < index; i++)
    {
        if (arr[i] == f)
        {
            return i;
        }
    }
    return -1;
}

// Function to display records
void display(int size, string name[], string age[], string date[], string cont[])
{
    cout << "Records:\n";
    for (int i = 0; i < size; i++)
    {
        if (name[i] != "")
        {
            cout << "Record " << i << endl;
            cout << "|" << "Name = " << name[i] << "|" << " Age = " << age[i] << "|" << " Date Joined = " << date[i] << "|" << " Contact Information" << cont[i] << "|" << endl;
        }
    }
}

// Function to save records to a file
void saveToFile(int size, string name[], string age[], string date[], string cont[])
{
    ofstream outFile("records.txt"); // Open a file for writing

    for (int i = 0; i < size; i++)
    {
        if (name[i] != "")
        {
            outFile << name[i] << " " << age[i] << " " << date[i] << " " << cont[i] << endl;
        }
    }

    outFile.close(); // Close the file
}

// Function to load records from a file
void loadFromFile(int &index, string name[], string age[], string date[], string cont[])
{
    ifstream inFile("records.txt"); // Open a file for reading

    while (inFile >> name[index] >> age[index] >> date[index] >> cont[index])
    {
        index++;
    }

    inFile.close(); // Close the file

}
void displayMenu(){
 cout << "1. Enter Record\n";
        cout << "____________________________________________________________________" << endl;
        cout << "2. Delete Record\n";
        cout << "____________________________________________________________________" << endl;
        cout << "3. Update Record\n";
        cout << "____________________________________________________________________" << endl;
        cout << "4. Display Record\n";
        cout << "____________________________________________________________________" << endl;
        cout << "5. Display customer packages\n";
        cout << "____________________________________________________________________" << endl;
        cout << "6. Exit\n";
        cout << "____________________________________________________________________" << endl;
}


int main()
{
    string name[255], age[255], dateJoined[255], contactinfo[255];
    int choice = 0;
    int index = 0;

    // Load existing records from the file
    loadFromFile(index, name, age, dateJoined, contactinfo);

    cout << "\t\t\t_GYM MANAGEMENT SYSTEM_" << endl;
    cout << "____________________________________________________________________" << endl;
    while (1)
    {
        displayMenu();
                cin >> choice;

        try
        {
            if (choice == 1)
            {
                string n, a, d, c;
                cout << "Enter your name with CNIC in bracket like ''name(your CNIC num):'' "<<endl;
                cin >> n;
                cout << "Enter Age : ";
                cin >> a;
                cout << "Enter Joining Date in numbers: ";
                cin >> d;
                cout << "Enter Contact Information :  ";
                cin >> c;
                name[index] = n;
                age[index] = a;
                dateJoined[index] = d;
                contactinfo[index] = c;
                index++;
                cout << "Record Saved\n";
                saveToFile(index, name, age, dateJoined, contactinfo);
            }
            else if (choice == 2)
            {
                string n;
                cout << "Enter Name with your CINIC like ''name(your CINIC num):''to delete : ";
                cin >> n;
                int a1;
                a1 = search(name, n, index);
                if (a1 == -1)
                {
                    cout << "Record NotFound";
                    throw 505;
                }
                else
                {
                    name[a1] = "";
                    age[a1] = "";
                    dateJoined[a1] = "";
                    contactinfo[a1] = "";
                    cout << "Record Deleted\n";
                }
            }
            else if (choice == 3)
            {
                cout << "Enter Name to update : ";
                string n;
                cin >> n;
                int a1;
                a1 = search(name, n, index);
                if (a1 == -1)
                {
                    cout << "Record NotFound";
                    throw 505;
                }
                else
                {
                    cout << "Record Found\n";
                    cout << "Enter Updated Record \n";
                    string n, a, d, i;
                    cout << "Enter your First Name  with your CINIC like ''name(your CINIC num):'' : ";
                    cin >> n;
                    cout << "Enter Age : ";
                    cin >> a;
                    cout << "Enter Joining Date in numbers : ";
                    cin >> d;
                    cout << "Enter Contact Information :  ";
                    cin >> i;
                    name[a1] = n;
                    age[a1] = a;
                    dateJoined[a1] = d;
                    contactinfo[a1] = i;
                    cout << "Record Updated \n";
                    saveToFile(index, name, age, dateJoined, contactinfo);
                }
            }
            else if (choice == 4)
            {
                display(index, name, age, dateJoined, contactinfo);
            }
            else if (choice == 5)
            {
                int a;
                string c;
                cout << "Enter your First Name  with your CNIC like ''name(your CNIC num):''  "<<endl;
                cin >> c;

                int a1 = search(name, c, index);
                if (a1 == -1)
                {
                    cout << "Record not found : \n";
                    throw 505;
                }
                else
                {
                    cout << " Record found : \n  ";
                    cout << "1. Premium customers : ";
                    cout << "\n2. Regular customer : \n";
                    cout<<"3.Student Packages:\n";
                    cin >> a;

                    if (a == 1)
                    {
                        int b;
                        int z;
                        do
                        {
                            cout << "Premium packages start from 5000 per month\n";
                            cout<<"to see the facilites here enter '0'"<<endl;
                            cin>>z;
                            if(z==0)
                            {
                            	cout << "Personal Training\n";
                        cout << "Personal Nutrition Counselling\n";
                        cout << "Cardio And Strength Training\n";
                        cout << "Spa Facilities\n";
                        cout << "Swimming Pool\n";
                        cout << "Luxury Locker Rooms\n";
                        cout << "Sauna\n";
                        cout << "Changing Room\n";
							}
                            cout << "Enter deposit  if you want to avail : ";
                            cin >> b;
                            
                        } while (b < 5000);
                        cout << "\t\tamount deposited"<<endl;
                        cout<<"\t\tnow you can start GYM"<<endl;
                    }
                    else if (a == 2)
                    {
                        int b;
                        int o;
                        do
                        {
                            cout << "Regular packages start from 2500 per month\n"<<endl;
                            cout<< "to see the facilites here enter '10'"<<endl;
                            cin>>o;
                            if(o==10)
                            {
							cout << "Lockers\n";
                            cout << "Strength Trainings\n";
                            cout << "Group Classes\n";
                            cout << "Changing Room\n";
							}
                            cout << "Enter deposit : ";
                            cin >> b;
                        } while (b < 2500);
                        cout << "\t\tamount deposited"<<endl;
                         cout<<"\t\tnow you can start GYM"<<endl;
                    }
                    else if(a==3)
                    {

                        int a,b,d;
                        
                        cout<<"Student packages require REGISTRATION NO of Institute\n";
                        cin>>a;
                        cout<<"Their deposit starts from 1500\n";
                        cout<<"Enter 5 if you want to see facilities:\n";
                        cin>>d;
                        if(d==5){

                        
                       do{
                        cout<<"Their facilities are\n";
                        cout<<"Group classes\n";
                        cout<<"Training in group\n";
                        cout<<"Changing Rooms\n";
                        cout<<"Strength Excersises\n";
                        cout<<"Enter your deposit\n";
                        cin>>b;}while(b>1500);
                        cout<<"You are eligible for Student package\n";
                    }
                }
                }
            }
            else if (choice == 6)
            {
                // Save records to the file before exiting
                saveToFile(index, name, age, dateJoined, contactinfo);
                break;
            }
           
        }
        catch (int mynum)
        {
            cout << "An exception occurred: " << mynum << endl;
        }
    }
    return 0;
}