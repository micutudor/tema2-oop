#ifndef TELEFON_H_INCLUDED
#define TELEFON_H_INCLUDED

#include<iostream>
#include"string.h"

#include"Produs.h"

class Telefon : public Produs
{
private:
    float dimensiuneEcran;
    std::string tipRetea;
    int memorieRAM;
    int memorieStocare;
    float rezolutieCamera;
    int capacitateBaterie;

public:
    Telefon(int id, const std::string denumire, const std::string marca, const std::string descriere, float pret,
            float dimensiuneEcran, const std::string tipRetea, int memorieRAM, int memorieStocare, float rezolutieCamera, int capacitateBaterie);

    Telefon();

    ~Telefon() override;

    Telefon& operator=(const Telefon &rhs);

    friend std::istream& operator >>(std::istream& is, Telefon &telefon);

    friend std::ostream& operator <<(std::ostream& os, const Telefon &telefon);

    void setDimensiuneEcran(float dimensiuneEcran);

    float getDimensiuneEcran() const;

    void setTipRetea(const std::string tipRetea);

    std::string getTipRetea() const;

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
