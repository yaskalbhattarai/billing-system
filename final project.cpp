// ----------------------------------------------------------------------------
// File: final project.cpp
// Author: [Yaskal Bhattarai]
// Description: This program implements a simple shopping application that allows
//              users to create a receipt by selecting products from a database.
// ----------------------------------------------------------------------------
#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;

class Product {
protected:
    float pcode;
    float price;
    float dis;
    string pname;
    public:


};

class shopping: public Product {
private:
    float npr;
    float mNumber;
    string mName;

public:

    void intro();
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();
    void membership();
    void dmembership();
    bool checkMembershipDiscount();



};


void shopping::menu() {
    bool continueMenu = true;

    while (continueMenu) {
        int choice;
        string email;
        string password;

        cout << "\n\t\t\t\t======================================\n";
        cout << "\t\t\t\t           Yeril Main Menu              \n";
        cout << "\t\t\t\t======================================\n";
        cout << "\t\t\t\t|  1) Administrator   |\n";
        cout << "\t\t\t\t|----------------------|\n";
        cout << "\t\t\t\t|  2) Buyer           |\n";
        cout << "\t\t\t\t|----------------------|\n";
        cout << "\t\t\t\t|  3) Exit            |\n";
        cout << "\t\t\t\t======================================\n";
        cout << "\n\t\t\t Please select! ";

        // Check if the input is a valid integer
        if (!(cin >> choice)) {
            cout << "\n\t\t\t Error: Please enter a valid number.\n";
            cin.clear(); // Clear the error flag
            cin.ignore(125, '\n'); // Discard invalid input
            continue; // Go back to the beginning of the loop
        }

        switch (choice) {
            Case 1:
                cout << "\n\t\t\t Please Login \n";
                cout << "\t\t\t Enter Email:   ";
                cin >> email;
                cout << "\t\t\t Password:       ";
                cin >> password;

                if (email == "admin" && password == "admin123") {
                    administrator();
                } else {
                    cout << "\t\t\t Invalid email/password";
                }
                break;

            Case 2:
                buyer();
                break;

            Case 3:
                continueMenu = false;
                break;

            default:
                cout << "\n\t\t\t Please select from the given options";
        }
    }
}


void shopping::administrator()
{
    int choice;

    while (true)
    {
        cout << "\n\n\n\t\t\t\t======================================";
        cout << "\n\t\t\t\t          Administrator Menu";
        cout << "\n\t\t\t\t======================================";
        cout << "\n\t\t\t\t|  1) Add the product               |";
        cout << "\n\t\t\t\t|  2) Modify the product            |";
        cout << "\n\t\t\t\t|  3) Delete the product            |";
        cout << "\n\t\t\t\t|  4) Add membership                |";
        cout << "\n\t\t\t\t|  5) Display membership record     |";
        cout << "\n\t\t\t\t|  6) To View All Receipt           |";
        cout << "\n\t\t\t\t|  7) Back to Main Menu             |";
        cout << "\n\t\t\t\t======================================";

        cout << "\n\n\t Please enter your choice: ";
                // Check if the input is a valid integer
        if (!(cin >> choice)) {
            cout << "\n\t\t\t Error: Please enter a valid number.\n";
            cin.clear(); // Clear the error flag
            cin.ignore(125, '\n'); // Discard invalid input
            continue; // Go back to the beginning of the loop
        }

        switch (choice)
        {
        Case 1:
            add();
            break;

        Case 2:
            edit();
            break;

        Case 3:
            rem();
            break;

        Case 4:
            membership();
            break;

        Case 5:
            dmembership();
            break;


        Case 7:
            return;



        default:
            cout << "\n\t\t\t\tInvalid choice!";
        }
    }
}




