#include <iostream>

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

// Initialize data for customers
Customer customers[] = {
    {"John Doe", 1234567890, "123 Main St"},
    {"Jane Smith", 9876543210, "456 Elm St"},
};

// Initialize data for admins
Admin admins[] = {
    {"admin1", "password1"},
    {"admin2", "password2"},
};

// Initialize data for cars
Car cars[] = {
    {"Toyota", "Camry", "Red", 10000.0, true, customers[0]},
    {"Honda", "Civic", "Blue", 15000.0, true, customers[0]},
};

void rentCar(Car cars[], int size, int carIndex, Customer customer) {
    if (carIndex >= 0 && carIndex < size) {
        if (!cars[carIndex].isRented) {
            cars[carIndex].isRented = true;
            cars[carIndex].rentedBy = customer;
            cout << "Car rented successfully.\n";
        }
        else {
            cout << "Sorry, the car is already rented.\n";
        }
    }
    else {
        cout << "Invalid car index.\n";
    }
}

int main()
{

	return 0;
}