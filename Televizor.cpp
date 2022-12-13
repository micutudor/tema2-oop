#include<iostream>
#include"string.h"

#include"Televizor.h"

#include"NotNullException.h"
#include"GreaterThanZeroException.h"

Televizor::Televizor(int id, const std::string denumire, const std::string marca, const std::string descriere, float pret,
                     float dimensiuneEcran, const std::string tipDisplay, const std::string rezolutieEcran, const std::string clasaConsum)
          : Produs(id, denumire, marca, descriere, pret)
{
    size_t len;

    this->dimensiuneEcran = dimensiuneEcran;
    this->tipDisplay = tipDisplay;
    this->rezolutieEcran = rezolutieEcran;
    this->clasaConsum = clasaConsum;
}

Televizor::Televizor() : Produs()
{
    dimensiuneEcran = 0;
    tipDisplay = "";
    rezolutieEcran = "";
    clasaConsum = "";
}

Televizor::~Televizor() = default;

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
    std::string buff;
    fflush(stdin);
    std::getline(std::cin, buff);
    televizor.setTipDisplay(buff);
    std::cout << "Rezolutie ecran: ";
    fflush(stdin);
    std::getline(std::cin, buff);
    televizor.setRezolutieEcran(buff);
    std::cout << "Clasa consum: ";
    fflush(stdin);
    std::getline(std::cin, buff);
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

void Televizor::setTipDisplay(const std::string tipDisplay)
{
    if (tipDisplay.length() == 0)
        throw NotNullException();

    this->tipDisplay = tipDisplay;
}

std::string Televizor::getTipDisplay() const
{
    return this->tipDisplay;
}

void Televizor::setRezolutieEcran(const std::string rezolutieEcran)
{
    if (rezolutieEcran.length() == 0)
        throw NotNullException();

    this->rezolutieEcran = rezolutieEcran;
}

std::string Televizor::getRezolutieEcran() const
{
    return this->rezolutieEcran;
}

void Televizor::setClasaConsum(const std::string clasaConsum)
{
    if (clasaConsum.length() == 0)
        throw NotNullException();

    this->clasaConsum = clasaConsum;
}

std::string Televizor::getClasaConsum() const
{
    return this->clasaConsum;
}

void Televizor::afiseaza() const
{
    std::cout << "[TELEVIZOR]:" << *this;
}
