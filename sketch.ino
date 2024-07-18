const int trigR = 2;
const int echoR = 3;

const int trigL = 4;
const int echoL = 5;

const int trigT = 7;
const int echoT = 6;

const int trigB = 8;
const int echoB = 9;

long t;
float dist, distR, distL, distT, distB;

void calc_dist(int trig, int echo){
  digitalWrite(trig, LOW);
  delayMicroseconds(5);
  digitalWrite(trig, HIGH);
  delayMicroseconds(5);
  digitalWrite(trig, LOW);
  t = pulseIn(echo, HIGH);
  dist = t / 58;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigR, OUTPUT);
  pinMode(echoR, INPUT);
  
  pinMode(trigL, OUTPUT);
  pinMode(echoL, INPUT);
  
  pinMode(trigT, OUTPUT);
  pinMode(echoT, INPUT);
  
  pinMode(trigB, OUTPUT);
  pinMode(echoB, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  calc_dist(trigR, echoR);
  distR = dist;

  calc_dist(trigL, echoL);
  distL = dist;

  calc_dist(trigT, echoT);
  distT = dist;

  calc_dist(trigB, echoB);
  distB = dist;

  if(distR <= 30 && distL <= 30 && distT <= 30 && distB <= 30){
    Serial.println("Stop");
  }
  else if(distR <= 30 && distL <= 30 && distT > 30 && distB > 30){
    Serial.println("Play/Pause");
  }
  else if(distR > 30 && distL > 30 && distT <= 30 && distB > 30){
    Serial.println("Volume Up");
  }
  else if(distR > 30 && distL > 30 && distT > 30 && distB <= 30){
    Serial.println("Volume Down");
  }
  else if(distR <= 30 && distL > 30 && distT > 30 && distB > 30){
    delay(1000);
    if(distR > 30 && distL <= 30 && distT > 30 && distB > 30){
      Serial.println("Backward");
    }
    else{
      Serial.println("Next");
    }
  }
  else if(distR > 30 && distL <= 30 && distT > 30 && distB > 30){
    delay(1000);
    if(distR <= 30 && distL > 30 && distT > 30 && distB > 30){
      Serial.println("Forward");
    }
    else{
      Serial.println("Previous");
    }
  }
  delay(2000);
}
