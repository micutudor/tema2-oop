#ifndef TELEFON_H_INCLUDED
#define TELEFON_H_INCLUDED

#include<iostream>

#include"Produs.h"

class Telefon : public Produs
{
private:
    float dimensiuneEcran;
    char* tipRetea;
    int memorieRAM;
    int memorieStocare;
    float rezolutieCamera;
    int capacitateBaterie;

public:
    Telefon(int id, const char* denumire, const char* marca, const char* descriere, float pret,
            float dimensiuneEcran, const char* tipRetea, int memorieRAM, int memorieStocare, float rezolutieCamera, int capacitateBaterie);

    Telefon();

    ~Telefon() override;

    Telefon& operator=(const Telefon &rhs);

    friend std::istream& operator >>(std::istream& is, Telefon &telefon);

    friend std::ostream& operator <<(std::ostream& os, const Telefon &telefon);

    void setDimensiuneEcran(float dimensiuneEcran);

    float getDimensiuneEcran() const;

    void setTipRetea(const char* tipRetea);

    char* getTipRetea() const;

    void setMemorieRAM(int memorieRAM);

    int getMemorieRAM() const;

    void setMemorieStocare(int memorieStocare);

    int getMemorieStocare() const;

    void setRezolutieCamera(float rezolutieCamera);

    float getRezolutieCamera() const;

    void setCapacitateBaterie(int capacitateBaterie);

    int getCapacitateBaterie() const;

    void afiseaza() const override;
};

#endif // TELEFON_H_INCLUDED
