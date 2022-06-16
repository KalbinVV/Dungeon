#ifndef VEC2I_H_INCLUDED
#define VEC2I_H_INCLUDED

class Vec2i{
public:
    int x;
    int y;
    Vec2i();
    Vec2i(Vec2i* anotherVec2i);
    Vec2i addX(int value);
    Vec2i addY(int value);
};

#endif // VEC2I_H_INCLUDED
