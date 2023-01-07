  int column[16]={13,12,11,10,9,8,7,6,5,4,3,2,1,0,A5,A4};
  int level[4]={A3,A2,A1,A0};
 
void setup()
{
  for(int i = 0; i<16; i++) pinMode(column[i], OUTPUT);
  for(int i = 0; i<4; i++) pinMode(level[i], OUTPUT);
  
  randomSeed(analogRead(A6));
}

void loop()
{
  turnEverythingOff();
  flickerOn();
  turnEverythingOn();
  turnLevelsOnOff();
  levelStompUpAndDown();
  snake();
  aroundEdgeDown();
  diagonal();
  turnEverythingOff();
  randomflicker();
  rain();
  diagonalRectangle();
  cross();
  allLedsOneAfterAnother();
  propeller();
  cube();
  spiral();
  flickerOff();
  turnEverythingOff();
  delay(2000);
}

//to turn all leds off
void turnEverythingOff()
 {
   for(int i = 0; i<16; i++)
   {
     digitalWrite(column[i], 1);
   }
   for(int i = 0; i<4; i++)
   {
     digitalWrite(level[i], 0);
   }
 }
 
//to turn all leds on
void turnEverythingOn()
{
  for(int i = 0; i<16; i++)
  {
    digitalWrite(column[i], 0);
  }
  for(int i = 0; i<4; i++)
  {
    digitalWrite(level[i], 1);
  }
}
//to turn columns off
void turnColumnsOff()
{
  for(int i = 0; i<16; i++)
  {
    digitalWrite(column[i], 1);
  }
}

//turns on and off
void flickerOn()
{
  int i = 150;
  while(i != 0)
  {
    turnEverythingOn();
    delay(i);
    turnEverythingOff();
    delay(i);
    i-= 5;
  }
}
//turn everything on and off by level up and down
void turnLevelsOnOff()
{
  int x = 75;
  for(int i = 5; i != 0; i--)
  {
    turnEverythingOn();
    for(int i = 4; i!=0; i--)
    {
      digitalWrite(level[i-1], 0);
      delay(x);
    }
    for(int i = 0; i<4; i++)
    {
      digitalWrite(level[i], 1);
      delay(x);
    }
      for(int i = 0; i<4; i++)
    {
      digitalWrite(level[i], 0);
      delay(x);
    }
    for(int i = 4; i!=0; i--)
    {
      digitalWrite(level[i-1], 1);
      delay(x);
    }
  }
}

//A snake movement lighting up the leds of a row one by one from left to right or right to left alternately until all rows are turned on.
//Then leds turn off in the opposite way.
void snake()
{
  int x = 75;
  turnEverythingOff();

  for(int i = 0; i<4; i++) digitalWrite(level[i], 1);
  
  for(int y = 0; y<2; y++)
  {
    for(int i = 0; i<4; i++)
    {
      digitalWrite(column[i], 0);
      delay(x);
    }
    
    for(int i = 7; i>3; i--)
    {
      digitalWrite(column[i], 0);
      delay(x);
    }

    for(int i = 8; i<12; i++)
    {
      digitalWrite(column[i], 0);
      delay(x);
    }
    
    for(int i = 15; i>11; i--)
    {
      digitalWrite(column[i], 0);
      delay(x);
    }
    //turn off
    for(int i = 0; i<4; i++)
    {
      digitalWrite(column[i], 1);
      delay(x);
    }
    
    for(int i = 7; i>3; i--)
    {
      digitalWrite(column[i], 1);
      delay(x);
    }

    for(int i = 8; i<12; i++)
    {
      digitalWrite(column[i], 1);
      delay(x);
    }
    
    for(int i = 15; i>11; i--)
    {
      digitalWrite(column[i], 1);
      delay(x);
    }
    //turn on
    for(int i = 12; i<16; i++)
    {
      digitalWrite(column[i], 0);
      delay(x);
    }

    for(int i = 11; i>7; i--)
    {
      digitalWrite(column[i], 0);
      delay(x);
    }

    for(int i = 4; i<8; i++)
    {
      digitalWrite(column[i], 0);
      delay(x);
    }

    for(int i = 3; i>=0; i--)
    {
      digitalWrite(column[i], 0);
      delay(x);
    }
 
    //turn off
    for(int i = 12; i<16; i++)
    {
      digitalWrite(column[i], 1);
      delay(x);
    }

    for(int i = 11; i>7; i--)
    {
      digitalWrite(column[i], 1);
      delay(x);
    }

    for(int i = 4; i<8; i++)
    {
      digitalWrite(column[i], 1);
      delay(x);
    }

    for(int i = 3; i>=0; i--)
    {
      digitalWrite(column[i], 1);
      delay(x);
    }
  }
}

