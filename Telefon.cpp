#include<iostream>
#include"string.h"

#include"Telefon.h"

#include"NotNullException.h"
#include"GreaterThanZeroException.h"

Telefon::Telefon(int id, const char* denumire, const char* marca, const char* descriere, float pret,
                    float dimensiuneEcran, const char* tipRetea, int memorieRAM, int memorieStocare, float rezolutieCamera, int capacitateBaterie)
        : Produs(id, denumire, marca, descriere, pret)
{
    size_t len;

    this->dimensiuneEcran = dimensiuneEcran;

    len = strlen(tipRetea);
    this->tipRetea = new char[len + 1];
    strcpy(this->tipRetea, tipRetea);

    this->memorieRAM = memorieRAM;
    this->memorieStocare = memorieStocare;
    this->rezolutieCamera = rezolutieCamera;
    this->capacitateBaterie = capacitateBaterie;
}

Telefon::Telefon() : Produs()
{
    dimensiuneEcran = 0;
    tipRetea = NULL;
    memorieRAM = 0;
    memorieStocare = 0;
    rezolutieCamera = 0;
    capacitateBaterie = 0;
}

Telefon::~Telefon()
{
    delete[] this->tipRetea;
}

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
    char* buff = new char[256];
    fflush(stdin);
    is.getline(buff, 256);
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

void Telefon::setTipRetea(const char* tipRetea)
{
    if (strlen(tipRetea) == 0)
        throw NotNullException();

    delete[] this->tipRetea;

    size_t len = strlen(tipRetea);
    this->tipRetea = new char[len + 1];
    strcpy(this->tipRetea, tipRetea);
}

char* Telefon::getTipRetea() const
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
    std::cout << *this;
}
