/**
 * @file Gnome.h
 * @author Haoxiang Zhang
 *
 *
 */

#ifndef SPARTYGNOME_GNOME_H
#define SPARTYGNOME_GNOME_H

class Stadium;

class Gnome {
private:

    Stadium   *mStadium;

    double mX = 0;     ///< X location for the center of the Gnome
    double mY = 0;     ///< Y location for the center of the Gnome

    /// The underlying Gnome image
    std::unique_ptr<wxImage> mGnomeImage;

    /// The bitmap we can display for the Gnome
    std::unique_ptr<wxBitmap> mGnomeBitmap;

public:

    Gnome(Stadium *stadium);

    /// Default constructor (disabled)
    Gnome() = delete;

    /// Copy constructor (disabled)
    Gnome(const Gnome &) = delete;

    /// Assignment operator
    void operator=(const Gnome &) = delete;


    void SetLocation(double x, double y) { mX = x; mY = y;}

    void Draw(wxDC *dc);

};

#endif //SPARTYGNOME_GNOME_H
