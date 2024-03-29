

#ifndef CUADERNILLO_1_TCALENDARIO_H
#define CUADERNILLO_1_TCALENDARIO_H
#include <iostream>
#include <string.h>
using namespace std;

class TCalendario {
private:
    int dia, mes, anyo;

    char *mensaje;

    static bool comprobarFecha (int, int, int);

    static bool bisiesto(int);

    int diasEnMes(int, int);

    void ajustarFecha(TCalendario &c);

    void defaultParameters();

    void copia(const TCalendario &);

    friend class TVectorCalendario;

public:
    TCalendario();

    TCalendario(int dia, int mes, int anyo, char *mens);

    TCalendario(const TCalendario &);

    ~TCalendario();

    TCalendario &operator=(const TCalendario &);

    TCalendario operator+(int);

    TCalendario operator-(int);

    TCalendario operator++(int);

    TCalendario &operator++();

    TCalendario operator--(int);

    TCalendario &operator--();

    bool ModFecha(int, int, int);

    bool ModMensaje(char *);

    bool operator==(const TCalendario &);

    bool operator!=(const TCalendario &);

    bool operator>(const TCalendario &);

    bool operator<(const TCalendario &);

    bool EsVacio();

    int Dia();

    int Mes();

    int Anyo();

    char *Mensaje();

    friend ostream &operator<<(ostream &, const TCalendario &);
};


#endif //CUADERNILLO1_TCALENDARIO_H
