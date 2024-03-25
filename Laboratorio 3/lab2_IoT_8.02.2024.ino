
/*
void setup()
{
pinMode(2, OUTPUT);
}
void loop()
{
digitalWrite(2,HIGH);
delay(2500);
digitalWrite(2,LOW);
delay(2500);
}
*/

/*
#ifdef __cplusplus
extern "C" {
#endif
uint8_t temprature_sens_read();
#ifdef __cplusplus
}
#endif
uint8_t temprature_sens_read();
void setup()
{
pinMode(2, OUTPUT);
Serial.begin(9600);
}
void loop()
{
digitalWrite(2,HIGH);
Serial.println("Led prendido");
delay(2500);
digitalWrite(2,LOW);
Serial.println("Led apagado");
delay(2500);
Serial.println("la temperatura interna del ESP32 es: ");
Serial.println(((temprature_sens_read() - 32 ) / 1.8));
Serial.println("");
}
*/

/*
#include <WiFi.h>
WiFiServer server(80);
WiFiClient client;
#ifdef __cplusplus
extern "C" {
#endif
uint8_t temprature_sens_read();
#ifdef __cplusplus
}
#endif
uint8_t temprature_sens_read();
void setup()
{
Serial.begin(9600);
WiFi.disconnect();
delay(3000);
Serial.println("Iniciando");
WiFi.begin("IoT","1t3s0IoT23");
while ((!(WiFi.status() == WL_CONNECTED))){
Serial.print("......");
delay(300);
}
Serial.println("Conexion establecida con el SSDI!");
Serial.println((WiFi.localIP()));
server.begin();
}

void loop()
{
client = server.available();
if (!client) { return; }
while(!client.available()){ delay(1); }
client.flush();
client.println("HTTP/1.1 200 OK");
client.println("Content-Type: text/html");
client.println("");
client.println("<!DOCTYPE HTML>");
client.println("<html>");
client.println("<head>");
client.println("<title> ""MiESP32"" </title>");
client.println("</head>");
client.println("<body>");
client.println("<h1 style=""color:#3366ff"">");
client.println("");
client.println("</h1>");
client.println("<span style=""color:#33cc00;font-size:14px"">");
client.println("Bienvenidos a mi pagina web");
client.println("</span>");
client.println("<br>");
client.println("<span style=""color:#cc6600;font-size:14px"">");
client.println("Esta pagina web ha estado activa por");
client.println("</span>");
client.println("<span style=""color:#009900;font-size:20px"">");
client.println((millis()/1000));
client.println("</span>");
client.println("<span style=""color:#cc6600;font-size:14px"">");
client.println("segundos");
client.println("</span>");
client.println("<br>");
client.println("<span style=""color:#ffcc33;font-size:14px"">");
client.println("La temperatura interna del ES32 es de:");
client.println("</span>");
client.println("<span style=""color:#000000;font-size:14px"">");
client.println(((temprature_sens_read() - 32 ) / 1.8));
client.println("</span>");
client.println("<span style=""color:#ffcc33;font-size:14px"">");
client.println("grados");
client.println("</span>");
client.println("</body>");
client.println("</html>");
delay(1);
}
*/

