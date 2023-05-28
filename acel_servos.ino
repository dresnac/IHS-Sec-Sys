#include <SparkFun_ADXL345.h>                                                                    
#include <SPI.h>
#include <Wire.h>
#include <Servo.h> //incluyo libreria para el servo

ADXL345 adxl = ADXL345();
Servo servoMotor1; // Declaramos la variable para controlar el servo
Servo servoMotor2;

void setup()
{
  Serial.begin(9600);
  Serial.println("iniciar");
  Serial.println();

  // Iniciamos el servo para que empiece a trabajar con el pin 9
  servoMotor1.attach(9);
  servoMotor2.attach(10);

  adxl.powerOn();
  adxl.setRangeSetting(16);    //definir el rango, valores 2, 4, 8 o 16
}

void loop() {
  
  int x,y,z;
  int modz;
  
  
  //leer los valores e imprimirlos
  
  adxl.readAccel(&x, &y, &z);
  modz = z* -1;
  Serial.println(modz);
  Serial.print(x);
  Serial.print(", ");
  Serial.print(y);
  Serial.print(", ");
  Serial.println(z);
  
  servoMotor2.write(0);
  servoMotor1.write(0);
    if (z>0)
    {
      servoMotor2.write(75);
      servoMotor1.write(90);
    }
    else if (modz>y)
    {
      servoMotor2.write(0);
      servoMotor1.write(0);
    }
    else
    {
      servoMotor2.write(75);
      servoMotor1.write(90);
    }

    delay(500);

    //cuando la inclinacion es en diagonal no funciona muy bien, cuando armemos el 
    //patin veo de pulir los valores y agregar condiciones

}
