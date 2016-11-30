import ddf.minim.*;
import ddf.minim.signals.*;
import ddf.minim.analysis.*;
import ddf.minim.effects.*; //Import ddf.minim library
import processing.serial.*; //Import serial library
import cc.arduino.*; //Import Arduino library

Arduino arduino; 
Minim minim;
AudioPlayer song;
FFT fft;
//I create the objects

//To play another song change the song_file value
String song_file = "song.mp3"; 
int xmax = 600; //window width
int ymax = 300;//window height

void setup()
{
  size(xmax, ymax);
  minim = new Minim(this);
  arduino = new Arduino(this, Arduino.list()[1], 57600);
  song = minim.loadFile(song_file);
  song.play();
  fft = new FFT(song.bufferSize(), song.sampleRate());
  // in this function I create the minim object, I start 
  //communicating with Arduino,I load the song and I play it and 
  // I start the Fast Fourier Transofrm
}

void draw()
{
  background(0);
  fft.forward(song.mix);
  stroke(127, 255, 0, 200); //I set the color of my lines
  for(int i = 10; i < fft.specSize(); i++){
    line(i, height-30, i, height - (30+fft.getFreq(i*10)));
    // I create lines that represent the amplitude
    // of each frequency.
    text("Min Freq", 10, height-10);
    text("Max Freq", fft.specSize(), height-10);
  }
  ledcontrol(); //I call the function for the arduino
}

void ledcontrol(){
  //In this function I use arduino analogWrite function
  // to write in PWM pins the amplitude 
  // of five general frequency
  arduino.analogWrite(3, int(fft.getFreq(500)));
  arduino.analogWrite(5, int(fft.getFreq(400)));
  arduino.analogWrite(6, int(fft.getFreq(250)));
  arduino.analogWrite(9, int(fft.getFreq(150)));
  arduino.analogWrite(10, int(fft.getFreq(80)));
  }