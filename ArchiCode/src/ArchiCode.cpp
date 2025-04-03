/*
Used for Testing Bukas dll file
*/

#include <Bukas.h>

class ArchiCode : public Bukas::Application {
public:
	ArchiCode() {

	}

	~ArchiCode() {

	}
};

Bukas::Application* Bukas::CreateApplication() {
	return new ArchiCode();
}