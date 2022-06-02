#ifndef GAMEMAP_H_
#define GAMEMAP_H_

#include "Layer.h"
#include <vector>

class GameMap
{
public:
    inline void Render() {
        for(unsigned int i=0; i < m_MapLayers.size(); i++)
            m_MapLayers[i]->Render();
    }

    inline void Update() {
        for(unsigned int i=0; i < m_MapLayers.size(); i++)
            m_MapLayers[i]->Update();
    }

    std::vector<Layer*> GetMapLayers(){return m_MapLayers;}
private:
    std::vector<Layer*> m_MapLayers;
};

#endif // GAMEMAP_H_
