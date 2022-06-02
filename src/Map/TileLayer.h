#ifndef TILELAYER_H_
#define TILELAYER_H_

#include "Layer.h"
#include <string>
#include <vector>

struct Tileset {
    int FirstID, LastID;
    int NumRows, NumCols;
    int TileCount, TileSize;
    std::string Name, Source;
};

using TilesetList = std::vector<Tileset>;
using TileMap = std::vector<std::vector<int>>;

class TileLayer : public Layer
{
public:
    TileLayer(int tilesize, int rowcount, int colcount, TileMap tilemap, TilesetList tilesets);
    virtual void Render();
    virtual void Update();
    inline TileMap GetTilemap() {return m_Tilemap;}

private:
    int m_TileSize;
    int m_RowCount, m_ColCount;

    TileMap m_Tilemap;
    TilesetList m_Tilesets;
};

#endif // TILELAYER_H_
