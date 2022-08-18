#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

class Address
{
private:
    std::string Country;
    std::string Street;
    int home;
    int room;
public:
    Address()
    {
        Country = "";
        Street = "";
        home = 0;
        room = 0;
    }
    Address(std::string Country, std::string Street, int home, int room)
    {
    this->Country = Country;
    this->Street = Street;
    this->home = home;
    this->room = room;
    }
    void set_address(std::string C, std::string S, int h, int r)
    {
        Country = C;
        Street = S;
        home = h;
        room = r;
    }
    std::string get_output_address()
    {
        return Country + "," + Street + "," + std::to_string(home) + "," + std::to_string(room);
    }
};

int out_file(Address *arrADR)
{
    std::cout << "Файл успешно открыт!!!" << std::endl;
    std::ifstream filer("in.txt");
    std::string Country;
    std::string Street;
    int home;
    int room;
    int countAddress;

    if (filer.is_open())
    {

        filer >> countAddress;
        std::cout << countAddress << std::endl;
        int iter = 0;
        for (int i = 0; i < countAddress; i++)
        {
            filer >> Country;
            filer >> Street;
            filer >> home;
            filer >> room;
            arrADR[iter] = Address(Country, Street, home, room);
            iter++;
        }
        std::cout << arrADR[2].get_output_address() + "\n";
        std::cout << arrADR[1].get_output_address() + "\n";
        std::cout << arrADR[0].get_output_address() + "\n";
    }
    else
    {
        std::cout << "Не получилось открыть файл!" << std::endl;
    }
    return countAddress;
    filer.close();
}

void writeFile(Address *arrADR, int countadr)
{
    std::ofstream filew("out.txt");
    filew << countadr << "\n";
    filew << arrADR[2].get_output_address() + "\n";
    filew << arrADR[1].get_output_address() + "\n";
    filew << arrADR[0].get_output_address() + "\n";
}

int main()
{
    setlocale(LC_ALL, "Russian");

    Address* arrADR = new Address[5];
    int countadr = out_file(arrADR);

    writeFile(arrADR,countadr);
    delete [] arrADR;
}
