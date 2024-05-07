#include <iostream>
#include <string>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BRIGHT_BLUE "\033[94m"

using namespace std;

void customerMenu();
void adminMenu();

int carCount = 10;
int customerCount = 5;
int signedInCustomerIndex = -1;
const int maxCars = 20;
const int MAX_REVIEWS = 20;
int numReviews = 0;

struct Customer {
    string name;
    string mobileNo;
    string address;
    int days = 0;
    double cost = 1;
};

struct Admin {
    string username;
    string password;
};

struct Car {
    string brand;
    string model;
    string color;
    double distanceTraveled = 0;
    bool isRented = false; // Indicate whether the car is currently rented.
    Customer rentedBy; // The customer that is currently renting the car. If the car is not rented, this value will be null.
    double price = 0; // Price per day.

    string ACavailability;
    string GPSavail;
    string airbagAvail;
    string type; // 4x4, Hatchback, Sports, Crossover, SUV.
};

struct Review {
    Customer user;
    string review;
    int rating = 0;
};

Customer customers[20] =
{
    {"ahmed","123456789", "mainstreet"},
    {"mariam","987654321", "hegazstreet"},
     {"nour","123012300", "mokattam"},
     {"jana","123451234", "tagamoa"},
     {"seif","010987654", "roxy"}

};

Admin admins[2] = {
    {"admin1", "password1"},
    {"admin2", "password2"}
};

Car cars[maxCars] =
{
    {"Nissan", "Altima", "Red", 10000.0, true, customers[0], 2000.0 ,"Available","Unavailable","Available","Sedan"},
    {"Honda", "Civic", "Blue", 15000.0,false, {}, 1500.0, "Unavailable","Unavailable","Available","Sedan"},
    {"Kia", "       Sportage", "White", 13000.0,true,customers[3], 1350.0, "Unavailable","Available","Available","SUV"},
    {"Mercedes", "E-Class", "Black", 15000.0,false, {}, 4500.0,"Unavailable","Available","Available","Sedan"},
    {"Hyundai", "Verna", "Blue", 15000.0,false, {}, 1925.0,"Available","Unavailable","Unavailable","Sedan"},
    {"Mini Cooper", "S", "Grey", 15000.0, false,{}, 1000.0,"Available","Available","Available","Hatchback"},
    {"Audi", "\tQ8", "White", 15000.0,false, {}, 1850.0,"Available","Available","Available","4X4"},
    {"Renault", "Trafic", "Black", 15000.0,false, {}, 4550.0,"Available","Unavailable","Available","Van"},
    {"Chevorlet","Express", "White", 15000.0,false, {}, 4000.0,"Available","Available","Available","\tVan"},
    {"BMW","\tM3", "Blue", 15000.0,false, {}, 3000.0,"Available","Available","Available","Sports"},
};


Review reviews[MAX_REVIEWS];

// ------------------------------ NOUR ------------------------------ //
void listOfCars(Car cars[], int carCount, bool isCustomer)
{
    cout << endl;
    cout << "<<<< List of cars >>>> \n";
    cout << endl;

    if (isCustomer)
    {
        cout << "   Brand\t\t" << "Model\t\t" << "Color \t\t" << "Disntance Traveled\t" << "Price per day\t" << endl;
        for (int i = 0; i < carCount; i++)
        {
            cout << i + 1 << ") " << cars[i].brand << "\t\t" << cars[i].model << "\t\t" << cars[i].color << "\t\t" << cars[i].distanceTraveled << "\t\t\t" << cars[i].price << "\t";
            cout << endl << endl;
        }
    }

    else {
        cout << "   Brand\t\t" << "Model\t\t" << "Color \t\t" << "Disntance Traveled\t" << "Price per day\t" << "     Renter\t" << endl;

        for (int i = 0; i < carCount; i++)
        {
            cout << i + 1 << ") " << cars[i].brand << "\t\t" << cars[i].model << "\t\t" << cars[i].color << "\t\t" << cars[i].distanceTraveled << "\t\t\t" << cars[i].price << "\t";
            if (cars[i].isRented == true)
            {
                cout << "             ";
                cout << cars[i].rentedBy.name;
            }

            cout << endl << endl;
        }
    }

    
}
// ----------------------------------------------------------------- //


