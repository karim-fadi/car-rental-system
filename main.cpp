#include <iostream>
#include <string>

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



int main()
{
	return 0;
}