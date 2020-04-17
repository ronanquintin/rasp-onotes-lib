
#ifndef DEVICE_H_
#define DEVICE_H_

#include <string>

class Device {

private:

	std::string name;

	std::string description;



public:
	Device();
	virtual ~Device();
};

#endif /* DEVICE_H_ */
