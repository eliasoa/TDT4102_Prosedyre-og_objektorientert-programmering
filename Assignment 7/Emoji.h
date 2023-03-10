#pragma once
#include "std_lib_facilities.h"
#include "AnimationWindow.h"

// Abstrakt klasse. Arvende konkrete klasser må implementere funksjonen draw()
// som tegner former i vinduet de skal bli vist i.
class Emoji
{
public:
    virtual void draw(AnimationWindow&) = 0;
    virtual ~Emoji(){}; //destruktør
};

class Face : public Emoji
{
public:
    /// @brief Constructor
    /// @param centre Point
    /// @param radius int
    Face(Point centre, int radius);

    /// @brief virtual function used for children of this class
    /// @param  AnimationWindow
    void draw(AnimationWindow& win)override = 0;
protected:
    Point centre;
    int radius;
};

class EmptyFace : public Face
{
private:
    Point leftEye{0,0};
    Point rightEye{0,0};
    int eyeRadius{0};
public:
    /// @brief Constructor
    /// @param centre Point
    /// @param radius int
    EmptyFace(Point centre, int radius);

    /// @brief Function that draws a blank face with eyes
    /// @param win AnimationWindow
    void draw(AnimationWindow& win)override;
};

class SmileyFace : public EmptyFace
{
protected:
    Point mouthPosition{0,0};
    int mouthWidth{0};
    int mouthHeight{0};
    int startDegree{0};
    int endDegree{0};
public:
    /// @brief Constructor
    /// @param centre Point
    /// @param radius int
    SmileyFace(Point centre, int radius);

    /// @brief Function that draws a smiley face
    /// @param win AnimationWindow
    void draw(AnimationWindow& win)override;
};

class SadFace : public EmptyFace
{
private:
    Point mouthPosition{0,0};
    int mouthWidth{0};
    int mouthHeight{0};
    int startDegree{0};
    int endDegree{0};
public:
    SadFace(Point centre, int radius);

    void draw(AnimationWindow& win);
};

class SuprisedFace : public EmptyFace
{
private:
    Point mouthPosition{0,0};
    int mouthWidth{0};
    int mouthHeight{0};
    int startDegree{0};
    int endDegree{0};
public:
    SuprisedFace(Point centre, int radius);

    void draw(AnimationWindow& win);

};

