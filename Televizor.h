#ifndef TELEVIZOR_H_INCLUDED
#define TELEVIZOR_H_INCLUDED

#include<iostream>

#include"Produs.h"

class Televizor : public Produs
{
private:
    float dimensiuneEcran;
    char* tipDisplay;
    char* rezolutieEcran;
    char* clasaConsum;

public:
    Televizor(int id, const char* denumire, const char* marca, const char* descriere, float pret,
              float dimensiuneEcran, const char* tipDisplay, const char* rezolutieEcran, const char* clasaConsum);

    Televizor();

    ~Televizor() override;

    Televizor& operator=(const Televizor &rhs);

    friend std::istream& operator >>(std::istream& is, Televizor &televizor);

    friend std::ostream& operator <<(std::ostream& os, const Televizor &televizor);

    void setDimensiuneEcran(float dimensiuneEcran);

    float getDimensiuneEcran() const;

    void setTipDisplay(const char* tipDisplay);

    char* getTipDisplay() const;

    void setRezolutieEcran(const char* rezolutieEcran);

    char* getRezolutieEcran() const;

    void setClasaConsum(const char* clasaConsum);

    char* getClasaConsum() const;

    void afiseaza() const override;
};

#endif // TELEVIZOR_H_INCLUDED
