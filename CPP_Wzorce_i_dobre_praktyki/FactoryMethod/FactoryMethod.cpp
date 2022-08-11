#include <iostream>
#include <vector>

class Computer
{
public:
    virtual void printSpecification() = 0;

    Computer(int ram, std::string cpu, int uuid)
        : _ram(ram), _cpu(cpu), _uuid(uuid)
    {
    }

protected:
    int _ram;
    std::string _cpu;
    int _uuid;
};

class Laptop : public Computer
{
public:
    Laptop(int ram, std::string cpu, int uuid)
        : Computer(ram, cpu, uuid)
    {
    }

    void printSpecification() override
    {
        std::cout << _uuid << " :Ten laptop ma: " << _ram << " giga ram, procesor " << _cpu << "\n";
    }
};

class Server : public Computer
{
public:
    Server(int ram, std::string cpu, int uuid)
        : Computer(ram, cpu, uuid)
    {
    }

    void printSpecification() override
    {
        std::cout << _uuid << " :Ten server ma: " << _ram << " giga ram, procesor " << _cpu << "\n";
    }
};

struct ComputerFactory //UWAGA: To nie jest prawdziwa fabryka tylko wzorzec metody fabrykujacej, creator
{
    enum class ComputerType
    {
        LAPTOP,
        SERVER
    };

    static std::shared_ptr<Computer> getComputer(ComputerType type, int ram, std::string cpu) //faktycznie metoda fabrykujaca
    {
        //Ta metoda zarz¹dza tworzeniem obiektów, czyli sprawdza któr¹ klasê utworzyæ czy laptop czy server. To ona ma logikê wybieraj¹ca
        if (type == ComputerType::LAPTOP)
        {
            //TODO: dodatkowe warunki sprawdzaj¹ce 
            return std::make_shared<Laptop>(ram, cpu, 0);
        }
        else if (type == ComputerType::SERVER)
        {
            return std::make_shared<Server>(ram, cpu, 0);
        }

        return nullptr;
    }
};

struct ComputerFactory2 //metoda fabrykujaca ktora podejmuje decyzje za nas ktora klase utworzyc
{
    static std::shared_ptr<Computer> getComputer(int ram, std::string cpu) 
    {
        if (ram > 64) //jesli potrzbea wiecej niz 64 giga ram to tworzymy server
        {
            return std::make_shared<Server>(ram, cpu, 0);
        }
        else 
        {
            return std::make_shared<Laptop>(ram, cpu, 0);
        }

        return nullptr;
    }
};

struct AbstractComputerFactory //Fabryka Abstrakcyjna
{
    AbstractComputerFactory()
    {
    }

    virtual std::shared_ptr<Computer> createComputer() = 0;

    static int currentUUID;
};

int AbstractComputerFactory::currentUUID = 0;

class IntelServerFactory : public AbstractComputerFactory
{
public:
    IntelServerFactory(int ram) //uzytkownik moze powiedziec ile maja miec ramu servery z tej fabryki
        : _ram(ram)
    {
    }

    IntelServerFactory() //domyslnie nasza fabryka bedzie tworzyc servery z 128 GB ram
        : _ram(128)
    {
    }

    std::shared_ptr<Computer> createComputer()
    {
        return std::make_shared<Server>(_ram, "Intel", ++currentUUID);
    }
private:
    int _ram;
};

class AMDServerFactory : public AbstractComputerFactory //ta fabryka tworzy tylko servery AMD z 666 GB ramu
{
public:
    std::shared_ptr<Computer> createComputer()
    {
        return std::make_shared<Server>(666, "AMD", ++currentUUID);
    }
};

int main()
{
    std::shared_ptr<Computer> lapek = ComputerFactory::getComputer(ComputerFactory::ComputerType::LAPTOP, 16, "amd");
    std::shared_ptr<Computer> serverek = ComputerFactory::getComputer(ComputerFactory::ComputerType::SERVER, 128, "intel");
    
    serverek->printSpecification();
    lapek->printSpecification();

    //tutaj to klasa z metoda fabrykujaca podejmuje decyzje ktora klase utworzyc a nasz main nie ma nawet pojecia ze moga byc rozne klasy komputerow
    std::shared_ptr<Computer> comp1 = ComputerFactory2::getComputer(16, "intel");
    std::shared_ptr<Computer> comp2 = ComputerFactory2::getComputer(256, "amd");
    comp1->printSpecification();
    comp2->printSpecification();

    std::shared_ptr<Server> server2 = std::dynamic_pointer_cast<Server>(ComputerFactory::getComputer(ComputerFactory::ComputerType::SERVER, 128, "intel")); //zaawansowane+


//******************************************************************
//Czas na Fabryke Abstrakcyjna
    std::cout << "\nFabryka Abstrakcyjna**************************\n\n";
    IntelServerFactory intel500giga(500);
    IntelServerFactory inteldefualt;
    AMDServerFactory amdFactory;

    std::vector<std::shared_ptr<Computer>> servers;

    for (int i = 0; i < 3; ++i)
    {
        servers.push_back(intel500giga.createComputer());
        servers.push_back(inteldefualt.createComputer());
        servers.push_back(amdFactory.createComputer());
    }

    for (const auto& server : servers)
    {
        server->printSpecification();
    }
}
