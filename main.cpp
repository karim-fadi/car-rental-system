#include <iostream>
#include <string>
using namespace std;
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
    {"Toyota", "Camry", "Red", 10000.0, true, customers[0]},
    {"Honda", "Civic", "Blue", 15000.0, true, customers[0]}
};

// Function to remove a car from the array by index
void removeCar(Car cars[], int& carCount, int index) {
    if (index < 0 || index >= carCount) {
        cout << "Invalid index. Cannot remove car." << endl;
        return;
    }

    // Shift elements to fill the gap
    for (int i = index; i < carCount - 1; ++i) {
        cars[i] = cars[i + 1];
    }

    // Decrement the car count
    carCount--;
}

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
void LoginAsAnAdmin()
{
    string username, password;
    cout << "Please sign in" << endl;
    cout << "Enter your username and password:" << endl;
    bool LoggedIn = false;
    do {
        cin >> username >> password;
        for (int i = 0; i < 2; i++)
        {
            if ((username == admins[i].username) && (password == admins[i].password))
            {
                LoggedIn = true;
                cout << "You are signed in successfully" << endl;
                cout << "Please enter a number:" << endl;
                cout << "Press 1 to add a car" << endl;
                cout << "Press 2 to remove a car" << endl;
                cout << "Press 3 to show list of cars" << endl;
                cout << "Press 4 to check available cars" << endl;
                cout << "Press 5 to update car detailes" << endl;
                break;
            }
        }
        if (LoggedIn == false)
        {
            cout << "Incorrect username or password" << endl;
            cout << "Please reneter your username and password:" << endl;
        }
    } while (LoggedIn == false);
}
void LoginAsACustomer()
{
    Customer newCustomer;
    char login;
    string username;
    string mobilenum;
    string address;
    cout << "Do you want to sign up or sign in?" << ' ' << "(U for signing up) and (I for signing in)" << endl;
    cin >> login;
    if (login == 'U' || login == 'u')
    {
        cout << "Creat new account" << endl;
        cout << "Enter new username:";
        do {
            cin >> newCustomer.name;
            bool found = false;
            for (int i = 0; i < 2; i++)
            {
                if (newCustomer.name == customers[i].name)
                {
                    found = true;
                    cout << "Someone already has that username" << endl;
                    cout << "Please enter another username:";
                    break;
                }
            }
            if (found == false)
            {
                cout << "username created successfully" << endl;
                cout << "Enter your mobile number:";
                cin >> newCustomer.mobileNo;
                cout << "Enter your address:";
                cin >> newCustomer.address;
                customers[2] = newCustomer;
                cout << "You are signed up successfully" << endl;
                cout << "Press 6 to rent a car" << endl;
                break;
            }
        } while (true);
    }
    else if (login == 'I' || login == 'i')
    {
        cout << "Enter your username , mobile number and address" << endl;
        bool found = false;
        do {
            cin >> username >> mobilenum >> address;
            for (int i = 0; i < 2; i++)
            {
                if ((username == customers[i].name) && (mobilenum == customers[i].mobileNo) && (address == customers[i].address))
                {
                    found = true;
                    cout << "You are signed in successfully" << endl;
                    cout << "Press 6 to rent a car" << endl;
                    break;
                }
            }
            if (found == false)
            {
                cout << "Incorrect username or mobile number or address" << endl;
                cout << "Please renter your username , mobile number and address:" << endl;
            }
        } while (found == false);
    }
}
void identity()
{
    string identity;
    char choice = 'N';
    do {
        cout << "Login as an admin or customer?" << endl;
        cin >> identity;
        if (identity == "admin")
        {
            LoginAsAnAdmin();
            break;
        }
        else if (identity == "customer")
            LoginAsACustomer();
        else
        {
            cout << "Invalid choice" << endl;
            cout << "Do you want to try again?" << ' ' << "(Y/N)" << endl;
            cin >> choice;
        }
    } while (choice == 'y' || choice == 'Y');
}
int main()
{
    identity();
    return 0;
}