void shopping::buyer()
{
    int choice;

    while (true)
    {
        cout << "\n\t\t\t   Buyer Menu\n";
        cout << "\t\t\t  ______________\n";
        cout << "\n";
        cout << "\t\t\t  1) Buy product\n";
        cout << "\t\t\t  2) Go back\n";
        cout << "\n";
        cout << "\t\t\t  Enter your choice: ";

        // Check if the input is a valid integer
        if (!(cin >> choice)) {
            cout << "\n\t\t\t Error: Please enter a valid number.\n";
            cin.clear(); // Clear the error flag
            cin.ignore(125, '\n'); // Discard invalid input
            continue; // Go back to the beginning of the loop
        }

        switch (choice)
        {
        Case 1:
            receipt();
            break;

        Case 2:
            return;

        default:
            cout << "\n\t\t\t  Invalid choice";
        }
    }
}


void shopping ::add() {
    fstream data;
    float c;
    int token = 0;
    float p;
    string n;
    float np;

    cout << "\n\n\t\t\t   Add New Product";


    do {
        cout << "\n\n\t Product Code: ";
        cin >> pcode;

        if (cin.fail() || pcode <= 0) {
            cin.clear();
            cin.ignore(1245, '\n');
            cout << "\n\t Please enter a valid positive value for Product Code.\n";
        } else {
            break;
        }
    } while (true);


    do {
        cout << "\n\t Price: ";
        cin >> price;

        if (cin.fail() || price <= 0) {
            cin.clear();
            cin.ignore(1245, '\n');
            cout << "\n\t Please enter a valid positive value for Price.\n";
        } else {
            break;
        }
    } while (true);

    do {
        cout << "\n\t Number of Products: ";
        cin >> npr;

        if (cin.fail() || npr <= 0) {
            cin.clear();
            cin.ignore(124, '\n');
            cout << "\n\t Please enter a valid positive value for Number of Products.\n";
        } else {
            break;
        }
    } while (true);

    do {
        cout << "\n\t Product Name: ";
        cin >> pname;


        stringstream ss(pname);
        float temp;
        if (ss >> temp) {
            cout << "\n\t Error! Please enter a valid name (not a number) for Product Name.\n";
        } else {
            break;
        }
    } while (true);
    data.open("database.txt", ios::in);

    if (!data) {
        data.open("database.txt", ios::app | ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << npr << "\n";
        data.close();
    } else {
        data >> c >> n >> p >> np;

        while (!data.eof()) {
            if (c == pcode) {
                token++;
            }
            data >> c >> n >> p >> np;
        }
        data.close();

        if (token == 1) {
            cout << "\n\t Product code already exists. Please enter a different product code.\n";
        } else {
            data.open("database.txt", ios::app | ios::out);
            data << " " << pcode << " " << pname << " " << price << " " << npr << "\n";
            data.close();
            cout << "\n\n\t\t Record inserted!";
        }
    }
}

void shopping::edit() {
    fstream data, data1;
    int pkey;
    int token = 0;
    int c;
    float p;
    float np;
    string n;

    cout << "\n\t\t\t Modify the record";
    cout << "\n\t\t\t Product code :";
    while (!(cin >> pkey) || pkey < 0) {
        cin.clear();
        cin.ignore(123, '\n');
        cout << "Invalid input! Please enter a positive integer for Product code: ";
    }

    data.open("database.txt", ios::in);
    if (!data) {
        cout << "\n\nFile doesn't exist! ";
    } else {
        data1.open("database1.txt", ios::app | ios::out);

        data >> pcode >> pname >> price>>npr;
        while (!data.eof()) {
            if (pkey == pcode) {
                cout << "\n\t\t Product new code :";
                while (!(cin >> c) || c < 0) {
                    cin.clear();
                    cin.ignore(123, '\n');
                    cout << "Invalid input! Please enter a positive integer for New Product code: ";
                }

               do {
        cout << "\n\t Product Name: ";
        cin >> n;


        stringstream ss(n);
        float temp;
        if (ss >> temp) {
            cout << "\n\t Error! Please enter a valid name (not a number) for Product Name.\n";
        } else {
            break;
        }
    } while (true);

                cout << "\n\t\t Price :";
                while (!(cin >> p) || p < 0) {
                    cin.clear();
                    cin.ignore(123, '\n');
                    cout << "Invalid input! Please enter a positive number for Price: ";
                }

                cout << "\n\t\t Number of product :";
                while (!(cin >> np) || np < 0) {
                    cin.clear();
                    cin.ignore(123, '\n');
                    cout << "Invalid input! Please enter a positive number for Number of product: ";
                }

                data1 << " " << c << " " << n << " " << p << " " << np << "\n";
                cout << "\n\n\t\t Record edited ";
                token++;
            } else {
                data1 << " " << pcode << " " << pname << " " << price << " " << npr << "\n";
            }
            data >> pcode >> pname >> price >> npr;
        }

        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0) {
            cout << "\n\n Record not found sorry!";
        }
    }
}

