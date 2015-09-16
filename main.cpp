#include <iostream>
#include <sstream>

using namespace std;

class Seller
{
    private:
        string companyName, pvmCode;
        int companyCode;
    public:
        //constructor
        Seller(string companyName, string pvmCode, int companyCode)
        {
            setcompanyName(companyName);
            setpvmCode(pvmCode);
            setcompanyCode(companyCode);
        }
        //setters
        void setcompanyName(string companyName)
        {
            this->companyName = companyName;
        }
        //------------------------------------------
        void setpvmCode(string pvmCode)
        {
            this->pvmCode = pvmCode;
        }
        //------------------------------------------
        void setcompanyCode(int companyCode)
        {
            this->companyCode = companyCode;
        }
        //getters
        string getcompanyName()
        {
            return companyName;
        }
        //------------------------------------------
        string getpvmCode()
        {
            return pvmCode;
        }
        //------------------------------------------
        int getcompanyCode()
        {
            return companyCode;
        }
        //destructor
        ~Seller(){}
};


class Buyer
{
    private:
        string name, surname, adress, city;
        long long int personalCode;
    public:
        //constructor
        Buyer(){};
        Buyer(string name, string surname, string adress, string city, long long int personalCode)
        {
            setname(name);
            setsurname(surname);
            setadress(adress);
            setcity(city);
            setpersonalCode(personalCode);
        }
        //setters
        void setname(string name)
        {
            this->name = name;
        }
        //------------------------------------------
        void setsurname(string surname)
        {
            this->surname = surname;
        }
        //------------------------------------------
        void setadress(string adress)
        {
            this->adress = adress;
        }
        //------------------------------------------
        void setcity(string city)
        {
            this->city = city;
        }
        //------------------------------------------
        void setpersonalCode(long long int personalCode)
        {
            this->personalCode = personalCode;
        }
        //getters
        string getname()
        {
            return name;
        }
        //------------------------------------------
        string getsurname()
        {
            return surname;
        }
        //------------------------------------------
        string getadress()
        {
            return adress;
        }
        //------------------------------------------
        string getcity()
        {
            return city;
        }
        //------------------------------------------
        int getpersonalCode()
        {
            return personalCode;
        }
        string toString()
        {
            stringstream ss;
            ss << "Vardas - " << name << " Pavarde - " << surname <<endl;
            ss << "Adresas - " << adress <<endl;
            ss << "Miestas - " << city <<endl;
            ss << "Asmens kodas - " << personalCode <<endl;
            return ss.str();
        }
        //destructor
        ~Buyer(){}
};

class Cars
{
    private:
        string make, model, idNumber, colour, licensePlate;
        int price, id;
        static int activeId, lastId;
        void incActiveId()
        {
            activeId++;
        }
    public:
        bool isEmpty;
        //constructor
        Cars(string make, string model, string idNumber, string colour, string licensePlate, int price)
        {
            setmake(make);
            setmodel(model);
            setidNumber(idNumber);
            setcolour(colour);
            setlicensePlate(licensePlate);
            setprice(price);
            id = ++lastId;
            incActiveId();
        }
        //Id Counter
        static int getactiveId()
        {
            return activeId;
        }

        //setters
        void setmake(string make)
        {
            this->make = make;
        }
        //------------------------------------------
        void setmodel(string model)
        {
            this->model = model;
        }
        //------------------------------------------
        void setidNumber(string idNumber)
        {
            this->idNumber = idNumber;
        }
        //------------------------------------------
        void setcolour(string colour)
        {
            this->colour = colour;
        }
        //------------------------------------------
        void setlicensePlate(string licensePlate)
        {
            this->licensePlate = licensePlate;
        }
        //------------------------------------------
        void setprice(int price)
        {
            this->price = price;
        }

        //getters
        string getmake()
        {
            return make;
        }
        //------------------------------------------
        string getmodel()
        {
            return model;
        }
        //------------------------------------------
        string getidNumber()
        {
            return idNumber;
        }
        //------------------------------------------
        string getcolour()
        {
            return colour;
        }
        //------------------------------------------
        string getlicensePlate()
        {
            return licensePlate;
        }
        //------------------------------------------
        int getprice()
        {
            return price;
        }

        string toString()
        {
            stringstream ss;
            ss << "Automobilis - " << make << " " << model <<endl;
            ss << "Identifikavimo nr. - " << idNumber <<endl;
            ss << "Spalva - " << colour << ", Valst. Nr. - " << licensePlate <<endl;
            ss << "Kaina - " << price <<endl;
            return ss.str();
        }

        //destructor
        ~Cars()
        {
            activeId--;
        }

};

int Cars::lastId = 0; //Primary values
int Cars::activeId = 0; //Primary values

int main()
{
    //Testing Buyer(string Name, string Surname, string Adress, string City, int PersonalCode)
    Buyer pirkejasAlfa("Vidas", "Naujokas", "Liepu g. 40", "Vilnius", 38506235555);
    cout << pirkejasAlfa.toString();
    cout << "\n\n" <<endl;

    //Naujas pirkejas su rankiniu priskirimu
    Buyer pirkejasBmw;
    pirkejasBmw.setname("Tadas");
    pirkejasBmw.setsurname("Blinda");
    pirkejasBmw.setadress("Kauno g. 20-10");
    pirkejasBmw.setcity("Klaipeda");
    pirkejasBmw.setpersonalCode(39601012222);
    cout << pirkejasBmw.toString();


    //Testing Seller(string CompanyName, string pvmCode, int CompanyCode)
    Seller pardavejas("UAB Autocar", "LT100009216547", 40680963);
    cout << pardavejas.getcompanyName() << ", im.k. " << pardavejas.getcompanyCode() <<endl;
    cout << "PVM k. " << pardavejas.getpvmCode() <<endl;
    cout << "\n\nNaujas pardavejas!\n" <<endl;

    pardavejas.setcompanyName("Tomo individuali imone");
    pardavejas.setcompanyCode(123456);
    pardavejas.setpvmCode("Nera");

    cout << pardavejas.getcompanyName() << ", im.k. " << pardavejas.getcompanyCode() <<endl;
    cout << "PVM k. " << pardavejas.getpvmCode() <<endl;
    cout << "\n\n" <<endl;

    //Testing Cars(string Make, string Model, string IDNumber, string Colour, string LicensePlate, int Price)
    Cars alfa("Alfa-Romeo", "MiTo", "WAUZZZ489ACAZ980AS1", "Raudona", "BT18 09K", 5200);

    cout << alfa.toString() <<endl;
    cout << "Gyvi klases objektai: " << alfa.getactiveId() << endl;

    //Creating new car
    cout << "\n\n\n\nNew Car!" <<endl;
    Cars *nauj;
    nauj = new Cars("BMW", "320d", "BKF124KOAPSZS92013", "Melyna", "HAE:222", 8450);
    cout << nauj->toString() <<endl;
    cout << "Gyvi klases objektai(pries istrinant nauja): " << alfa.getactiveId() << endl;
    delete nauj;
    cout << "Gyvi klases objektai(istrynus nauja): " << alfa.getactiveId() << endl;
    return 0;
}
