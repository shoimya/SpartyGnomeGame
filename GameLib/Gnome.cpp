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

/// The jump speed
const double JumpSpeed = -800;

/// Small value to ensure we do not stay in collision
const double Epsilon = 0.01;

Gnome::Gnome(Stadium* stadium, std::shared_ptr<Picture> picture) :Item(stadium, picture)
{

}

void Gnome::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    if(!GetPicture()->Empty())
    {
        int wid = GetPicture()->GetWidth();
        int hit = GetPicture()->GetHeight();
        graphics->DrawBitmap(GetPicture()->AsBitmap(graphics),
                (int) GetX()-wid/2, (int) GetY()-hit/2,
                wid+1, hit);
    }

}

Gnome::~Gnome()
{

}

void Gnome::Update(double elapsed)
{
    if(mStop)
    {
        SetLocation(GetX(),GetY());
        SetPicture(mPrevious);
    }
    else
    {

        // current position
        Vector p = GetPos();

        // Compute a new velocity with gravity added in.
        Vector newV(mV.X(), mV.Y()+Gravity*elapsed);

        // Update position
        Vector newP = p+newV*elapsed;

        SetLocation(p.X(), newP.Y());

        auto collided = GetStadium()->CollisionTest(this);

        if (collided!=nullptr) {
            if (collided->GetPhysical() && GetPhysical()) {
                if (newV.Y()>0) {
                    // We are falling, stop at the collision point
                    newP.SetY(collided->GetY()-collided->GetHeight()/2-GetHeight()/2-Epsilon);
                }
                else {
                    // We are rising, stop at the collision point
                    newP.SetY(collided->GetY()+collided->GetHeight()/2+GetHeight()/2+Epsilon);
                }
                // If we collide, we cancel any velocity
                // in the Y direction
                newV.SetY(0);
            }

        }
        //
        // Try updating the X location
        //
        SetLocation(newP.X(), p.Y());

        collided = GetStadium()->CollisionTest(this);
        if (collided!=nullptr) {
            if (GetPhysical() && collided->GetPhysical()) {
                if (newV.X()>0) {
                    // We are moving to the right, stop at the collision point
                    newP.SetX(collided->GetX()-collided->GetWidth()/2-GetWidth()/2-Epsilon);
                }
                else {
                    // We are moving to the left, stop at the collision point
                    newP.SetX(collided->GetX()+collided->GetWidth()/2+GetWidth()/2+Epsilon);
                }
                // If we collide, we cancel any velocity
                // in the X direction
                newV.SetX(0);
            }
        }



        // Update the velocity and position
        mV = newV;
        SetLocation(newP.X(), newP.Y());

        if (mV.X()<0 && mV.Y()==0) {
            if (mWalkMode==1) {
                SetPicture(L"gnome-walk-left-1.png");
                mPrevious = L"gnome-walk-left-1.png";
                mWalkMode = 2;
            }
            else {
                SetPicture(L"gnome-walk-left-2.png");
                mPrevious = L"gnome-walk-left-2.png";
                mWalkMode = 1;
            }
        }
        else if (mV.X()>0 && mV.Y()==0) {
            if (mWalkMode==1) {
                SetPicture(L"gnome-walk-right-1.png");
                mPrevious = L"gnome-walk-right-1.png";
                mWalkMode = 2;
            }
            else {
                SetPicture(L"gnome-walk-right-2.png");
                mPrevious = L"gnome-walk-right-2.png";
                mWalkMode = 1;
            }
        }
        else if (mV.X()!=0 && mV.Y()!=0) {
            if (mV.X()<0) {
                SetPicture(L"gnome-walk-left-1.png");
                mPrevious = L"gnome-walk-left-1.png";
                mWalkMode = 1;
            }
            else {
                SetPicture(L"gnome-walk-right-1.png");
                mPrevious = L"gnome-walk-right-1.png";
                mWalkMode = 1;
            }
        }
        else if (mV.X()==0) {
            SetPicture(L"gnome.png");
            mWalkMode = 1;
        }
    }
}

void Gnome::MovingUp()
{
    SetyVelocity(JumpSpeed);
}

void Gnome::SetyVelocity(double speed)
{
    if(mV.Y() == 0)
    {
        mV.SetY(speed);
    }
}

void Gnome::SetxVelocity(double speed)
{
    mV.SetX(speed);
}

void Gnome::MovingRight()
{
    SetxVelocity(HorizontalSpeed);
}

void Gnome::MovingLeft()
{
    SetxVelocity(-HorizontalSpeed);
}

void Gnome::SetStop(bool stop)
{
    mStop = stop;
}