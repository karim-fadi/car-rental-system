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
//max size of array of cars is 20
const int maxCars = 20;
// Initialize data for cars
Car cars[maxCars] =
{
    {"toyota", "camry", "red", 10000.0, true, customers[0]},
    {"honda", "civic", "blue", 15000.0, true, customers[0]}
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
void loginAsAnAdmin()
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

void loginAsACustomer()
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
            loginAsAnAdmin();
            break;
        }
        else if (identity == "customer")
            loginAsACustomer();
        else
        {
            cout << "Invalid choice" << endl;
            cout << "Do you want to try again?" << ' ' << "(Y/N)" << endl;
            cin >> choice;
        }
    } while (choice == 'y' || choice == 'Y');
}
void checkCarAvailability()
{
    int index;
    cout << "Enter the index of the car to check availability : ";
    cin >> index;
    if (index > carCount || index < 1)
    {
        cout << "invalid index.\n";
        return;
    }
    else if (carCount == 0)
    {
        cout << "No cars available to check.\n";
        return;
    }
    else if (cars[index - 1].isRented == false)
    {
        cout << "car is available to rent.\n";
        return;
    }
    cout << "car is rented.\n";
}
//list of car function
void listOfCars(Car cars[], int carCount) {
	cout << "<<<< Currently available cars are >>>> \n";
    cout << endl;
    cout << "Brand\t " << "Model\t " << "Color \t" << "DisntanceTravelled\t "  << "RenterName\t " << endl;
    for (int i = 0; i < carCount; i++) {
        cout << cars[i].brand << "\t " << cars[i].model << "\t " << cars[i].color << "\t" << "\t" << cars[i].distanceTraveled << "\t";
        cout << "\t" << "  " << customers[i].name << "\t " << endl;
    }
}

void carUpdate(int index) 
{
            //cout << "Current details of car with ID " << carID << ":" << endl;
            cout << "NAME: " << cars[index].brand << endl;
            cout << "MODEL: " << cars[index].model << endl;
            cout << "COLOUR: " << cars[index].color << endl;
            cout << "DISTANCE TRAVELLED: " << cars[index].distanceTraveled << endl; 
            //cout << "PRICE: " << cars[index].price << endl; 

            // Prompt the user to choose which part of the data he wishes to update
            cout << "Enter 1 to update name " << endl; 
            cout << "Enter 2 to update model " << endl; 
            cout << "Enter 3 to update colour " << endl; 
            cout << "Enter 4 to update top speed " << endl; 
            cout << "Enter 5 to update price " << endl; 

            int choice;
            cin >> choice;

            switch(choice) 
            {
                case 1:
                    cout << "Enter a new name: ";
                    cin >> cars[index].brand;
                    break;
                case 2:
                    cout << "Enter a new model: ";
                    cin >> cars[index].model;
                    break;
                case 3:
                    cout << "Enter a new colour: ";
                    cin >> cars[index].color;
                    break;
                 case 4:
                    cout << "Enter a new top speed: ";
                    cin >> cars[index].distanceTraveled;
                    break;
                 //case 5:
                   // cout << "Enter a new price: ";
                    //cin >> cars[index].price;
                    //break;
                default:
                    cout << "Invalid choice." << endl;
            }
            cout << "Car details are updated successfully." << endl;
            return;
}
//function to add car
void addCar(Car cars[], int& carCount) 
{
    if ((carCount < maxCars) && (carCount > 0))
    {
        Car newcar; //new variable of type car
        cout << "Enter brand:";
        cin >> newcar.brand; cout << endl;
        cout << "Enter model:";
        cin >> newcar.model; cout << endl;
        cout << "Enter color:";
        cin >> newcar.color; cout << endl;
        cout << "Enter distance traveled by car:";
        cin >> newcar.distanceTraveled; cout << endl;
        newcar.isRented = false;
        cars[carCount++] = newcar; //increment counter and add the newcar to the array
        cout << "car rented successfully and these are the details of the car:" << endl; //print data of the rented car
        cout << "Brand:" << newcar.brand << " " << "Model:" << newcar.model << " " << "Color:" << newcar.color << " " << "Distance traveled:" << newcar.distanceTraveled << endl;
    }
    else
    {
        cout << "can not add cars,max reached" << endl;
    }
}
int main() 
{
    return 0;
}