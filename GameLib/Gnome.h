/**
 * @file Gnome.h
 * @author Haoxiang Zhang, Shaojie Zhang
 *
 *
 */

#ifndef SPARTYGNOME_GNOME_H
#define SPARTYGNOME_GNOME_H

#include "Item.h"
#include "Visitor.h"


class Gnome : public Item{
private:

    Vector mV;

    Picture *picture;

    int mWalkMode = 1;

public:
    Gnome(Stadium *stadium, std::shared_ptr<Picture> picture);

    ~Gnome();

    /// Default constructor (disabled)
    Gnome() = delete;

    /// Copy constructor (disabled)
    Gnome(const Gnome &) = delete;

    /// Assignment operator
    void operator=(const Gnome &) = delete;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override ;

    void Accept(Visitor* visitor) override{ visitor->VisitGnome(this);}

    void Update(double elapsed) override;

    void SetyVelocity(double speed);

    void SetxVelocity(double speed);

    void MovingRight();

    void MovingLeft();

    void MovingUp();

    void ResetX() {mV.SetX(0);}

    Vector GetVelocity() {return mV;}
};

#endif //SPARTYGNOME_GNOME_H
