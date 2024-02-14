
#ifndef PED_TVECTORCALENDARIO_H
#define PED_TVECTORCALENDARIO_H
#include "tcalendario.h"

class TVectorCalendario{
    friend ostream & operator<<(ostream &, const TVectorCalendario &);  //falta
    private:
        TCalendario *c;
        int tamano;
        TCalendario error;

        void defaultParameters();
        void copia(const TVectorCalendario &);

    public:
        TVectorCalendario();

        TVectorCalendario(int);

        TVectorCalendario(TVectorCalendario &);

        ~TVectorCalendario();

        TVectorCalendario & operator=(const TVectorCalendario &);

        bool operator==(TVectorCalendario &);

        bool operator!=(TVectorCalendario &);

        TCalendario & operator[] (int);

        TCalendario operator[] (int) const;

        int Tamano();

        int Ocupadas();

        bool ExisteCal (TCalendario &);

        void MostrarMensajes (int, int, int);   //falta

        bool Redimensionar (int);   //falta

};


#endif //PED_TVECTORCALENDARIO_H