/*
#include <WiFi.h>
#include <WiFiClient.h>
const char* ssid = "INFINITUM8C42";
const char* password = "R23AJMS5dG";
WiFiServer server(80);
//Se tiene un LED incorporado en terminal 2, se puede usar

#define LED 2
String estado = "";
void setup() {
Serial.begin(9600);
pinMode(LED, OUTPUT);
digitalWrite(LED, LOW);
// Conectando a WiFi
WiFi.begin(ssid, password);
// Checa si esta conectado
while (WiFi.status() != WL_CONNECTED) {
delay(1000);
Serial.print(".");
}
Serial.println("");
Serial.println("WiFi conectado");
Serial.print("La dirección IP es: ");
Serial.println(WiFi.localIP()); //Muestra IP
// Inicio del Servidor web.
server.begin();
Serial.println("Servidor web iniciado.");
}

void loop() {
// Consulta si se ha conectado algún cliente.
WiFiClient client = server.available();
if (!client) {
return;
}
Serial.print("Nuevo cliente: ");
Serial.println(client.remoteIP());
// Espera hasta que el cliente envíe datos.
while(!client.available()){ delay(1); }
/////////////////////////////////////////////////////
// Lee la información enviada por el cliente.
String req = client.readStringUntil('\r');
Serial.println(req);
// Realiza la petición del cliente.
if (req.indexOf("on2") != -1) {digitalWrite(LED, HIGH);
estado = "Encendido";}
if (req.indexOf("off2") != -1){digitalWrite(LED, LOW);
estado = "Apagado";}
//////////////////////////////////////////////

// Página WEB. ////////////////////////////
client.println("HTTP/1.1 200 OK");
client.println("Content-Type: text/html");
client.println(""); // Importante.
client.println("<!DOCTYPE HTML>");
client.println("<html>");
client.println("<head><meta charset=utf-8></head>");client.println("<body><center><font face='Arial'>");
client.println("<h1>Servidor web con ESP32.</h1>");
client.println("<h1>Cesar Hurtado</h1>");
client.println("<h2><font color='#009900'>Webserver 1.0</font></h2>");client.println("<h3>Práctica boton</h3>");
client.println("<br><br>");
client.println("<a href='on2'><button>Enciende LED</button></a>");client.println("<a href='off2'><button>Apaga LED</button></a>");client.println("<br><br>");
client.println(estado);
client.println("</font></center></body></html>");
Serial.print("Cliente desconectado: ");
Serial.println(client.remoteIP());
client.flush();
client.stop();
}
*/
/*
#include <WiFi.h>
#include <WiFiClient.h>
const char* ssid = "IoT";
const char* password = "1t3s0IoT23";
WiFiServer server(80);
//Usar el pin 15 GPIO
#define LED 15
String estado = "";
void setup() {
Serial.begin(9600);
pinMode(LED, OUTPUT);
digitalWrite(LED, LOW);
// Conectando a WiFi
WiFi.begin(ssid, password);
// Checa si esta conectado
while (WiFi.status() != WL_CONNECTED) {
delay(1000);
Serial.print(".");
}
Serial.println("");
Serial.println("WiFi conectado");
Serial.print("La dirección IP es: ");
Serial.println(WiFi.localIP()); //Muestra IP
// Inicio del Servidor web.
server.begin();
Serial.println("Servidor web iniciado.");
}

void loop() {
// Consulta si se ha conectado algún cliente.
WiFiClient client = server.available();
if (!client) {
return;
}
Serial.print("Nuevo cliente: ");
Serial.println(client.remoteIP());
// Espera hasta que el cliente envíe datos.
while(!client.available()){ delay(1); }
/////////////////////////////////////////////////////
// Lee la información enviada por el cliente.
String req = client.readStringUntil('\r');
Serial.println(req);
// Realiza la petición del cliente.
if (req.indexOf("on2") != -1) {digitalWrite(LED, HIGH);
estado = "Encendido";}
if (req.indexOf("off2") != -1){digitalWrite(LED, LOW);
estado = "Apagado";}
//////////////////////////////////////////////

 //Página WEB. ////////////////////////////
client.println("HTTP/1.1 200 OK");
client.println("Content-Type: text/html");
client.println(""); // Importante.
client.println("<!DOCTYPE HTML>");
client.println("<html>");
client.println("<head><meta charset=utf-8></head>");
client.println("<body><center><font face='Arial'>");
client.println("<h1>Servidor web con ESP32.</h1>");
client.println("<h1>Cesar_Hurtado</h1>");
client.println("<h2><font color='#009900'>Webserver 1.0</font></h2>");
client.println("<h3>Práctica boton</h3>");
client.println("<br><br>");
client.println("<a href='on2'><button>Enciende LED</button></a>");
client.println("<a href='off2'><button>Apaga LED</button></a>");
client.println("<br><br>");
client.println(estado);
client.println("</font></center></body></html>");
Serial.print("Cliente desconectado: ");
Serial.println(client.remoteIP());
client.flush();
client.stop();
}
*/


/*// Practica 3*/

/*// Practica 3.2*/

/*
#include "DHT.h"
DHT dht15(15,DHT11);
void setup()
{
Serial.begin(9600);
delay(2000); //agregar al código de easycoding.tn
dht15.begin(); //agregar al código de easycoding.tn
}
void loop()
{
Serial.println("Temperatura en el sensor");
Serial.println((dht15.readTemperature( )));
Serial.println("Humedad en el sensor");
Serial.println((dht15.readHumidity()));
delay(5000);
}
*/

/*//7 Practica 3.3*/


