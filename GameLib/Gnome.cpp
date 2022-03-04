/**
 * @file Gnome.cpp
 * @author Haoxiang Zhang, Shaojie Zhang
 */

#include "pch.h"
#include "Gnome.h"
#include "Stadium.h"
using namespace std;

/// Gravity in virtual pixels per second per second
const double Gravity = 1000.0;

/// Horizontal character speed in pixels per second
const double HorizontalSpeed = 500.00;



/// Small value to ensure we do not stay in collision
const double Epsilon = 0.01;


const wstring GnomeImageName = L"/images/gnome.png";

Gnome::Gnome(Stadium* stadium, Picture* picture)
        :Item(stadium, picture)
{

}

void Gnome::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{

}

Gnome::~Gnome()
{

}

void Gnome::Update(double elapsed)
{
    Item::Update(elapsed);

    // current position
    Vector p = GetPos();

    // Compute a new velocity with gravity added in.
    Vector newV(mV.X(),mV.Y() + Gravity * elapsed);

    // Update position
    Vector newP = p + newV * elapsed;

    SetLocation(p.X(), newP.Y());

    mV = newV;

    auto collided = GetStadium() -> CollisionTest(this);

    if (collided != nullptr)
    {
        if (newV.Y() > 0)
        {
            // We are falling, stop at the collision point
            newP.SetY(collided->GetY() - collided->GetHeight() / 2 - GetHeight() / 2 - Epsilon);
        }
        else
        {
            // We are rising, stop at the collision point
            newP.SetY(collided->GetY() + collided->GetHeight() / 2 + GetHeight() / 2 + Epsilon);
        }

        // If we collide, we cancel any velocity
        // in the Y direction
        newV.SetY(0);

    }

    SetLocation(p.X(), newP.Y());

    mV = newV;
}


