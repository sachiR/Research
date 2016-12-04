import processing.sound.*;

AudioIn input;
Amplitude analyzer;
// TIME
float t = 0.0;
int xPos = 1;         // horizontal position of the graph
float inByte = 0;

void setup() {
  //create the window
  size(900, 600);
  smooth();

  // Start listening to the microphone
  // Create an Audio input and grab the 1st channel
  input = new AudioIn(this, 0);

  // start the Audio Input
  input.start();

  // create a new Amplitude analyzer
  analyzer = new Amplitude(this);

  // Patch the input to an volume analyzer
  analyzer.input(input);
}

void draw() {
  background(255);
  // Get the overall volume (between 0 and 1.0)
  float vol = analyzer.analyze();
  
  float xoff = t;
  noFill();
  stroke(0);
  strokeWeight(2);
  beginShape();
  for (int i = 0; i < width; i++) {
    float y = noise(xoff)*height;
    xoff += 0.01;
    vertex(i,y); 
  }
  endShape();
  t+= 0.01;
}