/*
//Mi medidor de “Cesar Hurtado878/”
const int trigPin = 5;
const int echoPin = 18;
//define sound speed in cm/uS
#define SOUND_SPEED 0.034
#define CM_TO_INCH 0.393701
long duration;
float distanceCm;
float distanceInch;
void setup() {
Serial.begin(115200); // Starts the serial communication
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
}

void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculate the distance
distanceCm = duration * SOUND_SPEED/2;
// Convert to inches
distanceInch = distanceCm * CM_TO_INCH;
// Prints the distance in the Serial Monitor
Serial.print("Distance (cm): ");
Serial.println(distanceCm);
Serial.print("Distance (inch): ");
Serial.println(distanceInch);
delay(1000);
}
*/

/*

/*
/****************************************
* Include Libraries
****************************************/
////#include "Ubidots.h"
/****************************************
* Define Instances and Constants
****************************************/
/*
const char* UBIDOTS_TOKEN = "BBUS-YQwxpawoYyNkdTdxhRKsJ3npeNUewB"; // Put here your Ubidots TOKEN
const char* UBIDOTS_DEVICELABEL = "practicona4"; // Device label to use
const char* WIFI_SSID = "INFINITUMAFAF_EXT1"; // Put here your Wi-Fi SSID
const char* WIFI_PASS = "Dbq3x7eXCj"; // Put here your Wi-Fi password
Ubidots ubidots(UBIDOTS_TOKEN, UBI_HTTP);
// Ubidots ubidots(UBIDOTS_TOKEN, UBI_TCP); // Uncomment to use TCP
// Ubidots ubidots(UBIDOTS_TOKEN, UBI_UDP); // Uncomment to use UDP
// Space to store values to send
char str_temp[10];
char str_hum[10];
#include "DHT.h"
#define pin1 15
DHT dht1(pin1, DHT11); //El sensor de temp y humedad azul.
/****************************************
* Main Functions
****************************************/
/*
void setup() {
Serial.begin(115200);
ubidots.wifiConnect(WIFI_SSID, WIFI_PASS);
// ubidots.setDebug(true); // Uncomment this line for printing debug messages
// Sensor de temp y humedad
dht1.begin();
}
void loop() {
float t1 = dht1.readTemperature();
float h1 = dht1.readHumidity();
Serial.print(" 1. La temperatura detectada en el sensor es de: ");
Serial.println(t1); // Imprime temperatura en el serial monitor
Serial.print(" 2. La humedad detectada por el sensor es de: ");
Serial.println(h1); // Imprime la humedad en el monitor serial
Serial.println(" Enviando Temperatura al disp virtual en ubidots via HTTP....");
ubidots.add("temperatura", t1); // Change for your variable name
Serial.println(" Enviando Humedad al dispositivo virtual en ubidots via HTTP....");
ubidots.add("humedad", h1);
bool bufferSent = false;
bufferSent = ubidots.send(UBIDOTS_DEVICELABEL); // Will send data to a device label that matches the device Id
if (bufferSent) {
// Do something if values were sent properly
Serial.println("Valores enviados al dispositivo en ubidots");
}
Serial.println("Esperare unos segundos para volver a leer y enviar....");
Serial.println(".....................................................");
delay(8000);
}
*/


/*
// Practica 5

#include <WiFi.h>
#include "ThingSpeak.h" // always include thingspeak header file
// your network SSID (name)
const char* ssid = "IoT";
// your network password
const char* pass = "1t3s0IoT23";
WiFiClient client;
unsigned long myChannelNumber = 2481172; //SECRET_CH_ID;
const char* myWriteAPIKey = "3P44DCK7AD25DWFE";
// Initialize with random values
int number1 = random(0,50);
int number2 = random(0,50);
String myStatus = "";
void setup() {
Serial.begin(115200);
WiFi.begin(ssid, pass);
Serial.println();
Serial.print("Wait for WiFi...");
while (WiFi.status() != WL_CONNECTED) {
Serial.print(".");
delay(500);
}
Serial.println("");
Serial.println("WiFi Connected");
Serial.println("IP address: ");
Serial.println(WiFi.localIP());
ThingSpeak.begin(client); // Initialize ThingSpeak
}

void loop() {
// set the fields with the values
ThingSpeak.setField(1, number1);
ThingSpeak.setField(2, number2);
// figure out the status message for multi fields
if(number1 > number2){
myStatus = String("field1 is greater than field2");
}
else if(number1 < number2){
myStatus = String("field1 is less than field2");
}
else{
myStatus = String("field1 equals field2");
}
// set the status
ThingSpeak.setStatus(myStatus);
// write to the ThingSpeak channel
int x = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
if(x == 200){
Serial.println("ThingSpeak Channel update successful.");
}
else{
Serial.println("Problem updating channel. HTTP error code " + String(x));
}
// change the values
number1++;
if(number1 > 99){
number1 = 0;
}
number2 = random(0,100);
delay(20000); // Wait 20 seconds to update the channel again
}

*/




