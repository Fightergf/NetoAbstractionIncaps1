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
    void set_address(std::string C, std::string S, int h, int r)
    {
        this->Country = C;
        this->Street = S;
        this->home = h;
        this->room = r;
    }
    std::string get_output_address()
    {
        return Country + "\n" + Street + "\n" + std::to_string(home) + "\n" + std::to_string(room);
    }
};

void out_file(Address &Ad)
{
    std::cout << "Файл успешно открыт!!!" << std::endl;
    Address adr;
    std::ifstream file("in.txt");
    std::string C;
    std::string St;
    int h;
    int r;
    int count;
    if (file.is_open())
    {
        file >> count;
        std::cout << count << std::endl;
        for (int i = 0; i < count; i++)
        {
            file >> C;
            file >> St;
            file >> h;
            file >> r;
            Ad.set_address(C, St, h, r);
            std::cout << adr.get_output_address();
        }
    }
    else
    {
        std::cout << "Не получилось открыть файл!" << std::endl;
    }
    file.close();
}


int main()
{
    setlocale(LC_ALL, "Russian");
    //SetConsoleOutputCP(1251);
    //SetConsoleCP(1251);
    Address adr;
    out_file(adr);

}
