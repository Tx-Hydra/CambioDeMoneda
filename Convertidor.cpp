#include <iostream>
#include <limits>
#include <cmath>
#include <windows.h>


//class de la cuenta
class Cuenta{           //Creo la class de la cuenta bancaria
    private:
        float Pesos;
        float Dolares;
        float Euros;
        float Libras;

    public:
        float numCuenta;

        void setpesos(float P);
        float getpesos();
        void setdolar(float D);
        float getdolar();
        void seteuro(float E);
        float geteuro();
        void setlibra(float L);
        float getlibra();
};

//Defino las Funciones del Class  (Set para inicializar, Get para obtener el valor)
void Cuenta::setpesos(float P){
    Pesos = P;
}
float Cuenta::getpesos(){
    return Pesos;
};
void Cuenta::setdolar(float D){
    Dolares = D;
}
float Cuenta::getdolar(){
    return Dolares;
}
void Cuenta::seteuro(float E){
    Euros = E;
}
float Cuenta::geteuro(){
    return Euros;
}
void Cuenta::setlibra(float L){
    Libras = L;
}
float Cuenta::getlibra(){
    return Libras;
}


//Selecciona la moneda a cambiar
int operacion(){
    while (true){
        std::cout<<"\nSeleccione que moneda desea cambiar: \n";
        std::cout<<"Pesos Dolares  Euros  Libras\n";
        int res;
        std::cin>>res;
        if(std::cin.fail()){
                std::cout<<"**Seleccion Erronea**\n";
                std::cin.clear();  //limpia el cin (la variable res)
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n'); //limpia el buffer (descarta caracteres del buffer de entrada)
                continue;
            }
        switch(res){ 
            case 1:
                return 1; //Pesos

            case 2:
                return 2; //Dolares

            case 3:
                return 3; //Euros

            case 4:
                return 4; //Libras

            case 0:
                return 0; //Cerrar

            default:
                std::cout<<"**Transaccion Erronea**\n";
                continue;
        }
    }   
}


//Tiempo de espera para no mostrar todo al mismo tiempo en pantalla
void carga(){  
    for (int i = 0; i <= 2; i++){
        Sleep(1000);
        std::cout<<".";
    }        
        Sleep(1000);
}


//Cambio de Pesos a...
void PesosA(Cuenta &cuenta, int arecibir, float cantidad){
    const int PaD = 40, PaE = 48, PaL = 55;
    switch (arecibir){
        case 1:
            carga();
            break;
        case 2:
            carga();
            cuenta.setdolar(cuenta.getdolar() + cantidad/PaD);
            break;
        
        case 3:
            carga();
            cuenta.seteuro(cuenta.geteuro() + cantidad/PaE);
            break;

        case 4:
            carga();
            cuenta.setlibra(cuenta.getlibra() + cantidad/PaL);
            break;
        }
}



//Cambios de Dolar a...
void DolarA(Cuenta &cuenta, int arecibir, float cantidad){
    const float DaP = 40, DaE = 1.2, DaL = 1.4;
    switch (arecibir){
        case 1:
            carga();
            cuenta.setpesos(cuenta.getpesos() + cantidad*DaP);
            break;

        case 2:
            carga();
            break;
        
        case 3:
            carga();
            cuenta.seteuro(cuenta.geteuro() + cantidad*DaE);
            break;

        case 4:
            carga();
            cuenta.setlibra(cuenta.getlibra() + cantidad*DaL);
            break;
        }
}



//Cambios de Euros a...
void EuroA(Cuenta &cuenta, int arecibir, float cantidad){
    const float EaP = 47.5, EaD = 1.2, EaL = 1.4;
    switch (arecibir){
        case 1:
            carga();
            cuenta.setpesos(cuenta.getpesos() + cantidad*EaP);
            break;
        case 2:
            carga();
            cuenta.setdolar(cuenta.getdolar() + cantidad*EaD);
            break;
        
        case 3:
            carga();
            break;

        case 4:
            carga();
            cuenta.setlibra(cuenta.getlibra() + cantidad*EaL);
            break;
        }
}



//Cambio de Libra a...
void LibraA(Cuenta &cuenta, int arecibir, float cantidad){
    const float LaP = 54.6, LaD = 1.3, LaE = 1.1;
    switch (arecibir){
        case 1:
            carga();
            cuenta.setpesos(cuenta.getpesos() + cantidad*LaP);
            break;

        case 2:
            carga();
            cuenta.setdolar(cuenta.getdolar() + cantidad*LaD);
            break;
        
        case 3:
            carga();
            cuenta.setdolar(cuenta.getdolar() + cantidad*LaE);
            break;

        case 4:
            carga();
            break;
        }
}