// Practica 5.2
#include <DHT.h>
#include <HTTPClient.h>
#include <ThingSpeak.h>
#include <WiFi.h>
// Temperature Data from sensors
struct TemperatureData
{
float dht;
// in Celsius
String getAllTemperatureData(){
return "\nDHT: " + (String)dht + "*C";
}
};
// dht11
const uint8_t dhtPin = 15; // Pin que usaras para el sensor de temp
const uint8_t dhtType = DHT11;
DHT dht(dhtPin, dhtType);
// data
TemperatureData temperatureData;
// timer
uint32_t startMillis;
const uint16_t timerDuration = 10000;
// wifi credentials
const char *ssid = "INFINITUMAFAF_EXT1"; // Tu SSID
const char *password = "Dbq3x7eXCj"; // Tu PWD del SSID
WiFiClient client;
// OpenWeather
String apiTemperature;
String serverPath = "https://api.openweathermap.org/data/2.5/weather?lat=20.6024&lon=-103.2714&appid=68c7c35f89fbfe4ec00ecace070c6e68&units=metric"; //El path que usaste en el web para la tem de la API - TODO el path con http
// ThingSpeak
uint32_t channelNumber = 2481172; // Tu channel ID number de thingspeak
const char *writeAPIKey = "3P44DCK7AD25DWFE"; // El API write de thingspeak
void setup()
{
Serial.begin(115200);
dht.begin();
ThingSpeak.begin(client); // Initialize ThingSpeak client
connectWiFi();
// start timer
startMillis = millis();
}
void loop()
{
if (millis() >= timerDuration + startMillis)
{
// get sensors readings
temperatureData.dht = getDHTTemperatureC();
// get API temp
apiTemperature = getTemperatureFromAPI();
// debug on serial monitor
Serial.println(temperatureData.getAllTemperatureData());
Serial.println("Temperatura de la API: " + apiTemperature + "*C");
delay(50);
sendDataToThingSpeak();
// restart
startMillis = millis();
}
}
// Helper functions
void connectWiFi(){
Serial.begin(115200);
WiFi.begin(ssid, password);
Serial.println();
Serial.print("Wait for WiFi...");
while (WiFi.status() != WL_CONNECTED) {
Serial.print(".");
delay(500);
}
Serial.println("");
Serial.println("WiFi Connected");
Serial.println("IP address: ");
Serial.println(WiFi.localIP());
}
void sendDataToThingSpeak(){
// Check connection or reconnect to WiFi
if (WiFi.status() != WL_CONNECTED)
{
Serial.println("No se detectó conexion a Internet");
connectWiFi();
}
// first set the fields
ThingSpeak.setField(1, temperatureData.dht);
ThingSpeak.setField(2, apiTemperature);
// set a status message based on any logic
float indoorTempAverage = temperatureData.dht;
float outdoorTemp = apiTemperature.toFloat();
String status;
if (indoorTempAverage > 30)
status = "Temperatura Relativamente Alta";
else if (indoorTempAverage <= 30 && indoorTempAverage >= 20)
status = "Temperatura Normal";
else if (indoorTempAverage < 20)
status = "Temperatura Relativamente Baja";
// set status
ThingSpeak.setStatus(status);
// write to the ThingSpeak Channel
int code = ThingSpeak.writeFields(channelNumber, writeAPIKey);
if(code == 200)
Serial.println("Canal de Thingspeak actualizado correctamente.");
else
Serial.println("Hubo un problema actualizando el canal. Error HTTP: " + String(code));
}
float getDHTTemperatureC(){
float t = dht.readTemperature(false);
if (isnan(t)){
t = 0;
Serial.println("Lectura fallida del sensor DHT");
}
return t;
}
String getTemperatureFromAPI()
{
// Check connection or reconnect to WiFi
if (WiFi.status() != WL_CONNECTED)
{
Serial.println("No se detecto conexion a Internet");
connectWiFi();
}
HTTPClient http;
// Domain + URL path or IP with path
http.begin(serverPath.c_str());
String temperature;
int httpResponseCode = http.GET();
if (httpResponseCode == 200)
{
String payload = http.getString();
// filter temperature
int index = payload.indexOf("\"temp\":");
temperature = payload.substring(index + 7, payload.indexOf(",\"feels_"));
}
else
{
Serial.print("Peticion Get fallo, codigo de Error: ");
Serial.println(httpResponseCode);
temperature = "0.0"; // if fails
}
// free
http.end();
return temperature;
}
