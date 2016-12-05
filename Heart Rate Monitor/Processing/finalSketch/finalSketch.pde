import processing.sound.*;
AudioIn input;
int val;
int [] x = new int[500];
int [] y = new int[500];


void setup() {
  frameRate(50);                   //20msec
  size(600, 350);
  textSize(20);
 
  for (int i = 0; i < x.length; i++){
    x[i] = i;
    y[i] = 128;
  }  
}

void draw(){ 
  background(0);
 
 for (int i = 0; i < y.length - 1; i++){
   y[i] = y[i+1];
 }
 y[y.length - 1] = val;
    
       fill(255);
       text("BPM "+ 80 ,490,330);
 
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