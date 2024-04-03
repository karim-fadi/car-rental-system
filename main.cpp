#include <iostream>
<<<<<<< Updated upstream
#include<string>
=======
#include <fstream>
#include <string>
#include <sstream>

>>>>>>> Stashed changes
using namespace std;
//yasater

<<<<<<< Updated upstream
=======
struct Customer {
    string name;
    int mobileNo;
    string address;
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

int main()
{
    return 0;
}
>>>>>>> Stashed changes