//Selecciona la moneda a recibir
int seleccion(){
    while (true){
    int num;
    std::cout<<"Seleccione la moneda a recibir: \n";
    std::cout<<"Pesos  Dolares  Euros  Libras\n";
    std::cin>>num;
    if (std::cin.fail()){
                std::cout<<"**Seleccion Erronea**\n";
                std::cin.clear();  //limpia el cin (la variable res)
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n'); // limpia el buffer (descarta caracteres del buffer de entrada)
                continue;
            }
    switch (num){
            
            case 1:
                return 1; //Pesos

            case 2:
                return 2; //Dolares

            case 3:
                return 3; //Euros

            case 4:
                return 4; //Libras

            case 0:
                return 0; //Cerrar

            default:
                std::cout<<"**Seleccion Erronea**\n";
                continue;
        }
    }
    
}



//Redondeo el valor de las cuentas para no saturar los decimales
void redondeo(Cuenta &cuenta, bool &t){
    cuenta.setpesos(round(cuenta.getpesos() * 100) / 100) ;
    cuenta.setdolar(round(cuenta.getdolar() * 100) / 100) ;
    cuenta.seteuro(round(cuenta.geteuro() * 100) / 100) ;
    cuenta.setlibra(round(cuenta.getlibra() * 100) / 100) ;
    t = false;
}


//Realiza el cambio si es posible
void aCambiar(Cuenta &cuenta, int moneda){
    bool TranTerminada = true;
    while (TranTerminada == true){
        int retorno = seleccion(); //selecciona para recibir
        float cantidad;
        std::cout<<"Indique la cantidad a cambiar: ";
        std::cin>>cantidad;
        if (std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"**Cantidad No Valida**\n";  //Si se inserta algo no valido
            break;
        }


        switch (moneda){

        
        case 1:  //Cambiar pesos
            if (cuenta.getpesos() < cantidad){
                std::cout<<"Saldo Insuficiente\n";
            }
            else{
                PesosA(cuenta, retorno, cantidad);
                cuenta.setpesos(cuenta.getpesos() - cantidad);
                std::cout<<"\n**Transaccion Completada**\n";
            }
            redondeo(cuenta,TranTerminada);

            break;


        case 2:  //Cambiar Dolares
            if (cuenta.getdolar() < cantidad){
                std::cout<<"Saldo Insuficiente\n";
            }
            else{
                DolarA(cuenta, retorno, cantidad);
                cuenta.setdolar(cuenta.getdolar() - cantidad);
                std::cout<<"\n**Transaccion Completada**\n";
            }

            redondeo(cuenta,TranTerminada);
            break;


        case 3:  //Cambiar Euros
            if (cuenta.geteuro() < cantidad){
                std::cout<<"Saldo Insuficiente\n";
            }
            else{
                EuroA(cuenta, retorno, cantidad);
                cuenta.seteuro(cuenta.geteuro() - cantidad);
                std::cout<<"\n**Transaccion Completada**\n";
            }
            redondeo(cuenta,TranTerminada);

            break;


        case 4:  //Cambiar Libras
            if (cuenta.getlibra() < cantidad){
                std::cout<<"Saldo Insuficiente\n";
            }
            else{
                LibraA(cuenta, retorno, cantidad);
                cuenta.setlibra(cuenta.getlibra()- cantidad);
                std::cout<<"\n**Transaccion Completada**\n";
            }
            redondeo(cuenta, TranTerminada);
            break;


        default:
            std::cout<<"**Seleccion Incorrecta**\n";
            continue;
        }
    }
}    



//Inicio del Programa
int main(){
    Cuenta cuenta;
    cuenta.numCuenta = 001;         //Creo la cuenta y le asigno valores
    cuenta.setpesos(10000);
    cuenta.setdolar(500);
    cuenta.seteuro(20);
    cuenta.setlibra(0);

    while (true){
        Sleep(1000);
        std::cout<<"Cuenta: "<< cuenta.numCuenta <<"\n";
        std::cout<<"Monedas: \n";
        std::cout<<"Pesos:   " << cuenta.getpesos() <<"\nDolares: "<< cuenta.getdolar()<<"\nEuros:   "<<cuenta.geteuro()<<"\nLibras:  "<< cuenta.getlibra();

        
        int oper = operacion(); //Selecciona la moneda a cambiar
        if (oper == 0){
            return 0;
        }
        aCambiar(cuenta, oper); //Realiza el cambio si es posible
    }
}


sisis te escucho