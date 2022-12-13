#include<iostream>
#include"string.h"

#include"Calculator.h"

#include"NotNullException.h"
#include"GreaterThanZeroException.h"

Calculator::Calculator(int id, const std::string denumire, const std::string marca, const std::string descriere, float pret,
                       float dimensiuneEcran, const std::string modelProcesor, const std::string modelPlacaVideo, int memorieRAM, const std::string tipStocare,
                       int memorieStocare)
    : Produs(id, denumire, marca, descriere, pret)
{
    this->dimensiuneEcran = dimensiuneEcran;
    this->modelProcesor = modelProcesor;
    this->modelPlacaVideo = modelPlacaVideo;
    this->memorieRAM = memorieRAM;
    this->tipStocare = tipStocare;
    this->memorieStocare = memorieStocare;
}

Calculator::Calculator() : Produs()
{
    dimensiuneEcran = 0;
    modelProcesor = "";
    modelPlacaVideo = "";
    memorieRAM = 0;
    tipStocare = "";
    memorieStocare = 0;
}

Calculator::~Calculator() = default;

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
    std::string buff;
    fflush(stdin);
    std::getline(std::cin, buff);
    calculator.setModelProcesor(buff);
    std::cout << "Model placa video: ";
    fflush(stdin);
    std::getline(std::cin, buff);
    calculator.setModelPlacaVideo(buff);
    std::cout << "RAM: ";
    int memorieRAM;
    is >> memorieRAM;
    calculator.setMemorieRAM(memorieRAM);
    std::cout << "Tip stocare: ";
    fflush(stdin);
    std::getline(std::cin, buff);
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

void Calculator::setModelProcesor(const std::string modelProcesor)
{
    if (modelProcesor.length() == 0)
        throw NotNullException();

    this->modelProcesor = modelProcesor;
}

std::string Calculator::getModelProcesor() const
{
    return this->modelProcesor;
}

void Calculator::setModelPlacaVideo(const std::string modelPlacaVideo)
{
    if (modelPlacaVideo.length() == 0)
        throw NotNullException();

    this->modelPlacaVideo = modelPlacaVideo;
}

std::string Calculator::getModelPlacaVideo() const
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

void Calculator::setTipStocare(const std::string tipStocare)
{
    if (tipStocare.length() == 0)
        throw NotNullException();

    this->tipStocare = tipStocare;
}

std::string Calculator::getTipStocare() const
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
    std::cout << "[CALCULATOR]:" << *this;
}
