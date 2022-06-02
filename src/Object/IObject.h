#ifndef IOBJECT_H_
#define IOBJECT_H_

class IObject
{
public:
    virtual void Draw() = 0;
    virtual void Update(float dt) = 0;
    virtual void Clean()=0;
};

#endif // IOBJECT_H_