//up and down single level stomp
void levelStompUpAndDown()
{
  int x = 75;
  for(int i = 0; i<4; i++)
  {
    digitalWrite(level[i], 0);
  }
  for(int y = 0; y<5; y++)
  {
    for(int count = 0; count<1; count++)
    { 
      for(int i = 0; i<4; i++)
      {
        digitalWrite(level[i], 1);
        delay(x);
        digitalWrite(level[i], 0);
      }
      for(int i = 4; i !=0; i--)
      {
        digitalWrite(level[i-1], 1);
        delay(x);
        digitalWrite(level[i-1], 0);
      }
    }
    for(int i = 0; i<4; i++)
    {
      digitalWrite(level[i], 1);
      delay(x);
    }
    for(int i = 4; i!=0; i--)
    {
      digitalWrite(level[i-1], 0);
      delay(x);
    }
  }
}
//flicker off
void flickerOff()
{
  turnEverythingOn();
  for(int i = 0; i!= 150; i+=5)
  {
    turnEverythingOff();
    delay(i+50);
    turnEverythingOn();
    delay(i);
  }
}
///around edge of the cube down
void aroundEdgeDown()
{
  for(int x = 200; x != 0; x -=50)
  {
    turnEverythingOff();
    for(int i = 4; i != 0; i--)
    {
      digitalWrite(level[i-1], 1);
      digitalWrite(column[5], 0);
      digitalWrite(column[6], 0);
      digitalWrite(column[9], 0);
      digitalWrite(column[10], 0);
      
      digitalWrite(column[0], 0);
      delay(x);
      digitalWrite(column[0], 1);
      digitalWrite(column[4], 0);
      delay(x);
      digitalWrite(column[4], 1);
      digitalWrite(column[8], 0);
      delay(x);
      digitalWrite(column[8], 1);
      digitalWrite(column[12], 0);
      delay(x);
      digitalWrite(column[12], 1);
      digitalWrite(column[13], 0);
      delay(x);
      digitalWrite(column[13], 1);
      digitalWrite(column[14], 0);
      delay(x);
      digitalWrite(column[14], 1);
      digitalWrite(column[15], 0);
      delay(x);
      digitalWrite(column[15], 1);
      digitalWrite(column[11], 0);
      delay(x);
      digitalWrite(column[11], 1);
      digitalWrite(column[7], 0);
      delay(x);
      digitalWrite(column[7], 1);
      digitalWrite(column[3], 0);
      delay(x);
      digitalWrite(column[3], 1);
      digitalWrite(column[2], 0);
      delay(x);
      digitalWrite(column[2], 1);
      digitalWrite(column[1], 0);
      delay(x);
      digitalWrite(column[1], 1);
    }
  }
}
//leds flicker randomly
void randomflicker()
{
  turnEverythingOff();
  int x = 10;
  for(int i = 0; i !=750; i+=2)
  {
  int randomLayer = random(0,4);
  int randomColumn = random(0,16);
  
  digitalWrite(level[randomLayer], 1);
  digitalWrite(column[randomColumn], 0);
  delay(x);
  digitalWrite(level[randomLayer], 0);
  digitalWrite(column[randomColumn], 1);
  delay(x); 
  }
}

