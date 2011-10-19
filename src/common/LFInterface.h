#ifndef IFACE_H
#define IFACE_H

///Interface
class LFInterface
{
public:
    ///Liest die fiff - Datei und gibt das LFFiffData - Objekt zurück
    static int fiffRead(LFData& output, const char* path);
};

#endif
