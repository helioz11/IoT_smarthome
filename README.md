# IoT_smarthome
## <dht.h>
dht		/Analog
-read11(int pin)	// using DHT11 to read humidity and temperature
-humidity		// return float humidity
-temperature		// return float temperature

## <sensor.h>
IR_sensor 	/Digital
- IR_sensor(int pin) 	// constructor
- detect()		// return 0 or 1, *need to change the resistance*

Smoke_sensor	/Analog
- IR_sensor(int pin) 	// constructor
- value			// return int value
- detect()		// return 0 or 1, affect by treshold

Sound_sensor	/Analog
- IR_sensor(int pin) 	// constructor
- value			// return int value
- detect()		// return 0 or 1, affect by treshold

Buzzer		/Digital
- IR_sensor(int pin) 	// constructor
- on()			// Buzzer on
- off()			// Buzzer off

Ultrasonic Sensor
- Ultrasonic_sensor(int trig, int echo)	// constructor
- value()				// return int value(with smoothing)

Photocell Sensor
- Photocell_sensor(int trig, int echo)	// constructor
- value()				// return int value(with smoothing)

Accelerometer
- Implementation like lab
- GY80 sensor = GY80(); 			//create GY80 instance
- GY80_scaled g_value = sensor.read_scaled();
- g_value.a_x , g_value.a_y, g_value.a_z. 	//x,y,z acceleration
