#include  "main.h"

//HELPER FUNCTIONS
void setDrive();
void resetDriveEncoders();
void resetQuadEncoders();
double avgDriveEncoderValue();
float avgQuadEncoderValue();
void initializeIMU();
int get_quad(double angle);
//void printheading();

//Driver CONTROL FUNCTION
void driverControl();
void constantDrive();

//AUTONOMOUS FUNCTIONS
void translate(int units, int voltage);
void translate2(int units, int voltage, bool correction);
void rotate(int degrees, int voltage);
