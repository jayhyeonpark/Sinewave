#include <stdio.h>
#include <math.h>

int F = 2;                                                   //frequency of the signal
int Fs = 500;                                                //sampling frequency
int n = 500;                                                 //number of samples
float t;                                                     //Time instance
int sampling_interval;
//byte samples[500];                                           // to store the samples
short samples[500];                                           // to store the samples

void setup() {

  //pinMode(13, OUTPUT);
  for (int n = 0; n < 500; n++)
  {
    t = (float) n / Fs;                                       //creating time isntance to find the 500 samples
    //samples[n] = (byte) (127.0 * sin(2 * 3.14 * t) + 127.0 ); //calculating the sin value at each time instance
    samples[n] = (short) (127.0 * sin(2 * 3.14 * t) + 127.0 ); //calculating the sin value at each time instance
  }
  sampling_interval = 1000000 / (F * n);                      
  //sampling interval Ts = 1/frequency x number of sample (Ts = 1/Fn or Ts = T/n)x1000000 to convert it in µS
}

//void loop() {
int main() {
  setup();
  for (int j = 0; j < 500; j++) {
    printf("| %d ",samples[j]);
    //analogWrite(13, samples[j]);
    //delayMicroseconds(sampling_interval);                      //time interval
  }
  printf("| \n");
}
