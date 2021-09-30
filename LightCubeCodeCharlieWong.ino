/* Charlie Wong
 *  
 *  
*/

int posts[] = {13, 9, 5, 14, 12, 8, 4, 15, 11, 7, 3, 16, 10, 6, 2, 17};      //mapped
//int posts[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, A0, A1, A2, A3};                  // Anode pins in order they represent as posts
int ledNums[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768};
int delay1 = 0;

//defining integers to tell seq1 what which leds on the layers to light up
int lay0;
int lay1;
int lay2;
int lay3;
void setup() {
  for (int next = 0; next < 16; next++)                          // sets anodes as outputs
  {
    pinMode(posts[next], OUTPUT);
  }
  pinMode(A4, OUTPUT);                                           //sets cathodes as outputs
  pinMode(A5, OUTPUT);
}

void loop() {
  //function runs all patterns
  //each for loop runs pattern for given number of times
  for (int i = 0; i< 1; i++) {
    planets();
  }
  for (int i = 0; i< 2; i++) {
    ledbounce();
  }
  for (int i = 0; i< 2; i++) {
    ledbounce2();
  }
  for (int i = 0; i < 2; i++) {
    singleled();
  }
  for (int i = 0; i < 1; i++) {
    droppinglogs();
  }
  for (int i = 0; i < 2; i++) {
    expandingcube();
  }
  for (int i = 0; i < 4; i++) {
    wholecubeblink();
  }
  for (int i = 0; i< 2; i++) {
    sidetoside2();
  }
  for (int i = 0; i < 3; i++) {
    upanddown();
  }
  for (int i = 0; i < 3; i++) {
    sidetoside();
  }
  for (int i = 0; i < 2; i++) {
    initials();
  }
}