//leds turn on serially from top to bottom of a random column creating a rain-like effect
void rain()
{
  turnEverythingOff();
  int x = 100;
  for(int i = 0; i!=60; i+=2)
  {
    int randomColumn = random(0,16);
    digitalWrite(column[randomColumn], 0);
    digitalWrite(level[0], 1);
    delay(x+50);
    digitalWrite(level[0], 0);
    digitalWrite(level[1], 1);
    delay(x);
    digitalWrite(level[1], 0);
    digitalWrite(level[2], 1);
    delay(x);
    digitalWrite(level[2], 0);
    digitalWrite(level[3], 1);
    delay(x+50);
    digitalWrite(level[3], 0);
    digitalWrite(column[randomColumn], 1);
  }
}

//diagonal rectangle that moves on the diagonal and the edges
void diagonalRectangle()
{
  int x = 350;
  turnEverythingOff();
  for(int count = 0; count<5; count++)
  {
    //top left
    for(int i = 0; i<8; i++)
    {
      digitalWrite(column[i], 0);
    }
    digitalWrite(level[3], 1);
    digitalWrite(level[2], 1);
    delay(x);
    turnEverythingOff();
    //middle middle
    for(int i = 4; i<12; i++)
    {
      digitalWrite(column[i], 0);
    }
    digitalWrite(level[1], 1);
    digitalWrite(level[2], 1);
    delay(x);
    turnEverythingOff();
    //bottom right
    for(int i = 8; i<16; i++)
    {
      digitalWrite(column[i], 0);
    }
    digitalWrite(level[0], 1);
    digitalWrite(level[1], 1);
    delay(x);
    turnEverythingOff();
    //bottom middle
    for(int i = 4; i<12; i++)
    {
      digitalWrite(column[i], 0);
    }
    digitalWrite(level[0], 1);
    digitalWrite(level[1], 1);
    delay(x);
    turnEverythingOff();
    //bottom left
    for(int i = 0; i<8; i++)
    {
      digitalWrite(column[i], 0);
    }
    digitalWrite(level[0], 1);
    digitalWrite(level[1], 1);
    delay(x);
    turnEverythingOff();
    //middle middle
    for(int i = 4; i<12; i++)
    {
      digitalWrite(column[i], 0);
    }
    digitalWrite(level[1], 1);
    digitalWrite(level[2], 1);
    delay(x);
    turnEverythingOff();
    //top right
    for(int i = 8; i<16; i++)
    {
      digitalWrite(column[i], 0);
    }
    digitalWrite(level[2], 1);
    digitalWrite(level[3], 1);
    delay(x);
    turnEverythingOff();
    //top middle
    for(int i = 4; i<12; i++)
    {
      digitalWrite(column[i], 0);
    }
    digitalWrite(level[2], 1);
    digitalWrite(level[3], 1);
    delay(x);
    turnEverythingOff();
  }
  //top left
  for(int i = 0; i<8; i++)
  {
    digitalWrite(column[i], 0);
  }
  digitalWrite(level[3], 1);
  digitalWrite(level[2], 1);
  delay(x);
  turnEverythingOff();
}

void propeller()
{
  turnEverythingOff();
  int x = 90;
  for(int y = 4; y>0; y--)
  {
    for(int i = 0; i<6; i++)
    {
      //turn on layer
      digitalWrite(level[y-1], 1);
      //a1
      turnColumnsOff();
      digitalWrite(column[0], 0);
      digitalWrite(column[5], 0);
      digitalWrite(column[10], 0);
      digitalWrite(column[15], 0);
      delay(x);
      //b1
      turnColumnsOff();
      digitalWrite(column[4], 0);
      digitalWrite(column[5], 0);
      digitalWrite(column[10], 0);
      digitalWrite(column[11], 0);
      delay(x);
      //c1
      turnColumnsOff();
      digitalWrite(column[6], 0);
      digitalWrite(column[7], 0);
      digitalWrite(column[8], 0);
      digitalWrite(column[9], 0);
      delay(x);
      //d1
      turnColumnsOff();
      digitalWrite(column[3], 0);
      digitalWrite(column[6], 0);
      digitalWrite(column[9], 0);
      digitalWrite(column[12], 0);
      delay(x);
      //d2
      turnColumnsOff();
      digitalWrite(column[2], 0);
      digitalWrite(column[6], 0);
      digitalWrite(column[9], 0);
      digitalWrite(column[13], 0);
      delay(x);
      //d3
      turnColumnsOff();
      digitalWrite(column[1], 0);
      digitalWrite(column[5], 0);
      digitalWrite(column[10], 0);
      digitalWrite(column[14], 0);
      delay(x);
    }
  }
  //d4
  turnColumnsOff();
  digitalWrite(column[0], 0);
  digitalWrite(column[5], 0);
  digitalWrite(column[10], 0);
  digitalWrite(column[15], 0);
  delay(x);
}

