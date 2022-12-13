#include<iostream>
#include"string.h"

#include"Telefon.h"

#include"NotNullException.h"
#include"GreaterThanZeroException.h"

Telefon::Telefon(int id, const std::string denumire, const std::string marca, const std::string descriere, float pret,
                    float dimensiuneEcran, const std::string tipRetea, int memorieRAM, int memorieStocare, float rezolutieCamera, int capacitateBaterie)
        : Produs(id, denumire, marca, descriere, pret)
{
    this->dimensiuneEcran = dimensiuneEcran;
    this->tipRetea = tipRetea;
    this->memorieRAM = memorieRAM;
    this->memorieStocare = memorieStocare;
    this->rezolutieCamera = rezolutieCamera;
    this->capacitateBaterie = capacitateBaterie;
}

Telefon::Telefon() : Produs()
{
    dimensiuneEcran = 0;
    tipRetea = "";
    memorieRAM = 0;
    memorieStocare = 0;
    rezolutieCamera = 0;
    capacitateBaterie = 0;
}

Telefon::~Telefon() = default;

Telefon& Telefon::operator=(const Telefon &rhs)
{
    Produs::operator=(rhs);

    if (this != &rhs)
        setTipRetea(rhs.tipRetea);

    this->dimensiuneEcran = rhs.dimensiuneEcran;
    this->memorieRAM = rhs.memorieRAM;
    this->memorieStocare = rhs.memorieStocare;
    this->rezolutieCamera = rhs.rezolutieCamera;
    this->capacitateBaterie = rhs.capacitateBaterie;

    return *this;
}

std::ostream& operator<<(std::ostream& os, const Telefon &telefon) {
    os << static_cast<const Produs &>(telefon);
    os << " | Dimensiune ecran: " << telefon.getDimensiuneEcran()
       << " | Retea: " << telefon.getTipRetea()
       << " | RAM: " << telefon.getMemorieRAM() << " GB"
       << " | Stocare: " << telefon.getMemorieStocare() << " GB"
       << " | Camera: " << telefon.getRezolutieCamera() << " Mpx"
       << " | Baterie: " << telefon.getCapacitateBaterie() << " mAh";

    return os;
}

std::istream& operator>>(std::istream& is, Telefon &telefon){
    Produs& produs = telefon;
    is >> produs;
    std::cout << "Dimensiune ecran: ";
    float dimensiuneEcran;
    is >> dimensiuneEcran;
    telefon.setDimensiuneEcran(dimensiuneEcran);
    std::cout << "Tip retea: ";
    std::string buff;
    fflush(stdin);
    std::getline(std::cin, buff);
    telefon.setTipRetea(buff);
    std::cout << "RAM: ";
    int memorieRAM;
    is >> memorieRAM;
    telefon.setMemorieRAM(memorieRAM);
    std::cout << "Stocare: ";
    int memorieStocare;
    is >> memorieStocare;
    telefon.setMemorieStocare(memorieStocare);
    std::cout << "Camera: ";
    float rezolutieCamera;
    is >> rezolutieCamera;
    telefon.setRezolutieCamera(rezolutieCamera);
    std::cout << "Baterie: ";
    int capacitateBaterie;
    is >> capacitateBaterie;
    telefon.setCapacitateBaterie(capacitateBaterie);
}

void Telefon::setDimensiuneEcran(float dimensiuneEcran)
{
    if (dimensiuneEcran <= 0)
        throw GreaterThanZeroException();

    this->dimensiuneEcran = dimensiuneEcran;
}

float Telefon::getDimensiuneEcran() const
{
    return this->dimensiuneEcran;
}

void Telefon::setTipRetea(const std::string tipRetea)
{
    if (tipRetea.length() == 0)
        throw NotNullException();

    this->tipRetea = tipRetea;
}

std::string Telefon::getTipRetea() const
{
    return this->tipRetea;
}

void Telefon::setMemorieRAM(int memorieRAM)
{
    if (memorieRAM <= 0)
        throw GreaterThanZeroException();

    this->memorieRAM = memorieRAM;
}

int Telefon::getMemorieRAM() const
{
    return this->memorieRAM;
}

void Telefon::setMemorieStocare(int memorieStocare)
{
    if (memorieStocare <= 0)
        throw GreaterThanZeroException();

    this->memorieStocare = memorieStocare;
}

int Telefon::getMemorieStocare() const
{
    return this->memorieStocare;
}

void Telefon::setRezolutieCamera(float rezolutieCamera)
{
    if (rezolutieCamera <= 0)
        throw GreaterThanZeroException();

    this->rezolutieCamera = rezolutieCamera;
}

float Telefon::getRezolutieCamera() const
{
    return this->rezolutieCamera;
}

void Telefon::setCapacitateBaterie(int capacitateBaterie)
{
    if (capacitateBaterie <= 0)
        throw GreaterThanZeroException();

    this->capacitateBaterie = capacitateBaterie;
}

int Telefon::getCapacitateBaterie() const
{
    return this->capacitateBaterie;
}

void Telefon::afiseaza() const
{
    std::cout << "[TELEFON]:" << *this;
}
