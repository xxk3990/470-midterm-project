import processing.serial.*;

Serial port;

int controller; //if controller below a value, display "bad images" 

ArrayList<PImage> imgList = new ArrayList<PImage>();

void setup(){
  size(600,400);
  
   String portName = Serial.list()[0];
   
   port = new Serial(this, portName, 9600);
 
   port.clear();
   port.bufferUntil('\n');
   
   imgList.add(loadImage("./../quarantine_positive_Image1.png"));
   imgList.add(loadImage("./../quarantine_negative_image1.jpg"));
}

void draw(){
  background(0);
  
  if(controller < 20){
    image(imgList.get(1), 0, 0, 600, 400);
  }
  else{
   image(imgList.get(0),0,0, 600, 400); 
  }
  
}

void serialEvent(Serial port){
 
 String inputString = port.readString();
 inputString = trim(inputString);
 println("Input:" + inputString);
 controller = int(inputString);
 println("Controller:" + controller);
}