void shopping::rem()
{

	fstream data,data1;
	int pkey;
	int token=0;
	cout<<"\n\n\t Delete product";
	cout<<"\n\n\t Product code :";
	while (!(cin >> pkey) || pkey < 0) {
        cin.clear();
        cin.ignore(123, '\n');
        cout << "Invalid input! Please enter a positive integer for Product code: ";
    }
	data.open("database.txt", ios::in);
	if(!data)
	{
		cout<<"File doesn't exist";

	}

	else{
		data1.open("database1.txt",ios::app|ios::out);
		data>>pcode>>pname>>price>>npr;
		while(!data.eof())
		{
			if(pcode==pkey)
			{
				cout<<"\n\n\t Product deleted succesfully";
				token++;
			}
			else
			{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<npr<<"\n";

			}
			data>>pcode>>pname>>price>>npr;
		}
		data.close();
		data1.close();
		remove("database.txt");
		rename("database1.txt", "database.txt");

		if(token==0)
		{
			cout<<"\n\n Record not found";
		}
	}
}

void shopping:: list()
{
	fstream data;
	data.open("database.txt",ios::in);
	cout<<"\n\n|___________________________________________________________\n";
	cout<<"ProNo\t\tName\t\tPrice\t\tNumber of product\n";
	cout<<"\n\n|___________________________________________________________\n";
	data>>pcode>>pname>>price>>npr;
	while(!data.eof())
	{
		cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\t\t"<<npr<<"\n";
		data>>pcode>>pname>>price>>npr;

	}
	data.close();
}
void shopping::receipt() {
    system("cls");
    fstream data;

    int arrc[100], arrq[100];
    char choice;
    int c = 0;
    float amount = 0;
    float total = 0;

    cout << "\n\n\t\t\t Receipt ";
    data.open("database.txt", ios::in);
    if (!data) {
        cout << "\n\n Empty database";
    } else {
        data.close();
        list();
        cout << "\n____________________________\n";
        cout << "\n|                            |";
        cout << "\n|    Please place the order  |";
        cout << "\n|____________________________|\n";
        do {
        m:
            cout << "\n\n Product Code : ";
            cin >> arrc[c];

            data.open("database.txt", ios::in);
            data >> pcode >> pname >> price >> npr;

            // Check if the product code is valid
            bool validProduct = false;
            while (!data.eof()) {
                if (pcode == arrc[c]) {
                    validProduct = true;
                    break;
                }
                data >> pcode >> pname >> price >> npr;
            }
            data.close();

            if (!validProduct) {
                cout << "\n\n Invalid Product Code. Please try again!";
                goto m;
            }

            cout << "\n Product Quantity : ";
            cin >> arrq[c];

            // Check if the quantity is greater than the available quantity
            if (arrq[c] > npr) {
                cout << "\n\n Error: Quantity exceeds available stock. Please enter a valid quantity.";
                goto m;
            }

            for (int i = 0; i < c; i++) {
                if (arrc[c] == arrc[i]) {
                    cout << "\n\n Duplicate Product Code. Please try again!";
                    goto m;
                }
            }

            c++;
            cout << "\n\n Want to buy another product? Press y for yes and n for no : ";
            cin >> choice;
        } while (choice == 'y');
        system("cls");


        cout << "\n\n\t\t\t__________RECEIPT______________\n";
        cout << "\nProduct Num.\tProduct Name\tQuantity \tPrice \tAmount\n";

        for (int i = 0; i < c; i++) {
            data.open("database.txt", ios::in);
            data >> pcode >> pname >> price >> npr;
            while (!data.eof()) {
                if (pcode == arrc[i]) {
                    amount = price * arrq[i];
                    total = total + amount;
                    cout << "\n" << pcode << "\t\t" << pname << "\t\t" << arrq[i] << "\t\t" << price << "\t" << amount;
                }
                data >> pcode >> pname >> price >> npr;
            }
            data.close();
        }

        fstream data("database.txt", ios::in);
        fstream temp("temp.txt", ios::out);

        while (data >> pcode >> pname >> price >> npr) {
            for (int i = 0; i < c; i++) {
                if (pcode == arrc[i]) {
                    npr -= arrq[i]; // Subtract the quantity purchased
                }
            }
            if (npr > 0) {
                temp << pcode << " " << pname << " " << price << " " << npr << endl;
            }
        }

        data.close();
        temp.close();

        remove("database.txt");
        rename("temp.txt", "database.txt");

        // Check membership for discount where all the task was done in the bool membership function
        if (checkMembershipDiscount()) {
            total -= total * 0.1;
            cout << "\n\n----------------------------------------";
            cout << "\n  Membership  found ,";
            cout << "\nTotal Amount (After 10% Discount) : " << total;
        } else {
            cout << "\n\n----------------------------------------";
            cout << "\n Membership does not found,";
            cout << "\nTotal Amount : " << total;
        }
    }
}

