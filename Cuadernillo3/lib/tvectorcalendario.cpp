#include "../include/tvectorcalendario.h"
using namespace std;


void TVectorCalendario::defaultParameters() {
    this-> c = NULL;
    this-> tamano = 0;
}


void TVectorCalendario::copia(const TVectorCalendario &vc){
    this->tamano=vc.tamano;
    if(tamano ==0)
    {
        c = NULL;
    }
    else{
        c= new TCalendario[tamano];
        for (int i = 1;i <= tamano;i++){
            c[i]=vc.c[i];
        }
    }
}


TVectorCalendario::TVectorCalendario() {
    defaultParameters();
}

TVectorCalendario::TVectorCalendario(int tam) {
    if(tam<0){
        defaultParameters();
    }
    else{
        this-> tamano = tam;
        this -> c = new TCalendario[this->tamano];
    }
}

TVectorCalendario::TVectorCalendario(TVectorCalendario & vc) {
    copia(vc);
}

TVectorCalendario::~TVectorCalendario(){
    tamano = 0;
    if (c != NULL){
        delete [] c;
        c = NULL;
    }
}

TVectorCalendario &TVectorCalendario::operator=(const TVectorCalendario &vc) {
    if(this == &vc){
        return *this;
    }
    else{
        (*this).~TVectorCalendario();
        this->tamano = vc.tamano;
        this -> c = new TCalendario[this->tamano];

        for (int i = 1; i <= this-> tamano; i++){
            this->c[i-1]=vc[i];
        }
        return (*this);
    }
}

bool TVectorCalendario::operator==(const TVectorCalendario & vc) const{
    if(this->tamano != vc.tamano){
        return false;
    }

    if(this->c==NULL && vc.c==NULL){
        return true;
    }

    if(this->c==NULL || vc.c==NULL){
        return false;
    }

    for(int i=0; i < this-> tamano; i++){
        if(this-> c[i] != vc.c[i]){
            return false;
        }
    }

    return true;
}


bool TVectorCalendario::operator!=(const TVectorCalendario & vc) const {
    return !(*this == vc);
}

TCalendario &TVectorCalendario::operator[] (int num){
    if(num > 0 && num <= tamano){
        return c[num-1]; //Ya que las posiciones de num empiezan en 1
    }
    return error;
}

TCalendario TVectorCalendario::operator[] (int num) const{
    if(num > 0 && num <= tamano){
        return c[num-1]; //Ya que las posiciones de num empiezan en 1
    }
    return error;
}


int TVectorCalendario::Tamano(){
    return tamano;
}

int TVectorCalendario::Ocupadas() {

    int ocupadas = 0;
    for(int i=0 ;i < tamano; i++){
        if(c[i] != error){
            ocupadas ++;
        }
    }
    return ocupadas;
}

bool TVectorCalendario::ExisteCal(TCalendario &c) {
    for(int i=0; i < this->tamano; i++){
        if(c == this->c[i]){
            return true;
        }
    }
    return false;
}

void TVectorCalendario::MostrarMensajes(int dia, int mes, int anyo) {
    cout << "[";
    if(TCalendario::comprobarFecha(dia, mes, anyo)){
        for (int i = 0; i < tamano; i++){

            if  (anyo > c[i].Anyo()){
                continue;
            }

            if  (anyo == c[i].Anyo() && mes > c[i].Mes()){
                continue;
            }

            if (anyo == c[i].Anyo() && mes == c[i].Mes() && dia > c[i].Dia()){
                continue;
            }

            cout << c[i];

            if ( i < tamano - 1){
                cout << ", ";
            }
        }
    }
    cout << "]";
}

bool TVectorCalendario::Redimensionar(int tam) {
    if (tam <= 0 || tam == tamano) {
        return false;
    }

    TCalendario *aux = new TCalendario[tam];

    int limite = tam;
    if (tam > tamano) {
        limite = tamano;
    }

    for (int i = 0; i < limite; i++) {
        aux[i] = c[i];
    }

    for (int i = limite; i < tam; i++) {
        aux[i] = TCalendario(); // Inicializar los elementos restantes si tam > tamano
    }

    delete[] c;
    c = aux;
    tamano = tam;

    return true;
}


ostream & operator<<(ostream &s, const TVectorCalendario &vc){
    s << "[";
    for(int i = 0; i < vc.tamano;  i++){
        s << "(" << i + 1 << ") " << vc[i+1];

        if (i < vc.tamano - 1){
            s << ", ";
        }
    }

    s <<"]";
    return s;
}
