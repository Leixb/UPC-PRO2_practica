/**
 * @file excepcions.hh
 * @brief Especificació de les excepcions
 */
#ifndef EXCEPCIONS_H
#define EXCEPCIONS_H

#include<exception>

class ExpectedError : public std::exception {};

class ProducteNoExistent : public ExpectedError {
    virtual const char* what() const throw() {
        return "No existeix un producte amb l'identificador especificat.";
    }
};

class ProducteJaExistent : public ExpectedError {
    virtual const char* what() const throw() {
        return "Ja existeix un producte amb l'identificador especificat.";
    }
};

class UnitatsAlMagatzem : public ExpectedError {
    virtual const char* what() const throw() {
        return "Encara hi ha unitats del producte al magatzem.";
    }
};

class UnitatsInsuficients : public ExpectedError {
    virtual const char* what() const throw() {
        return "No es poden eliminar mes unitats.";
    }
};

class DimensionsInsuficients : public ExpectedError {
    virtual const char* what() const throw() {
        return "Les dimensions donades no son suficients per a contenir els productes.";
    }
};
#endif /* ifndef EXCEPCIONS_H */
