import controlP5.*;
import processing.serial.*;

String val;     // Data received from the serial port
String inString;

Serial port;
ControlP5 cp5;
PImage bg;

void setup(){
  size(780,460);
  cp5 = new ControlP5(this);
  
  cp5.addButton("Carre").setPosition(50,20).setSize(100,100);
  cp5.addButton("Circle").setPosition(151,20).setSize(100,100);
  try{port = new Serial(this, "/dev/ttyACM0", 9600);}
  catch(Exception e){println("No port available");}
  port.bufferUntil(10);

  bg = loadImage("JuniaISEN.jpg");
}

void draw(){
  background(bg);
  //text("Direction souhaitée",1080,171);
  text("received: "+ inString,300,10);
  fill(color(255,255,255));
  square(100,300,50);
  square(50,350,50);square(100,350,50);square(150,350,50);
  square(100,400,50);
  if (keyPressed){
    fill(color(50,55,100));
    if(key == 'z'){
      port.write('z');
      circle(75,375,40);
    }
    if(key == 's'){
      port.write('s');
      circle(175,375,40);
    }
    if(key == 'q'){
      port.write('q');
      circle(125,425,40);
    }
    if(key == 'd'){
      port.write('d');
      circle(125,325,40);
    }
  }

}

void Carre(){port.write('c');}
void Circle(){port.write('o');}

void keyReleased(){
  port.write('x');
}

void serialEvent(Serial p)
{
  inString = p.readString();  
}
