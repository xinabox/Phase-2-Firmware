/*
	This is a library for the SI01 
	3D Accelerometer, 3D gyroscope, 3D magnetometer

	The board uses I2C for communication.
	
	The board communicates with two I2C devices:
	* 	LSM9DS1   
	
	Data Sheets:
	LSM9DS1 - http://www.st.com/content/ccc/resource/technical/document/datasheet/1e/3f/2a/d6/25/eb/48/46/DM00103319.pdf/files/DM00103319.pdf/jcr:content/translations/en.DM00103319.pdf
*/

#ifndef vaSI01_CONFIG_h
#define vaSI01_CONFIG_h

struct Gyroscope{
	uint8_t scale;
	uint8_t sampleRate;
	uint8_t bandwidth;
	uint8_t lowpower;
	uint8_t HPF;
	uint8_t HPF_CutOFF;
	uint8_t enable_axis;
	uint8_t latchedIRQ;	
	boolean enabled;
};

struct Accelerometer{
	uint8_t scale;
	uint8_t sampleRate;
	uint8_t bandwidth;
	uint8_t lowpower;
	uint8_t enable_axis;
	boolean enabled;
};

struct Magnotomer{
	uint8_t scale;
	uint8_t sampleRate;
	uint8_t bandwidth;
	uint8_t performanceXY;
	uint8_t performanceZ;
	uint8_t lowpower;
	uint8_t mode;
	uint8_t fast_read;
	uint8_t BDU;
	uint8_t enable_axis;
	boolean enabled;
};

struct Temperature{
	boolean enabled;
};

struct Sensitivity{
	float accel;
	float gyro;
	float mag;
};

struct vSI01{
	Gyroscope gyro;
	Accelerometer accel;
	Magnotomer mag;
	Temperature temp;
	Sensitivity sensitivity;
};

#endif

