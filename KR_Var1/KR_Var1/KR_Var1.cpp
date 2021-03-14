#include <iostream>
#include <map>
#include <vector>

class Taxpayer {
private:
    int upn;
    char name[10], passport[10];
public:
    Taxpayer(int curr_upn, char curr_name[], char curr_passport[]) {
        upn = curr_upn;
        strcpy_s(name, curr_name);
        strcpy_s(passport, curr_passport);
    }
    Taxpayer() : upn(0), name(""), passport("") {}
    Taxpayer(Taxpayer& curr) {
        upn = curr.upn;
        strcpy_s(name, curr.name);
        strcpy_s(passport, curr.passport);
    }

    Taxpayer clone() {
        return *new Taxpayer(*this);
    }

    friend std::istream& operator>> (std::istream& in, Taxpayer& curr) {
        in >> curr.upn;
        in >> curr.name;
        in >> curr.passport;
        return in;
    }

    friend std::ostream& operator<< (std::ostream& out, const Taxpayer& curr) {
        out << "UPN: " << curr.upn << " Name: " << curr.name << " Passport: " << curr.passport << "\n";
        return out;
    }

    friend bool operator< (const Taxpayer& a, const Taxpayer& b) {
        return a.upn < b.upn;
    }
};

template<typename T>
class Property {
 public:
    T worth;
    int year;
    std::shared_ptr<Taxpayer> owner;
    Property(T curr_worth, int curr_year) : worth(curr_worth), year(curr_year) {};
    Property(T curr_worth, int curr_year, std::shared_ptr<Taxpayer> curr_owner) : 
        worth(curr_worth), year(curr_year), owner(curr_owner) {};
    virtual Property* clone() {
        return new Property(this->worth, this->year, this->owner);
    }
    virtual double tax() {}
    virtual std::string toString() {}
    virtual ~Property() {}
};

template<typename T>
class Appartment : public Property<T> {
 public:
     using Property<T>::worth;
     inline static float TAX_RATE = 1 / 1000;
     std::string adress;
     double share;
     double tax() {
         return TAX_RATE * share * worth;
     }
};

template<typename T>
class Car : public Property<T> {
public:
    using Property<T>::worth;
    inline static float TAX_RATE = 1 / 200;
    std::string carNumber;
    long long factoryNumber;
    double tax() {
        return TAX_RATE * worth;
    }
};

template<typename T>
class CountryHouse : public Property<T> {
public:
    using Property<T>::worth;
    inline static float TAX_RATE = 1 / 500;
    int cadastraNumber;
    double square, pricePerAcre;
    std::string adress;
    double tax() {
        return TAX_RATE * square * pricePerAcre;
    }
};

template<typename T>
class TaxpayerDataBase {
 public:
    std::map<int, Taxpayer*> Taxpayers;
    std::map<Taxpayer*, std::vector<Property<T>*>> Properties;
    void addTaxpayer(Taxpayer* curr) {
        Taxpayer* ptr = new Taxpayer(curr);
        Taxpayers[ptr->upn] = ptr;
    }
    void addTaxpayerProperty(Taxpayer* currPayer, Property<T>* currProp) {
        Properties[currPayer].push_back(currProp);
    }
    friend std::ostream& operator<< (std::ostream& out, TaxpayerDataBase& Data) {
        for (auto&& curr : Data.Properties) {
            out << curr.first->name << ' ';
            T currWorth = 0;
            double currTax = 0;
            for (auto&& currProp : curr.second) {
                currWorth += currProp.worth;
                currTax += currProp.tax();
            }
            out << currWorth << ' ' << currTax;
        }
        out << '\n';
        return out;
    }
};

int main()
{
    
}