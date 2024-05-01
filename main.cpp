#include <iostream>
#include <string>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"

using namespace std;

void customerMenu();
void adminMenu();

int carCount = 2;
int signedInCustomerIndex = 0;
const int maxCars = 20;

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

Customer customers[20] = {
    {"john","123456789", "mainstreet"},
    {"smith","987654321", "hegazstreet"}
};

Admin admins[2] = {
    {"admin1", "password1"},
    {"admin2", "password2"}
};

Car cars[maxCars] =
{
    {"toyota", "camry", "red", 10000.0, true, customers[0]},
    {"honda", "civic", "blue", 15000.0, false, {}}
};

void addCar(Car cars[], int& carCount)
{
    if ((carCount < maxCars) && (carCount > 0))
    {
        Car newcar;
        cout << "Enter brand: ";
        cin >> newcar.brand; cout << endl;
        cout << "Enter model: ";
        cin >> newcar.model; cout << endl;
        cout << "Enter color: ";
        cin >> newcar.color; cout << endl;
        cout << "Enter distance traveled by car: ";
        cin >> newcar.distanceTraveled; cout << endl;
        newcar.isRented = false;
        cars[carCount++] = newcar;
        cout << GREEN <<"Car added successfully and these are the details of the car: " << RESET << endl << endl;
        cout << "Brand: " << newcar.brand << "  " << "Model: " << newcar.model << "  " << "Color: " << newcar.color << "  " << "Distance traveled: " << newcar.distanceTraveled << endl << endl;
    }
    else
    {
        cout << RED <<"Can't add cars, max reached." << RESET << endl;
    }
}

void removeCar(Car cars[], int& carCount) {
    cout << "Enter the index of the car you want to remove: ";

    int index;
    cin >> index;
    index -= 1;

    if (index < 0 || index >= carCount) {
        cout << RED << "Invalid index. Cannot remove car." << RESET << endl;
        return;
    }

    for (int i = index; i < carCount - 1; ++i) {
        cars[i] = cars[i + 1];
    }

    carCount--;

    cout << endl;
    cout << GREEN <<"Car Removed Successfully\n" << RESET;
    cout << endl;
}

void rentCar(Car cars[], int carCount) {
    cout << "Enter The index of the car you want to rent: ";
    int carIndex;
    cin >> carIndex;
    carIndex -= 1;

    Customer customer = customers[signedInCustomerIndex];

    if (carIndex >= 0 && carIndex < carCount) {
        if (!cars[carIndex].isRented) {
            cars[carIndex].isRented = true;
            cars[carIndex].rentedBy = customer;
            cout << endl;
            cout << GREEN << "Car rented successfully.\n" << RESET;
            cout << endl;
        }
        else {
            cout << RED << "Sorry, the car is already rented.\n" << RESET;
        }
    }
    else {
        cout << RED <<"Invalid car index.\n" << RESET;
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
                cout << endl;
                cout << GREEN << "You are signed in successfully" << RESET << endl;
                cout << endl;
                break;
            }
        }
        if (LoggedIn == false)
        {
            cout << RED << "Incorrect username or password" << RESET << endl;
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
    cout << endl;
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
                    cout << RED << "Someone already has that username" << RESET << endl;
                    cout << "Please enter another username:";
                    break;
                }
            }
            if (found == false)
            {
                cout << GREEN << "username created successfully" << RESET << endl;
                cout << "Enter your mobile number:";
                cin >> newCustomer.mobileNo;
                cout << "Enter your address:";
                cin >> newCustomer.address;
                customers[2] = newCustomer;
                cout << endl;
                cout << GREEN << "You are signed up successfully" << RESET << endl;
                cout << endl;
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
                    signedInCustomerIndex = i;
                    cout << endl;
                    cout << GREEN << "You are signed in successfully" << RESET << endl;
                    cout << endl;
                    break;
                }
            }
            if (found == false)
            {
                cout << RED <<"Incorrect username or mobile number or address" << RESET << endl;
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
        cout << "Login as an admin or customer? (Enter e to exit system)" << endl;
        cin >> identity;
        cout << endl;
        if (identity == "admin")
        {
            loginAsAnAdmin();
            adminMenu();
        }
        else if (identity == "customer")
        {
            loginAsACustomer();
            customerMenu();
        }

        else if (identity == "e")
        {
            break;
        }
            
        else
        {
            cout << RED << "Invalid choice" << RESET << endl;
            cout << "Do you want to try again?" << ' ' << "(Y/N)" << endl;
            cin >> choice;
        }
    } while (true);
}

