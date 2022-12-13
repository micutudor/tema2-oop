#ifndef PRODUS_H_INCLUDED
#define PRODUS_H_INCLUDED

#include<iostream>

#include"string.h"

class Produs {
private:
    int id;
    std::string denumire;
    std::string marca;
    std::string descriere;
    float pret;

public:
    Produs(int id, const std::string denumire, const std::string marca, const std::string descriere, float pret);

    Produs();

    virtual ~Produs();

    Produs& operator=(const Produs &rhs);

    friend std::istream& operator>>(std::istream& is, Produs &produs);

    friend std::ostream& operator<<(std::ostream& os, const Produs &produs);

    void setId(int id);

    int getId() const;

    void setDenumire(const std::string denumire);

    std::string getDenumire() const;

    void setMarca(const std::string marca);

    std::string getMarca() const;

    void setDescriere(const std::string descriere);

    std::string getDescriere() const;

    void setPret(float pret);

    float getPret() const;

    virtual void afiseaza() const = 0;
};

#endif // PRODUS_H_INCLUDED