// ------------------------------ TIA ------------------------------ //
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
// ------------------------------------------------------------------------ //


// ------------------------------ TIA & NOUR ------------------------------ //
void displaytotalcost(int& indexcarr)
{
    cout << "How many days do you want to rent the car?\n";
    cin >> customers[signedInCustomerIndex].days;
    customers[signedInCustomerIndex].cost = customers[signedInCustomerIndex].days * cars[indexcarr].price;
    cout << endl;
    cout << GREEN << "Car is rented successfully.\n" << RESET;
    cout << GREEN << "The total cost of your car: " << cars[indexcarr].brand << " is: " << customers[signedInCustomerIndex].cost << RESET;
    cout << GREEN << " for " << customers[signedInCustomerIndex].days << " days" << RESET << endl << endl;
}

void carFuncionalities()
{
    int carINDEX;
    string answer;
    do
    {
        cout << "Enter the index of car to display functionalities: ";
        cin >> carINDEX;
        carINDEX--;
        cout << endl;
        cout << "Another functionalities for " << cars[carINDEX].brand << " " << cars[carINDEX].model << endl;
        cout << "AC Avaialability\t" << "GPS Availability\t" << "Airbag Avaialability\t" << "Bodytype style\t" << endl << endl;
        cout << YELLOW << cars[carINDEX].ACavailability << "\t\t" << cars[carINDEX].GPSavail << "\t\t" << cars[carINDEX].airbagAvail << "\t\t" << cars[carINDEX].type << RESET << endl << endl;
        cout << "Do you want to know more funtionalities about another car? (y/n)";
        cin >> answer;
        do
        {
            if ((answer == "n" || answer == "N" || answer == "Y" || answer == "y"))
                break;
            cout << RED << "Invalid answer ,please re-enter " << RESET << endl;
            cin >> answer;
        } while ((answer != "Y" || answer != "y") && (answer != "N" || answer != "n"));
    } while (answer == "y" || answer == "Y");
}


void priceFilteration(Car cars[], int carCount)
{
    int price;
    bool found = true;
    cout << endl;
    cout << "Enter the maximum price you want to filter by:\n";
    cin >> price;
    if (price < 1000.0)
    {
        found = false;
        cout << RED << "Sorry,cars with this price is unavailable!\n\n" << RESET;
    }
    if (found)
    {
        cout << "These are the cars available for " << price << " and below " << endl;
        cout << "   Brand\t" << "Model\t" << "Color \t" << "Disntance Traveled\t" << "Price per day\n";
        for (int i = 0; i < carCount; i++)
        {
            if (cars[i].price <= price)
            {
                cout << i + 1 << ") " << cars[i].brand << "\t" << cars[i].model << "\t" << cars[i].color << "\t" << "\t" << cars[i].distanceTraveled << "\t\t    " << YELLOW << cars[i].price << "\t" << RESET << endl;
                cout << endl;
            }
        }
    }

}
// -------------------------------------------------------------------- //

