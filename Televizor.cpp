#include<iostream>
#include"string.h"

#include"Televizor.h"

#include"NotNullException.h"
#include"GreaterThanZeroException.h"

Televizor::Televizor(int id, const char* denumire, const char* marca, const char* descriere, float pret,
                     float dimensiuneEcran, const char* tipDisplay, const char* rezolutieEcran, const char* clasaConsum)
          : Produs(id, denumire, marca, descriere, pret)
{
    size_t len;

    this->dimensiuneEcran = dimensiuneEcran;

    len = strlen(tipDisplay);
    this->tipDisplay = new char[len + 1];
    strcpy(this->tipDisplay, tipDisplay);

    len = strlen(rezolutieEcran);
    this->rezolutieEcran = new char[len + 1];
    strcpy(this->rezolutieEcran, rezolutieEcran);

    len = strlen(clasaConsum);
    this->clasaConsum = new char[len + 1];
    strcpy(this->clasaConsum, clasaConsum);
}

Televizor::Televizor() : Produs()
{
    dimensiuneEcran = 0;
    tipDisplay = NULL;
    rezolutieEcran = NULL;
    clasaConsum = NULL;
}

Televizor::~Televizor()
{
    delete[] this->tipDisplay;
    delete[] this->rezolutieEcran;
    delete[] this->clasaConsum;
}

Televizor& Televizor::operator=(const Televizor &rhs)
{
    Produs::operator=(rhs);

    if (this != &rhs)
        setTipDisplay(rhs.tipDisplay);

    if (this != &rhs)
        setRezolutieEcran(rhs.rezolutieEcran);

    if (this != &rhs)
        setClasaConsum(rhs.clasaConsum);

    this->dimensiuneEcran = rhs.dimensiuneEcran;

    return *this;
}

std::ostream& operator<<(std::ostream& os, const Televizor &televizor) {
    os << static_cast<const Produs &>(televizor);
    os << " | Diagonala ecran: " << televizor.getDimensiuneEcran()
       << " | Tip display: " << televizor.getTipDisplay()
       << " | Rezolutie ecran: " << televizor.getRezolutieEcran()
       << " | Clasa consum: " << televizor.getClasaConsum() << " GB";

    return os;
}

std::istream& operator>>(std::istream& is, Televizor &televizor){
    Produs& produs = televizor;
    is >> produs;
    std::cout << "Diagonala ecran: ";
    float dimensiuneEcran;
    is >> dimensiuneEcran;
    televizor.setDimensiuneEcran(dimensiuneEcran);
    std::cout << "Tip display: ";
    char* buff = new char[256];
    fflush(stdin);
    is.getline(buff, 256);
    televizor.setTipDisplay(buff);
    std::cout << "Rezolutie ecran: ";
    fflush(stdin);
    is.getline(buff, 256);
    televizor.setRezolutieEcran(buff);
    std::cout << "Clasa consum: ";
    fflush(stdin);
    is.getline(buff, 256);
    televizor.setClasaConsum(buff);
}

void Televizor::setDimensiuneEcran(float dimensiuneEcran)
{
    if (dimensiuneEcran <= 0)
        throw GreaterThanZeroException();

    this->dimensiuneEcran = dimensiuneEcran;
}

float Televizor::getDimensiuneEcran() const
{
    return this->dimensiuneEcran;
}

void Televizor::setTipDisplay(const char* tipDisplay)
{
    if (strlen(tipDisplay) == 0)
        throw NotNullException();

    delete[] this->tipDisplay;

    size_t len = strlen(tipDisplay);
    this->tipDisplay = new char[len + 1];
    strcpy(this->tipDisplay, tipDisplay);
}

char* Televizor::getTipDisplay() const
{
    return this->tipDisplay;
}

void Televizor::setRezolutieEcran(const char* rezolutieEcran)
{
    if (strlen(rezolutieEcran) == 0)
        throw NotNullException();

    delete[] this->rezolutieEcran;

    size_t len = strlen(rezolutieEcran);
    this->rezolutieEcran = new char[len + 1];
    strcpy(this->rezolutieEcran, rezolutieEcran);
}

char* Televizor::getRezolutieEcran() const
{
    return this->rezolutieEcran;
}

void Televizor::setClasaConsum(const char* clasaConsum)
{
    if (strlen(clasaConsum) == 0)
        throw NotNullException();

    delete[] this->clasaConsum;

    size_t len = strlen(clasaConsum);
    this->clasaConsum = new char[len + 1];
    strcpy(this->clasaConsum, clasaConsum);
}

char* Televizor::getClasaConsum() const
{
    return this->clasaConsum;
}

void Televizor::afiseaza() const
{
    std::cout << *this;
}