//leds turn on and off in a spiral way creating a snail-like shape
void spiral()
{
  turnEverythingOn();
  int x = 60;
  for(int i = 0; i<6; i++)
  {
    //in 1
    digitalWrite(column[0], 1);
    delay(x);
    digitalWrite(column[1], 1);
    delay(x);
    digitalWrite(column[2], 1);
    delay(x);
    digitalWrite(column[3], 1);
    delay(x);
    digitalWrite(column[7], 1);
    delay(x);
    digitalWrite(column[11], 1);
    delay(x);
    digitalWrite(column[15], 1);
    delay(x);
    digitalWrite(column[14], 1);
    delay(x);
    digitalWrite(column[13], 1);
    delay(x);
    digitalWrite(column[12], 1);
    delay(x);
    digitalWrite(column[8], 1);
    delay(x);
    digitalWrite(column[4], 1);
    delay(x);
    digitalWrite(column[5], 1);
    delay(x);
    digitalWrite(column[6], 1);
    delay(x);
    digitalWrite(column[10], 1);
    delay(x);
    digitalWrite(column[9], 1);
    delay(x);
    //out 1
    digitalWrite(column[9], 0);
    delay(x);
    digitalWrite(column[10], 0);
    delay(x);
    digitalWrite(column[6], 0);
    delay(x);
    digitalWrite(column[5], 0);
    delay(x);
    digitalWrite(column[4], 0);
    delay(x);
    digitalWrite(column[8], 0);
    delay(x);
    digitalWrite(column[12], 0);
    delay(x);
    digitalWrite(column[13], 0);
    delay(x);
    digitalWrite(column[14], 0);
    delay(x);
    digitalWrite(column[15], 0);
    delay(x);
    digitalWrite(column[11], 0);
    delay(x);
    digitalWrite(column[7], 0);
    delay(x);
    digitalWrite(column[3], 0);
    delay(x);
    digitalWrite(column[2], 0);
    delay(x);
    digitalWrite(column[1], 0);
    delay(x);
    digitalWrite(column[0], 0);
    delay(x);
    //in 2
    digitalWrite(column[0], 1);
    delay(x);
    digitalWrite(column[4], 1);
    delay(x);
    digitalWrite(column[8], 1);
    delay(x);
    digitalWrite(column[12], 1);
    delay(x);
    digitalWrite(column[13], 1);
    delay(x);
    digitalWrite(column[14], 1);
    delay(x);
    digitalWrite(column[15], 1);
    delay(x);
    digitalWrite(column[11], 1);
    delay(x);
    digitalWrite(column[7], 1);
    delay(x);
    digitalWrite(column[3], 1);
    delay(x);
    digitalWrite(column[2], 1);
    delay(x);
    digitalWrite(column[1], 1);
    delay(x);
    digitalWrite(column[5], 1);
    delay(x);
    digitalWrite(column[9], 1);
    delay(x);
    digitalWrite(column[10], 1);
    delay(x);
    digitalWrite(column[6], 1);
    delay(x);
    // out 2
    digitalWrite(column[6], 0);
    delay(x);
    digitalWrite(column[10], 0);
    delay(x);
    digitalWrite(column[9], 0);
    delay(x);
    digitalWrite(column[5], 0);
    delay(x);
    digitalWrite(column[1], 0);
    delay(x);
    digitalWrite(column[2], 0);
    delay(x);
    digitalWrite(column[3], 0);
    delay(x);
    digitalWrite(column[7], 0);
    delay(x);
    digitalWrite(column[11], 0);
    delay(x);
    digitalWrite(column[15], 0);
    delay(x);
    digitalWrite(column[14], 0);
    delay(x);
    digitalWrite(column[13], 0);
    delay(x);
    digitalWrite(column[12], 0);
    delay(x);
    digitalWrite(column[8], 0);
    delay(x);
    digitalWrite(column[4], 0);
    delay(x);
    digitalWrite(column[0], 0);
    delay(x);
  }
}