void checkCarAvailability()
{
    int index;
    cout << "Enter the index of the car to check availability : ";
    cin >> index;
    if (index > carCount || index < 1)
    {
        cout << endl;
        cout << RED << "invalid index.\n" << RESET;
        cout << endl;
        return;
    }
    else if (carCount == 0)
    {
        cout << endl;
        cout << RED << "No cars available to check.\n" << RESET;
        cout << endl;
        return;
    }
    else if (cars[index - 1].isRented == false)
    {
        cout << endl;
        cout << GREEN << "car is available to rent.\n" << RESET;
        cout << endl;
        return;
    }
    cout << RED << "car is rented.\n" << RESET;
}

void listOfCars(Car cars[], int carCount) {
    cout << endl;
    cout << "<<<< Currently available cars are >>>> \n";
    cout << endl;
    cout << "   Brand\t " << "Model\t " << "Color \t" << "Disntance Traveled\t " << "Renter Name\t " << endl;
    for (int i = 0; i < carCount; i++) {
        cout << i + 1 << ") " << cars[i].brand << "\t " << cars[i].model << "\t " << cars[i].color << "\t" << "\t" << cars[i].distanceTraveled << "\t";
        if (cars[i].isRented == true)
            cout << "\t" << "  " << cars[i].rentedBy.name << "\t " << endl;

        cout << endl;
    }
    cout << endl;
}

void carUpdate()
{
    cout << "Enter the index of the car you want to update its details: ";
    int index;
    cin >> index;

    if (index > carCount || index < 1)
    {
        cout << endl;
        cout << RED <<"invalid index.\n" << RESET;
        cout << endl;
        return;
    }

    index--;

    cout << endl;
    cout << "Current Details: " << endl << endl;

    cout << "BRAND: " << cars[index].brand << endl;
    cout << "MODEL: " << cars[index].model << endl;
    cout << "COLOR: " << cars[index].color << endl;
    cout << "DISTANCE TRAVELED: " << cars[index].distanceTraveled << endl;
    cout << endl;

    cout << "Enter 1 to update brand " << endl;
    cout << "Enter 2 to update model " << endl;
    cout << "Enter 3 to update color " << endl;
    cout << "Enter 4 to update distance travelled " << endl;
    cout << endl;

    int choice;
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "Enter a new brand: ";
        cin >> cars[index].brand;
        break;
    case 2:
        cout << "Enter a new model: ";
        cin >> cars[index].model;
        break;
    case 3:
        cout << "Enter a new color: ";
        cin >> cars[index].color;
        break;
    case 4:
        cout << "Enter a new distance traveled: ";
        cin >> cars[index].distanceTraveled;
        break;

    default:
        cout << "Invalid choice." << endl;
    }
    cout << endl;
    cout << GREEN << "Car details are updated successfully." << RESET << endl;
    cout << endl;
    return;
}

void customerMenu()
{
    while (true)
    {
        cout << "Enter 1 to list cars" << endl;
        cout << "Enter 2 to check car availability" << endl;
        cout << "Enter 3 to rent car" << endl;
        cout << "Enter 0 to exit" << endl;
        cout << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            listOfCars(cars, carCount);
            break;
        case 2:
            checkCarAvailability();
            break;
        case 3:
            rentCar(cars, carCount);
            break;
        case 0:
            cout << "Exiting menu." << endl;
            return;
        default:
            cout << RED << "Invalid choice. Please try again." << RESET << endl;
            break;
        }
    }
}

void adminMenu()
{
    while (true)
    {
        cout << "Enter 1 to remove cars" << endl;
        cout << "Enter 2 to update car details" << endl;
        cout << "Enter 3 to add car" << endl;
        cout << "Enter 0 to exit" << endl;
        cout << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            removeCar(cars, carCount);
            break;
        case 2:
            carUpdate();
            break;
        case 3:
            addCar(cars, carCount);
            break;
        case 0:
            cout << "Exiting menu." << endl;
            return;
        default:
            cout << RED << "Invalid choice. Please try again." << RESET << endl;
            break;
        }
    }
}

int main()
{
    identity();
    return 0;
}