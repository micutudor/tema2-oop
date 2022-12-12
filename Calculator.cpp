#include<iostream>
#include"string.h"

#include"Calculator.h"

#include"NotNullException.h"
#include"GreaterThanZeroException.h"

Calculator::Calculator(int id, const char* denumire, const char* marca, const char* descriere, float pret,
                       float dimensiuneEcran, const char* modelProcesor, const char* modelPlacaVideo, int memorieRAM, const char* tipStocare,
                       int memorieStocare)
    : Produs(id, denumire, marca, descriere, pret)
{
    size_t len;

    this->dimensiuneEcran = dimensiuneEcran;

    len = strlen(modelProcesor);
    this->modelProcesor = new char[len + 1];
    strcpy(this->modelProcesor, modelProcesor);

    len = strlen(modelPlacaVideo);
    this->modelPlacaVideo = new char[len + 1];
    strcpy(this->modelPlacaVideo, modelPlacaVideo);

    this->memorieRAM = memorieRAM;

    len = strlen(tipStocare);
    this->tipStocare = new char[len + 1];
    strcpy(this->tipStocare, tipStocare);

    this->memorieStocare = memorieStocare;
}

Calculator::Calculator() : Produs()
{
    dimensiuneEcran = 0;
    modelProcesor = NULL;
    modelPlacaVideo = NULL;
    memorieRAM = 0;
    tipStocare = NULL;
    memorieStocare = 0;
}

Calculator::~Calculator()
{
    delete[] this->modelProcesor;
    delete[] this->modelPlacaVideo;
    delete[] this->tipStocare;
}

Calculator& Calculator::operator=(const Calculator &rhs)
{
    Produs::operator=(rhs);

    if (this != &rhs)
        setModelProcesor(rhs.modelProcesor);

    if (this != &rhs)
        setModelPlacaVideo(rhs.modelPlacaVideo);

    if (this != &rhs)
        setTipStocare(rhs.tipStocare);

    this->dimensiuneEcran = rhs.dimensiuneEcran;
    this->memorieRAM = rhs.memorieRAM;
    this->memorieStocare = rhs.memorieStocare;

    return *this;
}

std::ostream& operator<<(std::ostream& os, const Calculator &calculator) {
    os << static_cast<const Produs &>(calculator);
    os << " | Dimensiune ecran: " << calculator.getDimensiuneEcran()
       << " | Model procesor: " << calculator.getModelProcesor()
       << " | Model placa video: " << calculator.getModelPlacaVideo()
       << " | Memorie RAM: " << calculator.getMemorieRAM() << " GB"
       << " | Tip stocare: " << calculator.getTipStocare()
       << " | Memorie stocare: " << calculator.getMemorieStocare() << " GB";

    return os;
}

std::istream& operator>>(std::istream& is, Calculator &calculator){
    Produs& produs = calculator;
    is >> produs;
    std::cout << "Dimensiune ecran: ";
    float dimensiuneEcran;
    is >> dimensiuneEcran;
    calculator.setDimensiuneEcran(dimensiuneEcran);
    std::cout << "Model procesor: ";
    char* buff = new char[256];
    fflush(stdin);
    is.getline(buff, 256);
    calculator.setModelProcesor(buff);
    std::cout << "Model placa video: ";
    fflush(stdin);
    is.getline(buff, 256);
    calculator.setModelPlacaVideo(buff);
    std::cout << "RAM: ";
    int memorieRAM;
    is >> memorieRAM;
    calculator.setMemorieRAM(memorieRAM);
    std::cout << "Tip stocare: ";
    fflush(stdin);
    is.getline(buff, 256);
    calculator.setTipStocare(buff);
    std::cout << "Stocare: ";
    int memorieStocare;
    is >> memorieStocare;
    calculator.setMemorieStocare(memorieStocare);
}

void Calculator::setDimensiuneEcran(float dimensiuneEcran)
{
    if (dimensiuneEcran <= 0)
        throw GreaterThanZeroException();

    this->dimensiuneEcran = dimensiuneEcran;
}

float Calculator::getDimensiuneEcran() const
{
    return this->dimensiuneEcran;
}

void Calculator::setModelProcesor(const char* modelProcesor)
{
    if (strlen(modelProcesor) == 0)
        throw NotNullException();

    delete[] this->modelProcesor;

    size_t len = strlen(modelProcesor);
    this->modelProcesor = new char[len + 1];
    strcpy(this->modelProcesor, modelProcesor);
}

char* Calculator::getModelProcesor() const
{
    return this->modelProcesor;
}

void Calculator::setModelPlacaVideo(const char* modelPlacaVideo)
{
    if (strlen(modelPlacaVideo) == 0)
        throw NotNullException();

    delete[] this->modelPlacaVideo;

    size_t len = strlen(modelPlacaVideo);
    this->modelPlacaVideo = new char[len + 1];
    strcpy(this->modelPlacaVideo, modelPlacaVideo);
}

char* Calculator::getModelPlacaVideo() const
{
    return this->modelPlacaVideo;
}

void Calculator::setMemorieRAM(int memorieRAM)
{
    if (memorieRAM <= 0)
        throw GreaterThanZeroException();

    this->memorieRAM = memorieRAM;
}

int Calculator::getMemorieRAM() const
{
    return this->memorieRAM;
}

void Calculator::setTipStocare(const char* tipStocare)
{
    if (strlen(tipStocare) == 0)
        throw NotNullException();

    delete[] this->tipStocare;

    size_t len = strlen(tipStocare);
    this->tipStocare = new char[len + 1];
    strcpy(this->tipStocare, tipStocare);
}

char* Calculator::getTipStocare() const
{
    return this->tipStocare;
}

void Calculator::setMemorieStocare(int memorieStocare)
{
    if (memorieStocare <= 0)
        throw GreaterThanZeroException();

    this->memorieStocare = memorieStocare;
}

int Calculator::getMemorieStocare() const
{
    return this->memorieStocare;
}

void Calculator::afiseaza() const
{
    std::cout << *this;
}
