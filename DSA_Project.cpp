#include <iostream>
#include <fstream>
#include <conio.h>
#include <unistd.h>
#include <iomanip>

using namespace std;

class Customer // customer class
{
public:
    string customer_name;
    string car_model;
    string car_number;
};

class Rent : public Customer
{
public:
    int days = 0, rentalfee = 0;
    void login();
    void data()
    {

        login();
        sleep(1);
        system("CLS");
        cout << "\t\t\t\tPlease Enter Your Name: ";
        cin >> customer_name;
        cout << endl;
        // int i = 1;
        do
        {
            cout << "\t\t\t\tPlease Select A Car" << endl;
            cout << "\t\t\t\tEnter 'A' For Tesla 2011" << endl;
            cout << "\t\t\t\tEnter 'B' For Hyundai 2015" << endl;
            cout << "\t\t\t\tEnter 'C' For Ford 2017" << endl;
            cout << endl;
            cout << "\t\t\t\tChoose A Car From The Above Options : ";
            cin >> car_model;
            cout << endl;
            cout << "-------------------------------------------------------------------------------" << endl;
            sleep(0.2);
            if (car_model == "A")
            {
                system("CLS");

                cout << "You Have Choosed Tesla Model 2011" << endl;
                ifstream inA("Tesla_data.txt");
                char str[200];
                while (inA)
                {
                    inA.getline(str, 200);
                    if (inA)
                    {
                        cout << str << endl;
                    }
                }
            }
            sleep(1);
            if (car_model == "B")
            {
                system("CLS");

                cout << "You Have Choosed Hyundai Model 2015" << endl;
                ifstream inB("Hyundai_data.txt");
                char str[200];
                while (inB)
                {
                    inB.getline(str, 200);
                    if (inB)
                    {
                        cout << str << endl;
                    }
                }
            }
            sleep(1);
            if (car_model == "C")
            {
                system("CLS");

                cout << "You Have Choosed Ford Model 2017" << endl;
                ifstream inC("Ford_data.txt");
                char str[200];
                while (inC)
                {
                    inC.getline(str, 200);
                    if (inC)
                    {
                        cout << str << endl;
                    }
                }
            }
            sleep(1);
            if (car_model != "A" && car_model != "B" && car_model != "C")
            {
                cout << "Invalid Car Model.Please Try Again!";
                sleep(1);
                system("CLS");
            }

        } while (car_model != "A" && car_model != "B" && car_model != "C");

        cout << "-------------------------------------------------------------------------------" << endl;
        cout << "Please provide following information:" << endl;
        cout << "Please Select A Car No. : ";
        cin >> car_number;
        cout << "Number of Days you wish to rent the car : ";
        cin >> days;
        cout << endl;
    }
    void calculate();
    void showRent();
};

void Rent :: login(){
    string pass = "";
    char ch;
    cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t        CAR RENTAL SYSTEM \n\n";
    cout<<"\t\t\t\t\t--------------------------------";
    cout<<"\n\t\t\t\t\t\t       LOGIN  \n";
    cout<<"\t\t\t\t\t--------------------------------\n\n";
    cout<<"\t\t\t\t\t Enter Password : ";
    ch = _getch();
    while(ch != 13){
        pass.push_back(ch);
        cout<< '*';
        ch = _getch();
    }
    if(pass == "pass"){
        cout<<"\n\n\n\t\t\t\t\t\t Access Granted! \n";
        system("PAUSE");
        system("CLS");
    }
    else{
        cout<<"\n\n\n\t\t\t\t\t\t Access Aborted... \n\t\t\t\t\t\t\t Please Try Again \n\n";
        system("PAUSE");
        system("CLS");
        login();  
    }
}

void Rent ::calculate()
{
    sleep(1);
    system("CLS");
    cout << "Calculating rent.Please wait........" << endl;
    sleep(2);
    if (car_model == "A" || car_model == "B")
    {
        rentalfee = days * 56;
    }
    if (car_model == "A" || car_model == "B")
    {
        rentalfee = days * 60;
    }
    if (car_model == "A" || car_model == "B")
    {
        rentalfee = days * 75;
    }
}

void Rent ::showRent()
{
    cout << "\n\t\t                       Car Rental - Customer Invoice                       " << endl;
    cout << "\t\t     ////////////////////////////////////////////////////////////////////////" << endl;
    cout << "\t\t      |  Invoice No. :---------------------------|" << setw(10) << "#Cnb81353"
         << " |" << endl;
    cout << "\t\t      |  Customer Name :-------------------------|" << setw(10) << customer_name << " |" << endl;
    cout << "\t\t      |  Car Model :-----------------------------|" << setw(10) << car_model << " |" << endl;
    cout << "\t\t      |  Car No. :-------------------------------|" << setw(10) << car_number << " |" << endl;
    cout << "\t\t      |  Number Of Days :------------------------|" << setw(10) << days << " |" << endl;
    cout << "\t\t      |  Your Rental Amount Is :-----------------|" << setw(10) << rentalfee << " |" << endl;
    cout << "\t\t      |  Caution Money :-------------------------|" << setw(10) << "0"
         << " |" << endl;
    cout << "\t\t      |  Advanced :------------------------------|" << setw(10) << "0"
         << " |" << endl;
    cout << "\t\t         ====================================================================" << endl;
    cout << endl;
    cout << "\t\t      |  Total Rental Amount Is :----------------|" << setw(10) << rentalfee << " |" << endl;
    cout << "\t\t      # This is a computer generated invoice and it does not" << endl;
    cout << "\t\t        require an authorised signture #" << endl;
    cout << endl;
    cout << "\t\t     ////////////////////////////////////////////////////////////////////////" << endl;
    cout << "\t\t     You are advised to pay up the amount before due date." << endl;
    cout << "\t\t     otherwise panelty fee will be applied" << endl;
    cout << "\t\t     ////////////////////////////////////////////////////////////////////////" << endl;
    int f;
    system("PAUSE");
    system("CLS");
    ifstream inf("Thanks.txt");
    char str[1000];
    while (inf)
    {
        inf.getline(str, 1000);
        if (inf)
        {
            cout << str << endl;
        }
    }
    inf.close();
}

class welcome{
    public:
        int welcum(){
            ifstream in("welcome.txt");
            if(!in){
                cout<< "Cannot open input file.\n";
            }
            char str[1000];
            while(in){
                in.getline(str,1000);
                if(in){
                    cout<<str<<endl;
                }
            }
            in.close();
            sleep(1);
            cout<<"\nStarting the program please wait....."<<endl;
            sleep(1);
            cout<<"\nloading up files......."<<endl;
            sleep(1);
            system("CLS");
        }
};

int main()
{
    welcome obj1;
    obj1.welcum();
    Rent car;
    car.data();
    car.calculate();
    car.showRent();

    return 0;
}

/*void Rent ::login()
{
    int pass_key;
    cout << "\t\t\t\tEnter Security Password : ";
    cin >> pass_key;
    if (pass_key == 123)
    {
        cout << endl
             << "\t\t\t\tSuccessfully login(*_*)";
    }
    else
    {
        login();
    }
}*/
