#include<iostream>
#include"string.h"

#include"Produs.h"

#include"NotNullException.h"
#include"GreaterThanZeroException.h"

#include"string.h"

Produs::Produs(int id, const std::string denumire, const std::string marca, const std::string descriere, float pret)
{
    this->id = id;
    this->denumire = denumire;
    this->marca = marca;
    this->descriere = descriere;
    this->pret = pret;
}

Produs::Produs()
{
    id = -1;
    denumire = "";
    marca = "";
    descriere = "";
    pret = 0;
}

Produs::~Produs() = default;

Produs& Produs::operator=(const Produs &rhs) {
    if (this != &rhs)
        setDenumire(rhs.denumire);

    if (this != &rhs)
        setMarca(rhs.marca);

    if (this != &rhs)
        setDescriere(rhs.descriere);

    this->id = rhs.id;
    this->pret = rhs.pret;

    return *this;
}

std::ostream& operator<<(std::ostream& os, const Produs &produs) {
    os << "Denumire: " << produs.getDenumire()
       << " | Marca: " << produs.getMarca()
       << " | Descriere: " << produs.getDescriere()
       << " | Pret: " << produs.getPret() << " RON";

    return os;
}

std::istream& operator>>(std::istream& is, Produs &produs){
    std::cout << "Id: ";
    std::cin >> produs.id;
    std::cout << "Denumire: ";
    std::string buff;
    fflush(stdin);
    std::getline(std::cin, buff);
    produs.setDenumire(buff);
    std::cout << "Marca: ";
    fflush(stdin);
    std::getline(std::cin, buff);
    produs.setMarca(buff);
    std::cout << "Descriere: ";
    fflush(stdin);
    std::getline(std::cin, buff);
    produs.setDescriere(buff);
    std::cout << "Pret: ";
    float pret;
    std::cin >> pret;
    produs.setPret(pret);
}

void Produs::setId(int id)
{
    this->id = id;
}

int Produs::getId() const
{
    return this->id;
}

void Produs::setDenumire(const std::string denumire)
{
    if (denumire.length() == 0)
        throw NotNullException();

    this->denumire = denumire;
}

std::string Produs::getDenumire() const
{
    return this->denumire;
}

void Produs::setMarca(const std::string marca)
{
    if (marca.length() == 0)
        throw NotNullException();

    this->marca = marca;
}

std::string Produs::getMarca() const
{
    return this->marca;
}

void Produs::setDescriere(const std::string descriere)
{
    if (descriere.length() == 0)
        throw NotNullException();

    this->descriere = descriere;
}

std::string Produs::getDescriere() const
{
    return this->descriere;
}

void Produs::setPret(float pret)
{
    if (pret <= 0)
        throw GreaterThanZeroException();

    this->pret = pret;
}

float Produs::getPret() const
{
    return this->pret;
}
