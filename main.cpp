#include <iostream>
#include <cstring>
#include <vector>

#include"Magazin.h"
#include"Produs.h"
#include"Calculator.h"
#include"Telefon.h"
#include"Televizor.h"

#include"NotNullException.h"
#include"GreaterThanZeroException.h"

int main()
{
    bool isRunning = true;

    while (isRunning)
    {
        std::cout << "Optiuni: 1 - Toate produsele, 2 - Calculatoare, 3 - Telefoane,  4 - Televizoare, 5 - Adauga produse, 6 - exit\n";

        int opt;
        std::cin >> opt;

        switch (opt)
        {
            case 1:
            {
                Magazin::afiseazaProduse();
                break;
            }

            case 2:
            {
                Magazin::afiseazaCategorie("Calculatoare");
                break;
            }

            case 3:
            {
                Magazin::afiseazaCategorie("Telefoane");
                break;
            }

            case 4:
            {
                Magazin::afiseazaCategorie("Televizoare");
                break;
            }

            case 5:
            {
                int n, i = 0;
                std::cout<< "Cate produse doresti sa adaugi: ";
                std::cin >> n;

                while (i < n)
                {
                    std::cout<< "Categorie produs: ";
                    std::string categorie;
                    fflush(stdin);
                    std::getline(std::cin, categorie);

                    if (Magazin::adaugaProdus(categorie))
                        i ++;
                }

                break;
            }

            case 6:
            {
                isRunning = false;
                break;
            }

            default:
            {
                std::cout << "Eroare: Optiune invalida!\n";
                break;
            }
        }
    }

    return 0;
}
