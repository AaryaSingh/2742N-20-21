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
// void strafeControl();

//AUTONOMOUS FUNCTIONS
void ctranslate(double units, int voltage, int heading);
void translate2(int units, int voltage, bool correction);
void stranslate(int units, int voltage, bool correction);
void rotate(int degrees, int voltage);
