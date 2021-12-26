/*************************************************************************************************************************************************************************
   - Author           :<TEAM NAME> team                *
   - Robot name       :<ROBOT NAME>                    *
   - Supervising DR   : Mahmoud Saafan                 *
   - Team mempers     : 1- Hazem Alsayed Alkhamisi     *
                        2- Ahmed Mohamed Fouad         *
                        3- Mariam Awad                 *
                        4- Martena Kamel               *
                        5- Galal Mohamed               *
                        6- Bavly Adel                  *
                        7- Andrew Hany                 *
                        8- Hazem Mamdoh Abolila        *
                        9- Farah Hezma                 *
                        10- Bahy Oda                   *
                        11- Ahd Alaa El-dain           *
                        12- Fatma Osama                *
                        13- Hazem Alaa                 *
   - Main purpose     : Robotic Application            *
                        (rocket league robot)          *
   - Date             : 17/12/2021                     *
 *************************************************************************************************************************************************************************

                                           --------------------------------------------------------------------------------
                                                     <N A M E>   T H E   R O C K E T    L E A G U E    R O B O T
                                           --------------------------------------------------------------------------------


  // Components:
   - 4 Ultrasonic sensors (HC-SR04)
   - 4 IR sensors (TCRT5000)
   - 2 DC motors
   - Motor driver (L298N)
   - Arduino uno
   - Metal ball caster free wheel
   - Robot kit
   - Wires
   - Bread board
   - PCB board (optional)




                                                          ░░░░░░░░░░░░▄▄░░░░░░░░░
                                                          ░░░░░░░░░░░█░░█░░░░░░░░
                                                          ░░░░░░░░░░░█░░█░░░░░░░░
                                                          ░░░░░░░░░░█░░░█░░░░░░░░
                                                          ░░░░░░░░░█░░░░█░░░░░░░░
                                                          ███████▄▄█░░░░░██████▄░
                                                          ▓▓▓▓▓▓█░░░░░░░░░░░░░░█░
                                                          ▓▓▓▓▓▓█░░░░░░░░░░░░░░█░
                                                          ▓▓▓▓▓▓█░░░░░░░░░░░░░░█░
                                                          ▓▓▓▓▓▓█░░░░░░░░░░░░░░█░
                                                          ▓▓▓▓▓▓█░░░░░░░░░░░░░░█░
                                                          ▓▓▓▓▓▓█████░░░░░░░░░█░░
                                                          ██████▀░░░░▀▀██████▀░░░﻿

*/
//------------------------------------------------------------------------- INCLUDES -----------------------------------------------------------------------------------


//------------------------------------------------------------------------- INSTANCES -----------------------------------------------------------------------------------

// define Motor driver input pins:
#define ENA 9
#define IN1 10
#define IN2 11

#define ENB 5
#define IN3 7
#define IN4 6

String value, token, joystick, button;
int speedVal;
int motorSpeed[] = {60, 125, 190, 255};


//------------------------------------------------------------------ STARTING THE SETUP FUNCTION ------------------------------------------------------------------------
void setup()
{
  //************************************* I/O pins configuration **************************************************

  // Set OUTPUTS pins for motor driver:
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Serial.begin(9600);
//  myserial.begin(9600);

}
//------------------------------------------------------------------- ENDING THE SETUP FUNCTION --------------------------------------------------------------------------

//------------------------------------------------------------------- STARTING THE DIRECTION FUNCTION ----------------------------------------------------------------------
void directionValue(String dir)
{
    if (dir ==  "N")
    {
      north_forward();
    }
    else if (dir == "S")
    {
      south_backward();
    }
    else if (dir == "E")
    {
      east_right();
    }
    else if (dir == "W")
    {
      west_left();
    }
    else if (dir == "A")
    {
      northEast();
    }
    else if (dir == "B")
    {
      southEast();
    }
    else if (dir == "C")
    {
      southWest();
    }
    else if (dir == "D")
    {
      northWest();
    }
    else if (dir == "0")
    {
      stopMove();
    }
}
//------------------------------------------------------------------- ENDING THE DIRECTION FUNCTION ---------------------------------------------------------------------------

