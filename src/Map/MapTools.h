#ifndef MAPTOOLS_H_
#define MAPTOOLS_H_

struct Chunk {
    int x, y;
};

class MapInterface {
public:
    bool load(Chunk chunk);

    inline static MapInterface* GetInstance() {return s_Instance = (s_Instance != nullptr)? s_Instance : new MapParser();}

private:
    static MapInterface* s_Instance;
};

#endif // MAPTOOLS_H_
