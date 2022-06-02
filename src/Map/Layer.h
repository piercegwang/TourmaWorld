#ifndef LAYER_H_
#define LAYER_H_

class Layer
{
public:
    virtual void Render()=0;
    virtual void Update()=0;
};

#endif // LAYER_H_
