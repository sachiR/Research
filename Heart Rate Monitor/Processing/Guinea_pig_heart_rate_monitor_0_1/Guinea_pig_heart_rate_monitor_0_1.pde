import processing.serial.*;

void setup(){
  size(700, 600);
  colorMode(HSB, 100);
  //variables
  color c1 = color(#504C8B);
  color c2 = color(#000000);
  
  for (int i = 0; i < height; i++){
   float n =  map(i, 0, height, 0, 1);
   color newc = lerpColor(c1, c2, n);
   stroke(newc);
   line(0, i, width, i);
  }
}