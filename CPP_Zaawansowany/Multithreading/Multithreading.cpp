#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx; //pozwala nam ³adnie wypisaæ an cout bez konfiktów

void print(int id, int howMany)
{
    for (int i = 0; i < howMany; ++i)
    {
        std::lock_guard<std::mutex> lock(mtx); //zajmuje mutex mtx a¿ do koñca tego zasiêgu (do koñca 1 przebiegu pêtli)
        //mtx.lock(); //niepotrzebne gdy uzywamy lock_guard
        std::cout << "[id:" << id << "]-says: " << i << std::endl; //sekcja krytyczna
        //mtx.unlock(); //niepotrzebne gdy uzywamy lock_guard
    }
}

int main() //tutaj mamy 3 watki 1-main + 
{
    std::thread thread1(print, 1, 200); //tworzymy i startujemy 1 watek
    std::cout << "thread1 wystartowany" << std::endl;

    std::thread thread2(print, 2, 100); //tworzymy i startujemy 2 watek
    std::cout << "thread2 wystartowany" << std::endl;

    std::thread thread3([]() {std::cout << "Jeszcze ja tez tutaj jetem." << std::endl; }); //watek ktory przyjmuje lambde

    thread1.join(); //czekamy az thread1 sie zakoñczy
    thread2.join();
    thread3.join();
    std::cout << "Watki skonczyly juz prace";
}