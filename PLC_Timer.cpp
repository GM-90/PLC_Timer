#include "Arduino.h"
#include "PLC_Timer.h"

/***************** Constructor ******************/
Timer_ON::Timer_ON(){
    EN=false;
    OUT=false;
}
/*************** Encender el Timer ***************/
// la opcion de Restart reinicia los valores
// EN | restart | 
//────┼─────────┼────────
// 0  |    0    |  Recargar Valores
// 0  |    1    |  Recargar Valores
// 1  |    0    |       NO
// 1  |    1    |  Recargar Valores
void Timer_ON::on ( unsigned long pv, bool restart ){
    if ( !EN or restart ){
        EN=true;
        t_inicial=millis();
        PV=pv;
    }      
}

    /**************** Apagar Timer ******************/
void Timer_ON::off(){
    EN=false;
    //return ;      
}

/***************** Rutina del Timer. Ejecutar ciclicamente *******************/
void Timer_ON::TON (){
    if( EN==true ){
        t_actual = millis();
        if( t_actual >= t_inicial ){
            ET=t_actual-t_inicial;
        }
        else{
            ET=0xFFFFFFFF-(t_inicial-t_actual);
        }
        if ( ET >= PV )
            OUT=true;
        else
          OUT=false;
    }
    else{
        OUT=false;
        t_inicial=0;
        ET=0;
    }
    //return ;
}


#define no_autostop false

bool Timer_ON::timeout( bool autostop ){
    if( OUT && autostop ){
        off();
    }
    return OUT;
}
 
