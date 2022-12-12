#include <iostream>
#include <cstring>
#include <vector>
#include <memory>

#include"Magazin.h"
#include"Produs.h"
#include"Calculator.h"
#include"Telefon.h"
#include"Televizor.h"

#include"NotNullException.h"
#include"GreaterThanZeroException.h"

std::vector<std::shared_ptr<Produs>> Magazin::listaProduse;

bool Magazin::adaugaProdus(std::string categorie)
{
    if (categorie.compare("Calculatoare") == 0)
    {
        listaProduse.push_back(std::make_shared<Calculator>());
        std::shared_ptr<Calculator> calculator = std::dynamic_pointer_cast<Calculator>(listaProduse.back());

        bool ok = false;

        while (!ok)
            try {
                std::cin >> *calculator;
                ok = true;
            } catch (const NotNullException &e) {
                std::cout << e.what() << '\n';
            } catch (const GreaterThanZeroException &e) {
                std::cout << e.what() << '\n';
            }
    }
    else if (categorie.compare("Telefoane") == 0)
    {
        listaProduse.push_back(std::make_shared<Telefon>());
        std::shared_ptr<Telefon> telefon = std::dynamic_pointer_cast<Telefon>(listaProduse.back());

        bool ok = false;

        while (!ok) {
            try {
                std::cin >> *telefon;
                ok = true;
            } catch (const NotNullException &e) {
                std::cout << e.what() << '\n';
            } catch (const GreaterThanZeroException &e) {
                std::cout << e.what() << '\n';
            }
        }
    }
    else if (categorie.compare("Televizoare") == 0)
    {
        listaProduse.push_back(std::make_shared<Televizor>());
        std::shared_ptr<Televizor> televizor = std::dynamic_pointer_cast<Televizor>(listaProduse.back());

        bool ok = false;

        while (!ok) {
            try {
                std::cin >> *televizor;
                ok = true;
            } catch (const NotNullException &e) {
                std::cout << e.what() << '\n';
            } catch (const GreaterThanZeroException &e) {
                std::cout << e.what() << '\n';
            }
        }
    }
    else
        return false;

    return true;
}

void Magazin::afiseazaProduse()
{
    for (auto &produs : listaProduse) {
            produs->afiseaza();
            std::cout << std::endl;
    }

    std::cout << std::endl;
}

void Magazin::afiseazaCategorie(std::string categorie)
{
    for (auto &produs : listaProduse) {
        if (categorie.compare("Calculatoare") == 0)
        {
            std::shared_ptr<Calculator> calculator = std::dynamic_pointer_cast<Calculator>(produs);

            if (calculator != nullptr)
            {
                produs->afiseaza();
                std::cout << std::endl;
            }
        }
        else if (categorie.compare("Telefoane") == 0)
        {
            std::shared_ptr<Telefon> telefon = std::dynamic_pointer_cast<Telefon>(produs);

            if (telefon != nullptr)
            {
                produs->afiseaza();
                std::cout << std::endl;
            }
        }
        else if (categorie.compare("Televizoare") == 0)
        {
            std::shared_ptr<Televizor> televizor = std::dynamic_pointer_cast<Televizor>(produs);

            if (televizor != nullptr)
            {
                produs->afiseaza();
                std::cout << std::endl;
            }
        }
    }

    std::cout << std::endl;
}
