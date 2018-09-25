// Copyright (C) 2012 Sean Middleditch
// All rights reserved.
// This code is for illustration purposes for a talk.
// Do not use in your own projects for any reason.  Even
// if the copyright made it legal, you don't _want_ to
// use this code in a real project.  Seriously.
#include "../include/observed.h"
#include "../include/observer.h"

int main(int argc, char **argv)
{
	Observed observedObject;
	Observer observerObject;

	observedObject.Bind<Observer, MouseMessage, &Observer::OnMouse>(MSG_MOUSE, &observerObject);
}