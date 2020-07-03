//Ejemplo de interrupción
//Juan Felipe Gutiérrez Sánchez
//Tipo HARDWARE
//Proyecto de investigación - Info 2

long long int time1=0, time2; 
short modos=0, cont=0;
bool luz[5]={1,1,1,1,0};
void setup()
{
  attachInterrupt(digitalPinToInterrupt(2),codigo,FALLING); //Comando para realizar la interrupcion
  for(short i=3;i<=7;i++){                                  //FALLING porque la interrupción se activa en el flanco de caida
    pinMode(i, OUTPUT);
    digitalWrite(i,0);
  }
  
}

void loop()
{
  time2=millis();		//Tiempo de cada led en la secuencia
  if(time2-time1>=500){ 
    time1=time2;
    switch(modos){
      case 0:			//Secuencia de 5 leds hacia la izquierda
        luz[cont]=0;
        if (cont==0) luz[4]=1;
      		else luz[cont-1]=1;
        cont++;

        if (cont==5) cont=0;
      break;
        
      default:          //Caso donde este oprimido el botón, va a hacer lo contrario al otro caso
        luz[cont]=0;
         if (cont==4) luz[0]=1;
      		else luz[cont+1]=1;
        cont--;
        if (cont==-1) cont=4;
      break;
       
    }
    for(short i=0;i<=4;i++){ 
          digitalWrite(i+3,luz[i]);
       }
  }
}

void codigo(){  //Funcion que permitesaber que modo o secuencia va a activar
  modos=1-modos;
  if(modos) cont=0;
  else cont=0;
}