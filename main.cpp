#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

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
    bool isRented; //Indicate whether the car is currently rented
    Customer rentedBy; //the customer that is currently renting the car, If the car is not rented, this value will be null

};
int numCars = 0;
Car* cars;
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
int main() {
    cars = ExtractCarsFromFile("database.txt");
    if (cars == nullptr)
    {
        cout << "Error reading cars from file." << endl;
        return 1;
    }
}




