#ifndef CALCULATOR_H_INCLUDED
#define CALCULATOR_H_INCLUDED

#include<iostream>

#include"Produs.h"

class Calculator : public Produs
{
private:
    float dimensiuneEcran;
    char* modelProcesor;
    char* modelPlacaVideo;
    int memorieRAM;
    char* tipStocare;
    int memorieStocare;

public:
    Calculator(int id, const char* denumire, const char* marca, const char* descriere, float pret,
               float dimensiuneEcran, const char* modelProcesor, const char* modelPlacaVideo, int memorieRAM, const char* tipStocare, int memorieStocare);

    Calculator();

    ~Calculator() override;

    Calculator& operator=(const Calculator &rhs);

    friend std::istream& operator >>(std::istream& is, Calculator &calculator);

    friend std::ostream& operator <<(std::ostream& os, const Calculator &calculator);

    void setDimensiuneEcran(float dimensiuneEcran);

    float getDimensiuneEcran() const;

    void setModelProcesor(const char* modelProcesor);

    char* getModelProcesor() const;

    void setModelPlacaVideo(const char* modelPlacaVideo);

    char* getModelPlacaVideo() const;

    void setMemorieRAM(int memorieRAM);

    int getMemorieRAM() const;

    void setTipStocare(const char* tipStocare);

    char* getTipStocare() const;

    void setMemorieStocare(int memorieStocare);

    int getMemorieStocare() const;

    void afiseaza() const override;
};

#endif // CALCULATOR_H_INCLUDED
