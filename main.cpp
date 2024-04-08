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
int numCars = 0;
Car* cars;
int numCustomers = 0;
int numAdmins = 0;

// Function to read cars from a file and populate the dynamic array
Car* ExtractCarsFromFile(string filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "Error: Unable to open file " << filename << endl;
        return nullptr;
    }

    // Read number of cars from the first line
    string line;
    getline(file, line);
    numCars = stoi(line);
    Car* cars = new Car[numCars];

    // Read cars from file
    for (int i = 0; i < numCars; ++i)
    {
        getline(file, line);
        stringstream ss(line);
        Car car;
        if (!(ss >> car.brand >> car.model >> car.color >> car.distanceTraveled >> car.isRented)) {
            cerr << "Error: Invalid car data in file " << filename << " at line " << (i + 2) << endl;
            delete[] cars; // Free dynamically allocated memory
            return nullptr;
        }

        if (car.isRented) {
            Customer customer;
            if (!(ss >> customer.name >> customer.mobileNo >> customer.address)) {
                cerr << "Error: Invalid customer data for rented car in file " << filename << " at line " << (i + 2) << endl;
                delete[] cars; // Free dynamically allocated memory
                return nullptr;
            }
            car.rentedBy = customer;
        }
        cars[i] = car;
    }

    file.close();
    return cars;
}

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
int main() {
    cars = ExtractCarsFromFile("database.txt");
    if (cars == nullptr)
    {
        cout << "Error reading cars from file." << endl;
        return 1;
    }
}