// ------------------------------ JUMANA ------------------------------ //
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
        cout << "enter price per day of the car:";
        cin >> newcar.price;
        cout << "Is AC available in the car? (Available/Unavailable) ";
        cin >> newcar.ACavailability;
        if (newcar.ACavailability == "yes" || newcar.ACavailability == "available")
            newcar.ACavailability = "Available";
        else
            newcar.ACavailability = "Unavailable";
        cout << "Is GPS available in the car? (Available/Unavailable) ";
        cin >> newcar.GPSavail;
        if (newcar.GPSavail == "yes" || newcar.GPSavail == "available")
            newcar.GPSavail = "Available";
        else
            newcar.GPSavail = "Unavailable";
        cout << "Is airbag available in the car? (Available/Unavailable) ";
        cin >> newcar.airbagAvail;
        if (newcar.airbagAvail == "yes" || newcar.airbagAvail == "available")
            newcar.airbagAvail = "Available";
        else
            newcar.airbagAvail = "Unavailable";
        cout << "Enter car type: ";
        cin >> newcar.type;
        newcar.isRented = false;
        cars[carCount++] = newcar;
        cout << GREEN << "Car added successfully and these are the details of the car: " << RESET << endl << endl;
        cout << "Brand: " << newcar.brand << "  " << "Model: " << newcar.model << "  " << "Color: " << newcar.color << "  " << "Distance traveled: " << newcar.distanceTraveled << "   " << "price per day:" << newcar.price << endl;
    }
    else
    {
        cout << RED << "Can't add cars, max reached." << RESET << endl;
    }
}


// ----------------------------------------------------------------- //


// ------------------------------ MARTIN ------------------------------ //
void rentCar(Car cars[], int carCount)
{
    cout << "Enter The index of the car you want to rent: ";

    int carIndex;
    cin >> carIndex;
    carIndex -= 1;

    Customer customer = customers[signedInCustomerIndex];

    if (carIndex >= 0 && carIndex < carCount)
    {
        if (!cars[carIndex].isRented)
        {
            cars[carIndex].isRented = true;
            cars[carIndex].rentedBy = customer;
            cout << endl;
            displaytotalcost(carIndex);
        }
        else {
            cout << RED << "Sorry, the car is already rented.\n" << RESET;
        }
    }
    else {
        cout << RED << "Invalid car index.\n" << RESET;
    }
}
// ----------------------------------------------------------------- //


