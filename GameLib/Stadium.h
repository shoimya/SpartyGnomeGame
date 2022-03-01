/**
 * @file Stadium.h
 * @author Haoxiang Zhang
 *
 *
 */

#ifndef SPARTYGNOME_STADIUM_H
#define SPARTYGNOME_STADIUM_H

class Stadium {
private:
    void XmlTile(wxXmlNode *node);

    /// Directory containing the system images
    std::wstring mImagesDirectory;



public:
    Stadium();
    virtual ~Stadium() = default;
    const std::wstring &GetImagesDirectory() {return mImagesDirectory;}

    void SetImageDirectory(const std::wstring& dir);

    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics);
};

#endif //SPARTYGNOME_STADIUM_H
