#ifndef CALCULATOR_H_INCLUDED
#define CALCULATOR_H_INCLUDED

#include<iostream>

#include"string.h"

#include"Produs.h"

class Calculator : public Produs
{
private:
    float dimensiuneEcran;
    std::string modelProcesor;
    std::string modelPlacaVideo;
    int memorieRAM;
    std::string tipStocare;
    int memorieStocare;

public:
    Calculator(int id, const std::string denumire, const std::string marca, const std::string descriere, float pret,
               float dimensiuneEcran, const std::string modelProcesor, const std::string modelPlacaVideo, int memorieRAM, const std::string tipStocare, int memorieStocare);

    Calculator();

    ~Calculator() override;

    Calculator& operator=(const Calculator &rhs);

    friend std::istream& operator >>(std::istream& is, Calculator &calculator);

    friend std::ostream& operator <<(std::ostream& os, const Calculator &calculator);

    void setDimensiuneEcran(float dimensiuneEcran);

    float getDimensiuneEcran() const;

    void setModelProcesor(const std::string modelProcesor);

    std::string getModelProcesor() const;

    void setModelPlacaVideo(const std::string modelPlacaVideo);

    std::string getModelPlacaVideo() const;

    void setMemorieRAM(int memorieRAM);

    int getMemorieRAM() const;

    void setTipStocare(const std::string tipStocare);

    std::string getTipStocare() const;

    void setMemorieStocare(int memorieStocare);

    int getMemorieStocare() const;

    void afiseaza() const override;
};

#endif // CALCULATOR_H_INCLUDED
