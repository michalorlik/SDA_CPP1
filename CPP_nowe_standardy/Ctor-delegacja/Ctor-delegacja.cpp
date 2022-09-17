#include <iostream>

enum class Waluta
{
    PLN,
    EUR,
    USD
};

class KontoBankowe
{
public: 
    KontoBankowe(std::string imie, float stan, float procent)
        : imieWlasciciela(imie)
        , stanKonta(stan)
        , oprocentowanie(procent)
    {
    }

    KontoBankowe(std::string imie)
        : KontoBankowe(imie, 100, 5 )
    {
    }

    float przelicz(float kwota, Waluta waluta)
    {
        switch (waluta)
        {
        case Waluta::EUR:
            return kwota * 4.80;
            break;
        case Waluta::USD:
            return kwota * 4.50;
            break;
        case Waluta::PLN:
        default:
        }
    }

    KontoBankowe(std::string imie, float stan, Waluta waluta)
        : KontoBankowe(imie, przelicz(stan, waluta), 5)
    {
    }

    KontoBankowe()
        : KontoBankowe("",0,0)
    {
    }

protected:
    std::string imieWlasciciela;
    float stanKonta;
    float oprocentowanie;
};

class KontoBankoweVip : public KontoBankowe
{
public: 
    using KontoBankowe::KontoBankowe;

    void podejdzBezKolejki()
    {
        std::cout << "Zapraszam szanownego klienta" << std::endl;
    }
};

class KontoBankoweWalutowe : public KontoBankowe
{
public:

    KontoBankoweWalutowe(std::string imie, float stan, float procent, Waluta walutaKonta)
        : KontoBankowe(imie, stan, procent)
        , waluta(walutaKonta)
    {
    }

protected:
    Waluta waluta;
};

int main()
{
    KontoBankowe kontoStefana("Stefan", 200, 6);
    KontoBankowe kontoMarian("Marian");
    KontoBankoweVip kontoVipZdzisiek("Zdzisiek");
    KontoBankoweVip kontoVipJanuarego("January", 10000, 7);

    std::cout << "Hello World!\n";
}