//This is self-described.
void allLedsOneAfterAnother()
{
  int x = 15;
  turnEverythingOff();
  for(int y = 0; y<5; y++)
  {
    //0-3
    for(int count = 4; count != 0; count--)
    {
      digitalWrite(level[count-1], 1);
      for(int i = 0; i<4; i++)
      {
        digitalWrite(column[i], 0);
        delay(x);
        digitalWrite(column[i], 1);
        delay(x);
      }
    digitalWrite(level[count-1], 0);
    }
    //4-7
    for(int count = 0; count < 4; count++)
    {
      digitalWrite(level[count], 1);
      for(int i = 4; i<8; i++)
      {
        digitalWrite(column[i], 0);
        delay(x);
        digitalWrite(column[i], 1);
        delay(x);
      }
    digitalWrite(level[count], 0);
    }
    //8-11
    for(int count = 4; count != 0; count--)
    {
      digitalWrite(level[count-1], 1);
      for(int i = 8; i<12; i++)
      {
        digitalWrite(column[i], 0);
        delay(x);
        digitalWrite(column[i], 1);
        delay(x);
      }
    digitalWrite(level[count-1], 0);
    }
    //12-15
    for(int count = 0; count < 4; count++)
    {
      digitalWrite(level[count], 1);
      for(int i = 12; i<16; i++)
      {
        digitalWrite(column[i], 0);
        delay(x);
        digitalWrite(column[i], 1);
        delay(x);
      }
    digitalWrite(level[count], 0);
    }
  }
}

//This turns the leds of the cube's diagonal on and off.
void diagonal()
{
  turnEverythingOff();
  for (int x = 100; x>0; x-=25){
    //first move
    digitalWrite(level[0], 1);
    digitalWrite(column[15], 0);
    delay(x);
    digitalWrite(level[0], 0);
    digitalWrite(column[15], 1);
    digitalWrite(level[1], 1);
    digitalWrite(column[10], 0);
    delay(x);
    digitalWrite(level[1], 0);
    digitalWrite(column[10], 1);
    digitalWrite(level[2], 1);
    digitalWrite(column[5], 0);
    delay(x);
    digitalWrite(level[2], 0);
    digitalWrite(column[5], 1);
    digitalWrite(level[3], 1);
    digitalWrite(column[0], 0);
    delay(x);

    //second move
    digitalWrite(level[3], 0);
    digitalWrite(column[0], 1);
    digitalWrite(level[2], 1);
    digitalWrite(column[1], 0);
    delay(x);
    digitalWrite(level[2], 0);
    digitalWrite(column[1], 1);
    digitalWrite(level[1], 1);
    digitalWrite(column[2], 0);
    delay(x);
    digitalWrite(level[1], 0);
    digitalWrite(column[2], 1);
    digitalWrite(level[0], 1);
    digitalWrite(column[3], 0);
    delay(x);

    //third move
    digitalWrite(level[0], 0);
    digitalWrite(column[3], 1);
    digitalWrite(level[1], 1);
    digitalWrite(column[6], 0);
    delay(x);
    digitalWrite(level[1], 0);
    digitalWrite(column[6], 1);
    digitalWrite(level[2], 1);
    digitalWrite(column[9], 0);
    delay(x);
    digitalWrite(level[2], 0);
    digitalWrite(column[9], 1);
    digitalWrite(level[3], 1);
    digitalWrite(column[12], 0);
    delay(x);

    //fourth move
    digitalWrite(level[3], 0);
    digitalWrite(column[12], 1);
    digitalWrite(level[2], 1);
    digitalWrite(column[13], 0);
    delay(x);
    digitalWrite(level[2], 0);
    digitalWrite(column[13], 1);
    digitalWrite(level[1], 1);
    digitalWrite(column[14], 0);
    delay(x);
    digitalWrite(level[1], 0);
    digitalWrite(column[14], 1);
  }
    digitalWrite(level[0], 1);
    digitalWrite(column[15], 0);
    digitalWrite(level[0], 0);
    digitalWrite(column[15], 1);
}

