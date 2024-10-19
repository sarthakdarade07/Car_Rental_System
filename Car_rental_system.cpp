#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

// Template function for sorting
template <typename T, typename Compare>
void sortVector(vector<T> &vec, Compare comp)
{
  sort(vec.begin(), vec.end(), comp);
}

//  Class Company
class company
{
public:
  vector<company> Cars;
  string car, model, status;
  int rate;

public:
  void addCar();
  void removeCar();
  void showCarlist();
  void show_history();
  company();
  company(string c, string m, string s, int r);
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
  Cars.push_back(company("Suzuki", "Swift", "Available", 15));
  Cars.push_back(company("Audi", "Q5", "Available", 125));
  Cars.push_back(company("Honda", "City", "Available", 25));
  
}

// Parameterized constructor for setting values

company::company(string c, string m, string s, int r)
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
      if (Cars[i].status == "Rented")
      {
        cout << "Car is rented,can't remove\n";
        return;
      }
      else
      {
        Cars.erase(Cars.begin() + i);
        cout << "Car removed sucessfully!!\n";
        return;
      }
    }
  }
  cout << "Car not found \n";
}

// Function to show Carlist car

void company::showCarlist()
{
  // Using lambda to compare car names
  sortVector(Cars, [](const company &a, const company &b)
             {
               return a.car < b.car; // Sorting in ascending order by car name
             });
  cout << "\nCar Name " << "Model " << "rate perkm " << "Status \n";
  for (int i = 0; i < Cars.size(); i++)
  {
    cout << Cars[i].car << "\t " << Cars[i].model << "\t" << Cars[i].rate << "\t  " << Cars[i].status << endl;
  }
  cout << endl;
}

void company::show_history(){
ifstream fin;
fin.open("Bill.txt");
char ch;
if (!fin){
cout<<"No Bookings Yet\n";
}
else{
  while (fin.get(ch))
  {
    cout <<"\n"<< ch;
  }
  fin.close();
}
}
class Transport_vehicle
{
private:
  string vehicleName, cname;
  string description;
  double price, km;
  vector<string> vec1;
  vector<string> vec2;
  vector<double> vec3;

public:
  Transport_vehicle()
  {
    vec1.push_back("Tata Ace");
    vec2.push_back(" Small businesses,transporting over short distances.");
    vec3.push_back(25.0);

    vec1.push_back("Bolero Pickup");
    vec2.push_back(" Agricultural products and medium-weight loads.   ");
    vec3.push_back(30.0);

    vec1.push_back("Tata LPT");
    vec2.push_back(" Heavy cargo transportation over long distances.");
    vec3.push_back(50.0);
  }
  void book_vehicle()
  {
    cout << "\n Enter vehical name: ";
    cin.ignore();
    getline(cin, vehicleName);
 
    for (int i = 0; i < vec1.size(); i++)
    {
      if (vehicleName == vec1[i])
      {
        cout << "Enter your Name: ";
        cin.ignore();
        getline(cin, cname);
        cout << "Enter Km: ";
        cin >> km;
        cout << "Vehicle Booked Succesfully\n";
        return;
      }
      }
        cout << "Invalid Car";
      return;
    }
  void display()
  {
    cout << "\n Vehicle Name  " << "  Vechile Description" << "\t\t\t\t\t  Price \\km \n";
    for (int i = 0; i < vec1.size(); i++)
    {
      cout << vec1[i] << " \t" << vec2[i] << "\t\t" << vec3[i] << endl;
    }
  }
};


// Class user to accept user details

class user : protected company, protected Transport_vehicle
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
  void bill_file();
};

// function to book car

void user::bookCar()
{
  company::showCarlist();
  cout << "Enter Car name: ";
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
        cin.ignore();
        getline(cin, name);
        cout << "Enter pickup Address: ";
        cin.ignore();
        getline(cin, pickup);
        cout << "Enter the destination address: ";
        cin.ignore();
        getline(cin, destination);
        cout << "Enter the total Km: ";
        cin >> km;
        Cars[i].status = "Rented";
        km *= Cars[i].rate;
        cout << "\nCar rented succesfully!\n";
        bill();
        bill_file();
      }
      return;
    }
  }
  cout << "Invalid Car\n";
}

// function to return car

void user::returnCar()
{
  cout << "Enter Car name: ";
  cin >> carName;
  cout << "Enter car Modle: ";
  cin >> carModle;
  for (int i = 0; i < Cars.size(); i++)
  {
    if (carName == Cars[i].car && carModle == Cars[i].model && Cars[i].status != "Available")
    {
      Cars[i].status = "Available";

      cout << "Car returned Succesfully!\n";
      return;
    }
  }
  cout << "Invalid Car\n";
}

// function to get booking bill
void user::bill()
{
  for (int i = 0; i < 60; i++)
  {
    cout << "*";
  }
  cout << "\n\t\t\tBILL\n";
  cout << "Name: " << name << endl;
  cout << "Car Name: " << carName << endl;
  cout << "Car Modle: " << carModle << endl;
  cout << "Pickup Addr:" << pickup << endl;
  cout << "Destination Addr: " << destination << endl;
  cout << "Total Amount: " << km << " Rs." << endl;
  for (int i = 0; i < 60; i++)
  {
    cout << "*";
  }
}

// Function to store booking details history into file

void user::bill_file()
{
  fstream fout;
  fout.open("Bill.txt", ios::app); // file is opened in append mode
  fout << "Name: " << name << endl;
  fout << "Car Name: " << carName << endl;
  fout << "Car Modle: " << carModle << endl;
  fout << "Pickup Addr:" << pickup << endl;
  fout << "Destination Addr: " << destination << endl;
  fout << "Total Amount: " << km << " Rs." << "\n";
  fout << endl;
  fout.close();
}

void user::getchoice_user()
{
  int ch;
  do
  {
    cout << "\n 1.Book Car\n 2.Return Car\n 3.Book transport vehicle\n 4.back\n";
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
      display();
      book_vehicle();
      break;
    case 4:
      return;
      break;
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
    cout << "\n 1.Add Car\n 2.Remove Car\n 3.Show Carlist\n 4.Show booking History\n 5.Back\n";
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
      show_history();
      break;
      case 5:
      return;
      break;
    default:
      cout << "Enter Valid Choice\n";
    }
  } while (ch != 5);
}

int main()
{
  user u1;
  int ch1;
  do
  {
    cout << "\n 1.User\n 2.Company\n 3.Exit\n";
    cout << "Enter Your choice:";

    try
    {             // Exception handling : If user enter choice other than int value it will
      cin >> ch1; // get terminated in controlled manner
      if (ch1 == 0)
      {
        throw(ch1);
      }
      else
      {
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
      }
    }
    catch (int b)
    {
      cout << "\nEnter choice in Integer!! \n\n";
      break;
    }
  } while (ch1 != 3);

  return 0;
}