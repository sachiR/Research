import processing.sound.*;
import ddf.minim.*;
import ddf.minim.analysis.*;

AudioInput input;
Amplitude analyzer;
Minim minim;
BeatDetect beat;

float val;
float [] x = new float[500];
float [] y = new float[500];
float rad = 70;
int  r = 200;

void setup() {
  //create the window
  //frameRate(50);                   //20msec
  size(600, 350);
  textSize(20);
  
  minim = new Minim(this);
  
  // Start listening to the microphone
  // Create an Audio input and grab the 1st channel
  //input = new AudioIn(this);
  // start the Audio Input
  //input.start();
  input = minim.getLineIn();
  
  // a beat detection object song SOUND_ENERGY mode with a sensitivity of 10 milliseconds
  beat = new BeatDetect();
  
  // create a new Amplitude analyzer
  //analyzer = new Amplitude(this);
  
  // Patch the input to an volume analyzer
  //analyzer.input(input);
  
  for (int i = 0; i < x.length; i++){
    x[i] = i;
    y[i] = 128;
  }  
}

void draw(){ 
  background(0);
  beat.detect(input.mix);
  
 
  for (int i = 0; i < y.length - 1; i++){
    y[i] = y[i+1];
  }
  y[y.length - 1] = val;
  
  val = input.bufferSize();
  
  //BPM
  fill(255);
  text("BPM " ,490,330);
 
  pushMatrix();
  translate(50,300);
  scale(1,-1);
  fill(0);
  stroke(255);
  rect(0,0,500,256);
  stroke(0,255,0);
    
  //the graph 
  for (int i = 0; i < x.length - 1; i++){
    line(x[i],y[i],x[i+1],y[i+1]);
  }
    
  popMatrix();
}