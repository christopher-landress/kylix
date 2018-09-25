#include "../include/observed.h"
#include "../include/observer.h"

int main(int argc, char **argv)
{
	Observed observedObject;
	Observer observerObject;

	observedObject.Bind<Observer, MouseMessage, &Observer::OnMouse>(MSG_MOUSE, &observerObject);
}