//Creates an X on the cube.
void cross()
{
  turnEverythingOff();
  for (int x =150; x>0; x-=50){
    digitalWrite(level[0], 1);
    for (int i = 3; i<16; i+=4) digitalWrite(column[i],0);
    delay(x);
    digitalWrite(level[0], 0);
    for (int i = 3; i<16; i+=4) digitalWrite(column[i],1);
    digitalWrite(level[1], 1);
    for (int i = 2; i<16; i+=4) digitalWrite(column[i],0); 
    delay(x);
    digitalWrite(level[1], 0);
    for (int i = 2; i<16; i+=4) digitalWrite(column[i],1);
    digitalWrite(level[2], 1);
    for (int i = 1; i<16; i+=4) digitalWrite(column[i],0); 
    delay(x);
    digitalWrite(level[2], 0);
    for (int i = 1; i<16; i+=4) digitalWrite(column[i],1);
    digitalWrite(level[3], 1);
    for (int i = 0; i<16; i+=4) digitalWrite(column[i],0); 
    delay(x);
    digitalWrite(level[3], 0);
    for (int i = 0; i<16; i+=4) digitalWrite(column[i],1);
    
    //second half
    digitalWrite(level[0], 1);
    for (int i = 0; i<16; i+=4) digitalWrite(column[i],0);
    delay(x);
    digitalWrite(level[0], 0);
    for (int i = 0; i<16; i+=4) digitalWrite(column[i],1);
    digitalWrite(level[1], 1);
    for (int i = 1; i<16; i+=4) digitalWrite(column[i],0); 
    delay(x);
    digitalWrite(level[1], 0);
    for (int i = 1; i<16; i+=4) digitalWrite(column[i],1);
    digitalWrite(level[2], 1);
    for (int i = 2; i<16; i+=4) digitalWrite(column[i],0); 
    delay(x);
    digitalWrite(level[2], 0);
    for (int i = 2; i<16; i+=4) digitalWrite(column[i],1);
    digitalWrite(level[3], 1);
    for (int i = 3; i<16; i+=4) digitalWrite(column[i],0); 
    delay(x);
    digitalWrite(level[3], 0);
    for (int i = 3; i<16; i+=4) digitalWrite(column[i],1);
  }
}

//A cibe that grows and shrinks.
void cube()
{
  turnEverythingOff();
  int x = 100;
  for(int j=0;j<3;j++)
  {
    for(int i=0; i<4; i++)
    {
      digitalWrite(level[3-i],1);
      light_updown(i+1, true);
      delay(x);
    }
    for(int i=3; i>-1; i--)
    {
      digitalWrite(level[3-i],0);
      light_updown(i+1, false);
      delay(x);
    }
  }
}

void light_updown(int n, bool k)
{
  if (n==1) 
  {
    digitalWrite(column[15],not k);
  }
  else if (n==2) 
  {
    digitalWrite(column[14],not k);
    digitalWrite(column[11],not k);
    digitalWrite(column[10],not k);
  }
  else if (n==3) 
  {
    digitalWrite(column[13],not k);
    digitalWrite(column[9],not k);
    digitalWrite(column[5],not k);
    digitalWrite(column[6],not k);
    digitalWrite(column[7],not k);
  }
  else 
  {
    digitalWrite(column[0],not k);
    digitalWrite(column[1],not k);
    digitalWrite(column[2],not k);
    digitalWrite(column[3],not k);
    digitalWrite(column[4],not k);
    digitalWrite(column[8],not k);
    digitalWrite(column[12],not k);
  }
}
