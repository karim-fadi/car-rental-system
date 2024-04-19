#include <iostream>
#include <string>

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
        cout << "Car added successfully and these are the details of the car: " << endl << endl;
        cout << "Brand: " << newcar.brand << "  " << "Model: " << newcar.model << "  " << "Color: " << newcar.color << "  " << "Distance traveled: " << newcar.distanceTraveled << endl << endl;
    }
    else
    {
        cout << "Can't add cars, max reached." << endl;
    }
}

void removeCar(Car cars[], int& carCount) {
    cout << "Enter the index of the car you want to remove: ";

    int index;
    cin >> index;
    index -= 1;

    if (index < 0 || index >= carCount) {
        cout << "Invalid index. Cannot remove car." << endl;
        return;
    }

    for (int i = index; i < carCount - 1; ++i) {
        cars[i] = cars[i + 1];
    }

    carCount--;

    cout << endl;
    cout << "Car Removed Successfully\n";
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
            cout << "Car rented successfully.\n";
            cout << endl;
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
                cout << endl;
                cout << "You are signed in successfully" << endl;
                cout << endl;
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
                cout << endl;
                cout << "You are signed up successfully" << endl;
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
                    cout << "You are signed in successfully" << endl;
                    cout << endl;
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
            cout << "Invalid choice" << endl;
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
        cout << "invalid index.\n";
        cout << endl;
        return;
    }
    else if (carCount == 0)
    {
        cout << endl;
        cout << "No cars available to check.\n";
        cout << endl;
        return;
    }
    else if (cars[index - 1].isRented == false)
    {
        cout << endl;
        cout << "car is available to rent.\n";
        cout << endl;
        return;
    }
    cout << "car is rented.\n";
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
        cout << "invalid index.\n";
        cout << endl;
        return;
    }

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
    cout << "Car details are updated successfully." << endl;
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
            cout << "Invalid choice. Please try again." << endl;
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
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }
}

int main()
{
    identity();
    return 0;
}