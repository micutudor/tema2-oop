#include<iostream>
#include"string.h"

#include"Produs.h"

#include"NotNullException.h"
#include"GreaterThanZeroException.h"

Produs::Produs(int id, const char* denumire, const char* marca, const char* descriere, float pret)
{
    size_t len;

    this->id = id;

    len = strlen(denumire);
    this->denumire = new char[len + 1];
    strcpy(this->denumire, denumire);

    len = strlen(marca);
    this->marca = new char[len + 1];
    strcpy(this->marca, marca);

    len = strlen(descriere);
    this->descriere = new char[len + 1];
    strcpy(this->descriere, descriere);

    this->pret = pret;
}

Produs::Produs()
{
    id = -1;
    denumire = NULL;
    marca = NULL;
    descriere = NULL;
    pret = 0;
}

Produs::~Produs()
{
    delete[] this->denumire;
    delete[] this->marca;
    delete[] this->descriere;
}

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
    char* buff = new char[256];
    fflush(stdin);
    std::cin.getline(buff, 256);
    produs.setDenumire(buff);
    std::cout << "Marca: ";
    fflush(stdin);
    std::cin.getline(buff, 256);
    produs.marca = new char[strlen(buff) + 1];
    strcpy(produs.marca, buff);
    std::cout << "Descriere: ";
    fflush(stdin);
    std::cin.getline(buff, 256);
    produs.descriere = new char[strlen(buff) + 1];
    strcpy(produs.descriere, buff);
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

void Produs::setDenumire(const char* denumire)
{
    if (strlen(denumire) == 0)
        throw NotNullException();

    delete[] this->denumire;

    size_t len = strlen(denumire);
    this->denumire = new char[len + 1];
    strcpy(this->denumire, denumire);
}

char* Produs::getDenumire() const
{
    return this->denumire;
}

void Produs::setMarca(const char* marca)
{
    if (strlen(marca) == 0)
        throw NotNullException();

    delete[] this->marca;

    size_t len = strlen(marca);
    this->marca = new char[len + 1];
    strcpy(this->marca, marca);
}

char* Produs::getMarca() const
{
    return this->marca;
}

void Produs::setDescriere(const char* descriere)
{
    delete[] this->descriere;

    size_t len = strlen(descriere);
    this->descriere = new char[len + 1];
    strcpy(this->descriere, descriere);
}

char* Produs::getDescriere() const
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
