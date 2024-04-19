
 
void setup() {
  Serial.begin(9600);

}
 
void loop() {
  int value = analogRead(A0);
  Serial.println(value);
  if (value > 950) {
    
  } else {
    
  }
 
  if (value < 300) {
    
  } else if (value > 300 && value < 950) {
  
  } else if (value > 950) {
    
}