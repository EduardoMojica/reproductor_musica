#pragma once
#include <vector>
#include <string>
#include "Cancion.h"

class FileLoader {
public:
    std::vector<Cancion> scanDirectory(const std::string& path);
};