bool shopping::checkMembershipDiscount() {
    ifstream membershipData("mdatabase.txt");
    int memberNumber;
    string memberName;

    cout << "\nEnter Membership Code: ";
    cin >> mNumber;

    while (membershipData >> memberNumber >> memberName) {
        if (memberNumber == mNumber) {
            return true; // Membership found
        }
    }

    return false; // Membership not found
}

void shopping::membership() {
    ifstream data("mdatabase.txt");
    int token = 0;
    int nm;
    string mn;

    cout << "\n\n\t\t\t   Add New Membership record";


    while (true) {
        cout << "\n\n\t Number of Membership: ";
        if (cin >> mNumber) {
            break;
        }
        else {
            cin.clear(); // it will  clear the previous screen if the input is invalid
            cin.ignore(123, '\n'); // discard the previous  input.
            cout << "\n\t Invalid input! Please enter a valid number for Membership.\n";
        }
    }


        do {
        cout << "\n\t Name of membership holder : ";
        cin >> mName;

        stringstream ss(mName);
        float as;
        if (ss >> as) {
            cout << "\n\t Error! Please enter a valid name (not a number) for Product Name.\n";
        } else {
            break;
        }
    } while (true);
    data.open("mdatabase.txt", ios::in);


    if (data) {
        while (data >> nm >> mn) {
            if (nm == mNumber) {
                token++;
            }
        }
        data.close();
    }

    if (token == 1) {
        cout << "\n\t Membership already exists. \n";
    }
    else {
        ofstream data("mdatabase.txt", ios::app);
        data << " " << mNumber << " " << mName << "\n";
        cout << "\n\n\t\t Record inserted!";
    }
}


void shopping::dmembership()
{
    fstream data;
    data.open("mdatabase.txt", ios::in);

    cout << "\n\n|___________________________________________________________\n";
    cout << "Number of Membership Holders\t\tName of Membership Holder\n";
    cout << "|___________________________________________________________|\n";

    while (data >> mNumber >> mName)
    {
        cout << mNumber << "                \t\t" << mName << "\n";
    }

    data.close();
}

int main()
{
	shopping s;
	s.menu();
}




