#ifndef TELEVIZOR_H_INCLUDED
#define TELEVIZOR_H_INCLUDED

#include<iostream>
#include"string.h"

#include"Produs.h"

class Televizor : public Produs
{
private:
    float dimensiuneEcran;
    std::string tipDisplay;
    std::string rezolutieEcran;
    std::string clasaConsum;

public:
    Televizor(int id, const std::string denumire, const std::string marca, const std::string descriere, float pret,
              float dimensiuneEcran, const std::string tipDisplay, const std::string rezolutieEcran, const std::string clasaConsum);

    Televizor();

    ~Televizor() override;

    Televizor& operator=(const Televizor &rhs);

    friend std::istream& operator >>(std::istream& is, Televizor &televizor);

    friend std::ostream& operator <<(std::ostream& os, const Televizor &televizor);

    void setDimensiuneEcran(float dimensiuneEcran);

    float getDimensiuneEcran() const;

    void setTipDisplay(const std::string tipDisplay);

    std::string getTipDisplay() const;

    void setRezolutieEcran(const std::string rezolutieEcran);

    std::string getRezolutieEcran() const;

    void setClasaConsum(const std::string clasaConsum);

    std::string getClasaConsum() const;

    void afiseaza() const override;
};

#endif // TELEVIZOR_H_INCLUDED
