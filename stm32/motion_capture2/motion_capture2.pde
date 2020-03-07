import JMyron.*;

JMyron picture;
int[][] globArray;

void setup() {
  size(640, 480);

  picture = new JMyron();
  picture.start(width, height);
  picture.findGlobs(1);
  picture.trackColor(155, 0, 0, 100);
}

void draw() {
  picture.update();
  int[] currFrame = picture.image();

  loadPixels();
  for (int i = 0; i < width*height; i++) 
    pixels[i] = currFrame[i];

  updatePixels();

  globArray = picture.globCenters(); //Get centers of wanted object

  int x = -1, y = -1;
  for(int i = 0; i < globArray.length; i++) {
    x = globArray[i][0];
    y = globArray[i][1];
    if (x > 0.001 || y > 0.001)  //Filter out unwanted centers
      setPosition(x, y);
  }
}

public void setPosition(int x, int y) {
  print("x:" + x + "y:" + y);
}
