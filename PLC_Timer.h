#ifndef PLC_Timer_h
#define PLC_Timer_h

#include "Arduino.h"

#define RESTART_TIMER true

class Timer_ON {
  private:
    bool EN;
    uint32_t t_inicial;
    uint32_t PV;
    uint32_t ET; //elapsed time
    uint32_t t_actual;
    bool OUT;
  public:
    /***************** Constructor ******************/
    Timer_ON( void );
    /*************** Encender el Timer ***************/
    void on ( unsigned long pv, bool restart=false  );
    /**************** Apagar Timer ******************/
    void off( void );
    /***************** Rutina del Timer. Ejecutar ciclicamente *******************/
    void TON ( void );

    //Consultar esta funcion para verificar timeout
    bool timeout( bool autostop=true );
 
};



#endif