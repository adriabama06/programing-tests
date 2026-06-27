#include <iostream>

using namespace std;

class radio
{
    private:
        int frecuencia;
        int volumen;
    public:
        void iniciar(void);
        void iniciar(int f, int v);
        
        void subir_volumen(void);
        void bajar_volumen(void);
        
        void subir_frecuencia(void);
        void bajar_frecuencia(void);

        void mostrar_voluen(void);
        void mostrar_frecuencia(void);

        int obtener_volumen(void);
        int obtener_frecuencia(void);
};

void radio::iniciar()
{
    volumen = 100;
    frecuencia = 50;
    return;
}
void radio::iniciar(int v, int f)
{
    volumen = v;
    frecuencia = f;
    return;
}

void radio::subir_volumen()
{
    volumen++;
    return;
}
void radio::bajar_volumen()
{
    volumen--;
    return;
}

void radio::subir_frecuencia()
{
    frecuencia++;
    return;
}
void radio::bajar_frecuencia()
{
    frecuencia--;
    return;
}

void radio::mostrar_voluen()
{
    cout << "\nVolumen: " << volumen;
    return;
}
void radio::mostrar_frecuencia()
{
    cout << "\nFrecuencia: " << frecuencia;
    return;
}

int radio::obtener_volumen()
{
    return volumen;
}
int radio::obtener_frecuencia()
{
    return frecuencia;
}

int main()
{
    /*
    radio *myradio = new radio;
    O
    */
    radio myradio;

    myradio.iniciar();
    // myradio.iniciar(50, 100);

    myradio.mostrar_voluen();
    myradio.mostrar_frecuencia();

    for(int i = 0; i < 25; i++) {
        myradio.bajar_volumen();
    }
    for (int i = 0; i < 50; i++)
    {
        myradio.subir_frecuencia();
    }
    
    myradio.mostrar_voluen();
    myradio.mostrar_frecuencia();

    //delete myradio; // libera memoria, solo funciona en el modo puntero

    return 0;
}