//------------------------------------------------------------------- STARTING THE SPEED FUNCTION -----------------------------------------------------------------------------
void speedValue(String bu)
{
  int buttonVal = bu.toInt();
  
  if (buttonVal == 0)
  {
    speedVal = speedVal;
  }
  else if (buttonVal == 1)
  {
    speedVal = motorSpeed[0];
  }
  else if (buttonVal == 2)
  {
    speedVal = motorSpeed[1];
  }
  else if (buttonVal == 3)
  {
    speedVal = motorSpeed[2];
  }
  else if (buttonVal == 4)
  {
    speedVal = motorSpeed[3];
  }
  else 
  {
    speedVal = 0;
  }
}

//------------------------------------------------------------------- ENDING THE SPEED FUNCTION ----------------------------------------------------------------------------


//------------------------------------------------------------------- STARTING THE MOVEMENT FUNCTIONS ----------------------------------------------------------------------
void north_forward()
{
  analogWrite(ENA, speedVal);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  analogWrite(ENB, speedVal);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  Serial.print(joystick); Serial.print("\t");
  Serial.print(speedVal);
  Serial.println("");
}

void south_backward()
{
  analogWrite(ENA, speedVal);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  analogWrite(ENB, speedVal);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  Serial.print(joystick); Serial.print("\t");
  Serial.print(speedVal);
  Serial.println("");
}

void east_right()
{
  analogWrite(ENA, speedVal);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  analogWrite(ENB, speedVal);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  Serial.print(joystick); Serial.print("\t");
  Serial.print(speedVal);
  Serial.println("");
}

void west_left()
{
  analogWrite(ENA, speedVal);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  analogWrite(ENB, speedVal);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  Serial.print(joystick); Serial.print("\t");
  Serial.print(speedVal);
  Serial.println("");
}

void northEast()
{
  analogWrite(ENA, (speedVal / 2));
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  analogWrite(ENB, speedVal);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  Serial.print(joystick); Serial.print("\t");
  Serial.print(speedVal);
  Serial.println("");
}

void southEast()
{
  analogWrite(ENA, (speedVal / 2));
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  analogWrite(ENB, speedVal);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  Serial.print(joystick); Serial.print("\t");
  Serial.print(speedVal);
  Serial.println("");
}

void southWest()
{
  analogWrite(ENA, speedVal);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  analogWrite(ENB, (speedVal));
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  Serial.print(joystick); Serial.print("\t");
  Serial.print(speedVal);
  Serial.println("");
}

void northWest()
{
  analogWrite(ENA, speedVal);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  analogWrite(ENB, (speedVal / 2));
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  Serial.print(joystick); Serial.print("\t");
  Serial.print(speedVal);
  Serial.println("");
}

//------------------------------------------------------------------- ENDING THE MOVEMENT FUNCTIONS ------------------------------------------------------------------------------


//------------------------------------------------------------------- STARTING THE STOP FUNCTION ---------------------------------------------------------------------------------
void stopMove()
{
  analogWrite(ENA, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  analogWrite(ENB, 0);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  Serial.print(joystick); Serial.print("\t");
  Serial.print(speedVal);
  Serial.println("");
}
//------------------------------------------------------------------- ENDING THE STOP FUNCTIONS ----------------------------------------------------------------------------------


//------------------------------------------------------------------- STARTING THE LOOP FUNCTION ---------------------------------------------------------------------------------
void loop()
{

  if (Serial.available() > 0)
  {
    value = Serial.readStringUntil('#');
    if (value.length() == 2)
    {
      joystick = value.substring(0, 1);
      button = value.substring(1, 2);
//      Serial.print(joystick);
//      Serial.print("\t");
//      Serial.print(button);
//      Serial.println("");

      
      directionValue(joystick);
      speedValue(button);



    
      Serial.flush();
      value = "";
    }
    


    
  }








}
//------------------------------------------------------------------- ENDING THE LOOP FUNCTION ------------------------------------------------------------------------------
