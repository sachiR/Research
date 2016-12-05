import processing.serial.*;
 
Serial myPort;
int val;
int [] x = new int[500];
int [] y = new int[500];
 
void setup() 
{
  frameRate(50);                   //20msec
  size(600, 350);
  myPort = new Serial(this, "COM3", 9600);
  textSize(20);
 
  for (int i = 0; i < x.length; i++){
    x[i] = i;
    y[i] = 128;
  }  
}
 
void draw()
{
    background(0);
 

    for (int i = 0; i < y.length - 1; i++){
      y[i] = y[i+1];
    }
    y[y.length - 1] = val;
 

    fill(255);
    text("0V",10,310);
    text("5V",10,54);
    text("0sec",530,340);
    text("-10sec",30,340);
    fill(0,255,0);
    text(val/255.0*5,560,100);
     

    pushMatrix();
    translate(50,300);
    scale(1,-1);
    fill(0);
    stroke(255);
    rect(0,0,500,256);
    stroke(0,255,0);
    for (int i = 0; i < x.length - 1; i++){
      line(x[i],y[i],x[i+1],y[i+1]);
    }
    popMatrix();
}
 
void serialEvent(Serial myPort){
  delay(10);
  val = myPort.read();
}