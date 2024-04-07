#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct Customer {
    string name;
    int mobileNo;
    string address;
};


struct Admin {
    string username;
    string password;
};

struct Car {
    string brand;
    string model;
    string color;
    double distanceTraveled;
    bool isRented; // Indicate whether the car is currently rented.
    Customer rentedBy; // The customer that is currently renting the car. If the car is not rented, this value will be null.
};

int numCustomers = 0;
int numAdmins = 0;

Customer* readCustomerData(string filename) {
    ifstream file(filename);

    if (!file.is_open())
    {
        cout << "Can't Open file" << endl;
        return nullptr;
    }

    string line; 
    getline(file, line);
    numCustomers = stoi(line);
    Customer* customers = new Customer[numCustomers];

    for (int i = 0; i < numCustomers; ++i)
    {
        getline(file, line);
        stringstream ss(line);
        Customer customer;

        if (!(ss >> customer.name >> customer.mobileNo >> customer.address))
        {
            delete[] customers;
            return nullptr;
        }

        customers[i] = customer;
     
    }

    file.close();
    return customers;

}

Admin* readAdminData(string filename) {
    ifstream file(filename);

    if (!file.is_open())
    {
        cout << "Can't Open file" << endl;
        return nullptr;
    }

    string line;
    getline(file, line);
    numAdmins = stoi(line);
    Admin* admins = new Admin[numAdmins];

    for (int i = 0; i < numAdmins; ++i)
    {
        getline(file, line);
        stringstream ss(line);
        Admin admin;

        if (!(ss >> admin.username >> admin.password))
        {
            delete[] admins;
            return nullptr;
        }

        admins[i] = admin;

    }

    file.close();
    return admins;
}


int main()
{

    return 0;
}