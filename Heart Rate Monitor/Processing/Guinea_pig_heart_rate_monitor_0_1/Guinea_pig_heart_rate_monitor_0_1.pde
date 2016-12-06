import processing.sound.*;

AudioIn input;
Amplitude amp;

int bands = 512;
float[] spectrum = new float[bands];
float val;
float [] x = new float[500];
float [] y = new float[500];
int BPM;

void setup() {
  //create the window
  size(600, 350);
  textSize(20);
  
  // Create an Input stream which is routed into the Amplitude analyzer
  amp = new Amplitude(this);
  input = new AudioIn(this,0);
  
  // start the Audio Input
  input.start();
  
  amp.input(input);
  
  // Patch the input to an volume analyzer
  for (int i = 0; i < x.length; i++){
    x[i] = i;
    y[i] = 128;
  }  
}

void draw(){ 
  background(0);
  float ampAnalyzer =amp.analyze();
  println("amplitute = " + ampAnalyzer);
  val = ampAnalyzer * 1700;
  println("value = " + ampAnalyzer);
  println("--------------------");
 
  for (int i = 0; i < y.length - 1; i++){
    y[i] = y[i+1];
  }
  y[y.length - 1] = val;
  
  //BPM
  fill(255);
  text("BPM " + BPM ,490,330);
 
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