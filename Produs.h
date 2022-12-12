#ifndef PRODUS_H_INCLUDED
#define PRODUS_H_INCLUDED

#include<iostream>

class Produs {
private:
    int id;
    char* denumire;
    char* marca;
    char* descriere;
    float pret;

public:
    Produs(int id, const char* denumire, const char* marca, const char* descriere, float pret);

    Produs();

    virtual ~Produs();

    Produs& operator=(const Produs &rhs);

    friend std::istream& operator>>(std::istream& is, Produs &produs);

    friend std::ostream& operator<<(std::ostream& os, const Produs &produs);

    void setId(int id);

    int getId() const;

    void setDenumire(const char* denumire);

    char* getDenumire() const;

    void setMarca(const char* marca);

    char* getMarca() const;

    void setDescriere(const char* descriere);

    char* getDescriere() const;

    void setPret(float pret);

    float getPret() const;

    virtual void afiseaza() const = 0;
};

#endif // PRODUS_H_INCLUDED
