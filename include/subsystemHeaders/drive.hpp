#include  "main.h"

//HELPER FUNCTIONS
void setDrive();
void resetDriveEncoders();
void resetQuadEncoders();
double avgDriveEncoderValue();
float avgQuadEncoderValue();
void initializeIMU();
//void printheading();

//Driver CONTROL FUNCTION
void driverControl();
void constantDrive();

//AUTONOMOUS FUNCTIONS
void translate(int units, int voltage);
void translate2(int units, int voltage);
void rotate(int degrees, int voltage);
