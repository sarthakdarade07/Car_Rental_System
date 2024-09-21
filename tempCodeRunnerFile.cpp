#include <iostream>
#include <vector>
using namespace std;

//  Class Company
class company
{
public:
  vector<company> Cars;
  string car, model, status, rate;

public:
  void addCar();
  void removeCar();
  void showCarlist();
  company();
  company(string c, string m, string s, string r);
};

// Default constructor

company::company()
{
  cout << "\t\t\t WELCOME \n";
  for (int i = 0; i <= 60; i++)
  {
    cout << "*";
  }
  cout << endl;
  Cars.push_back(company("BMW", "Q5", "Available", "125"));
}

// Parameterized constructor for setting values

company::company(string c, string m, string s, string r)
{
  car = c;
  model = m;
  status = s;
  rate = r;
}

// Function to add car

void company::addCar()
{
  cout << "\nEnter Car Name:";
  cin >> car;
  cout << "\nEnter Car Model:";
  cin >> model;
  cout << "\nEnter Rate:";
  cin >> rate;
  cout << "\nEnter status:";
  cin >> status;
  Cars.push_back(company(car, model, status, rate));
}

// Function to remove car

void company::removeCar()
{
  cout << "\nEnter Car Name:";
  cin >> car;
  cout << "\nEnter Car Model:";
  cin >> model;
  for (int i = 0; i < Cars.size(); i++)
  {
    if (Cars[i].car == car && Cars[i].model == model)
    {
      Cars.erase(Cars.begin() + i);
      cout << "Car removed sucessfully!!\n";
      return;
    }
  }
  cout << "Car not found \n";
}

// Function to remove car

void company::showCarlist()
{

  cout << "\nCar Name " << "Model " << "rate perkm " << "Status \n";
  for (int i = 0; i < Cars.size(); i++)
  {
    cout << Cars[i].car << "\t " << Cars[i].model << "\t" << Cars[i].rate << "\t  " << Cars[i].status << endl;
  }
  cout << endl;
}

class user : protected company
{
private:
  string name, carName, carModle, pickup, destination;
  int km;

public:
  void getchoice_user();
  void getchoice_company();
  void bill();
  void bookCar();
  void returnCar();
};

void user::bill()
{
  cout << "Name: " << name << endl;
  cout << "Car Name: " << carName << endl;
  cout << "Car Modle: " << carModle << endl;
  cout << "Pickup addr: " << pickup << endl;
  cout << "Destination addr: " << destination << endl;
  cout << "Total Amount: " << km << endl;
}

void user::bookCar()
{
  company::showCarlist();
  cout << "Enter Car name:  ";
  cin >> carName;
  cout << "Enter car Modle: ";
  cin >> carModle;

  for (int i = 0; i < Cars.size(); i++)
  {
    if (carName == Cars[i].car && carModle == Cars[i].model)
    {
      if (Cars[i].status == "Rented" || Cars[i].status == "rented")
      {
        cout << "Car is Already rented\n";
      }
      else
      {
        cout << "Enter your Name: ";
        cin >> name;
        cout << "Enter pickup Address: ";
        cin.ignore();
        getline(cin, pickup);
        cout << "Enter the destination address: ";
        cin.ignore();
        getline(cin, destination);
        cout << "Enter the total Km: ";
        cin >> km;
        Cars[i].status = "Rented";
        bill();
        cout << "Car rented succesfully!\n";
      }
      return;
    }
  }
  cout << "Invalid Car\n";
}

void user::returnCar()
{
  cout << "Enter Car name: ";
  cin >> carName;
  cout << "Enter car Modle: ";
  cin >> carModle;
  for (int i = 0; i < Cars.size(); i++)
  {
    if (carName == Cars[i].car && carModle == Cars[i].model)
    {
      Cars[i].status = "Available";

      cout << "Car returned Succesfully!\n";
      return;
    }
  }
  cout << "Invalid Car\n";
}

void user::getchoice_user()
{
  int ch;
  do
  {
    cout << "\n 1.Book Car\n 2.Return Car\n 3.Back\n";
    cout << "Enter Your choice:";
    cin >> ch;
    switch (ch)
    {
    case 1:
      bookCar();
      break;
    case 2:
      returnCar();
      break;
    case 3:
      return;
    default:
      cout << "Entered valid choice\n";
    }
  } while (ch != 3);
}

void user::getchoice_company()
{
  int ch;
  do
  {
    cout << "\n 1.Add Car\n 2.Remove Car\n 3.Show Carlist\n 4.Back\n";
    cout << "Enter Your choice:";
    cin >> ch;
    switch (ch)
    {
    case 1:
      addCar();
      break;
    case 2:
      removeCar();
      break;
    case 3:
      showCarlist();
      break;
    case 4:
      return;
      break;
    default:
      cout << "Enter Valid Choice\n";
    }
  } while (ch != 4);
}

int main()
{
  user u1;
  int ch1;
  do
  {
    cout << "\n 1.User\n 2.Company\n 3.Exit\n";
    cout << "Enter Your choice:";
    cin >> ch1;
    switch (ch1)
    {
    case 1:
      u1.getchoice_user();
      break;
    case 2:
      u1.getchoice_company();
      break;
    case 3:
      cout << "THANK YOU!!";
      break;
    default:
      cout << "Enter Valid Choice";
    }
  } while (ch1 != 3);

  return 0;
}