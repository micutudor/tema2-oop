#ifndef MAGAZIN_H_INCLUDED
#define MAGAZIN_H_INCLUDED

#include<vector>
#include<memory>
#include"string.h"

#include"Produs.h"

class Magazin
{
private:
    static std::vector<std::shared_ptr<Produs>> listaProduse;

public:
    static bool adaugaProdus(std::string categorie);

    static void afiseazaProduse();

    static void afiseazaCategorie(std::string categorie);
};

#endif // MAGAZIN_H_INCLUDED
