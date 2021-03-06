#include  "main.h"

//HELPER FUNCTIONS
void setDrive(int left, int right);
void setStrafe(int voltage);
void resetDriveEncoders();
void resetQuadEncoders();
double avgDriveEncoderValue();
float avgQuadEncoderValue();
void initializeIMU();
int get_quad(double angle);
//void printheading();

//Driver CONTROL FUNCTION
void driveControl();
void arrows();
// void strafeControl();

//AUTONOMOUS FUNCTIONS
void dtranslate(int units, int voltage, bool correction);
void ctranslate(double units, int voltage, int heading, int cf);
void translate2(int units, int voltage, bool correction);
void stranslate(int units, int voltage, bool correction);
void rotate(int degrees, int voltage);
