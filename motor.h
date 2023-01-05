
//motors as output, relays as output
void initMotors();

void homeAxis();

void moveMotor(char id, char direction);
void stopMotor(char id);

void moveXTo(char p);

void moveYTo(char p);

void moveZUp();
void moveZDown();