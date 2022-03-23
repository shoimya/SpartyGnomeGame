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

/// Gnome class
class Gnome : public Item{
private:
    /// The speed vector
    Vector mV;

    /// The walk mode
    int mWalkMode = 1;

    /// The init position
    Vector mInitPos;

    /// The stop status
    bool mStop = false;

    /// The previous path
    std::wstring mPrevious = L"";

public:
    /// Constructor
    Gnome(Stadium *stadium, std::shared_ptr<Picture> picture);

    ~Gnome();

    /// Default constructor (disabled)
    Gnome() = delete;

    /// Copy constructor (disabled)
    Gnome(const Gnome &) = delete;

    /// Assignment operator
    void operator=(const Gnome &) = delete;

    /**
     * Draw function for gnome
     * @param graphics The graphics we are using
     */
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override ;

    /**
     * The accept function for visitor
     * @param visitor The visitor
     */
    void Accept(Visitor* visitor) override{ visitor->VisitGnome(this);}

    /**
     * The update function
     * @param elapsed The time to update
     */
    void Update(double elapsed) override;

    /**
     * Set the y velocity for gnome
     * @param speed The y speed to set
     */
    void SetyVelocity(double speed);

    /**
     * Set the x speed for gnome
     * @param speed The x speed to set
     */
    void SetxVelocity(double speed);

    /**
     * The moving right function
     */
    void MovingRight();

    /**
     * The moving left function
     */
    void MovingLeft();

    /**
     * The moving up function
     */
    void MovingUp();

    /**
     * The reset function
     */
    void ResetX() {mV.SetX(0);}

    /**
     * Set init position
     * @param vec The init position
     */
    void SetInitPosition(Vector vec)
    {
        mInitPos = vec;
    }

    /**
     * Initialize init position
     */
    void InitPosition(){ SetLocation(mInitPos);}

    /**
     * Get the init position
     * @return The init position
     */
    Vector GetInitPos(){return mInitPos;}

    /**
     * Get the current velocity
     * @return The velocity
     */
    Vector GetVelocity() {return mV;}

    /**
     * Set stop status
     * @param stop The stop status
     */
    void SetStop(bool stop);
};

#endif //SPARTYGNOME_GNOME_H
