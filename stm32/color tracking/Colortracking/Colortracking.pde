/*
Simple color detection using web cam data!!!
 */
//===================Inlcudes========================
import processing.serial.*;
import JMyron.*;// import JMyron d
//===================EndInlcudes=====================

//===================Objects========================
JMyron m; // create JMyorn objekt "m"
Serial s; //serial object
//===================ENd Objects====================

void setup()
{
  // app size
  size(640, 480); 
  m = new JMyron();  //new Jmyron
  s = new Serial(this, "COM4", 9600);
  m.start(640, 480);  //screen size
  m.findGlobs(1);    //turn on inteligence
}
void mousePressed()
{
  m.settings(); //tune up camera settings
}
void draw()
{
  m.trackColor(0, 250, 20, 215); //find  SOME color on camera frames

  m.update(); //update camera

  int[] img = m.image(); //get the normal image of the camera

  //first draw the camera view onto the screen
  loadPixels();
  //fill array of all pixels -> depending on the APP size create array of pixel of that size
  
  for (int i=0; i<width*height; i++)
  {
    pixels[i] = img[i]; // array of 640*480 pixels
  }
  updatePixels(); // refresh app with new frame

  noFill();//Disables filling geometry


  //initiate a two dimensional array that will hold the glob start point
  int[][] a; // a[0] -> [value 1] [value 2]
             // a[1] -> [value 1] [value 2]
             //.....

  //draw bounding boxes of globs
  //a = m.globBoxes();
  //
  a = m.globCenters(); //globe centers returns a list of center points for each glob. 
                       //or list of all regions that match the glob pattern given with the trackColor
                       //pattern matching algorithm aplied match pixel colour values by analyzing their neighbours and previous values
 
  
  stroke(255, 255, 0);
  for (int i=0; i<a.length; i++) // get all globe centers
  
  {
    int[] b = a[0]; // but use only the first one found

    strokeWeight(10);
    textSize(25);
    fill(0, 0, 0);
    
    text("X =" + b[0], 50, 50); // print X value of matching object
    text("Y =" + b[1], 50, 80); // print Y value of matching object
    
    ellipse(b[0], b[1], 55, 55); // draw a ellipse around it
  
    point(b[0], b[1]); // draw a point in the center of matching object
    
    fill(255, 255, 255);
    
     text("Green Death", b[0]-30,b[1] - 30);
    s.write(b[0]); // Send X position data to serila port
    //rect(b[0], b[1], b[2], b[3]);
  }
}

public void stop() {
  m.stop();
  super.stop();
}
