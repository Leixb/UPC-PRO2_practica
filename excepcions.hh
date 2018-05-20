/**
 * @file excepcions.hh
 * @brief Especificació de les excepcions
 */
#ifndef EXCEPCIONS_H
#define EXCEPCIONS_H

#include<exception>

class ExpectedError : public std::exception  {};

class ProducteNoExistent : public ExpectedError {
    virtual const char* what() const throw() {
        return "No exteix un producte amb l'identificador especificat";
    }
};

class ProducteJaExistent : public ExpectedError {
    virtual const char* what() const throw() {
        return "No es pot afegir un producte, l'id ja existeix";
    }
};

class UnitatsAlMagatzem : public ExpectedError {
    virtual const char* what() const throw() {
        return "Encara hi ha productes amb l'identificador al magatzem";
    }
};

class UnitatsInsuficients : public ExpectedError {
    virtual const char* what() const throw() {
        return "No es poden eliminar mes unitats";
    }
};

class DimensionsInsuficients : public ExpectedError {
    virtual const char* what() const throw() {
        return "Les dimentsions donades no son sufificents per a contenir els productes";
    }
};
#endif /* ifndef EXCEPCIONS_H */