// ------------------------------ TOQA ------------------------------ //
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
                listOfCars(cars, carCount, false);
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
    bool validChoice = false; // Flag to check if the choice is valid
    do {
        cout << "Do you want to sign up or sign in?" << ' ' << "(U for signing up) and (I for signing in)" << endl;
        cin >> login;
        cout << endl;
        if (login == 'U' || login == 'u')
        {
            validChoice = true;
            do {
                cout << "Create new account" << endl;
                cout << "Enter new username:";
                cin >> newCustomer.name;
                bool found = false;
                for (int i = 0; i < customerCount; i++)
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
                    customers[customerCount] = newCustomer;
                    signedInCustomerIndex = customerCount;
                    customerCount++;
                    cout << endl;
                    cout << GREEN << "You are signed up successfully" << RESET << endl;
                    cout << endl;
                    listOfCars(cars, carCount, true);
                    cout << endl;
                    break;
                }
            } while (true);
        }
        else if (login == 'I' || login == 'i')
        {
            validChoice = true;
            cout << "Enter your username , mobile number and address" << endl;
            bool found = false;
            do {
                cin >> username >> mobilenum >> address;
                for (int i = 0; i < customerCount; i++)
                {
                    if ((username == customers[i].name) && (mobilenum == customers[i].mobileNo) && (address == customers[i].address))
                    {
                        found = true;

                        cout << endl;
                        cout << GREEN << "You are signed in successfully" << RESET << endl;
                        cout << endl;
                        listOfCars(cars, carCount, true);
                        cout << endl;
                        signedInCustomerIndex = i;
                        break;
                    }
                }
                if (found == false)
                {
                    cout << RED << "Incorrect username or mobile number or address" << RESET << endl;
                    cout << "Please renter your username , mobile number and address:" << endl;
                }
            } while (found == false);
        }
        else if (validChoice == false)
        {
            cout << RED << "invalid choice" << RESET << endl;
            cout << RED << "TRY AGAIN" << RESET << endl;
        }
    } while (validChoice == false);
}
void startProgram()
{
    string identity;
    char choice = 'N';
    do {
        cout << BRIGHT_BLUE << '\t' << '\t' << '\t' << '\t' << '\t' << "WELCOME TO OUR CAR RENTAL SYSTEM" << RESET << endl << endl;
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
// ------------------------------------------------------------------ //

// ------------------------------ MENNA ------------------------------ //
void carUpdate()
{
    cout << "Enter the index of the car you want to update its details: ";
    int index;
    cin >> index;

    if (index > carCount || index < 1)
    {
        cout << endl;
        cout << RED << "invalid index.\n" << RESET;
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
// ----------------------------------------------------------------- //


// ------------------------------ KARIM ------------------------------ //
void removeCar(Car cars[], int& carCount) {
    cout << "Enter the index of the car you want to remove: ";

    int index;
    cin >> index;
    index -= 1;

    if (index < 0 || index >= carCount) {
        cout << RED << "Invalid index. Cannot remove car." << RESET << endl;
        return;
    }

    for (int i = index; i < carCount; i++) {
        cars[i] = cars[i + 1];
    }

    carCount--;

    cout << endl;
    cout << GREEN << "Car Removed Successfully\n" << RESET;
    cout << endl;
}


void addReview(Review reviews[]) {
    if (numReviews >= MAX_REVIEWS) {
        cout << "Maximum number of reviews reached." << endl;
        return;
    }

    Review newReview;
    newReview.user = customers[signedInCustomerIndex];
    cout << "Write your review: ";
    cin.ignore();
    getline(cin, newReview.review);

    while (true) {
        cout << "Enter your rating (1 - 5): ";
        cin >> newReview.rating;
        if (newReview.rating >= 1 && newReview.rating <= 5) {
            break;
        }
        else {
            cout << RED << "Invalid rating. Please enter a number between 1 and 5." << RESET << endl;
        }
    }

    reviews[numReviews++] = newReview;
    cout << GREEN << "Thank you for your review!" << RESET << endl;
}

void printReviews() {
    cout << endl;
    cout << "<<<< Reviews >>>> \n";
    cout << endl;
   
    for (int i = 0; i < numReviews; i++)
    {
        cout << "User: " << reviews[i].user.name << endl;
        cout << "Review: " << reviews[i].review << endl;
        cout << "Rating: ";

        for (int j = 0; j < reviews[i].rating; j++)
            cout << "*";

        cout << endl << endl;
    }
}


void customerMenu()
{
    while (true)
    {
        cout << "Enter 1 to display more functionalities for specific car" << endl;
        cout << "Enter 2 to check car availability" << endl;
        cout << "Enter 3 to rent car" << endl;
        cout << "Enter 4 to view list of cars" << endl;
        cout << "Enter 5 to filter list by price " << endl;
        cout << "Enter 6 to add a review" << endl;
        cout << "Enter 0 to exit" << endl;
        cout << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            carFuncionalities();
            break;
        case 2:
            checkCarAvailability();
            break;
        case 3:
            rentCar(cars, carCount);
            break;
        case 4:
            listOfCars(cars, carCount, true);
            break;
        case 5:
            priceFilteration(cars, carCount);
            break;
        case 6:
            addReview(reviews);
            break;
        case 0:
            cout << "Exiting menu." << endl;
            return;
        default:
            cout << RED << "Invalid choice. Please try again." << RESET << endl;
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
        cout << "Enter 4 to print reviews" << endl;
        cout << "Enter 5 to list cars" << endl;
        cout << "Enter 0 to exit" << endl;
        cout << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            removeCar(cars, carCount);
            break;
        case 2:
            carUpdate();
            break;
        case 3:
            addCar(cars, carCount);
            break;
        case 4:
            printReviews();
            break;
        case 5:
            listOfCars(cars, carCount, false);
            break;
        case 0:
            cout << "Exiting menu." << endl;
            return;
        default:
            cout << RED << "Invalid choice. Please try again." << RESET << endl;
        }

    }
}
// ------------------------------------------------------------------ //

int main()
{
    startProgram();
    return 0;
}