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

public:
    Gnome(Stadium *stadium, Picture *picture);

    ~Gnome();

    /// Default constructor (disabled)
    Gnome() = delete;

    /// Copy constructor (disabled)
    Gnome(const Gnome &) = delete;

    /// Assignment operator
    void operator=(const Gnome &) = delete;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics);

    void Accept(Visitor* visitor) override{ visitor->VisitGnome(this);}

    void Update(double elapsed);

    void SetyVelocity() {mV.Y() = JumpSpeed ;}
};

#endif //SPARTYGNOME_GNOME_H