void LEDposts() {
  //LightITUp(ledNums[0]+ledNums[5]+ledNums[15]);
  LightITUp(4096);
}
void LightITUp(unsigned int commandCode) {
  for (int x = 0; x < 16; x++) {
    digitalWrite (posts[x], LOW);
  }
  for (int x = 0; x < 16; x++) {
    if (bitRead(commandCode, x) == 1) {
      digitalWrite (posts[x], HIGH);
    }
  }
}

 
void wholecubeblink() {
  //pattern in which the whole cube turns on and off
  int pause1 = 200;
  //runs 200 times

  lay0 = 65535;
  lay1 = 65535;
  lay2 = 65535;
  lay3 = 65535;
  //all layers on
  
  for(int i = 0; i <pause1; i++) { 
    seq1(lay0,lay1,lay2,lay3);  //input into seq1
  }
  
  delay(150);
  //delay for 150 milliseconds 
}
void upanddown() {
  //pattern in which layer of lit leds move up and down
  //structure below is same used for all patterns: 
  //  using the horadric cube calculator, determine number for each layer.
  //  for each frame of the pattern, assign numbers to layers
  //  input layer integers into for loop, to run for a certain amount of time
  //  redefine each layer and new for loop for every frame of pattern
  
  int pause1= 150;

  //frame 1
  lay0 = 65535;
  lay1 = 0;
  lay2 = 0;
  lay3 = 0;
  for (int i=0; i<pause1; i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 2
  lay0 = 0;
  lay1 = 65535;
  lay2 = 0;
  lay3 = 0;
  for (int i=0; i<pause1; i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 3
  lay0 = 0;
  lay1 = 0;
  lay2 = 65535;
  lay3 = 0;
  for (int i=0; i<pause1; i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 4
  lay0 = 0;
  lay1 = 0;
  lay2 = 0;
  lay3 = 65535;
  for (int i=0; i<(pause1*2); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 5
  lay0 = 0;
  lay1 = 0;
  lay2 = 65535;
  lay3 = 0;
  for (int i=0; i<pause1; i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 6 
  lay0 = 0;
  lay1 = 65535;
  lay2 = 0;
  lay3 = 0;
  for (int i=0; i<pause1; i++) {
    seq1(lay0,lay1,lay2,lay3);
  } 

  //frame 7
  lay0 = 65535;
  lay1 = 0;
  lay2 = 0;
  lay3 = 0;
  for (int i=0; i<pause1; i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
}

void sidetoside() {
  //pattern in which full side of lit leds moves side to side
  int pause1= 150;
  //frame 1
  lay0 = 4369;
  lay1 = 4369;
  lay2 = 4369;
  lay3 = 4369;
  for (int i=0; i<pause1; i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 2
  lay0 = 8738;
  lay1 = 8738;
  lay2 = 8738;
  lay3 = 8738;
  for (int i=0; i<pause1; i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 3
  lay0 = 17476;
  lay1 = 17476;
  lay2 = 17476;
  lay3 = 17476;
  for (int i=0; i<pause1; i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 4
  lay0 = 34952;
  lay1 = 34952;
  lay2 = 34952;
  lay3 = 34952;
  for (int i=0; i<(pause1*2); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 5
  lay0 = 17476;
  lay1 = 17476;
  lay2 = 17476;
  lay3 = 17476;
  for (int i=0; i<pause1; i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 6 
  lay0 = 8738;
  lay1 = 8738;
  lay2 = 8738;
  lay3 = 8738;
  for (int i=0; i<pause1; i++) {
    seq1(lay0,lay1,lay2,lay3);
  } 

  //frame 7
  lay0 = 4369;
  lay1 = 4369;
  lay2 = 4369;
  lay3 = 4369;
  for (int i=0; i<pause1; i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
}

void initials() {
  //pattern in which the initials "C" and "W" are displayed (visible from top)
  int pause1= 100;
  //Letter C
  //frame 1
  lay0 = 0;
  lay1 = 0;
  lay2 = 0;
  lay3 = 2;
  for (int i=0; i<pause1; i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 2
  lay0 = 0;
  lay1 = 0;
  lay2 = 0;
  lay3 = 64;
  for (int i=0; i<pause1; i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 3
  lay0 = 0;
  lay1 = 0;
  lay2 = 0;
  lay3 = 2048;
  for (int i=0; i<(pause1*2); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 4
  lay0 = 0;
  lay1 = 0;
  lay2 = 0;
  lay3 = 2050;
  for (int i=0; i<(pause1*2); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 5
  lay0 = 0;
  lay1 = 0;
  lay2 = 0;
  lay3 = 2066;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 6
  lay0 = 0;
  lay1 = 0;
  lay2 = 0;
  lay3 = 2562;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 7
  lay0 = 0;
  lay1 = 0;
  lay2 = 0;
  lay3 = 18434;
  for (int i=0; i<(pause1*2); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 8
  lay0 = 0;
  lay1 = 0;
  lay2 = 0;
  lay3 = 18450;
  for (int i=0; i<(pause1*2); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 9
  lay0 = 0;
  lay1 = 0;
  lay2 = 0;
  lay3 = 18706;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 10
  lay0 = 0;
  lay1 = 0;
  lay2 = 0;
  lay3 = 26642;
  for (int i=0; i<(pause1*2); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 11 THE FINAL C
  lay0 = 0;
  lay1 = 0;
  lay2 = 0;
  lay3 = 26898;
  for (int i=0; i<(pause1*5); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //fills cube, then empties cube and removes C
  //frame 1
  lay0 = 65535;
  lay1 = 0;
  lay2 = 0;
  lay3 = 26898;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 2
  lay0 = 65535;
  lay1 = 65535;
  lay2 = 0;
  lay3 = 26898;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 3
  lay0 = 65535;
  lay1 = 65535;
  lay2 = 65535;
  lay3 = 26898;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 4
  lay0 = 65535;
  lay1 = 65535;
  lay2 = 65535;
  lay3 = 65535;
  for (int i=0; i<(pause1*2); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 5
  lay0 = 65535;
  lay1 = 65535;
  lay2 = 65535;
  lay3 = 0;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 6
  lay0 = 65535;
  lay1 = 65535;
  lay2 = 0;
  lay3 = 0;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 7
  lay0 = 65535;
  lay1 = 0;
  lay2 = 0;
  lay3 = 0;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 8
  lay0 = 0;
  lay1 = 0;
  lay2 = 0;
  lay3 = 0;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  
  //Initial "W"
  //frame 1
  lay0 = 0;
  lay1 = 0;
  lay2 = 0;
  lay3 = 4;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 2
  lay0 = 0;
  lay1 = 0;
  lay2 = 0;
  lay3 = 128;
  for (int i=0; i<(pause1*2); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 3
  lay0 = 0;
  lay1 = 0;
  lay2 = 0;
  lay3 = 132;
  for (int i=0; i<(pause1*2); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 4
  lay0 = 0;
  lay1 = 0;
  lay2 = 0;
  lay3 = 134;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 5
  lay0 = 0;
  lay1 = 0;
  lay2 = 0;
  lay3 = 196;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 6
  lay0 = 0;
  lay1 = 0;
  lay2 = 0;
  lay3 = 2180;
  for (int i=0; i<(pause1*2); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 7
  lay0 = 0;
  lay1 = 0;
  lay2 = 0;
  lay3 = 2181;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 8
  lay0 = 0;
  lay1 = 0;
  lay2 = 0;
  lay3 = 2212;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 9
  lay0 = 0;
  lay1 = 0;
  lay2 = 0;
  lay3 = 3204;
  for (int i=0; i<(pause1*2); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 10
  lay0 = 0;
  lay1 = 0;
  lay2 = 0;
  lay3 = 3220;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 11
  lay0 = 0;
  lay1 = 0;
  lay2 = 0;
  lay3 = 3716;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 12
  lay0 = 0;
  lay1 = 0;
  lay2 = 0;
  lay3 = 19588;
  for (int i=0; i<(pause1*2); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 13
  lay0 = 0;
  lay1 = 0;
  lay2 = 0;
  lay3 = 19844;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 14
  lay0 = 0;
  lay1 = 0;
  lay2 = 0;
  lay3 = 27780;
  for (int i=0; i<(pause1*2); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 15 
  lay0 = 0;
  lay1 = 0;
  lay2 = 0;
  lay3 = 28036;
  for (int i=0; i<(pause1*5); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //Filling cube and removing W
  //frame 1
  lay0 = 65535;
  lay1 = 0;
  lay2 = 0;
  lay3 = 28036;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 2
  lay0 = 65535;
  lay1 = 65535;
  lay2 = 0;
  lay3 = 28036;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 3
  lay0 = 65535;
  lay1 = 65535;
  lay2 = 65535;
  lay3 = 28036;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 4
  lay0 = 65535;
  lay1 = 65535;
  lay2 = 65535;
  lay3 = 65535;
  for (int i=0; i<(pause1*2); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 5
  lay0 = 65535;
  lay1 = 65535;
  lay2 = 65535;
  lay3 = 0;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 6
  lay0 = 65535;
  lay1 = 65535;
  lay2 = 0;
  lay3 = 0;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 7
  lay0 = 65535;
  lay1 = 0;
  lay2 = 0;
  lay3 = 0;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 8
  lay0 = 0;
  lay1 = 0;
  lay2 = 0;
  lay3 = 0;
  for (int i=0; i<(pause1*5); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
}

void expandingcube() {
  //pattern in which lit leds expand from 2x2x2, to 3x3x3, to full cube
  int pause1 = 50;
  //DROPPING LED
  // frame 1
  lay0 = 0;
  lay1 = 0;
  lay2 = 0;
  lay3 = 32768;
  for (int i=0; i<(pause1*2); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 2
  lay0 = 0;
  lay1 = 0;
  lay2 = 32768;
  lay3 = 0;
  for (int i=0; i<(pause1*2); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 3
  lay0 = 0;
  lay1 = 32768;
  lay2 = 0;
  lay3 = 0;
  for (int i=0; i<(pause1*2); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 4
  lay0 = 32768;
  lay1 = 0;
  lay2 = 0;
  lay3 = 0;
  for (int i=0; i<(pause1*10); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //expanding to 2x2x2 cube
  //frame 1
  lay0 = 34816;
  lay1 = 0;
  lay2 = 0;
  lay3 = 0;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 2
  lay0 = 35840;
  lay1 = 0;
  lay2 = 0;
  lay3 = 0;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 3
  lay0 = 52224;
  lay1 = 0;
  lay2 = 0;
  lay3 = 0;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 4
  lay0 = 52224;
  lay1 = 16384;
  lay2 = 0;
  lay3 = 0;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 5
  lay0 = 52224;
  lay1 = 17408;
  lay2 = 0;
  lay3 = 0;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 6
  lay0 = 52224;
  lay1 = 19456;
  lay2 = 0;
  lay3 = 0;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 7
  lay0 = 52224;
  lay1 = 52224;
  lay2 = 0;
  lay3 = 0;
  for (int i=0; i<(pause1*7); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //expand to 3x3x3 cube
  //frame 1
  lay0 = 52224;
  lay1 = 52224;
  lay2 = 32768;
  lay3 = 0;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  
  //frame 2
  lay0 = 52224;
  lay1 = 52224;
  lay2 = 49152;
  lay3 = 0;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 3
  lay0 = 52224;
  lay1 = 52224;
  lay2 = 57344;
  lay3 = 0;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 4
  lay0 = 52224;
  lay1 = 60416;
  lay2 = 57344;
  lay3 = 0;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 5
  lay0 = 60416;
  lay1 = 60416;
  lay2 = 57344;
  lay3 = 0;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 6
  lay0 = 60928;
  lay1 = 60416;
  lay2 = 57344;
  lay3 = 0;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 7
  lay0 = 60928;
  lay1 = 60928;
  lay2 = 57344;
  lay3 = 0;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 8
  lay0 = 60928;
  lay1 = 60928;
  lay2 = 57856;
  lay3 = 0;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 9
  lay0 = 60928;
  lay1 = 60928;
  lay2 = 57888;
  lay3 = 0;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 10
  lay0 = 60928;
  lay1 = 60960;
  lay2 = 57888;
  lay3 = 0;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 11
  lay0 = 60960;
  lay1 = 60960;
  lay2 = 57888;
  lay3 = 0;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 12
  lay0 = 61024;
  lay1 = 60960;
  lay2 = 57888;
  lay3 = 0;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 13
  lay0 = 61152;
  lay1 = 60960;
  lay2 = 57888;
  lay3 = 0;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 14
  lay0 = 61152;
  lay1 = 61088;
  lay2 = 57888;
  lay3 = 0;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 15
  lay0 = 61152;
  lay1 = 61152;
  lay2 = 57888;
  lay3 = 0;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 16
  lay0 = 61152;
  lay1 = 61152;
  lay2 = 57952;
  lay3 = 0;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 17
  lay0 = 61152;
  lay1 = 61152;
  lay2 = 58080;
  lay3 = 0;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 18
  lay0 = 61152;
  lay1 = 61152;
  lay2 = 59104;
  lay3 = 0;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 19
  lay0 = 61152;
  lay1 = 61152;
  lay2 = 61152;
  lay3 = 0;
  for (int i=0; i<(pause1*7); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  // expanding to 4x4x4 cube
  //frame 1
  lay0 = 61152;
  lay1 = 61152;
  lay2 = 61152;
  lay3 = 32768;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 2
  lay0 = 61152;
  lay1 = 61152;
  lay2 = 61152;
  lay3 = 49152;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 3
  lay0 = 61152;
  lay1 = 61152;
  lay2 = 61152;
  lay3 = 57344;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 4
  lay0 = 61152;
  lay1 = 61152;
  lay2 = 61152;
  lay3 = 61440;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 5
  lay0 = 61152;
  lay1 = 61152;
  lay2 = 61152;
  lay3 = 3840;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 6
  lay0 = 61152;
  lay1 = 61152;
  lay2 = 61152;
  lay3 = 240;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 7
  lay0 = 61152;
  lay1 = 61152;
  lay2 = 61152;
  lay3 = 15;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 8
  lay0 = 61152;
  lay1 = 61152;
  lay2 = 61167;
  lay3 = 0;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 9
  lay0 = 61152;
  lay1 = 61167;
  lay2 = 61152;
  lay3 = 0;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 10
  lay0 = 61167;
  lay1 = 61152;
  lay2 = 61152;
  lay3 = 0;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 11
  lay0 = 61167;
  lay1 = 61152;
  lay2 = 61152;
  lay3 = 32768;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 12
  lay0 = 61167;
  lay1 = 61152;
  lay2 = 61152;
  lay3 = 49152;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 13
  lay0 = 61167;
  lay1 = 61152;
  lay2 = 61152;
  lay3 = 57344;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 14
  lay0 = 61167;
  lay1 = 61152;
  lay2 = 61152;
  lay3 = 61440;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 15
  lay0 = 61167;
  lay1 = 61152;
  lay2 = 61152;
  lay3 = 3840;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 16
  lay0 = 61167;
  lay1 = 61152;
  lay2 = 61152;
  lay3 = 240;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 17
  lay0 = 61167;
  lay1 = 61152;
  lay2 = 61152;
  lay3 = 15;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 18
  lay0 = 61167;
  lay1 = 61152;
  lay2 = 61167;
  lay3 = 0;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 19
  lay0 = 61167;
  lay1 = 61167;
  lay2 = 61152;
  lay3 = 0;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 20
  lay0 = 61167;
  lay1 = 61167;
  lay2 = 61152;
  lay3 = 32768;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 21
  lay0 = 61167;
  lay1 = 61167;
  lay2 = 61152;
  lay3 = 49152;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 22
  lay0 = 61167;
  lay1 = 61167;
  lay2 = 61152;
  lay3 = 57344;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 23
  lay0 = 61167;
  lay1 = 61167;
  lay2 = 61152;
  lay3 = 61440;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 24
  lay0 = 61167;
  lay1 = 61167;
  lay2 = 61152;
  lay3 = 3840;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 25
  lay0 = 61167;
  lay1 = 61167;
  lay2 = 61152;
  lay3 = 240;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 26
  lay0 = 61167;
  lay1 = 61167;
  lay2 = 61152;
  lay3 = 15;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 27
  lay0 = 61167;
  lay1 = 61167;
  lay2 = 61167;
  lay3 = 0;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 28
  lay0 = 61167;
  lay1 = 61167;
  lay2 = 61167;
  lay3 = 32768;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 29
  lay0 = 61167;
  lay1 = 61167;
  lay2 = 61167;
  lay3 = 49152;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 30
  lay0 = 61167;
  lay1 = 61167;
  lay2 = 61167;
  lay3 = 57344;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 31
  lay0 = 61167;
  lay1 = 61167;
  lay2 = 61167;
  lay3 = 61440;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 32
  lay0 = 61167;
  lay1 = 61167;
  lay2 = 61167;
  lay3 = 3840;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 33
  lay0 = 61167;
  lay1 = 61167;
  lay2 = 61167;
  lay3 = 240;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 34
  lay0 = 61167;
  lay1 = 61167;
  lay2 = 61167;
  lay3 = 15;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 35
  lay0 = 61167;
  lay1 = 61167;
  lay2 = 61167;
  lay3 = 32783;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 36
  lay0 = 61167;
  lay1 = 61167;
  lay2 = 61167;
  lay3 = 34831;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 37
  lay0 = 61167;
  lay1 = 61167;
  lay2 = 61167;
  lay3 = 34959;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 38
  lay0 = 61167;
  lay1 = 61167;
  lay2 = 61167;
  lay3 = 17487;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 39
  lay0 = 61167;
  lay1 = 61167;
  lay2 = 61167;
  lay3 = 8751;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 40
  lay0 = 61167;
  lay1 = 61167;
  lay2 = 61167;
  lay3 = 4383;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 41
  lay0 = 61167;
  lay1 = 61167;
  lay2 = 65535;
  lay3 = 15;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 42
  lay0 = 61167;
  lay1 = 65535;
  lay2 = 61167;
  lay3 = 15;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 43
  lay0 = 65535;
  lay1 = 61167;
  lay2 = 61167;
  lay3 = 15;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  
  //frame 44
  lay0 = 65535;
  lay1 = 61167;
  lay2 = 61167;
  lay3 = 32783;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 45
  lay0 = 65535;
  lay1 = 61167;
  lay2 = 61167;
  lay3 = 34831;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 46
  lay0 = 65535;
  lay1 = 61167;
  lay2 = 61167;
  lay3 = 34959;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 47
  lay0 = 65535;
  lay1 = 61167;
  lay2 = 61167;
  lay3 = 17487;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 48
  lay0 = 65535;
  lay1 = 61167;
  lay2 = 61167;
  lay3 = 8751;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 49
  lay0 = 65535;
  lay1 = 61167;
  lay2 = 61167;
  lay3 = 4383;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 50
  lay0 = 65535;
  lay1 = 61167;
  lay2 = 65535;
  lay3 = 15;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 51
  lay0 = 65535;
  lay1 = 65535;
  lay2 = 61167;
  lay3 = 15;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  
  //frame 52
  lay0 = 65535;
  lay1 = 65535;
  lay2 = 61167;
  lay3 = 32783;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 53
  lay0 = 65535;
  lay1 = 65535;
  lay2 = 61167;
  lay3 = 34831;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 46
  lay0 = 65535;
  lay1 = 65535;
  lay2 = 61167;
  lay3 = 34959;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 47
  lay0 = 65535;
  lay1 = 65535;
  lay2 = 61167;
  lay3 = 17487;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 48
  lay0 = 65535;
  lay1 = 65535;
  lay2 = 61167;
  lay3 = 8751;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 49
  lay0 = 65535;
  lay1 = 65535;
  lay2 = 61167;
  lay3 = 4383;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 50
  lay0 = 65535;
  lay1 = 65535;
  lay2 = 65535;
  lay3 = 37151;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

//frame 51
  lay0 = 65535;
  lay1 = 65535;
  lay2 = 65535;
  lay3 = 53535;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 52
  lay0 = 65535;
  lay1 = 65535;
  lay2 = 65535;
  lay3 = 61727;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 53
  lay0 = 65535;
  lay1 = 65535;
  lay2 = 65535;
  lay3 = 7967;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 54
  lay0 = 65535;
  lay1 = 65535;
  lay2 = 65535;
  lay3 = 4607;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 55
  lay0 = 65535;
  lay1 = 65535;
  lay2 = 65535;
  lay3 = 37375;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 56
  lay0 = 65535;
  lay1 = 65535;
  lay2 = 65535;
  lay3 = 53759;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 57
  lay0 = 65535;
  lay1 = 65535;
  lay2 = 65535;
  lay3 = 61951;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 58
  lay0 = 65535;
  lay1 = 65535;
  lay2 = 65535;
  lay3 = 8191;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 59
  lay0 = 65535;
  lay1 = 65535;
  lay2 = 65535;
  lay3 = 40959;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 60
  lay0 = 65535;
  lay1 = 65535;
  lay2 = 65535;
  lay3 = 57343;
  for (int i=0; i<(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //frame 61
  lay0 = 65535;
  lay1 = 65535;
  lay2 = 65535;
  lay3 = 65535;
  for (int i=0; i<(pause1*5); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
}

void droppinglogs() {
  //tetris-style pattern where blocks are dropped, then removed by "dropping" through middle
  int pause1 = 150;
  //first block
  //frame 1
  lay0 = 0;
  lay1 = 0;
  lay2 = 0;
  lay3 = 65280;
  for(int i = 0; i <pause1; i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 2
  lay0 = 0;
  lay1 = 0;
  lay2 = 65280;
  lay3 = 65280;
  for(int i = 0; i <pause1; i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 3
  lay0 = 0;
  lay1 = 65280;
  lay2 = 65280;
  lay3 = 0;
  for(int i = 0; i <pause1; i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 4
  lay0 = 65280;
  lay1 = 65280;
  lay2 = 0;
  lay3 = 0;
  for(int i = 0; i <(pause1*5); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //dropping second block
  //frame 1
  lay0 = 65280;
  lay1 = 65280;
  lay2 = 0;
  lay3 = 204;
  for(int i = 0; i <pause1; i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 2
  lay0 = 65280;
  lay1 = 65280;
  lay2 = 204;
  lay3 = 204;
  for(int i = 0; i <pause1; i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 3
  lay0 = 65280;
  lay1 = 65484;
  lay2 = 204;
  lay3 = 204;
  for(int i = 0; i <pause1; i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 4
  lay0 = 65484;
  lay1 = 65484;
  lay2 = 204;
  lay3 = 0;
  for(int i = 0; i <(pause1*5); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //dropping third block
  //frame 1
  lay0 = 65484;
  lay1 = 65484;
  lay2 = 204;
  lay3 = 51;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 2
  lay0 = 65484;
  lay1 = 65484;
  lay2 = 255;
  lay3 = 51;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 3
  lay0 = 65484;
  lay1 = 65535;
  lay2 = 255;
  lay3 = 51;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 4
  lay0 = 65535;
  lay1 = 65535;
  lay2 = 255;
  lay3 = 51;
  for(int i = 0; i <(pause1*5); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  
  //dropping the fourth block
  //frame 1
  lay0 = 65535;
  lay1 = 65535;
  lay2 = 255;
  lay3 = 65331;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 2
  lay0 = 65535;
  lay1 = 65535;
  lay2 = 65535;
  lay3 = 65535;
  for(int i = 0; i <(pause1*3); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //middle columns dropping through
  //frame 1
  lay0 = 65535;
  lay1 = 65535;
  lay2 = 65535;
  lay3 = 63903;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 2
  lay0 = 65535;
  lay1 = 65535;
  lay2 = 63903;
  lay3 = 63903;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 3
  lay0 = 65535;
  lay1 = 63903;
  lay2 = 63903;
  lay3 = 63903;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 4
  lay0 = 63903;
  lay1 = 63903;
  lay2 = 63903;
  lay3 = 63903;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //move sides in for dropping down middle
  //frame 1
  lay0 = 40953;
  lay1 = 40953;
  lay2 = 40953;
  lay3 = 40953;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 2
  lay0 = 40953;
  lay1 = 40953;
  lay2 = 40953;
  lay3 = 39321;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 3
  lay0 = 40953;
  lay1 = 40953;
  lay2 = 39321;
  lay3 = 39321;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 4
  lay0 = 40953;
  lay1 = 39321;
  lay2 = 39321;
  lay3 = 39321;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 5
  lay0 = 39321;
  lay1 = 39321;
  lay2 = 39321;
  lay3 = 39321;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //move other sides in for dropping in middle
  //frame 1
  lay0 = 38505;
  lay1 = 38505;
  lay2 = 38505;
  lay3 = 38505;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 2
  lay0 = 38505;
  lay1 = 38505;
  lay2 = 38505;
  lay3 = 36873;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 3
  lay0 = 38505;
  lay1 = 38505;
  lay2 = 36873;
  lay3 = 36873;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 4
  lay0 = 38505;
  lay1 = 36873;
  lay2 = 36873;
  lay3 = 36873;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 5
  lay0 = 36873;
  lay1 = 36873;
  lay2 = 36873;
  lay3 = 36873;
  for(int i = 0; i <(pause1*2); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }

  //corner posts pattern
  // repeats pattern, gets faster every loop
  for (int i = 0; i < 50; i++) {
    pause1 -= 10;
    //frame 1
    lay0 = 36873;
    lay1 = 36873;
    lay2 = 36873;
    lay3 = 0;
    for(int i = 0; i <(pause1); i++) {
      seq1(lay0,lay1,lay2,lay3);
    }
    //frame 2
    lay0 = 36873;
    lay1 = 36873;
    lay2 = 0;
    lay3 = 36873;
    for(int i = 0; i <(pause1); i++) {
      seq1(lay0,lay1,lay2,lay3);
    }
    //frame 3
    lay0 = 36873;
    lay1 = 0;
    lay2 = 36873;
    lay3 = 36873;
    for(int i = 0; i <(pause1); i++) {
      seq1(lay0,lay1,lay2,lay3);
    }
    //frame 4
    lay0 = 0;
    lay1 = 36873;
    lay2 = 36873;
    lay3 = 36873;
    for(int i = 0; i <(pause1); i++) {
      seq1(lay0,lay1,lay2,lay3);
    }
  }
  //all leds off
  pause1 = 150;
    lay0 = 0;
    lay1 = 0;
    lay2 = 0;
    lay3 = 0;
    for(int i = 0; i <(pause1*3); i++) {
      seq1(lay0,lay1,lay2,lay3);
    }
  
}

void singleled() {
  //pattern where single lit led moves around cube
  int pause1 = 100;
  //frame 1
  lay0 = 32768;
  lay1 = 0;
  lay2 = 0;
  lay3 = 0;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 2
  lay0 = 0;
  lay1 = 32768;
  lay2 = 0;
  lay3 = 0;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 3
  lay0 = 0;
  lay1 = 0;
  lay2 = 32768;
  lay3 = 0;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 4
  lay0 = 0;
  lay1 = 0;
  lay2 = 0;
  lay3 = 32768;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 5
  lay0 = 0;
  lay1 = 0;
  lay2 = 0;
  lay3 = 16384;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 6
  lay0 = 0;
  lay1 = 0;
  lay2 = 0;
  lay3 = 8192;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 7
  lay0 = 0;
  lay1 = 0;
  lay2 = 0;
  lay3 = 4096;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 8
  lay0 = 0;
  lay1 = 0;
  lay2 = 4096;
  lay3 = 0;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 9
  lay0 = 0;
  lay1 = 4096;
  lay2 = 0;
  lay3 = 0;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 10
  lay0 = 4096;
  lay1 = 0;
  lay2 = 0;
  lay3 = 0;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 11
  lay0 = 8192;
  lay1 = 0;
  lay2 = 0;
  lay3 = 0;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 12
  lay0 = 16384;
  lay1 = 0;
  lay2 = 0;
  lay3 = 0;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 13
  lay0 = 32768;
  lay1 = 0;
  lay2 = 0;
  lay3 = 0;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 14
  lay0 = 0;
  lay1 = 32768;
  lay2 = 0;
  lay3 = 0;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 15
  lay0 = 0;
  lay1 = 0;
  lay2 = 32768;
  lay3 = 0;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 16
  lay0 = 0;
  lay1 = 0;
  lay2 = 0;
  lay3 = 32768;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 17
  lay0 = 0;
  lay1 = 0;
  lay2 = 0;
  lay3 = 2048;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 18
  lay0 = 0;
  lay1 = 0;
  lay2 = 0;
  lay3 = 128;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 19
  lay0 = 0;
  lay1 = 0;
  lay2 = 0;
  lay3 = 8;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 20
  lay0 = 0;
  lay1 = 0;
  lay2 = 8;
  lay3 = 0;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 21
  lay0 = 0;
  lay1 = 8;
  lay2 = 0;
  lay3 = 0;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 22
  lay0 = 8;
  lay1 = 0;
  lay2 = 0;
  lay3 = 0;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 23
  lay0 = 128;
  lay1 = 0;
  lay2 = 0;
  lay3 = 0;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 24
  lay0 = 2048;
  lay1 = 0;
  lay2 = 0;
  lay3 = 0;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 25
  lay0 = 32768;
  lay1 = 0;
  lay2 = 0;
  lay3 = 0;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 26
  lay0 = 0;
  lay1 = 32768;
  lay2 = 0;
  lay3 = 0;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 27
  lay0 = 0;
  lay1 = 0;
  lay2 = 32768;
  lay3 = 0;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 28
  lay0 = 0;
  lay1 = 0;
  lay2 = 0;
  lay3 = 32768;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 29
  lay0 = 0;
  lay1 = 0;
  lay2 = 0;
  lay3 = 1024;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 30
  lay0 = 0;
  lay1 = 0;
  lay2 = 0;
  lay3 = 32;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 31
  lay0 = 0;
  lay1 = 0;
  lay2 = 0;
  lay3 = 1;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 32
  lay0 = 0;
  lay1 = 0;
  lay2 = 1;
  lay3 = 0;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 33
  lay0 = 0;
  lay1 = 1;
  lay2 = 0;
  lay3 = 0;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 34
  lay0 = 1;
  lay1 = 0;
  lay2 = 0;
  lay3 = 0;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 35
  lay0 = 32;
  lay1 = 0;
  lay2 = 0;
  lay3 = 0;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 36
  lay0 = 1024;
  lay1 = 0;
  lay2 = 0;
  lay3 = 0;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 37
  lay0 = 32768;
  lay1 = 0;
  lay2 = 0;
  lay3 = 0;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
} 

void ledbounce() {
  //pattern where single lit led bounces around cube
  int pause1 = 100;
  //frame 1
  lay0 = 32768;
  lay1 = 0;
  lay2 = 0;
  lay3 = 0;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 2
  lay0 = 0;
  lay1 = 2048;
  lay2 = 0;
  lay3 = 0;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 3
  lay0 = 0;
  lay1 = 0;
  lay2 = 128;
  lay3 = 0;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 4
  lay0 = 0;
  lay1 = 0;
  lay2 = 0;
  lay3 = 8;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 5
  lay0 = 0;
  lay1 = 0;
  lay2 = 4;
  lay3 = 0;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 6
  lay0 = 0;
  lay1 = 2;
  lay2 = 0;
  lay3 = 0;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 7
  lay0 = 1;
  lay1 = 0;
  lay2 = 0;
  lay3 = 0;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 8
  lay0 = 0;
  lay1 = 16;
  lay2 = 0;
  lay3 = 0;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 9 
  lay0 = 0;
  lay1 = 0;
  lay2 = 256;
  lay3 = 0;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 10
  lay0 = 0;
  lay1 = 0;
  lay2 = 0;
  lay3 = 4096;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 11
  lay0 = 0;
  lay1 = 0;
  lay2 = 8192;
  lay3 = 0;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 12
  lay0 = 0;
  lay1 = 16384;
  lay2 = 0;
  lay3 = 0;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
}

void ledbounce2() {
  //pattern where 2 lit leds bounce around cube
  int pause1 = 100;
  //frame 1
  lay0 = 32768;
  lay1 = 0;
  lay2 = 0;
  lay3 = 1;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 2
  lay0 = 0;
  lay1 = 2048;
  lay2 = 2;
  lay3 = 0;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 3
  lay0 = 0;
  lay1 = 4;
  lay2 = 128;
  lay3 = 0;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 4
  lay0 = 8;
  lay1 = 0;
  lay2 = 0;
  lay3 = 8;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 5
  lay0 = 0;
  lay1 = 128;
  lay2 = 4;
  lay3 = 0;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 6
  lay0 = 0;
  lay1 = 2;
  lay2 = 2048;
  lay3 = 0;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 7
  lay0 = 1;
  lay1 = 0;
  lay2 = 0;
  lay3 = 32768;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 8
  lay0 = 0;
  lay1 = 16;
  lay2 = 16384;
  lay3 = 0;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 9 
  lay0 = 0;
  lay1 = 8192;
  lay2 = 256;
  lay3 = 0;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 10
  lay0 = 4096;
  lay1 = 0;
  lay2 = 0;
  lay3 = 4096;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 11
  lay0 = 0;
  lay1 = 256;
  lay2 = 8192;
  lay3 = 0;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 12
  lay0 = 0;
  lay1 = 16384;
  lay2 = 16;
  lay3 = 0;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  
}

void sidetoside2 () {
  // "Staircase" style pattern. single side of leds moves across cube, then back, forming "staircase". Then, moves back across cube, forming upside down staircase
  int pause1 = 100;
  //frame 1
  lay0 = 0;
  lay1 = 0;
  lay2 = 0;
  lay3 = 0;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 2
  lay0 = 15;
  lay1 = 15;
  lay2 = 15;
  lay3 = 15;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 3
  lay0 = 240;
  lay1 = 240;
  lay2 = 240;
  lay3 = 240;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 4
  lay0 = 3840;
  lay1 = 3840;
  lay2 = 3840;
  lay3 = 3840;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 5
  lay0 = 61440;
  lay1 = 61440;
  lay2 = 61440;
  lay3 = 61440;
  for(int i = 0; i <(pause1*3); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 6
  lay0 = 61440;
  lay1 = 61440;
  lay2 = 61440;
  lay3 = 3840;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 7
  lay0 = 61440;
  lay1 = 61440;
  lay2 = 3840;
  lay3 = 240;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 8
  lay0 = 61440;
  lay1 = 3840;
  lay2 = 240;
  lay3 = 15;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 9
  lay0 = 61440;
  lay1 = 4080;
  lay2 = 255;
  lay3 = 15;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 10
  lay0 = 61440;
  lay1 = 4095;
  lay2 = 255;
  lay3 = 15;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 11
  lay0 = 65280;
  lay1 = 4095;
  lay2 = 255;
  lay3 = 15;
  for(int i = 0; i <(pause1/2); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 12
  lay0 = 65520;
  lay1 = 4095;
  lay2 = 255;
  lay3 = 15;
  for(int i = 0; i <(pause1/2); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 13
  lay0 = 65535;
  lay1 = 4095;
  lay2 = 255;
  lay3 = 15;
  for(int i = 0; i <(pause1*3); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 14
  lay0 = 4095;
  lay1 = 255;
  lay2 = 15;
  lay3 = 15;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 15
  lay0 = 255;
  lay1 = 15;
  lay2 = 15;
  lay3 = 15;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 16
  lay0 = 15;
  lay1 = 15;
  lay2 = 15;
  lay3 = 15;
  for(int i = 0; i <(pause1*3); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 17
  lay0 = 15;
  lay1 = 15;
  lay2 = 15;
  lay3 = 255;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 18
  lay0 = 15;
  lay1 = 15;
  lay2 = 255;
  lay3 = 4095;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 19
  lay0 = 15;
  lay1 = 255;
  lay2 = 4095;
  lay3 = 65535;
  for(int i = 0; i <(pause1*3); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
}

void planets() {
  //pattern where a "sun" is formed in middle of cube, two "planets" eventually "orbit" around it
  int pause1 = 100;
  //bringing in the sun
  //frame 1
  lay0 = 0;
  lay1 = 0;
  lay2 = 0;
  lay3 = 0;
  for(int i = 0; i <(pause1*3); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 2
  lay0 = 4096;
  lay1 = 0;
  lay2 = 0;
  lay3 = 0;
  for(int i = 0; i <(pause1); i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  // loop of small sun - rotates single led around in middle of cube, gets faster with each loop
  for(int i = 0; i < 10; i++) {
    //frame 3
    lay0 = 0;
    lay1 = 512;
    lay2 = 0;
    lay3 = 0;
    for(int i = 0; i <(pause1); i++) {
      seq1(lay0,lay1,lay2,lay3);
    }
    //frame 4
    lay0 = 0;
    lay1 = 0;
    lay2 = 1024;
    lay3 = 0;
    for(int i = 0; i <(pause1); i++) {
      seq1(lay0,lay1,lay2,lay3);
    }
    //frame 5
    lay0 = 0;
    lay1 = 0;
    lay2 = 64;
    lay3 = 0;
    for(int i = 0; i <(pause1); i++) {
      seq1(lay0,lay1,lay2,lay3);
    }
    //frame 6
    lay0 = 0;
    lay1 = 32;
    lay2 = 0;
    lay3 = 0;
    for(int i = 0; i <(pause1); i++) {
      seq1(lay0,lay1,lay2,lay3);
    }
    pause1 -= 10;
  }
  //making sun bigger - expands sun to 2x2x2 cube in middle, sun "twinkles" (turns off for short intervals each loop)
  pause1 = 100;
  for (int i = 0; i < 10; i++) {
    //frame 1
    lay0 = 0;
    lay1 = 1632;
    lay2 = 1632;
    lay3 = 0;
    for(int i = 0; i <(pause1); i++) {
      seq1(lay0,lay1,lay2,lay3);
    }
    //frame 2
    lay0 = 0;
    lay1 = 0;
    lay2 = 0;
    lay3 = 0;
    for(int i = 0; i <10; i++) {
      seq1(lay0,lay1,lay2,lay3);
    }
  }

  //adding first "planet", orbits on 3rd layer of cube
  //for loop must be used for each stage of "planet" orbit, to continue sun "twinkling"

  //2 orbits
  for (int i = 0; i < 2; i++) {
    //FRAME 1
    for (int i = 0; i < 2; i++) {
    //frame 1
    lay0 = 0;
    lay1 = 1632;
    lay2 = 5728;
    lay3 = 0;
    for(int i = 0; i <(pause1); i++) {
      seq1(lay0,lay1,lay2,lay3);
    }
    //frame 2
    lay0 = 0;
    lay1 = 0;
    lay2 = 4096;
    lay3 = 0;
    for(int i = 0; i <10; i++) {
      seq1(lay0,lay1,lay2,lay3);
    }
  }
  //FRAME 2
  for (int i = 0; i < 2; i++) {
    //frame 1
    lay0 = 0;
    lay1 = 1632;
    lay2 = 9824;
    lay3 = 0;
    for(int i = 0; i <(pause1); i++) {
      seq1(lay0,lay1,lay2,lay3);
    }
    //frame 2
    lay0 = 0;
    lay1 = 0;
    lay2 = 8192;
    lay3 = 0;
    for(int i = 0; i <10; i++) {
      seq1(lay0,lay1,lay2,lay3);
    }
  }
  //FRAME 3
  for (int i = 0; i < 2; i++) {
    //frame 1
    lay0 = 0;
    lay1 = 1632;
    lay2 = 18016;
    lay3 = 0;
    for(int i = 0; i <(pause1); i++) {
      seq1(lay0,lay1,lay2,lay3);
    }
    //frame 2
    lay0 = 0;
    lay1 = 0;
    lay2 = 16384;
    lay3 = 0;
    for(int i = 0; i <10; i++) {
      seq1(lay0,lay1,lay2,lay3);
    }
  }
  //FRAME 4
  for (int i = 0; i < 2; i++) {
    //frame 1
    lay0 = 0;
    lay1 = 1632;
    lay2 = 34400;
    lay3 = 0;
    for(int i = 0; i <(pause1); i++) {
      seq1(lay0,lay1,lay2,lay3);
    }
    //frame 2
    lay0 = 0;
    lay1 = 0;
    lay2 = 32768;
    lay3 = 0;
    for(int i = 0; i <10; i++) {
      seq1(lay0,lay1,lay2,lay3);
    }
  }
  //FRAME 5
  for (int i = 0; i < 2; i++) {
    //frame 1
    lay0 = 0;
    lay1 = 1632;
    lay2 = 3680;
    lay3 = 0;
    for(int i = 0; i <(pause1); i++) {
      seq1(lay0,lay1,lay2,lay3);
    }
    //frame 2
    lay0 = 0;
    lay1 = 0;
    lay2 = 2048;
    lay3 = 0;
    for(int i = 0; i <10; i++) {
      seq1(lay0,lay1,lay2,lay3);
    }
  }
  //FRAME 6
  for (int i = 0; i < 2; i++) {
    //frame 1
    lay0 = 0;
    lay1 = 1632;
    lay2 = 1760;
    lay3 = 0;
    for(int i = 0; i <(pause1); i++) {
      seq1(lay0,lay1,lay2,lay3);
    }
    //frame 2
    lay0 = 0;
    lay1 = 0;
    lay2 = 128;
    lay3 = 0;
    for(int i = 0; i <10; i++) {
      seq1(lay0,lay1,lay2,lay3);
    }
  }
  //FRAME 7
  for (int i = 0; i < 2; i++) {
    //frame 1
    lay0 = 0;
    lay1 = 1632;
    lay2 = 1640;
    lay3 = 0;
    for(int i = 0; i <(pause1); i++) {
      seq1(lay0,lay1,lay2,lay3);
    }
    //frame 2
    lay0 = 0;
    lay1 = 0;
    lay2 = 8;
    lay3 = 0;
    for(int i = 0; i <10; i++) {
      seq1(lay0,lay1,lay2,lay3);
    }
  }
  //FRAME 8
  for (int i = 0; i < 2; i++) {
    //frame 1
    lay0 = 0;
    lay1 = 1632;
    lay2 = 1636;
    lay3 = 0;
    for(int i = 0; i <(pause1); i++) {
      seq1(lay0,lay1,lay2,lay3);
    }
    //frame 2
    lay0 = 0;
    lay1 = 0;
    lay2 = 4;
    lay3 = 0;
    for(int i = 0; i <10; i++) {
      seq1(lay0,lay1,lay2,lay3);
    }
  }
  //FRAME 9
  for (int i = 0; i < 2; i++) {
    //frame 1
    lay0 = 0;
    lay1 = 1632;
    lay2 = 1634;
    lay3 = 0;
    for(int i = 0; i <(pause1); i++) {
      seq1(lay0,lay1,lay2,lay3);
    }
    //frame 2
    lay0 = 0;
    lay1 = 0;
    lay2 = 2;
    lay3 = 0;
    for(int i = 0; i <10; i++) {
      seq1(lay0,lay1,lay2,lay3);
    }
  }
  //FRAME 10
  for (int i = 0; i < 2; i++) {
    //frame 1
    lay0 = 0;
    lay1 = 1632;
    lay2 = 1633;
    lay3 = 0;
    for(int i = 0; i <(pause1); i++) {
      seq1(lay0,lay1,lay2,lay3);
    }
    //frame 2
    lay0 = 0;
    lay1 = 0;
    lay2 = 1;
    lay3 = 0;
    for(int i = 0; i <10; i++) {
      seq1(lay0,lay1,lay2,lay3);
    }
  }
  //FRAME 11
  for (int i = 0; i < 2; i++) {
    //frame 1
    lay0 = 0;
    lay1 = 1632;
    lay2 = 1648;
    lay3 = 0;
    for(int i = 0; i <(pause1); i++) {
      seq1(lay0,lay1,lay2,lay3);
    }
    //frame 2
    lay0 = 0;
    lay1 = 0;
    lay2 = 16;
    lay3 = 0;
    for(int i = 0; i <10; i++) {
      seq1(lay0,lay1,lay2,lay3);
    }
  }
  //FRAME 12
  for (int i = 0; i < 2; i++) {
    //frame 1
    lay0 = 0;
    lay1 = 1632;
    lay2 = 1888;
    lay3 = 0;
    for(int i = 0; i <(pause1); i++) {
      seq1(lay0,lay1,lay2,lay3);
    }
    //frame 2
    lay0 = 0;
    lay1 = 0;
    lay2 = 256;
    lay3 = 0;
    for(int i = 0; i <10; i++) {
      seq1(lay0,lay1,lay2,lay3);
    }
  }
  }

// adding second "planet"

//2 orbits
for (int i = 0; i < 4; i++) {
  //FRAME 1
    for (int i = 0; i < 2; i++) {
    //frame 1
    lay0 = 0;
    lay1 = 1632;
    lay2 = 5728;
    lay3 = 8;
    for(int i = 0; i <(pause1); i++) {
      seq1(lay0,lay1,lay2,lay3);
    }
    //frame 2
    lay0 = 0;
    lay1 = 0;
    lay2 = 4096;
    lay3 = 8;
    for(int i = 0; i <10; i++) {
      seq1(lay0,lay1,lay2,lay3);
    }
  }
  //FRAME 2
  for (int i = 0; i < 2; i++) {
    //frame 1
    lay0 = 0;
    lay1 = 1632;
    lay2 = 9828;
    lay3 = 0;
    for(int i = 0; i <(pause1); i++) {
      seq1(lay0,lay1,lay2,lay3);
    }
    //frame 2
    lay0 = 0;
    lay1 = 0;
    lay2 = 8196;
    lay3 = 0;
    for(int i = 0; i <10; i++) {
      seq1(lay0,lay1,lay2,lay3);
    }
  }
  //FRAME 3
  for (int i = 0; i < 2; i++) {
    //frame 1
    lay0 = 0;
    lay1 = 1634;
    lay2 = 18016;
    lay3 = 0;
    for(int i = 0; i <(pause1); i++) {
      seq1(lay0,lay1,lay2,lay3);
    }
    //frame 2
    lay0 = 0;
    lay1 = 2;
    lay2 = 16384;
    lay3 = 0;
    for(int i = 0; i <10; i++) {
      seq1(lay0,lay1,lay2,lay3);
    }
  }
  //FRAME 4
  for (int i = 0; i < 2; i++) {
    //frame 1
    lay0 = 1;
    lay1 = 1632;
    lay2 = 34400;
    lay3 = 0;
    for(int i = 0; i <(pause1); i++) {
      seq1(lay0,lay1,lay2,lay3);
    }
    //frame 2
    lay0 = 1;
    lay1 = 0;
    lay2 = 32768;
    lay3 = 0;
    for(int i = 0; i <10; i++) {
      seq1(lay0,lay1,lay2,lay3);
    }
  }
  //FRAME 5
  for (int i = 0; i < 2; i++) {
    //frame 1
    lay0 = 16;
    lay1 = 1632;
    lay2 = 3680;
    lay3 = 0;
    for(int i = 0; i <(pause1); i++) {
      seq1(lay0,lay1,lay2,lay3);
    }
    //frame 2
    lay0 = 16;
    lay1 = 0;
    lay2 = 2048;
    lay3 = 0;
    for(int i = 0; i <10; i++) {
      seq1(lay0,lay1,lay2,lay3);
    }
  }
  //FRAME 6
  for (int i = 0; i < 2; i++) {
    //frame 1
    lay0 = 256;
    lay1 = 1632;
    lay2 = 1760;
    lay3 = 0;
    for(int i = 0; i <(pause1); i++) {
      seq1(lay0,lay1,lay2,lay3);
    }
    //frame 2
    lay0 = 256;
    lay1 = 0;
    lay2 = 128;
    lay3 = 0;
    for(int i = 0; i <10; i++) {
      seq1(lay0,lay1,lay2,lay3);
    }
  }
  //FRAME 7
  for (int i = 0; i < 2; i++) {
    //frame 1
    lay0 = 4096;
    lay1 = 1632;
    lay2 = 1640;
    lay3 = 0;
    for(int i = 0; i <(pause1); i++) {
      seq1(lay0,lay1,lay2,lay3);
    }
    //frame 2
    lay0 = 4096;
    lay1 = 0;
    lay2 = 8;
    lay3 = 0;
    for(int i = 0; i <10; i++) {
      seq1(lay0,lay1,lay2,lay3);
    }
  }
  //FRAME 8
  for (int i = 0; i < 2; i++) {
    //frame 1
    lay0 = 0;
    lay1 = 9824;
    lay2 = 1636;
    lay3 = 0;
    for(int i = 0; i <(pause1); i++) {
      seq1(lay0,lay1,lay2,lay3);
    }
    //frame 2
    lay0 = 0;
    lay1 = 8192;
    lay2 = 4;
    lay3 = 0;
    for(int i = 0; i <10; i++) {
      seq1(lay0,lay1,lay2,lay3);
    }
  }
  //FRAME 9
  for (int i = 0; i < 2; i++) {
    //frame 1
    lay0 = 0;
    lay1 = 1632;
    lay2 = 18018;
    lay3 = 0;
    for(int i = 0; i <(pause1); i++) {
      seq1(lay0,lay1,lay2,lay3);
    }
    //frame 2
    lay0 = 0;
    lay1 = 0;
    lay2 = 16386;
    lay3 = 0;
    for(int i = 0; i <10; i++) {
      seq1(lay0,lay1,lay2,lay3);
    }
  }
  //FRAME 10
  for (int i = 0; i < 2; i++) {
    //frame 1
    lay0 = 0;
    lay1 = 1632;
    lay2 = 1633;
    lay3 = 32768;
    for(int i = 0; i <(pause1); i++) {
      seq1(lay0,lay1,lay2,lay3);
    }
    //frame 2
    lay0 = 0;
    lay1 = 0;
    lay2 = 1;
    lay3 = 32768;
    for(int i = 0; i <10; i++) {
      seq1(lay0,lay1,lay2,lay3);
    }
  }
  //FRAME 11
  for (int i = 0; i < 2; i++) {
    //frame 1
    lay0 = 0;
    lay1 = 1632;
    lay2 = 1648;
    lay3 = 2048;
    for(int i = 0; i <(pause1); i++) {
      seq1(lay0,lay1,lay2,lay3);
    }
    //frame 2
    lay0 = 0;
    lay1 = 0;
    lay2 = 16;
    lay3 = 2048;
    for(int i = 0; i <10; i++) {
      seq1(lay0,lay1,lay2,lay3);
    }
  }
  //FRAME 12
  for (int i = 0; i < 2; i++) {
    //frame 1
    lay0 = 0;
    lay1 = 1632;
    lay2 = 1888;
    lay3 = 128;
    for(int i = 0; i <(pause1); i++) {
      seq1(lay0,lay1,lay2,lay3);
    }
    //frame 2
    lay0 = 0;
    lay1 = 0;
    lay2 = 256;
    lay3 = 128;
    for(int i = 0; i <10; i++) {
      seq1(lay0,lay1,lay2,lay3);
    }
  }
  }

  //ending pattern, clearing leds
  //frame 1
  lay0 = 65535;
  lay1 = 1632;
  lay2 = 1888;
  lay3 = 128;
  for(int i = 0; i < pause1; i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 2
  lay0 = 65535;
  lay1 = 65535;
  lay2 = 1888;
  lay3 = 128;
  for(int i = 0; i < pause1; i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 3
  lay0 = 65535;
  lay1 = 65535;
  lay2 = 65535;
  lay3 = 128;
  for(int i = 0; i < pause1; i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 4
  lay0 = 65535;
  lay1 = 65535;
  lay2 = 65535;
  lay3 = 65535;
  for(int i = 0; i < pause1; i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 5
  lay0 = 0;
  lay1 = 65535;
  lay2 = 65535;
  lay3 = 65535;
  for(int i = 0; i < pause1; i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 6
  lay0 = 0;
  lay1 = 0;
  lay2 = 65535;
  lay3 = 65535;
  for(int i = 0; i < pause1; i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 7
  lay0 = 0;
  lay1 = 0;
  lay2 = 0;
  lay3 = 65535;
  for(int i = 0; i < pause1; i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  //frame 8
  lay0 = 0;
  lay1 = 0;
  lay2 = 0;
  lay3 = 0;
  for(int i = 0; i < pause1; i++) {
    seq1(lay0,lay1,lay2,lay3);
  }
  
}





void seq1(int L0,int L1,int L2,int L3) {
  digitalWrite(A4, LOW);
  digitalWrite(A5, LOW);
  LightITUp(L0);
  delay(delay1);
  LightITUp(0);
  digitalWrite(A4, LOW);
  digitalWrite(A5, HIGH);
  LightITUp(L1);
  delay(delay1);
  LightITUp(0);
  digitalWrite(A4, HIGH);
  digitalWrite(A5, LOW);
  LightITUp(L2);
  delay(delay1);
  LightITUp(0);
  digitalWrite(A4, HIGH);
  digitalWrite(A5, HIGH);
  LightITUp(L3);
  delay(delay1);
  LightITUp(0);
}
