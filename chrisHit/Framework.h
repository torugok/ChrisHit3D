#ifndef FRAMEWORK_H
#define FRAMEWORK_H

class Framework
{
public:
	virtual void init()=0;
	virtual void Loop(float delta)=0;
};

#endif