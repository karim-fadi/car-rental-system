#include <iostream>
#include <string>

using namespace std;

int carCount = 2;

struct Customer {
    string name;
    string mobileNo;
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

// Initialize data for customers
Customer customers[3] = {
    {"john","+1234567890", "mainstreet"},
    {"smith","+9876543210", "hegazstreet"}
};
// Initialize data for admins
Admin admins[2] = {
    {"admin1", "password1"},
    {"admin2", "password2"}
};
// Initialize data for cars
Car cars[] =
{
    {"toyota", "camry", "red", 10000.0, true, customers[0]},
    {"honda", "civic", "blue", 15000.0, true, customers[0]}
};

//list of car function

void listofcars(Car cars[], int carCount) {
	cout << "<<<< Currently available cars are >>>> \n";
    cout << endl;
    cout << "Brand\t " << "Model\t " << "Color \t" << "DisntanceTravelled\t "  << "RenterName\t " << endl;
    for (int i = 0; i < carCount; i++) {
        cout << cars[i].brand << "\t " << cars[i].model << "\t " << cars[i].color << "\t" << "\t" << cars[i].distanceTraveled << "\t";
        cout << "\t" << "  " << customers[i].name << "\t " << endl;

    }
}
int main() {
    listofcars(cars, carCount);
}